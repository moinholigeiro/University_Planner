#include "Disciplina.hpp"

// string _codigo;
// string _nome = "";
// int _periodo = -1;
// int _prioridade = -1;
// bool ja_cursou = false;

// vector<string> pre_requisito;
// vector<string> co_requisito;
// vector<string> requisitadas;

Disciplina::Disciplina(string codigo, string nome) : _codigo(codigo), _nome(nome){}

Disciplina::Disciplina(string codigo) : _codigo(codigo){}

bool Disciplina::compara_periodo(const Disciplina* d1, const Disciplina* d2) {
    if (d1->_periodo == d2->_periodo)
        return d1->_codigo < d2->_codigo;
    return d1->_periodo < d2->_periodo;
}

bool Disciplina::compara_prioridade(const Disciplina* d1, const Disciplina* d2) {
    if (d1->_prioridade == d2->_prioridade)
        return d1->_codigo < d2->_codigo;
    return d1->_prioridade < d2->_prioridade;
}

void Disciplina::adiciona_nome(string nome){
    _nome = nome;
}

void Disciplina::adiciona_requisitadas(string codigo){
    requisitadas.push_back(codigo);
}

void Disciplina::adiciona_pre_requisito(string codigo){
    pre_requisito.push_back(codigo);
}
void Disciplina::adiciona_co_requisito(string codigo){
    co_requisito.push_back(codigo);
}

void Disciplina::calcula_periodo(unordered_map<string, Disciplina*>& disc){
    _periodo = 0;

    for(string codigo : pre_requisito){
        if(disc[codigo]->_periodo < 0)
            disc[codigo]->calcula_periodo(disc);

        if(disc[codigo]->_ja_cursou); // Se ja cursou, ignora
        else if(_periodo <= disc[codigo]->_periodo)
            _periodo = disc[codigo]->_periodo + 1;
    }

    for(string codigo : co_requisito){
        if(disc[codigo]->_periodo < 0)
            disc[codigo]->calcula_periodo(disc);

        if(disc[codigo]->_ja_cursou); // Se ja cursou, ignora
        else if(_periodo < disc[codigo]->_periodo)
            _periodo = disc[codigo]->_periodo;
    }
}

void Disciplina::calcula_prioridade(unordered_map<string, Disciplina*>& disc){
    _prioridade = 0;

    for(string codigo : requisitadas){
        if(disc[codigo]->_prioridade < 0)
            disc[codigo]->calcula_prioridade(disc);

        if(disc[codigo]->_ja_cursou); // Se ja cursou, ignora
        else if(_prioridade <= disc[codigo]->_prioridade)
            _prioridade = disc[codigo]->_prioridade + 1;
    }
}

ostream& operator<<(ostream& out, Disciplina& d){
    out << d._codigo << " " << d._nome << endl;

    for(string codigo : d.pre_requisito)
        out << '\t' << codigo << endl;
    for(string codigo : d.co_requisito)
        out << '\t' << '-' << codigo << endl;

    return out;
}
