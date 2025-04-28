#ifndef _DISCIPLINA_HPP
#define _DISCIPLINA_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <unordered_map>

using namespace std;

class Disciplina{
private:

    string _codigo;
    string _nome = "";
    int _periodo = -1;
    int _prioridade = -1;
    bool _ja_cursou = false;

    // vector<vector<string>> equivalencia;
    vector<string> pre_requisito;
    vector<string> co_requisito;
    vector<string> requisitadas;
public:

    Disciplina(string codigo, string nome);
    Disciplina(string codigo);

    void calcula_periodo(unordered_map<string, Disciplina*>&);
    void calcula_prioridade(unordered_map<string, Disciplina*>&);

    static bool compara_periodo(const Disciplina* d1, const Disciplina* d2);
    static bool compara_prioridade(const Disciplina* d1, const Disciplina* d2);

    void adiciona_nome(string nome);
    void adiciona_pre_requisito(string codigo);
    void adiciona_co_requisito(string codigo);
    void adiciona_requisitadas(string codigo);

    void set_cursou(bool cursou){ _ja_cursou = cursou;}
    
    bool ja_cursou(){ return _ja_cursou;}

    string get_codigo(){ return _codigo;}
    string get_nome(){ return _nome;}
    int get_periodo(){ return _periodo;}
    int get_prioridade(){ return _prioridade;}

    friend ostream& operator<<(ostream& out, Disciplina& d);

    ~Disciplina(){}
};

#endif
