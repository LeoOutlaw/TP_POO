/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autodromo.h
 * Author: Leonardo
 *
 * Created on 3 de Novembro de 2019, 15:01
 */

#ifndef AUTODROMO_H
#define AUTODROMO_H
#include <iostream>
#include <iomanip>
#include "DGV.h"

class Autodromo{
    string nome;
    int pistas;
    int comprimento;
    int segundo_actual;
    vector <Carro*> classificacao;
    vector <Carro*> corrida;
    vector <Carro*> garagem;
public:
    Autodromo(int pistas, int comprimento, string nome);
    void addCarroCorrida(Carro *carro);
    void addCarroGaragem(Carro *carro);
    void addCarroClassificacao( Carro *carro);
    void sinalEmergenciaActivado(Carro * carro);
    void carroDanificado(Carro *carro);
    void destroiCarro(Carro* carro);
    vector <Carro*> getClassificacao();
    vector <Carro*> getCorrida();
    vector <Carro*> getGaragem();
    int getPistas() const;
    int getSegundoActual();
    int getComprimento() const;
    string getNome() const;
    void mostraClassificacaoCorrida();
    void mostraAutodromo();
    void carrosParaCorrida();
    bool passaUmSegundo();

    ~Autodromo();
};


#endif /* AUTODROMO_H */

