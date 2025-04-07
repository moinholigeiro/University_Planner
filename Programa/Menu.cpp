#include "Menu.hpp"

void Menu::exibir(vector<string> opcoes, bool opcao_voltar){
    while (true) {
        cout << endl << "=== " << _titulo << " ===" << endl;

        for(size_t i=0;i < _titulo.size();i++)
            cout << "-";
        cout << "--------" << endl;
        
        for(size_t i = 0; i < opcoes.size(); i++)
            cout << i + 1 << ". " << opcoes[i] << endl;

        cout << endl;
        cout << "9. Encerrar programa" << endl;
        if(opcao_voltar)
            cout << "0. Voltar para o menu anterior" << endl;
        
        cout << endl;
        cout << "Digite o número correspondente: ";

        string escolha;
        cin >> escolha;

        if(escolha.length() == 1 && (((size_t) escolha[0] <= ((size_t)'0' + opcoes.size()) && (escolha[0] >= ('1' - opcao_voltar))) || escolha[0] == '9')){
            _opcao_atual = escolha[0] - '0';
            return;
        }
        
        cout << "Opção inválida. Tente novamente." << endl;
    }
}
