#ifndef _EXCECAO_HPP
#define _EXCECAO_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <exception>

using namespace std;

class Excecao : public exception{
private:
    string mensagem;

public:
    explicit Excecao(const string& msg) : mensagem(msg) {}

    const char* what() const noexcept override { return mensagem.c_str();}
};

#endif
