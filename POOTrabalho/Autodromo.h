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

#include "DVG.h"

class Autodromo{
    string nome;
    int pistas;
    int comprimento;
    vector <Carro> classificacao;
    vector <Carro> corrida;
    vector <Carro> garagem;
public:
    Autodromo(int pistas, int comprimento, string nome);
    void addCarroCorrida(Carro carro);
    void addCarroGaragem(Carro carro);
    int getPistas() const;
    int getComprimento() const;
    string getNome() const;
    void mostraClassificacaoCorrida();
    ~Autodromo();
};


#endif /* AUTODROMO_H */

