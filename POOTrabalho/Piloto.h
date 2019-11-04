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
    string tipo;
    bool carro;                         //se esta a conduzir algum carro ou nao                 
    int lembra_comecar;
public:
    Piloto(string tipo ,string nome);
    string getNome() const;
    string getTipo() const;
    Piloto & operator=(const Piloto & piloto);
    void mostrarPiloto();
    ~Piloto();
};


#endif /* PILOTOS_H */
