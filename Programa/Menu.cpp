#include "Menu.hpp"

namespace Menu {

    namespace Inicial {
        void print(){
            cout << "============================================" << endl;
            cout << "Bem vindo ao organizador de disciplinas!" << endl;
            cout << "============================================" << endl;
            cout << endl;
            cout << REALIZAR_PLANEJAMENTO << " - Realizar planejamento" << endl;
            cout << UNDEF2 << "2 - " << endl;
            cout << UNDEF3 << "3 - " << endl;
            cout << UNDEF4 << "4 - " << endl;
            cout << UNDEF2 << "9 - Ajuda" << endl;
            cout << "Para sair e encerrar o programa, digite" << endl;
            cout << "qualquer outra tecla" << endl;
            cout << "============================================" << endl;
            cout << endl;
            cout << "Digite o número de acordo com o desejado: " << endl;
        }
    }

}
