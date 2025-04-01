#ifndef _DISCIPLINA_HPP
#define _DISCIPLINA_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Disciplina{
private:

    string _codigo;
    string _nome = "";

    vector<Disciplina&> pre_requisito;
    vector<Disciplina&> co_requisito;

public:

    Disciplina(string codigo);

    void adiciona_nome(string nome);
    void adiciona_pre_requisito(Disciplina&);
    void adiciona_co_requisito(Disciplina&);

    // static 

    friend ostream& operator<<(ostream& out, Disciplina& d);

    ~Disciplina(){};
};

#endif
