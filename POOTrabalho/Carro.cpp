/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Carro.h"

char Carro::letra = 'a';


Carro::Carro( int cap_min , int cap_max ,string marca, string modelo ){
    this->piloto = NULL;
    this->marca = marca;
    this->modelo = modelo;
    this->cap_min = cap_min;
    this->cap_max = cap_max;
    this->velocidade = 0;
    this->estado = false;
    this->acelera = false;
    this->trava = false;
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

bool Carro::getEstado(){
    return estado;
}

bool Carro::getAcelera(){
    return acelera;
}

bool Carro::getTrava(){
    return trava;
}

Piloto * Carro::getPiloto(){
    return piloto;
}


int Carro::getVelocidade(){
    return velocidade;
}

void Carro::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}

void Carro::mostrarCarro(){
    cout << "ID: " << this->id << " Marca:  " << this->marca << "  Modelo: " << this->modelo << endl;
    if(this->piloto != NULL){
        cout << "0 piloto " << piloto->getNome() << " encontra se ao volante!\n";
    }
}

void Carro::setPiloto(Piloto* piloto){
    this->piloto = piloto;
}

Carro::~Carro(){
}