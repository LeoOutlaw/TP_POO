/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilotos.h
 * Author: Leonardo
 *
 * Created on 31 de Outubro de 2019, 16:28
 */

#ifndef PILOTOS_H
#define PILOTOS_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Piloto{
    string const nome;
    bool carro;                         //se esta a conduzir algum carro ou nao
    char aux;
    int tipo;                           //tipo de condutor
    int lembra_comecar;
public:
    Piloto(int tipo, string const *nome, int lembra){
        this->nome = nome;
        this->tipo= tipo;
        carro = false;
        aux = '0';
        this->lembra_comecar = 0;
    }
};


#endif /* PILOTOS_H */

