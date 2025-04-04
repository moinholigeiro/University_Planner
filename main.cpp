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

#define ARQUIVO_FEITAS "feitas.txt"
#define ARQUIVO_GRADE "grade.txt"

using namespace std;

int main(){
    unordered_map<string, Disciplina*> disciplinas;
    list<Disciplina*> disciplinas_list;

    string linha;
    string codigo, nome;

    ifstream feitas(ARQUIVO_FEITAS);
    ifstream grade(ARQUIVO_GRADE);

    if(!grade || !feitas){
        if(grade){
            cerr << "Arquivo \'" << ARQUIVO_FEITAS << "\' não encontrado!" << endl;
            grade.close();
        } else if(feitas){
            cerr << "Arquivo \'" << ARQUIVO_GRADE << "\' não encontrado!" << endl;
            feitas.close();
        } else
            cerr << "Arquivos \'" << ARQUIVO_FEITAS << "\' e \'" << ARQUIVO_GRADE << "\' não encontrados!" << endl;

        cerr << "Confira o README.md para mais informações!" << endl;
        cerr << "Encerrando..." << endl;
        return 1;
    }

    while(getline(feitas, linha)){
        if(linha.empty()) break;

        if(linha.back() == '\r') linha.pop_back(); // Especialmente útil para formatação vinda de Windows
        if(linha.front() <= ' ') continue;

        istringstream iss(linha);
        iss >> codigo; // Evita problemas caso o usuário não deixe na formatação adequada (deixe o nome da disciplina junto)
        if(!disciplinas[codigo]) disciplinas[codigo] = new Disciplina(codigo);
        disciplinas[codigo]->set_cursou(true);
    }
    feitas.close();

    while(getline(grade, linha)){
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

    }
    grade.close();

    Disciplina::calcula_prioridade(disciplinas);
    Disciplina::calcula_semestre(disciplinas);

    for(auto it = disciplinas.begin(); it != disciplinas.end(); it++)
        disciplinas_list.push_back(it->second);
    
    disciplinas_list.sort(Disciplina::compara_semestre);

    for(int i=0;!disciplinas_list.empty();i++){
        cout << "Período " << i + 1 << ":" << endl;
        while(!disciplinas_list.empty() && disciplinas_list.front()->get_semestre() == i){
            if(!disciplinas_list.front()->ja_cursou())
                cout << disciplinas_list.front()->get_codigo() << " " << disciplinas_list.front()->get_nome() << " (Prioridade " << disciplinas_list.front()->get_prioridade() << ")" << endl;
            disciplinas_list.pop_front();
        }
        cout << endl;
    }

    for(auto it = disciplinas.begin(); it != disciplinas.end(); it++)
        delete it->second;

    return 0;
}
