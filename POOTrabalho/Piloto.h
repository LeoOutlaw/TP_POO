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
    string  nome;
    bool carro;                         //se esta a conduzir algum carro ou nao
    char aux;
    //int tipo;                           //tipo de condutor
    int lembra_comecar;
public:
    Piloto( string nome);
    string getNome() const;
    ~Piloto();
};


#endif /* PILOTOS_H */

