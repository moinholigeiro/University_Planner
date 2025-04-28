
#include <list>

#include "Planejamento.hpp"
#include "Menu.hpp"

void Planejamento::exemplo_de_formatacao(ostream& out){
    out << "Exemplo de formatação:" << endl;
    out << "COD00001 NOME DA DISCIPLINA 1" << endl;
    out << "\tCOD00002" << endl;
    out << "\tCOD00003" << endl;
    out << "\t-COD00004" << endl;
    out << "COD00002 NOME DA DISCIPLINA 2" << endl;
    out << "COD00003 NOME DA DISCIPLINA 3" << endl;
    out << "COD00005 NOME DA DISCIPLINA 5" << endl;
    out << "\t-COD00001" << endl;
    out << "\tCOD00006" << endl;
    out << "COD00004 NOME DA DISCIPLINA 4" << endl;
    out << "COD00006 NOME DA DISCIPLINA 6" << endl;
    out << endl;
    out << "Perceba que:" << endl;
    out << "\tO código da disciplina em questão é sempre a primeira \"palavra\" da linha, e não pode ter espaçamento. (Por exemplo, tem que ser \"COD12345\" e não \"COD 12345\")." << endl;
    out << "\tO nome da disciplina em questão é o restante da linha." << endl;
    out << "\tAs linhas que começam com um caractere em branco (espaço ou tab, por exemplo) e sem um '-' são pré-requisitos da disciplina em questão." << endl;
    out << "\tAs linhas que começam com um caractere em branco (espaço ou tab, por exemplo) e com um '-' são co-requisitos da disciplina em questão." << endl;
    out << endl;
    out << "Ou seja, nesse caso:" << endl;
    out << "\tA disciplina COD00001 tem como pré-requisitos as disciplinas COD00002 e COD00003 e como co-requisito a disciplina COD00004." << endl;
    out << "\tA disciplina COD00005 tem como pré-requisito a disciplina COD00006 e como co-requisito a disciplina COD00001." << endl;
    out << "\tNenhuma outra disciplina tem quaisquer pré-requisitos ou co-requisitos." << endl;
    out << endl;
}

// void Planejamento::_importa_equiv(string caminho){
//     ifstream input(caminho);
//     string linha;
//     string codigo = "";

//     if(input){
//         while(getline(input, linha)){
//             if(input.eof()) break;

//             Menu::trim_back(linha);
                
//             if(linha.empty()) continue;
        
//             if(linha[0] <= ' ' && codigo != ""){
//                 Menu::trim_front(linha);
    
//                 // _disciplinas[codigo]->adiciona_pre_requisito(linha);

//                 // if(!_disciplinas[linha]) _disciplinas[linha] = new Disciplina(linha);
//                 // _disciplinas[linha]->adiciona_requisitadas(codigo);
//             }

//             istringstream iss(linha);
//             iss >> codigo; // Evita problemas caso o usuário não deixe na formatação adequada (deixe o nome da disciplina junto)
//             Menu::uppercase(codigo); // Coloca o código todo em maiúsculo pra evitar duplicação de disciplinas
            
//             if(!_disciplinas[codigo])
//                 _disciplinas[codigo] = new Disciplina(codigo);
//             _disciplinas[codigo]->set_cursou(true);
//         }
//         input.close();
//     }
// }

void Planejamento::_importa_feitas(string caminho){
    ifstream input(caminho);
    string linha;
    string codigo;

    if(input){
        while(getline(input, linha)){
            if(input.eof()) break;

            Menu::trim_back(linha);
                
            if(linha.empty()) continue;

            if(linha.front() <= ' ') continue;

            istringstream iss(linha);
            iss >> codigo; // Evita problemas caso o usuário não deixe na formatação adequada (deixe o nome da disciplina junto)
            Menu::uppercase(codigo); // Coloca o código todo em maiúsculo pra evitar duplicação de disciplinas
            
            if(!_disciplinas[codigo])
                _disciplinas[codigo] = new Disciplina(codigo);
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
        throw runtime_error("Arquivo não existe: " + caminho);
    }

    while (getline(input, linha)) {
        if(input.eof()) break;

        Menu::trim_back(linha);
        
        if(linha.empty()) continue;
        
        if(linha[0] <= ' ' && _disciplinas[codigo]){
            Menu::trim_front(linha);

            if (linha[0] == '-') { // Aqui, a linha é de co-requisito da disciplina em questão
                linha.erase(0, 1); // Remove '-'
                Menu::trim_front(linha);

                _disciplinas[codigo]->adiciona_co_requisito(linha);
            } else { // Aqui, a linha é de pré-requisito da disciplina em questão
                _disciplinas[codigo]->adiciona_pre_requisito(linha);

                if(!_disciplinas[linha]) _disciplinas[linha] = new Disciplina(linha);
                _disciplinas[linha]->adiciona_requisitadas(codigo);
            }
        } else if(linha[0] <= ' ' && !_disciplinas[codigo]){
            cerr << "Erro!" << endl;
            throw runtime_error("Não foi possível identificar a disciplina pela qual \'" + linha + "\' seja pré ou co-requisito!");
        } else{ // Aqui, a linha é a da disciplina em questão
            istringstream iss(linha);
            iss >> codigo; // Primeiro token é o código
            Menu::trim(codigo);
            Menu::uppercase(codigo); // Coloca o código todo em maiúsculo pra evitar duplicação de disciplinas

            getline(iss, nome); // O restante é o nome
            Menu::trim(nome);
            
            if(_disciplinas[codigo])
                _disciplinas[codigo]->adiciona_nome(nome);
            else
                _disciplinas[codigo] = new Disciplina(codigo, nome);
        }
    }

    input.close();
}

Planejamento::Planejamento(string caminho_grade, string caminho_feitos){
    try{
        _importa_grade(caminho_grade);
        _importa_feitas(caminho_feitos);

        for (auto it = _disciplinas.begin(); it != _disciplinas.end(); it++)
            it->second->calcula_prioridade(_disciplinas);

        for (auto it = _disciplinas.begin(); it != _disciplinas.end(); it++)
            it->second->calcula_periodo(_disciplinas);
    } catch (const runtime_error& e) {
        for(auto it = _disciplinas.begin(); it != _disciplinas.end(); it++)
            delete it->second;
        throw runtime_error(string(e.what()));
    }
}

ostream& operator<<(ostream& out, Planejamento* p){
    list<Disciplina*> disciplinas_list;

    for(auto it = p->_disciplinas.begin(); it != p->_disciplinas.end(); it++)
        disciplinas_list.push_back(it->second);

    if(p->_modo_de_exportacao == p->Por_periodo){
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
    } else if(p->_modo_de_exportacao == p->Por_prioridade){
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
    } else if(p->_modo_de_exportacao == p->DEBUG){
        for(auto it = p->_disciplinas.begin(); it != p->_disciplinas.end(); it++)
            cout << *it->second;
    }

    return out;
}

Planejamento::~Planejamento(){
    for(auto it = _disciplinas.begin(); it != _disciplinas.end(); it++)
        delete it->second;
}
