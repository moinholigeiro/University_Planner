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

#include "_DEBUG.hpp"

#define ARQUIVO_INPUT_FEITAS "../Arquivos/Feitas.txt"
#define ARQUIVO_INPUT_GRADE "../Arquivos/Grade.txt"
#define ARQUIVO_INPUT_TABELA_EQUIVALENCIA "../Arquivos/Tabela_de_Equivalencia.txt"

#define ARQUIVO_OUTPUT_PLANEJ_PERIODO "../Arquivos/Planejamento por período.txt"
#define ARQUIVO_OUTPUT_PLANEJ_PRIOR "../Arquivos/Planejamento por prioridade.txt"

using namespace std;

void creditos(){
    Menu::limpar_terminal();
    cout << "Feito por: Daniel Moulin (Moinho)" << endl;
    cout << "\t- github.com/moinholigeiro" << endl;
}

bool importar_planejamento(Planejamento*& planner, Menu& menu){
    while(planner == nullptr){

        try{
            planner = new Planejamento(ARQUIVO_INPUT_GRADE, ARQUIVO_INPUT_FEITAS);
        } catch(const runtime_error& e){
            string continuar;
            
            cout << "Crie o arquivo " << ARQUIVO_INPUT_GRADE << " com a grade do curso, e na formatação correta para continuar." << endl;
            cout << "Confira o README.md para mais informações!\n" << endl;

            vector<string> opcoes = {
                "Continuar após ter criado o arquivo",
                "Ver exemplo de formatação correta para o arquivo"
            };

            // menu.set_titulo("Erro ao criar planejamento");
            while(true){
                menu.exibir(opcoes, false);
                if(menu.opcao() == 1){
                    break;
                } else if(menu.opcao() == 2){
                    Planejamento::exemplo_de_formatacao(cout);
                } else{
                    cout << "Encerrando..." << endl;
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    Planejamento* planner = nullptr;
    Menu menu("Buscando " + string(ARQUIVO_INPUT_GRADE));

    Menu::limpar_terminal();

    if(!importar_planejamento(planner, menu))
        return 1;

    menu.set_titulo("Menu Inicial");
    vector<string> opcoes = {
        "Exportar planejamento por período",
        "Exportar planejamento por prioridade",
        "Configurar",
        "Créditos"
    };

    while(true){
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
        cout << endl;
    }

    delete planner;

    // // ----------------------- DEBUG -------------------------
    // string arq_per = ARQUIVO_OUTPUT_PLANEJ_PERIODO;
    // string arq2_per_CORRETO = (arq_per.substr(0, arq_per.size() - sizeof(".txt") + 1));
    // arq2_per_CORRETO += " - CORRETO.txt";

    // string arq_prior = ARQUIVO_OUTPUT_PLANEJ_PRIOR;
    // string arq2_prior_CORRETO = (arq_prior.substr(0, arq_prior.size() - sizeof(".txt") + 1));
    // arq2_prior_CORRETO += " - CORRETO.txt";

    // cout << arq2_per_CORRETO << endl;
    // cout << arq2_prior_CORRETO << endl;

    // if (!DEBUG::arquivos_iguais(arq_per, arq2_per_CORRETO))
    //     cout << "ARQUIVO " << ARQUIVO_OUTPUT_PLANEJ_PERIODO << " ERRADO!" << endl;
    // if (!DEBUG::arquivos_iguais(arq_per, arq2_per_CORRETO))
    //     cout << "ARQUIVO " << ARQUIVO_OUTPUT_PLANEJ_PRIOR << " ERRADO!" << endl;
    // // --------------------------------------------------------

    return 0;
}
