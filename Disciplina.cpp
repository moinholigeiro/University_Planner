#include "Disciplina.hpp"

// string _codigo;
// string _nome = "";
// int _semestre = -1;
// int _prioridade = -1;
// bool ja_cursou = false;

// vector<string> pre_requisito;
// vector<string> co_requisito;
// vector<string> requisitadas;

Disciplina::Disciplina(string codigo, string nome) : _codigo(codigo), _nome(nome){}

Disciplina::Disciplina(string codigo) : _codigo(codigo){}

bool Disciplina::compara_semestre(const Disciplina* d1, const Disciplina* d2) {
    if (d1->_semestre == d2->_semestre)
        return d1->_codigo < d2->_codigo;
    return d1->_semestre < d2->_semestre;
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

void Disciplina::_calcula_semestre(unordered_map<string, Disciplina*>& disc){
    _semestre = 0;

    for(string codigo : pre_requisito){
        if(disc[codigo]->_semestre < 0)
            disc[codigo]->_calcula_semestre(disc);

        if(disc[codigo]->_ja_cursou);
        else if(_semestre <= disc[codigo]->_semestre)
            _semestre = disc[codigo]->_semestre + 1;
    }

    for(string codigo : co_requisito){
        if(disc[codigo]->_semestre < 0)
            disc[codigo]->_calcula_semestre(disc);

        if(disc[codigo]->_ja_cursou);
        else if(_semestre < disc[codigo]->_semestre)
            _semestre = disc[codigo]->_semestre;
    }
}

void Disciplina::_calcula_prioridade(unordered_map<string, Disciplina*>& disc){
    _prioridade = 0;

    for(string codigo : requisitadas){
        if(disc[codigo]->_prioridade < 0)
            disc[codigo]->_calcula_prioridade(disc);

        if(disc[codigo]->_ja_cursou);
        else if(_prioridade <= disc[codigo]->_prioridade)
            _prioridade = disc[codigo]->_prioridade + 1;
    }
}

void Disciplina::calcula_semestre(unordered_map<string, Disciplina*>& disc){
    for (auto it = disc.begin(); it != disc.end(); ++it)
        it->second->_calcula_semestre(disc);
}

void Disciplina::calcula_prioridade(unordered_map<string, Disciplina*>& disc){
    for (auto it = disc.begin(); it != disc.end(); ++it)
        it->second->_calcula_prioridade(disc);
}

ostream& operator<<(ostream& out, Disciplina& d){
    out << d._codigo << " " << d._nome << endl;

    for(string codigo : d.pre_requisito)
        out << '\t' << codigo << endl;
    for(string codigo : d.co_requisito)
        out << '\t' << '-' << codigo << endl;

    return out;
}

// ostream& operator<<(ostream& out, Disciplina& d){
//     out << d._codigo << " " << d._nome << endl;

//     if(!d.pre_requisito.empty()){
//         out << '\t' << "Pré-requisitos:" << endl;
//         for(string codigo : d.pre_requisito)
//             out << '\t' << '\t' << codigo << endl;
//     }
//     if(!d.co_requisito.empty()){
//         out << '\t' << "Co-requisitos:" << endl;
//         for(string codigo : d.co_requisito)
//             out << '\t' << '\t' << codigo << endl;
//     }
//     return out;
// }
