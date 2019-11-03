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

TextUI::TextUI(){
    //gameData= new GameData();
}

void TextUI::start(){
//    dvg.push_back(new DVG());
    iter = 0;
    string comando;
    imprimeNome();
    do{
        getline(cin,comando);
    }while(leComandos(this->toLower(comando)));
}

void TextUI::imprimeNome(){
    cout << "------------Simulador de Corridas------------" << endl;
}

bool TextUI::leComandos(string comando){
    vector<string> stringSeparada;
    stringSeparada = separaComando(comando, ' ');
    if(stringSeparada[0] == "fim"){
        return false;
    }else if(stringSeparada[0] == "cria"){
        
    }else if(stringSeparada[0] == "carregaP"){
        
    }else if(stringSeparada[0] == "carregaC"){
        
    }else if(stringSeparada[0] == "carregaA"){
        
    }else if(stringSeparada[0] == "apaga"){
        
    }else if(stringSeparada[0] == "entranocarro"){
        
    }else if(stringSeparada[0] == "saidocarro"){
        
    }else if(stringSeparada[0] == "lista"){
        
    }else if(stringSeparada[0] == "savedgv"){
        
    }else if(stringSeparada[0] == "loaddvg"){
        
    }else if(stringSeparada[0] == "deldvg"){
        
    }
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