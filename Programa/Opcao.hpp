#ifndef _OPCAO_HPP
#define _OPCAO_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <functional>

#include "Planejamento.hpp"
#include "Menu.hpp"

using namespace std;

class Menu; // Forward declaration

class Opcao {
private:
    string _descricao;
    function<void(Planejamento&)> _acao;
    Menu* _sub_menu = nullptr;

public:
    Opcao(string descricao, function<void(Planejamento&)> acao, Menu* sub_menu): _descricao(descricao), _acao(acao), _sub_menu(sub_menu){}

    string get_descricao() const { return _descricao;}
    Menu* get_sub_menu() const { return _sub_menu;}

    void executar(Planejamento& p){ _acao(p);}
};

#endif
