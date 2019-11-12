/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextUI.cpp
 * Author: Leonardo
 *
 * Created on 3 de Novembro de 2019, 1:20
 */

#include "TextUI.h"

TextUI::TextUI() {
    dvg = new DVG();
    camp = new Campeonato();
}

void TextUI::start() {
    //    dvg.push_back(new DVG());
    iter = 0;
    string comando;
    imprimeNome();
    do {
        getline(cin, comando);
    } while (leComandos(this->toLower(comando)));
    system("clear");
    cout << "------------Entrou no modo 2-----------------\n";
    do {
        getline(cin, comando);
    } while (leComandosModo2(this->toLower(comando)));
}

void TextUI::imprimeNome() {
    cout << "------------Simulador de Corridas------------" << endl;
}

bool TextUI::leComandos(string comando) {
    vector<string> stringSeparada;
    string aux;
    stringSeparada = separaComando(comando, ' ');
    if (stringSeparada[0] == "fim") {
        if (dvg->getVectorCarros()->size() != 0) {
            if (dvg->getVectorPilotos()->size() != 0) {
                if (camp->getTodasAsPistas()->size() != 0) {
                    return false;
                }
            }
        }
        if (dvg->getVectorCarros()->size() == 0) {
            cout << "Nao existe carros\n";
        }
        if (dvg->getVectorPilotos()->size() == 0) {
            cout << "Nao existe pilotos\n";
        }
        if (camp->getTodasAsPistas()->size() == 0) {
            cout << "Nao existem autodromos\n";
        }
    } else if (stringSeparada[0] == "cria") {
        if (stringSeparada[1] == "c") {
            if (stringSeparada.size() == 5) {
                dvg->addCarro(Carro(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), atoi(stringSeparada[4].c_str()), stringSeparada[4]));
            } else if (stringSeparada.size() == 6) {
                dvg->addCarro(Carro(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), atoi(stringSeparada[4].c_str()), stringSeparada[5], stringSeparada[6]));
            } else {
                cout << "Comando mal implementado -->EX: cria c <cap_min> <cap_max> <marca> <modelo>\n";
            }
        } else if (stringSeparada[1] == "p") {
            if (stringSeparada[2] == "crazy" || stringSeparada[2] == "surpresa" || stringSeparada[2] == "rapido") {
                aux = juntarNome(stringSeparada, 3);
                dvg->addPiloto(Piloto(stringSeparada[2], aux));
            } else {
                cout << "Comando mal implementado -->EX: cria p tipo nome\n";
            }
        } else if (stringSeparada[1] == "a") {
            if (stringSeparada.size() == 5) {
                camp->addAutodromo(Autodromo(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), stringSeparada[4]));
            } else {
                cout << "Comando mal implementado -->EX: cria a <pistas> <comprimento> <nome>\n";
            }
        }
    } else if (stringSeparada[0] == "carregap") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadPilotos(stringSeparada[1])) {
                cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
            }
        } else {
            cout << "Numero de argumentos errado!\n";
        }
    } else if (stringSeparada[0] == "carregac") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadCarros(stringSeparada[1])) {
                cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
            }
        } else {
            cout << "Numero de argumentos errado!\n";
        }
    } else if (stringSeparada[0] == "carregaa") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadAutodromos(stringSeparada[1])) {
                cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
            }
        } else {
            cout << "Numero de argumentos errado!\n";
        }
    } else if (stringSeparada[0] == "apaga") {
        if (stringSeparada[1] == "c") {
            if (stringSeparada[2].size() == 1) {
                if (comandoRemoveCarro(stringSeparada[2])) {
                    cout << "Carro " << stringSeparada[2] << " eliminado!\n";
                } else {
                    cout << "Carro nao existe!\n";
                }
            } else {
                cout << "Id demasiado grande!\n";
            }
        } else if (stringSeparada[1] == "p") {
            aux = juntarNome(stringSeparada, 2);
            if (comandoRemovePiloto(aux)) {
                cout << "Piloto " << aux << " eliminado!\n";
            } else {
                cout << "Piloto " << aux << " nao existe!\n";
            }
        } else if (stringSeparada[1] == "a") {
            if (comandoRemoveAutodromo(stringSeparada[2])) {
                cout << "Autodromo " << stringSeparada[2] << " eliminado!\n";
            } else {
                cout << "Autodromo " << stringSeparada[2] << " nao existe!\n";
            }
        } else {
            cout << "Comando mal escrito!\n";
        }
    } else if (stringSeparada[0] == "entranocarro") {
        if (stringSeparada.size() > 2) {
            int aux;
            aux = comandoEntraNoCarro(stringSeparada);
            switch (aux) {
                case -1:
                    cout << "Piloto nao existe!\n";
                    break;
                case 0:
                    cout << "Carro nao existe!\n";
                    break;
                case 1:
                    cout << "Piloto entrou no carro com sucesso!\n";
            }
        } else {
            cout << "Comando mal escrito! entranocarro <idCarro> <nomePiloto>\n";
        }
    } else if (stringSeparada[0] == "saidocarro") {
        if (dvg->encontraCarro(stringSeparada[1][0])) {
            if (dvg->buscaCarro(stringSeparada[1][0])->getPiloto() != NULL) {
                dvg->buscaCarro(stringSeparada[1][0])->setPiloto(NULL);
            } else {
                cout << "Carro encontra ja se sem piloto!\n";
            }
        } else {
            cout << "Carro nao existe!\n";
        }
    } else if (stringSeparada[0] == "lista") {
        dvg->listarPilotos();
        cout << "---------------------------\n";
        dvg->listarCarros();
    } else if (stringSeparada[0] == "savedgv") {

    } else if (stringSeparada[0] == "loaddvg") {

    } else if (stringSeparada[0] == "deldvg") {

    }else{
        cout << "Este comando nao existe!\n";
    }
}


bool TextUI::leComandosModo2(string comando){
    vector<string> stringSeparada;
    string aux;
    stringSeparada = separaComando(comando, ' ');
    if (stringSeparada[0] == "fim"){
        return false;
    }
}

int TextUI::comandoEntraNoCarro(vector<string> comando) {
    string aux;
    if (dvg->encontraCarro(comando[1][0])) {
        aux = juntarNome(comando, 2);
        if (dvg->encontraPiloto(aux)) {
            dvg->buscaCarro(comando[1][0])->setPiloto(dvg->buscaPiloto(aux));
        } else {
            return -1;
        }
    } else {
        return 0;
    }
    return 1;
}

bool TextUI::comandoRemoveCarro(string id) {
    if (!dvg->removeCarro(id[0])) {
        return false;
    }
    return true;
}

bool TextUI::comandoRemovePiloto(string nome) {
    Carro * c = dvg->verSePilotoEstaAoVolante(nome);
    c->setPiloto(NULL);
    if (!dvg->removePiloto(nome)) {
        return false;
    }
    return true;
}

bool TextUI::comandoRemoveAutodromo(string nome) {
    if (!camp->removeAutodromo(nome)) {
        return false;
    }
    return true;
}

bool TextUI::comandoLoadPilotos(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    string aux;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        if (stringSeparada.size() > 2) {
            aux = juntarNome(stringSeparada, 1);
        }
        dvg->addPiloto(Piloto(stringSeparada[0], this->toLower(aux)));
    }
    dados.close();
    return true;
}

bool TextUI::comandoLoadCarros(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        dvg->addCarro(Carro(atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str()), atoi(stringSeparada[2].c_str()), stringSeparada[3], stringSeparada[4]));
    }
    dados.close();
    return true;
}

bool TextUI::comandoLoadAutodromos(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        camp->addAutodromo(Autodromo(atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str()), stringSeparada[2]));
    }
    dados.close();
    return true;
}

vector<string> TextUI::separaComando(string comando, char separador) {
    vector<string> stringSeparada;
    stringstream ss;
    ss.str(comando);
    string token;
    while (getline(ss, token, separador)) {
        if (!token.empty()) {
            stringSeparada.push_back(token);
        }
    }
    return stringSeparada;
}

string TextUI::juntarNome(vector<string> nome, int num) {
    for (int i = num; i < nome.size() - 1; i++) {
        nome[num] += ' ';
        nome[num] += nome[i + 1];
    }
    return nome[num];
}

string TextUI::toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

TextUI::~TextUI() {

}