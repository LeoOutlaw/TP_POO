/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Carro.h"

char Carro::letra = 'a';

Carro::Carro(string marca, int cap_min , int cap_max ){
    this->marca = marca;
    this->modelo = "modelo base";
    this->cap_min = cap_min;
    this->cap_max = cap_max;
    this->velocidade = 0;
    this->estado = false;
    this->sinal_emergencia = false;
    this->id = this->letra;
    this->letra++;
}

Carro::Carro(string marca, string modelo, int cap_min , int cap_max ){
    //this->piloto = NULL;
    this->marca = marca;
    this->modelo = modelo;
    this->cap_min = cap_min;
    this->cap_max = cap_max;
    this->velocidade = 0;
    this->estado = false;
    this->sinal_emergencia = false;
    this->id = this->letra;
    this->letra++;
}

string Carro::getMarca() const{
    return marca;
}

string Carro::getModelo() const{
    return modelo;
}

char Carro::getID() const{
    return id;
}

int Carro::getVelocidade(){
    return velocidade;
}

void Carro::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}

Carro::~Carro(){
    
}