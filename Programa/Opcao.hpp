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

using namespace std;

class Opcao {
private:
    string _descricao;
    function<void()> _acao;

public:
    Opcao(){};
};

#endif
