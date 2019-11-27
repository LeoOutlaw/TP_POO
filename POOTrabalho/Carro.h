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
    Piloto * piloto;
    string marca;
    string modelo;
    char id;
    int pos;
    int pos_x;
    int cap_min;
    int cap_max;
    int num_carga;
    int velocidade;
    int velocidade_max;  // velocidade maxima do carro
    bool trava;
    bool acelera;
    //int trata_carro;  // Saber o que o piloto esta a fazer, se esta a acelarar travar ou nem um nem outro
    bool sinal_emergencia;
    bool ocupado;
    static char letra;
public:
    Carro(int velocidade, int cap_min, int cap_max, string marca, string modelo = "modelo base");
    string getMarca() const;
    string getModelo() const;
    bool getOcupado();
    void setOcupado(bool ocupado);
    char getID() const;
    bool getAcelera();
    bool getTrava();
    int getPosicao();
    int getPosicao_x();
    void setPosicao(int pos);
    Piloto * getPiloto();
    int getVelocidade();
    void setVelocidade(int velocidade);
    void mostrarCarro();
    void setPiloto(Piloto *piloto);
    Carro & operator =(Carro *c);
    ~Carro();
};

#endif /* CARRO_H */

