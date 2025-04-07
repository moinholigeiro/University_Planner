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
#include "Planejamento.hpp"
#include "Excecao.hpp"
#include "Menu.hpp"

#define ARQUIVO_INPUT_FEITAS "../Arquivos/Feitas.txt"
#define ARQUIVO_INPUT_GRADE "../Arquivos/Grade.txt"
#define ARQUIVO_OUTPUT_PLANEJ_PERIODO "../Arquivos/Planejamento por período.txt"
#define ARQUIVO_OUTPUT_PLANEJ_PRIOR "../Arquivos/Planejamento por prioridade.txt"

using namespace std;

void creditos(){
    cout << endl;
    cout << "Feito por: Daniel Moulin (Moinho)" << endl;
    cout << "\t- github.com/moinholigeiro" << endl;
}

int main(){
    Planejamento* planner = nullptr;
    Menu menu("Buscando " + string(ARQUIVO_INPUT_GRADE));

    while(planner == nullptr){
        try{
            planner = new Planejamento(ARQUIVO_INPUT_GRADE, ARQUIVO_INPUT_FEITAS);
        } catch(const exception& e){
            string continuar;
            cout << "Crie o arquivo " << ARQUIVO_INPUT_GRADE << " com a grade do curso, e na formatação correta para continuar." << endl;
            cout << "Confira o README.md para mais informações!" << endl;

            vector<string> opcoes = {
                "Continuar após ter criado o arquivo",
                "Ver exemplo de formatação correta para o arquivo",
                "Encerrar programa"
            };

            menu.set_titulo("Erro ao criar planejamento");
            menu.exibir(opcoes, false);
            if(menu.opcao() == 1){
                continue;
            } else if(menu.opcao() == 2){
                cout << endl;
                Planejamento::exemplo_de_formatacao(cout);
            } else{
                cout << "Encerrando..." << endl;
                return 0;
            }
        }
    }

    menu.set_titulo("Menu Inicial");
    vector<string> opcoes = {
        "Exportar planejamento por período",
        "Exportar planejamento por prioridade",
        "Configurar",
        "Créditos"
    };
    while(true){
        cout << "\n\n" << endl;
        menu.exibir(opcoes, false);

        if(menu.opcao() == 1){
            planner->set_modo_de_exportacao(Planejamento::Por_periodo);
            ofstream output(ARQUIVO_OUTPUT_PLANEJ_PERIODO);
            output << planner;
            output.close();
        } else if(menu.opcao() == 2){
            planner->set_modo_de_exportacao(Planejamento::Por_prioridade);
            ofstream output(ARQUIVO_OUTPUT_PLANEJ_PRIOR);
            output << planner;
            output.close();
        } else if(menu.opcao() == 3){
            cout << "Ainda não implementado." << endl;
            cout << "Aguarde a próxima versão!" << endl;
        } else if(menu.opcao() == 4){
            creditos();
        } else{
            break;
        }
    }

    delete planner;

    return 0;
}
