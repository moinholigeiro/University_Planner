
#include "Disciplina.hpp"

// string _codigo;
// string _nome;

// vector<Disciplina&> pre_requisito;
// vector<Disciplina&> co_requisito;

Disciplina::Disciplina(string codigo) : _codigo(codigo){}

void Disciplina::adiciona_nome(string nome){
    _nome = nome;
}
void Disciplina::adiciona_pre_requisito(Disciplina& r){
    pre_requisito.push_back(r);
}
void Disciplina::adiciona_co_requisito(Disciplina& r){
    co_requisito.push_back(r);
}

ostream& operator<<(ostream& out, Disciplina& d){
    out << d._codigo << " " << d._nome << endl;

    if(!d.pre_requisito.empty()){
        out << '\t' << "Pré-requisitos:" << endl;
        for(Disciplina& r : d.pre_requisito){
            out << '\t' << '\t' << r._codigo;
        // for(int i = 0 ; i <  ; i++){

        }
    }
    return out;
}
