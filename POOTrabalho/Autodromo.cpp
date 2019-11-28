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

void Autodromo::addCarroCorrida(Carro *carro) {
    corrida.push_back(carro);
}

void Autodromo::addCarroGaragem(Carro *carro) {
    garagem.push_back(carro);
}

void Autodromo::addCarroClassificacao(Carro *carro) {
    classificacao.push_back(carro);
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

void Autodromo::mostraAutodromo() {
    cout << "Nome: " << this->nome << " Comprimento: " << this->comprimento << " Pistas: " << this->pistas << endl;
}

vector <Carro*> Autodromo::getGaragem() {
    return garagem;
}

vector <Carro*> Autodromo::getCorrida() {
    return corrida;
}

vector <Carro*> Autodromo::getClassificacao() {
    return classificacao;

}

void Autodromo::mostraClassificacaoCorrida() {
    cout << " Informacao sobre a corrida no autodromo " << this->nome << " (" << this->comprimento << " )\n";
    for (int i = 0; i < classificacao.size(); i++) {
        cout << i+1 << "º. " << classificacao[i]->getID() << " " << classificacao[i]->getMarca() << " / "
                << classificacao[i]->getPiloto()->getNome() << " (" << classificacao[i]->getPiloto()->getTipo()
                << ") - " << classificacao[i]->getPosicao_x() << " - " << classificacao[i]->getVelocidade() << endl;
    }
}

void Autodromo::carrosParaCorrida() {
    if (garagem.size() > pistas) {
        for (int i = 0; i < pistas; i++) {
            addCarroCorrida(garagem[i]);
            addCarroClassificacao(garagem[i]);
        }
    } else {
        for (int i = 0; i < garagem.size(); i++) {
            addCarroCorrida(garagem[i]);
            addCarroClassificacao(garagem[i]);
        }
    }
}

void Autodromo::passaUmSegundo() {
    Carro * carro;
    for (int i = 0; i < corrida.size(); i++) {
        if (corrida[i]->getAcelera()) {
            //APENAS PARA A 1A META
            corrida[i]->setVelocidade(1);
            
            //corrida[i]->setVelocidade(corrida[i]->getVelocidade() + 1);
            corrida[i]->setPosicao(corrida[i]->getPosicao() + corrida[i]->getVelocidade());
        } else if (corrida[i]->getTrava()) {
            //corrida[i]->setVelocidade(corrida[i]->getVelocidade() - 1);
            //corrida[i]->setPosicao(corrida[i]->getPosicao() + corrida[i]->getVelocidade());
        }
    }
    //fazer ciclo para ver quem esta com a posicao maior e trocar classificacao

    for (int i = 0; i < classificacao.size()-1; i++) { //Decrescente
        if (classificacao[i]->getPosicao() < classificacao[i + 1]->getPosicao()) {
            carro = classificacao[i + 1];
            classificacao[i + 1] = classificacao[i];
            classificacao[i] = carro;
            i=-1;
        }
    }
}

Autodromo::~Autodromo() {

}