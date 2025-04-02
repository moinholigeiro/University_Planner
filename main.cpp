#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <unordered_map>

#include "Disciplina.hpp"

using namespace std;

int main(){
    unordered_map<string, Disciplina*> disciplinas;
    // vector<Disciplina*> disciplinas_vector;
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

        if(linha.back() == '\r') linha.pop_back();

        if (linha[0] == '\t' && disciplinas[codigo]) {
            linha.erase(0, 1); // Remove '\t'

            if (linha[0] == '-') { // Aqui, a linha é de co-requisito da disciplina em questão
                linha.erase(0, 1); // Remove '-'
                
                // cout << "\t-" << linha << "\r\n";

                disciplinas[codigo]->adiciona_co_requisito(linha);
            } else { // Aqui, a linha é de pré-requisito da disciplina em questão
                disciplinas[codigo]->adiciona_pre_requisito(linha);

                // cout << "\t" << linha << "\r\n";

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
    
            // cout << codigo << " " << nome << "\r\n";
            
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

    // for (auto it = disciplinas.begin(); it != disciplinas.end(); ++it)
    //     cout << *it->second;
    cout << "\t\t\ts\tp\n";
    for (auto it = disciplinas.begin(); it != disciplinas.end(); ++it)
        cout << it->second->get_codigo() << "\t" << it->second->get_semestre() << "\t" << it->second->get_prioridade() << "\n";

    for (auto it = disciplinas.begin(); it != disciplinas.end(); ++it)
        delete it->second;

    return 0;
}

// int main(){
//     unordered_map<string, Disciplina*> disciplinas;
//     ifstream input("teste.txt");
    
//     if(!input){
//         cerr << "Erro ao abrir o arquivo!\n";
//         return 1;
//     }

//     string linha;
//     Disciplina* atual = nullptr;
//     string codigo, nome;

//     while(getline(input, linha)){
//         if(linha.empty()) break;

//         if (linha[0] > ' ') {
//             istringstream iss(linha);
//             iss >> codigo; // Primeiro token é o código
//             getline(iss, nome); // O restante é o nome

//             // Remover espaço extra inicial do nome (se houver)
//             if (!nome.empty() && nome[0] <= ' ') {
//                 nome.erase(0, 1);
//             }


//             disciplinas.insert(codigo, new Disciplina(codigo, nome));
//         }
//     }
//     input.close();

//     return 0;
// }
