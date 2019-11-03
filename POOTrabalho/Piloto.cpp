/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Piloto.h"

Piloto::Piloto( string nome){
    this->nome = nome;
    carro = false;
    aux = '0';
    this->lembra_comecar = 0;
}

string Piloto::getNome() const{
    return nome;
}

Piloto::~Piloto(){
    
}