/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Carro.h"

char Carro::letra = 'a';

Carro::Carro(int velocidade_max, int cap_min , int cap_max ,string marca, string modelo ){
    this->piloto = NULL;
    this->marca = marca;
    this->modelo = modelo;
    this->pos = 0;
    this->cap_min = cap_min;
    this->cap_max = cap_max;
    this->velocidade = 0;
    this->velocidade_max = velocidade_max;
    this->acelera = true;
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

int Carro::getPosicao(){
    return pos;
}

void Carro::setPosicao(int pos){
    this->pos = pos;
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

Carro& Carro::operator=(Carro *c) {
    if(this != c){
        this->piloto = c->piloto;
        this->marca = c->marca;
        this->modelo = c->modelo;
        this->id = c->id;
        this->pos = c->pos;
        this->cap_min = c->cap_min;
        this->cap_max = c->cap_max;
        this->num_carga = c->num_carga;
        this->velocidade = c->velocidade;
        this->velocidade_max =c->velocidade_max;
        this->trava = c->trava;
        this->acelera = c->acelera;
        this->sinal_emergencia = c->sinal_emergencia;
    }
    return *this;
}

Carro::~Carro(){
}