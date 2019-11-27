/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextUI.h
 * Author: Leonardo
 *
 * Created on 3 de Novembro de 2019, 1:04
 */

#ifndef TEXTUI_H
#define TEXTUI_H

#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "DVG.h"
#include "Campeonato.h"
#include "Consola.h"

using namespace std;

class TextUI {
    DVG * dvg;
    Campeonato * camp;
    int iter;
public:
    TextUI();

    bool start();
    void imprimeNome();
    bool leComandos(string comando);
    bool leComandosModo2(string comando);
    vector<string> separaComando(string comando, char separador);
    bool comandoLoadPilotos(string ficheiro);
    bool comandoLoadCarros(string ficheiro);
    bool comandoLoadAutodromos(string ficheiro);
    bool comandoRemoveCarro(string id);
    bool comandoRemovePiloto(string nome);
    bool comandoRemoveAutodromo(string nome);
    int comandoEntraNoCarro(vector <string> comando);
    bool comandoCampeonato(vector<string> comando);
    void comandoPassaTempo(int passa);
    string juntarNome(vector<string> nome, int num);
    bool iniciaModo2();
    bool mostra_janela_passatempo(int num);
    void mostra_janela_inicial();
    string toLower(string str);
    string toUpper(string str);
    void imprimeLog(string msg);
    void imprimeErro(string msg);
    ~TextUI();
};

#endif /* TEXTUI_H */

