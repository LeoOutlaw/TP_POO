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
    this->pontos = 0;
}

Piloto::Piloto(const Piloto& piloto){
    nome = piloto.nome;
    tipo = piloto.tipo;
    carro = piloto.carro;
}

string Piloto::getNome() const{
    return this->nome;
}

void Piloto::mostrarPiloto(){
    cout <<  "Tipo :  " << tipo << "  Nome :  " << nome  << endl;
}

string Piloto::getTipo() const{
    return tipo;
}

int Piloto::getPontos(){
    return pontos;
}

void Piloto::setPontos(int pontos){
    this->pontos += pontos;
}

bool Piloto::getCarro(){
    return carro;
}

void Piloto::setCarro(bool val){
    carro = val;
}

bool Piloto::getAcelera() const {
    return acelera;
}

bool Piloto::getTrava() const {
    return trava;
}

void Piloto::setAcelera(bool acelera) {
    this->acelera = acelera;

}

void Piloto::setTrava(bool trava) {
    this->trava = trava;

}

Piloto& Piloto::operator =(Piloto* p){
    if(this != p){
        this->nome = p->nome;
        this->tipo = p->tipo;
        this->carro = p->carro;
        this->pontos = p->pontos;
    }
    return *this;
}


Piloto::~Piloto(){
    
}