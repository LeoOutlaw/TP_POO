/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Carro.h"

char Carro::letra = 'a';

Carro::Carro(int velocidade, double cap_inicial, int cap_max, string marca, string modelo) : modelo(modelo) {
    this->piloto = NULL;
    this->marca = marca;
    this->pos = 0;
    this->pos_corrida = 0;
    this->cap_inicial = cap_inicial;
    this->cap_max = cap_max;
    this->cap_actual = cap_inicial;
    this->velocidade = 0;
    this->velocidade_max = velocidade;
    this->sinal_emergencia = false;
    this->danificado = false;
    this->id = this->letra;
    this->ocupado = false;
    this->nr_volta = 1;
    this->letra++;
}

Carro::Carro(int velocidade, double cap_min, int cap_max, string marca, int id, Piloto * piloto, string modelo) : modelo(modelo) {
    this->piloto = piloto;
    this->marca = marca;
    this->pos = 0;
    this->pos_corrida = 0;
    this->cap_inicial = cap_min;
    this->cap_max = cap_max;
    this->cap_actual = cap_min;
    this->velocidade = 0;
    this->velocidade_max = velocidade;
    this->id = id;
    this->nr_volta = 1;
    this->sinal_emergencia = false;
    this->danificado = false;
    this->ocupado = true;
}

void Carro::defaultCarro(){
    this->pos = 0;
    this->pos_corrida = 0;
    this->velocidade = 0;
    this->nr_volta = 1;
    this->sinal_emergencia = false;
    this->danificado = false;
    this->ocupado = true;
}

int Carro::getVolta() const{
    return nr_volta;
}

void Carro::setVolta(int i){
    nr_volta = i;
}

string Carro::getMarca() const {
    return marca;
}

string Carro::getModelo() const {
    return modelo;
}

double Carro::getCapActual() {
    return cap_actual;
}

int Carro::getCapMax() {
    return cap_max;
}

void Carro::setCapActual(double cap_actual) {
    this->cap_actual = cap_actual;
}

double Carro::getCapInicial() {
    return cap_inicial;
}

bool Carro::getOcupado() {
    return ocupado;
}

void Carro::setOcupado(bool ocupado) {
    this->ocupado = ocupado;
}

char Carro::getID() const {
    return id;
}

Piloto * Carro::getPiloto() {
    return piloto;
}

int Carro::getVelocidade() {
    return velocidade;
}

void Carro::setVelocidade(int velocidade) {
    this->velocidade = velocidade;
}

int Carro::getVelociadeMax() {
    return velocidade_max;
}

int Carro::getPosicao() {
    return pos;
}

void Carro::setPosicao(int pos) {
    this->pos = pos;
}

int Carro::getPosicaoCorrida(){
    return pos_corrida;
}

void Carro::setPosicaoCorrida(int pos){
    this->pos_corrida = pos;
}

void Carro::mostrarCarro() {
    cout << "ID: " << this->id << " Marca:  " << this->marca << "  Modelo: " << this->modelo << "Carga: ";
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << this->cap_actual << endl;
    if (this->piloto != NULL) {
        cout << "0 piloto " << piloto->getNome() << " encontra se ao volante!\n";
    }
}

void Carro::mostraCarroEmCorrida() {
    cout << "Piloto: " << piloto->getNome() << " Carro(id): (" << this->id << ") -> Marca:  " << this->marca << "  Energia actual --->" << this->cap_actual << "  Energia max(" << this->cap_max << ")" << endl;
    cout << "Danificado : " << this->danificado << "  Sinal de Emergencia: " << this->sinal_emergencia << endl;
}

void Carro::setPiloto(Piloto* piloto) {
    this->piloto = piloto;
}

bool Carro::getSinalEmergencia() {
    return sinal_emergencia;
}

void Carro::setSinalEmergencia(bool sinal) {
    this->sinal_emergencia = sinal;
}

bool Carro::getDanificado() {
    return danificado;
}

void Carro::setDanificado(bool danificado) {
    this->danificado = danificado;
}

Carro& Carro::operator=(Carro *c) {
    if (this != c) {
        this->piloto = c->piloto;
        this->marca = c->marca;
        this->modelo = c->modelo;
        this->id = c->id;
        this->pos = c->pos;
        this->cap_inicial = c->cap_inicial;
        this->cap_max = c->cap_max;
        this->cap_actual = c->cap_actual;
        this->velocidade = c->velocidade;
        this->velocidade_max = c->velocidade_max;
        this->sinal_emergencia = c->sinal_emergencia;
    }
    return *this;
}

Carro::~Carro() {
}