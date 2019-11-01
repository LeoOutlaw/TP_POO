/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leonardo
 *
 * Created on 28 de Outubro de 2019, 16:56
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*class Piloto{
    string nome;
    static int random;
 * 
 * 
 * 
public:
    Piloto(string * nome);
};

Piloto::Piloto(string * nome){
    this->nome = nome;
}

class People{
    Piloto * pilotos[5];
public:
    People(Piloto * piloto){
        
    }
};
 */

int main(int argc, char** argv) {
    //Piloto a("Leonardo");
    //People(&a);
    vector <string> leo;
    string a = "Leonardo Rocha";
    string c = "Pedro Reis";
    cout << a << endl;
    char b = '0';
    cout << b << endl;
    a += b;
    cout << a << endl;
    leo.push_back(a);
    leo.push_back(a);
    cout << "LEonardo";
    leo.pop_back();
    leo.push_back(c);
    for(int i=0; i< leo.size() ; i++){
        cout << leo[i];
    }
    return 0;
}

