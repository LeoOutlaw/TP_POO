/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carro.h
 * Author: Leonardo
 *
 * Created on 3 de Novembro de 2019, 2:27
 */

#ifndef CARRO_H
#define CARRO_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "Piloto.h"

using namespace std;

class Carro {
    //Piloto piloto;
    string marca;
    string modelo;
    char id;
    int cap_min;
    int cap_max;
    int num_carga;
    int velocidade;
    bool estado;
    bool sinal_emergencia;
    static char letra;
public:
    Carro(string marca, int cap_min = 0, int cap_max = 100);
    Carro(string marca, string modelo, int cap_min = 0, int cap_max = 100);
    string getMarca() const;
    string getModelo() const;
    char getID() const;
    int getVelocidade();
    void setVelocidade(int velocidade);
    ~Carro();
};

#endif /* CARRO_H */

