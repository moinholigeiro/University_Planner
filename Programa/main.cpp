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

int main(){
    string comando;

    // while(true){
    //     Menu::inicial();
    //     cin >> comando;
        
    //     try{

    //         Planejamento planner = Planejamento(ARQUIVO_INPUT_GRADE, ARQUIVO_INPUT_FEITAS);
    
    
    
    //         planner.set_modo_de_exportacao(planner.Por_prioridade);
    //         cout << planner;
    //     } catch(const Excecao& e){
    //         cerr << e.what();
    //         cerr << "Confira o README.md para mais informações!" << endl;
    //     } catch(const exception& e){
    //         cerr << e.what();
    //         cerr << "Confira o README.md para mais informações!" << endl;
    //         cerr << "Encerrando..." << endl;
    //         break;
    //     }
    // }
    return 0;
}
