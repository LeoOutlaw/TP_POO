/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DVG.h
 * Author: Leonardo
 *
 * Created on 3 de Novembro de 2019, 2:23
 */

#ifndef DVG_H
#define DVG_H

#include <vector>
#include "Piloto.h"
#include "Carro.h"


class DVG{
    vector <Piloto> pilotos;
    vector <Carro> carros;
public:
    DVG();
    bool removeCarro(char id);
    bool removePiloto(string nome);
    void addPiloto(Piloto piloto);
    void addCarro(Carro carro);
    void listarCarros();
    void listarPilotos();
    Carro* verSePilotoEstaAoVolante(string nome);
    bool encontraPiloto(string nome);
    bool encontraCarro(char id);
    Carro *buscaCarro( char id);
    Piloto *buscaPiloto (string nome);
    vector <Carro> * getVectorCarros();
    vector <Piloto> * getVectorPilotos();
    ~DVG();
};
#endif /* DVG_H */

