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
#include <iostream>
#include <iomanip>
#include"Piloto.h"

using namespace std;

class Carro {
    Piloto * piloto;
    string marca;
    string modelo;
    char id;
    int pos;
    int pos_corrida;
    double cap_inicial;
    int cap_max;
    int nr_volta;
    double cap_actual;  // numero actual da carga
    int velocidade;
    int velocidade_max; // velocidade maxima do carro
    //int trata_carro;  // Saber o que o piloto esta a fazer, se esta a acelarar travar ou nem um nem outro
    bool sinal_emergencia;
    bool danificado;
    bool ocupado;
    static char letra;
public:
    Carro(int velocidade, double cap_min, int cap_max, string marca, string modelo = "modelo base");
    Carro(int velocidade, double cap_min, int cap_max, string marca, int id, Piloto * piloto, string modelo = "modelo base");
    void defaultCarro();
    string getMarca() const;
    string getModelo() const;
    double getCapActual();
    void setCapActual(double cap_actual);
    double getCapInicial();
    int getCapMax();
    bool getOcupado();
    void setOcupado(bool ocupado);
    char getID() const;
    int getPosicao();
    void setPosicao(int pos);
    int getPosicaoCorrida();
    void setPosicaoCorrida(int pos);
    int getVolta() const;
    void setVolta(int i);
    Piloto * getPiloto();
    int getVelocidade();
    void setVelocidade(int velocidade);
    int getVelociadeMax();
    void mostrarCarro();
    void mostraCarroEmCorrida();
    void setPiloto(Piloto *piloto);
    
    bool getSinalEmergencia();
    void setSinalEmergencia(bool sinal);
    bool getDanificado();
    void setDanificado(bool danificado);
    Carro & operator=(Carro *c);
    ~Carro();
};

#endif /* CARRO_H */

