#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <unordered_map>

// #include "includes/Disciplina.hpp"

using namespace std;

int main(){
    // unordered_map<string, Disciplina&> disciplinas;
    ifstream input("teste.txt");
    
    if(!input){
        cerr << "Erro ao abrir o arquivo!\n";
        return 1;
    }

    string linha;
    while(getline(input, linha)){
        if (!linha.empty() && linha[0] == '\t') {
            linha.erase(0, 1); // remove '\t'

            if (!linha.empty() && linha[0] == '-') {
                linha.erase(0, 1); // remove '-'
                // Linha de co-requisito
            } else {
                // Linha de requisito
            }
        } else {
            // Separar código e nome
            istringstream iss(linha);
            string codigo, nome;
            iss >> codigo; // Primeiro token é o código
            getline(iss, nome); // O restante é o nome

            // Remover espaço extra inicial do nome (se houver)
            if (!nome.empty() && nome[0] == ' ') {
                nome.erase(0, 1);
            }

            // Criar nova categoria
            categorias.push_back({codigo, nome, {}});
        }
    }
    input.close();

    return 0;
}



codigo1 nome do que eu quero 1 
	codigo2
	codigo3
	-codigo4
codigo5 nome do que eu quero 2
	codigo6 
codigo7 nome do que eu quero 3
	codigo8
