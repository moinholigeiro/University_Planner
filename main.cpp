#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <deque>
#include <list>

#include <unordered_map>

#include "Disciplina.hpp"

using namespace std;

int main(){
    unordered_map<string, Disciplina*> disciplinas;
    list<Disciplina*> disciplinas_list;
    ifstream input("teste - backup.txt");
    
    if(!input){
        cerr << "Erro ao abrir o arquivo!\n";
        return 1;
    }

    string linha;
    string codigo, nome;

    int i = 0;
    while(getline(input, linha)){
        if(linha.empty()) break;

        if(linha.back() == '\r') linha.pop_back(); // Especialmente útil para formatação vinda de Windows

        if (linha[0] == '\t' && disciplinas[codigo]) {
            linha.erase(0, 1); // Remove '\t'

            if (linha[0] == '-') { // Aqui, a linha é de co-requisito da disciplina em questão
                linha.erase(0, 1); // Remove '-'

                disciplinas[codigo]->adiciona_co_requisito(linha);
            } else { // Aqui, a linha é de pré-requisito da disciplina em questão
                disciplinas[codigo]->adiciona_pre_requisito(linha);

                if(!disciplinas[linha]) disciplinas[linha] = new Disciplina(linha);
                disciplinas[linha]->adiciona_requisitadas(codigo);
            }
        } else if (linha[0] == '\t' && !disciplinas[codigo]) {
            if (linha[0] == '-') {
                linha.erase(0, 1); // Remove '-'
                cout << "Erro! não foi possível identificar a disciplina pela qual \'" << linha << "\' seja co-requisito!" << endl;
            } else {
                cout << "Erro! não foi possível identificar a disciplina pela qual \'" << linha << "\' seja pré-requisito!" << endl;
            }
        } else { // Aqui, a linha é a da disciplina em questão
            istringstream iss(linha);
            iss >> codigo; // Primeiro token é o código
            getline(iss, nome); // O restante é o nome

            if (!nome.empty() && nome[0] == ' ')
                nome.erase(0, 1);
            
            if(disciplinas[codigo])
                disciplinas[codigo]->adiciona_nome(nome);
            else
                disciplinas[codigo] = new Disciplina(codigo, nome);
        }

        i++;
    }
    input.close();

    Disciplina::calcula_prioridade(disciplinas);
    Disciplina::calcula_semestre(disciplinas);


    for (auto it = disciplinas.begin(); it != disciplinas.end(); it++)
        disciplinas_list.push_back(it->second);
    
    disciplinas_list.sort(Disciplina::compara_semestre);

    for(int i=0;!disciplinas_list.empty();i++){
        cout << "Período " << i << ":" << endl;
        while(!disciplinas_list.empty() && disciplinas_list.front()->get_semestre() == i){
            cout << disciplinas_list.front()->get_codigo() << " " << disciplinas_list.front()->get_nome() << " (Prioridade " << disciplinas_list.front()->get_prioridade() << ")" << endl;
            disciplinas_list.pop_front();
        }
    }

    for (auto it = disciplinas.begin(); it != disciplinas.end(); it++)
        delete it->second;

    return 0;
}
