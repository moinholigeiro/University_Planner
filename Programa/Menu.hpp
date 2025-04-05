#ifndef _MENU_HPP
#define _MENU_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <functional>

#include <unordered_map>

using namespace std;

class Menu{
private:

    class Opcao{
    public:
        string descricao;
        void (*procedimento)(void*);
    };

    string titulo;
    vector<Opcao> opcoes;

public:


};

#endif
