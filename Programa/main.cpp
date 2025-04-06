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

// while(true){
//     try{
//         p = Planejamento(ARQUIVO_INPUT_GRADE, ARQUIVO_INPUT_FEITAS);
//         break;
//     } catch(const exception& e){
//         string continuar;
//         cerr << "Crie o arquivo com a grade do curso para continuar." << endl;
//         cerr << "Confira o README.md para mais informações!" << endl;
//         cout << "Digite \'1\' para continuar ou qualquer outra tecla para encerrar o programa: ";

//         cin >> continuar;
//         if(continuar != "1"){
//             cerr << "Encerrando..." << endl;
//             return;
//         }
//     }
// }

void realizar_planejamento(Planejamento& p){
    p = Planejamento(ARQUIVO_INPUT_GRADE, ARQUIVO_INPUT_FEITAS);
}

void ajuda(Planejamento& p){
    
}

void exportar_por_periodo(Planejamento& p){
    p.set_modo_de_exportacao(Planejamento::Por_periodo);
    ofstream output(ARQUIVO_OUTPUT_PLANEJ_PERIODO);
    output << p;
    output.close();
}

void exportar_por_prioridade(Planejamento& p){
    p.set_modo_de_exportacao(Planejamento::Por_prioridade);
    ofstream output(ARQUIVO_OUTPUT_PLANEJ_PRIOR);
    output << p;
    output.close();
}

int main(){
    Planejamento planner;

    Menu menu_inicial("Menu Inicial");
    Menu menu2("O que você deseja fazer?");

    menu_inicial.adicionar_opcao("Realizar planejamento", realizar_planejamento, &menu2);
    menu_inicial.adicionar_opcao("Ajuda", ajuda, nullptr);

    menu2.adicionar_opcao("Exportar planejamento por período", exportar_por_periodo, nullptr);
    menu2.adicionar_opcao("Exportar planejamento por prioridade", exportar_por_prioridade, nullptr);

    menu_inicial.exibir(planner);

    // Planejamento planner = Planejamento(ARQUIVO_INPUT_GRADE, ARQUIVO_INPUT_FEITAS);
    // planner.set_modo_de_exportacao(planner.Por_prioridade);
    // cout << planner;

    return 0;
}
