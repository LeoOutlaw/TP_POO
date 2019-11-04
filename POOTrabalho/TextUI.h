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

using namespace std;

class TextUI{
    DVG * dvg;
    int iter;
public:
    TextUI();
    
    void start();
    void imprimeNome();
    bool leComandos(string comando);
    vector<string> separaComando(string comando, char separador);
    string toLower(string str);
    bool comandoLoadPilotos(string ficheiro);
    bool comandoLoadCarros(string ficheiro);
    bool comandoRemoveCarro(string id);
};

#endif /* TEXTUI_H */

