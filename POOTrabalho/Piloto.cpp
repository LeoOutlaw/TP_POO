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
    this->pontos = 0;
}

Piloto::Piloto(const Piloto& piloto){
    nome = piloto.nome;
    tipo = piloto.tipo;
    carro = piloto.carro;
    lembra_comecar = piloto.lembra_comecar;
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

int Piloto::getPontos(){
    return pontos;
}

void Piloto::setPontos(int pontos){
    this->pontos = pontos;
}


Piloto::~Piloto(){
    
}