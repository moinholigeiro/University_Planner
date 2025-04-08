#ifndef _MENU_HPP
#define _MENU_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <string>

#include "Planejamento.hpp"

#include "Excecao.hpp"

using namespace std;

class Menu {
private:
    string _titulo = "Menu Principal";
    size_t _opcao_atual = 0;

public:
    Menu(string titulo_inicial) : _titulo(titulo_inicial){}

    static void limpar_terminal();
    void exibir(vector<string> opcoes, bool opcao_voltar);

    // void set_titulo(string titulo) { _titulo = titulo;}

    size_t opcao() const { return _opcao_atual;}
};

#endif
