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
}

void TextUI::start() {
    //    dvg.push_back(new DVG());
    iter = 0;
    string comando;
    imprimeNome();
    do {
        getline(cin, comando);
    } while (leComandos(this->toLower(comando)));
}

void TextUI::imprimeNome() {
    cout << "------------Simulador de Corridas------------" << endl;
}

bool TextUI::leComandos(string comando) {
    vector<string> stringSeparada;
    stringSeparada = separaComando(comando, ' ');
    if (stringSeparada[0] == "fim") {
        return false;
    } else if (stringSeparada[0] == "cria") {
        if (stringSeparada[1] == "c") {
            dvg->addCarro(stringSeparada[2]);
        } else if (stringSeparada[1] == "p") {
            if (stringSeparada[2] == "crazy" || stringSeparada[2] == "surpresa" || stringSeparada[2] == "rapido") {
                for (int i = 3; i < stringSeparada.size() - 1; i++) {
                    stringSeparada[3] += ' ';
                    stringSeparada[3] += stringSeparada[i + 1];
                }
                dvg->addPiloto(Piloto(stringSeparada[2], stringSeparada[3]));
            } else {
                cout << "Comando mal implementado -->EX: cria p tipo nome\n";
            }
        } else if (stringSeparada[1] == "a") {

        }
    } else if (stringSeparada[0] == "carregap") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadPilotos(stringSeparada[1])) {
                cout << "Ficheiro nao encontrado!\n";
            }
        } else {
            cout << "Numero de argumentos errado!\n       load -ficheiro.\n";
        }
    } else if (stringSeparada[0] == "carregac") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadCarros(stringSeparada[1])) {
                cout << "Ficheiro nao encontrado!\n";
            }
        } else {
            cout << "Numero de argumentos errado!\n       load -ficheiro.\n";
        }
    } else if (stringSeparada[0] == "carregaA") {

    } else if (stringSeparada[0] == "apaga") {
        if (stringSeparada[1] == "c") {
            if (stringSeparada[2].size() == 1) {
                comandoRemoveCarro(stringSeparada[2]);
            } else {
                //id demasiado grande
            }
        } else if (stringSeparada[1] == "p") {

        } else if (stringSeparada[1] == "a") {

        } else {
            cout << "Comando mal escrito!\n";
        }
    } else if (stringSeparada[0] == "entranocarro") {
        if (dvg->encontraCarro(stringSeparada[1][0])) {
            for (int i = 2; i < stringSeparada.size() - 1; i++) {
                stringSeparada[2] += ' ';
                stringSeparada[2] += stringSeparada[i + 1];
            }
            if (dvg->encontraPiloto(stringSeparada[2])) {
                dvg->buscaCarro(stringSeparada[1][0])->setPiloto(dvg->buscaPiloto(stringSeparada[2]));
                dvg->buscaCarro(stringSeparada[1][0])->getPiloto()->mostrarPiloto();
            } else {
                cout << "Piloto nao existe!\n";
            }
        } else {
            cout << "Carro nao existe!\n";
        }
    } else if (stringSeparada[0] == "saidocarro") {
        if (dvg->encontraCarro(stringSeparada[1][0])) {
            if (dvg->buscaCarro(stringSeparada[1][0])->getPiloto()!= NULL) {
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

    }
}

bool TextUI::comandoRemoveCarro(string id) {
    dvg->removeCarro(id[0]);
}

bool TextUI::comandoLoadPilotos(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        if (stringSeparada.size() > 2) {
            for (int i = 1; i < stringSeparada.size() - 1; i++) {
                stringSeparada[1] += ' ';
                stringSeparada[1] += stringSeparada[i + 1];
            }
        }
        dvg->addPiloto(Piloto(stringSeparada[0], stringSeparada[1]));
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
        dvg->addCarro(Carro(stringSeparada[2], stringSeparada[3], atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str())));
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

string TextUI::toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}