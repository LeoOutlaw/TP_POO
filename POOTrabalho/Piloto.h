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
#include <stdlib.h>
#include <string>
#include <ctime>

using namespace std;

class Piloto {
    string nome;
    bool carro; //se esta a conduzir algum carro ou nao                 
    int pontos;
protected:
    string tipo;
    int comeca_corrida;
    bool acelera;
    bool trava;
public:
    Piloto(string tipo, string nome);
    string getNome() const;
    virtual string getTipo() const;
    virtual bool caracteristicaPiloto(int segundo) const = 0;
    virtual int getComecaCorrida() const = 0;
    int getPontos();
    void setPontos(int pontos);
    bool getCarro();
    void setCarro(bool val);
    bool getAcelera() const;
    bool getTrava() const;
    void setAcelera(bool acelera);
    void setTrava(bool trava);
    Piloto(const Piloto & piloto);
    Piloto& operator=(Piloto *p);
    void mostrarPiloto();

    virtual ~Piloto();
};


#endif /* PILOTOS_H */

