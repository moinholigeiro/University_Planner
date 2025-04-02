#ifndef _DISCIPLINA_HPP
#define _DISCIPLINA_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

#include <unordered_map>

using namespace std;

class Disciplina{
private:

    string _codigo;
    string _nome = "";
    int _semestre = -1;
    int _prioridade = -1;

    vector<string> pre_requisito;
    vector<string> co_requisito;
    vector<string> requisitadas;

    void _calcula_semestre(unordered_map<string, Disciplina*>&);
    void _calcula_prioridade(unordered_map<string, Disciplina*>&);
public:

    Disciplina(string codigo, string nome);
    Disciplina(string codigo);

    void adiciona_nome(string nome);
    void adiciona_pre_requisito(string codigo);
    void adiciona_co_requisito(string codigo);
    void adiciona_requisitadas(string codigo);

    string get_codigo(){ return _codigo;}
    string get_nome(){ return _nome;}
    int get_semestre(){ return _semestre;}
    int get_prioridade(){ return _prioridade;}


    static void calcula_semestre(unordered_map<string, Disciplina*>&);
    static void calcula_prioridade(unordered_map<string, Disciplina*>&);

    friend ostream& operator<<(ostream& out, Disciplina& d);

    ~Disciplina(){}
};

#endif
