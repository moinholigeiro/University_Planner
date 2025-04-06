
#include <list>

#include "Planejamento.hpp"

void Planejamento::_importa_feitas(string caminho){
    ifstream input(caminho);
    string linha;
    string codigo;

    if(input){
        while(getline(input, linha)){
            if(linha.empty()) break;

            while(linha.back() <= ' ') linha.pop_back(); // Especialmente útil para formatação vinda de Windows ou entradas com caracteres em branco no final da linha
            if(linha.front() <= ' ') continue;

            istringstream iss(linha);
            iss >> codigo; // Evita problemas caso o usuário não deixe na formatação adequada (deixe o nome da disciplina junto)
            if(!_disciplinas[codigo]) _disciplinas[codigo] = new Disciplina(codigo);
            _disciplinas[codigo]->set_cursou(true);
        }
        input.close();
    }
}

void Planejamento::_importa_grade(string caminho){
    ifstream input(caminho);
    string linha;
    string codigo, nome;

    if(!input){
        cerr << "Arquivo \'" << caminho << "\' não encontrado!" << endl;
    }

    while (getline(input, linha)) {
        if(linha.empty()) break;

        while(linha.back() <= ' ') linha.pop_back(); // Especialmente útil para formatação vinda de Windows ou entradas com caracteres em branco no final da linha

        if (linha[0] == '\t' && _disciplinas[codigo]) {
            linha.erase(0, 1); // Remove '\t'

            if (linha[0] == '-') { // Aqui, a linha é de co-requisito da disciplina em questão
                linha.erase(0, 1); // Remove '-'

                _disciplinas[codigo]->adiciona_co_requisito(linha);
            } else { // Aqui, a linha é de pré-requisito da disciplina em questão
                _disciplinas[codigo]->adiciona_pre_requisito(linha);

                if(!_disciplinas[linha]) _disciplinas[linha] = new Disciplina(linha);
                _disciplinas[linha]->adiciona_requisitadas(codigo);
            }
        } else if (linha[0] == '\t' && !_disciplinas[codigo]) {
            if (linha[0] == '-') {
                linha.erase(0, 1); // Remove '-'
                cout << "Erro! não foi possível identificar a disciplina pela qual \'" << linha << "\' seja co-requisito!" << endl;
            } else {
                cout << "Erro! não foi possível identificar a disciplina pela qual \'" << linha << "\' seja pré-requisito!" << endl;
            }
        } else { // Aqui, a linha é a da disciplina em questão
            istringstream iss(linha);
            iss >> codigo; // Primeiro token é o código
            getline(iss, nome); // O restante é o nome

            if (!nome.empty() && nome[0] == ' ')
                nome.erase(0, 1);
            
            if(_disciplinas[codigo])
                _disciplinas[codigo]->adiciona_nome(nome);
            else
                _disciplinas[codigo] = new Disciplina(codigo, nome);
        }
    }

    input.close();
}

Planejamento::Planejamento(string caminho_grade, string caminho_feitos){
    _importa_feitas(caminho_feitos);
    _importa_grade(caminho_grade);

    for (auto it = _disciplinas.begin(); it != _disciplinas.end(); it++)
        it->second->calcula_prioridade(_disciplinas);

    for (auto it = _disciplinas.begin(); it != _disciplinas.end(); it++)
        it->second->calcula_periodo(_disciplinas);
}

ostream& operator<<(ostream& out, Planejamento& p){
    list<Disciplina*> disciplinas_list;

    for(auto it = p._disciplinas.begin(); it != p._disciplinas.end(); it++)
        disciplinas_list.push_back(it->second);

    if(p._modo_de_exportacao == p.Por_periodo){
        disciplinas_list.sort(Disciplina::compara_periodo);

        for(int i=0;!disciplinas_list.empty();i++){
            out << "Período " << i + 1 << ":" << endl;
            while(!disciplinas_list.empty() && disciplinas_list.front()->get_periodo() == i){
                if(!disciplinas_list.front()->ja_cursou())
                    out << disciplinas_list.front()->get_codigo() << " " << disciplinas_list.front()->get_nome() << " (Prioridade " << disciplinas_list.front()->get_prioridade() << ")" << endl;
                disciplinas_list.pop_front();
            }
            out << endl;
        }
    } else if(p._modo_de_exportacao == p.Por_prioridade){
        disciplinas_list.sort(Disciplina::compara_prioridade);

        for(int i=disciplinas_list.back()->get_prioridade();!disciplinas_list.empty() && i >= -1;i--){
            out << "Prioridade " << i << ":" << endl;
            while(!disciplinas_list.empty() && disciplinas_list.back()->get_prioridade() == i){
                if(!disciplinas_list.back()->ja_cursou())
                    out << disciplinas_list.back()->get_codigo() << " " << disciplinas_list.back()->get_nome() << " (Período " << (disciplinas_list.back()->get_periodo() + 1) << ")" << endl;
                disciplinas_list.pop_back();
            }
            out << endl;
        }
    } else if(p._modo_de_exportacao == p.DEBUG){
        for(auto it = p._disciplinas.begin(); it != p._disciplinas.end(); it++)
            cout << *it->second;
    }

    return out;
}

Planejamento::~Planejamento(){
    for(auto it = _disciplinas.begin(); it != _disciplinas.end(); it++)
        delete it->second;
}
