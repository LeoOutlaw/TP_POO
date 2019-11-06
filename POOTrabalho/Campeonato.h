/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Campeonato.h
 * Author: Leonardo
 *
 * Created on 6 de Novembro de 2019, 18:00
 */

#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include "Autodromo.h"

class Campeonato{
    vector <Autodromo> campeonato;
    vector <Autodromo> todas_as_pistas;
    vector <Carro> concorrentes; //carros e pilotos que estao a participar no campeonato
    vector <Piloto> classificacao; // que pilotos e carros que estao a frente
public:
    Campeonato();
    void addAutodromo(Autodromo autodromo);
    bool removeAutodromo(string nome);
    void mostraClassificacaoFinal();
    void mostraAutodromos();
};

#endif /* CAMPEONATO_H */

