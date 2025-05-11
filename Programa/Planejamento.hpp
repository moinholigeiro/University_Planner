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
#include <unordered_set>

#include "Excecao.hpp"
#include "Disciplina.hpp"

#include "Equivalencia.hpp"

using namespace std;

class Planejamento{
private:

    // unordered_map<vector<string>*, vector<vector<string>>> _equivalencias; // vector<string> é o conjunto de disciplinas, que em geral vai ter o código de apenas uma disciplina
    unordered_map<string, Disciplina*> _disciplinas;
    int _modo_de_exportacao = Planejamento::Por_periodo;

    void _importa_equiv(string caminho);
    void _importa_feitas(string caminho);
    void _importa_grade(string caminho);

public:

    enum MODO_DE_EXPORTAR {
        Por_periodo,
        Por_prioridade,
        DEBUG
    };

    // Planejamento() = default;
    Planejamento(string caminho_grade, string caminho_feitos, string caminho_equiv);

    static void exemplo_de_formatacao(ostream& out);

    void set_modo_de_exportacao(MODO_DE_EXPORTAR modo){ _modo_de_exportacao = modo;}

    friend ostream& operator<<(ostream& out, Planejamento* p);

    ~Planejamento();
};

#endif
