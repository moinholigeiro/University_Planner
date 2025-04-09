#include "Menu.hpp"
#include <cstdlib>
#include <cctype>

void Menu::trim_front(string& linha){
    int i=0;
    for(i=0;i < !linha.empty() && linha[i] <= ' ';i++)
        continue;
    linha.erase(0, i);
}

void Menu::trim_back(string& linha){
    while (!linha.empty() && linha.back() <= ' ')
        linha.pop_back();
}

void Menu::trim(string& linha) {
    trim_back(linha);
    trim_front(linha);
}

void Menu::uppercase(string& str) {
    for (char& c : str)
        c = toupper(static_cast<unsigned char>(c));
}

void Menu::limpar_terminal(){
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear"); // Linux / MacOS
#endif
}

// Aqui eu só peguei do ChatGPT mesmo, na cara dura, confesso
#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
    char ler_caractere() {
        return _getch(); // ou getch(), dependendo do compilador
    }
#else
    #include <termios.h>
    #include <unistd.h>
    char ler_caractere() {
        termios oldt, newt;
        char c;
        tcgetattr(STDIN_FILENO, &oldt);          // salva configurações
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);        // modo não canônico, sem eco
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // aplica mudanças
        c = getchar();                           // lê caractere
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaura configurações
        return c;
    }
#endif


void Menu::exibir(vector<string> opcoes, bool opcao_voltar){
    while (true) {
        cout << "=== " << _titulo << " ===" << endl;

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

        char escolha = ler_caractere();
        limpar_terminal();
        if((size_t) escolha <= ((size_t)'0' + opcoes.size()) && (escolha >= ('1' - opcao_voltar))){
            _opcao_atual = escolha - '0';
            _titulo = "Opção selecionada: " + opcoes[_opcao_atual - 1];
            return;
        } else if(escolha == '9'){
            _opcao_atual = 9;
            _titulo = "Encerrando programa...";
            return;
        }

        // Alternativa abaixo, funcional, precisando pressionar enter:
        /* 
            string escolha;
            cin >> escolha;
            limpar_terminal();
            if(escolha.length() == 1){
                if((size_t) escolha[0] <= ((size_t)'0' + opcoes.size()) && (escolha[0] >= ('1' - opcao_voltar))){
                    _opcao_atual = escolha[0] - '0';
                    _titulo = "Opção selecionada: " + opcoes[_opcao_atual - 1];
                    return;
                } else if(escolha[0] == '9'){
                    _opcao_atual = 9;
                    _titulo = "Encerrando programa...";
                    return;
                }
            }
        */

        cout << "Opção inválida. Tente novamente.\n" << endl;
    }
}
