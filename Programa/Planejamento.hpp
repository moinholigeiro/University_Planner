#ifndef _PLANEJAMENTO_HPP
#define _PLANEJAMENTO_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <unordered_map>

#include "Excecao.hpp"
#include "Disciplina.hpp"

using namespace std;

class Planejamento{
private:

    unordered_map<string, Disciplina*> _disciplinas;
    int _modo_de_exportacao = Planejamento::Por_periodo;

    void _importa_feitas(string caminho);
    void _importa_grade(string caminho);

public:

    enum MODO_DE_EXPORTAR {
        Por_periodo,
        Por_prioridade,
        DEBUG
    };

    Planejamento(string caminho_grade, string caminho_feitos);

    void set_modo_de_exportacao(MODO_DE_EXPORTAR modo){ _modo_de_exportacao = modo;}

    friend ostream& operator<<(ostream& out, Planejamento& p);

    ~Planejamento();
};

#endif
