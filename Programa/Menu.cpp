#include "Menu.hpp"

void Menu::adicionar_opcao(const string& desc, function<void()> func) {
    _opcoes.push_back({desc, func});
}

void Menu::exibir() {
    while (true) {
        cout << endl << "=== " << _titulo << " ===" << endl;
        for (size_t i = 0; i < opcoes.size(); ++i) {
            cout << i + 1 << ". " << opcoes[i].descricao << "\n";
        }
        cout << "0. Voltar\n";
        cout << "Escolha: ";

        int escolha;
        cin >> escolha;

        if (escolha == 0) break;

        if (escolha > 0 && (size_t)escolha <= opcoes.size()) {
            opcoes[escolha - 1].acao();
        } else {
            cout << "Opção inválida.\n";
        }
    }
}

// namespace Menu {

    namespace Inicial {
        void print(vector<string>& items){
            cout << "============================================" << endl;
            cout << "Bem vindo ao organizador de disciplinas!" << endl;
            cout << "============================================" << endl;
            cout << endl;

            for(int i=0; i < (int) items.size(); i++)
                if(!items[i].empty())
                    cout << i << " - " << items[i] << endl;

            cout << "Para sair e encerrar o programa, digite" << endl;
            cout << "qualquer outra tecla" << endl;
            cout << "============================================" << endl;
            cout << endl;
            cout << "Digite o número de acordo com o desejado: " << endl;
        }
    }

    // namespace Outro{
    //     void print(vector<string>& items){
    //         cout << "=============== testando ================" << endl;
    //         cout << endl;

    //         for(int i=0; i < (int) items.size(); i++)
    //             cout << i << " - " << items[items.size() - 1 - i] << endl;
    //         cout << "============================================" << endl;
    //         cout << endl;
    //     }
    // }

// }
