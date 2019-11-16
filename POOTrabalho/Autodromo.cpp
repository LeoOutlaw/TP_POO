/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Autodromo.h"

Autodromo::Autodromo(int pistas, int comprimento, string nome) {
    this->nome = nome;
    this->pistas = pistas;
    this->comprimento = comprimento;
}

void Autodromo::addCarroCorrida(Carro carro) {
    corrida.push_back(carro);
}

void Autodromo::addCarroGaragem(Carro carro) {
    garagem.push_back(carro);
}

string Autodromo::getNome() const {
    return nome;
}

int Autodromo::getComprimento() const {
    return comprimento;
}

int Autodromo::getPistas() const {
    return pistas;
}

void Autodromo::mostraClassificacaoCorrida() {
    cout << " Informacao sobre a corrida no autodromo " << this->nome << " (" << this->comprimento << " )\n";
    for (int i = 0; i < classificacao.size(); i++) {
        cout << i + 1 << "º. " << classificacao[i].getID() << " " << classificacao[i].getMarca() << " / " 
                << classificacao[i].getPiloto()->getNome() << " (" << classificacao[i].getPiloto()->getTipo()
                << " - " << classificacao[i].getVelocidade() << endl;
    }
}

Autodromo::~Autodromo() {

}