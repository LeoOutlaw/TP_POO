/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Piloto.h"

Piloto::Piloto(string tipo, string nome){
    this->nome = nome;
    this->tipo = tipo;
    carro = false;
    this->lembra_comecar = 0;
}

string Piloto::getNome() const{
    return nome;
}

void Piloto::mostrarPiloto(){
    cout << " Nome :  " << this->nome  << "  Tipo :  " << this->tipo << endl;
}

string Piloto::getTipo() const{
    return tipo;
}

Piloto & Piloto::operator =(const Piloto & piloto){
    this->nome = piloto.nome;
    this->tipo = piloto.tipo;
    this->carro = piloto.carro;
    this->lembra_comecar = piloto.lembra_comecar;
}

Piloto::~Piloto(){
    
}