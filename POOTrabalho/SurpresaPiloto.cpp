/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "SurpresaPiloto.h"

SurpresaPiloto::SurpresaPiloto(string nome) : Piloto("surpresa", nome) {
    this->comeca_corrida = 0;
    this->acelera = false;
    this->trava = false;
    this->tipo = "surpresa";
}

string SurpresaPiloto::getTipo() const {
    return this->tipo;
}
