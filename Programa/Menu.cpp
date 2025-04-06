#include "Menu.hpp"


void Menu::adicionar_opcao(const string& desc, function<void(Planejamento&)> func, Menu* sub_menu) {
    _opcoes.emplace_back(desc, func, sub_menu);
}

void Menu::exibir(Planejamento& p) {
    while (true) {
        cout << endl << "=== " << _titulo << " ===" << endl;

        for(size_t i=0;i < _titulo.size();i++)cout << "=";
        cout << "========" << endl;
        

        for(size_t i = 0; i < _opcoes.size(); i++)
            cout << i + 1 << ". " << _opcoes[i].get_descricao() << endl;

        cout << "0. Voltar" << endl;
        cout << endl;
        cout << "Digite o número correspondente: ";

        size_t escolha;
        cin >> escolha;

        if (escolha == 0) break;

        if (escolha > 0 && escolha <= _opcoes.size()) {
            try {
                _opcoes[escolha - 1].executar(p);
                if(_opcoes[escolha - 1].get_sub_menu() != nullptr)
                    _opcoes[escolha - 1].get_sub_menu()->exibir(p);
            } catch (const exception& e) {
                cerr << "Ocorreu um erro: " << e.what() << endl;
                cerr << "Esta última operação não foi realizada com sucesso." << endl;
                cerr << "Confira o README.md para mais informações!" << endl;
            }
        } else {
            cout << "Opção inválida.\n";
        }
    }
}

// namespace Menu {

    // namespace Inicial {
    //     void print(vector<string>& items){
    //         cout << "============================================" << endl;
    //         cout << "Bem vindo ao organizador de disciplinas!" << endl;
    //         cout << "============================================" << endl;
    //         cout << endl;

    //         for(int i=0; i < (int) items.size(); i++)
    //             if(!items[i].empty())
    //                 cout << i << " - " << items[i] << endl;

    //         cout << "Para sair e encerrar o programa, digite" << endl;
    //         cout << "qualquer outra tecla" << endl;
    //         cout << "============================================" << endl;
    //         cout << endl;
    //         cout << "Digite o número de acordo com o desejado: " << endl;
    //     }
    // }

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
