#ifndef _MENU_HPP
#define _MENU_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <string>

#include "Opcao.hpp"

using namespace std;

class Menu {
private:
    string _titulo;
    vector<Opcao&> _opcoes;

public:
    Menu(string titulo) : _titulo(titulo) {}

    void adicionar_opcao(const string& desc, function<void()> func);
    void exibir();
};

#endif
