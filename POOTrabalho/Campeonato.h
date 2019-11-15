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
    vector <Autodromo *> campeonato;
    int actualAutodromo;   // saber em que corrida vai
    vector <Autodromo> todas_as_pistas;
    vector <Carro*> concorrentes; //carros e pilotos que estao a participar no campeonato
    vector <Piloto> classificacao; // que pilotos e carros que estao a frente
public:
    Campeonato();
    int getActualAutodromo();
    void setActualAutodromo(int prox);
    vector <Autodromo*> getAutodromoCampeonato();
    vector <Carro*> getConcorrentes();
    void addAutodromoParaCampeonato( Autodromo *autodromo);
    void addAutodromo(Autodromo autodromo);
    void addConcorrentes(Carro *carro);
    bool removeAutodromo(string nome);
    void mostraClassificacaoFinal();
    void mostraAutodromos();
    vector <Autodromo> getTodasAsPistas();
    Autodromo *getPista(string nome);   // Todas as pistas
    void addConcorrentesAoAutodromo();
};

#endif /* CAMPEONATO_H */

