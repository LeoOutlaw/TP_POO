/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <valarray>

#include "Autodromo.h"

Autodromo::Autodromo(int pistas, int comprimento, string nome) {
    this->nome = nome;
    this->pistas = pistas;
    this->comprimento = comprimento;
    this->segundo_actual = 0;
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
    cout.precision(2);
    cout << " Segundo -----> " << segundo_actual << endl;
    for (int i = 0; i < classificacao.size(); i++) {
        cout << i + 1 << "º. " << classificacao[i]->getID() << " " << classificacao[i]->getMarca() << " / "
                << classificacao[i]->getPiloto()->getNome() << " (" << classificacao[i]->getPiloto()->getTipo()
                << ") - " << classificacao[i]->getPosicao() << " - " << classificacao[i]->getVelocidade()
                << " - Carga: ";
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << classificacao[i]->getCapActual() << endl;
        cout << "Acelera: " << classificacao[i]->getPiloto()->getAcelera();
        cout << "  Trava: " << classificacao[i]->getPiloto()->getTrava() << endl;
        if (classificacao[i]->getSinalEmergencia()) {
            cout << "Sinal de emerencia ACTIVADO!\n";
        }
        if (classificacao[i]->getDanificado()) {
            cout << "O carro encontrase DANIFICADO!\n";
        }
    }
}

void Autodromo::carrosParaCorrida() {
    if (garagem.size() > pistas) {
        for (int i = 0; i < pistas; i++) {
            addCarroCorrida(garagem[i]);
            addCarroClassificacao(garagem[i]);
        }
        garagem.erase(garagem.begin(), garagem.begin() + pistas);
    } else {
        for (int i = 0; i < garagem.size(); i++) {
            addCarroCorrida(garagem[i]);
            addCarroClassificacao(garagem[i]);
        }
        garagem.erase(garagem.begin(), garagem.end());
    }
}

void Autodromo::sinalEmergenciaActivado(Carro* carro) {
    for (int i = 0; i < corrida.size(); i++) {
        if (corrida[i]->getID() == carro->getID()) {
            garagem.push_back(corrida[i]);
            corrida.erase(corrida.begin() + i);
            break;
        }
    }
    for (int i = 0; i < classificacao.size(); i++) {
        if (classificacao[i]->getID() == carro->getID()) {
            classificacao.erase(classificacao.begin() + i);
        }
    }
}

void Autodromo::carroDanificado(Carro *carro) {
    for (int i = 0; i < corrida.size(); i++) {
        if (corrida[i]->getID() == carro->getID()) {
            corrida[i]->setDanificado(true);
            corrida[i]->setVelocidade(0);
            break;
        }
    }
}

void Autodromo::destroiCarro(Carro* carro) {
    for (int i = 0; i < garagem.size(); i++) {
        if (garagem[i]->getID() == carro->getID()) {
            garagem.erase(garagem.begin() + i);
        }
    }
    for (int i = 0; i < corrida.size(); i++) {
        if (corrida[i]->getID() == carro->getID()) {
            corrida.erase(corrida.begin() + i);
        }
    }
    for (int i = 0; i < classificacao.size(); i++) {
        if (classificacao[i]->getID() == carro->getID()) {
            classificacao.erase(classificacao.begin() + i);
        }
    }
}

void Autodromo::passaUmSegundo() {
    Carro * carro;
    double aux;
    for (int i = 0; i < corrida.size(); i++) {
        if (corrida[i]->getDanificado() || corrida[i]->getSinalEmergencia()) {
            corrida[i]->setVelocidade(0);
        } else {
            if (corrida[i]->getPiloto()->getComecaCorrida() == segundo_actual) {
                corrida[i]->getPiloto()->setAcelera(true);
            }
            if (corrida[i]->getPiloto()->getAcelera()) {
                corrida[i]->setVelocidade(corrida[i]->getVelocidade() + 1);
                if (corrida[i]->getVelocidade() > corrida[i]->getVelociadeMax()) {
                    corrida[i]->setVelocidade(corrida[i]->getVelociadeMax());
                }
                aux = corrida[i]->getCapActual() - 0.1;
                corrida[i]->setCapActual(aux);
            } else if (corrida[i]->getPiloto()->getTrava()) {
                corrida[i]->setVelocidade(corrida[i]->getVelocidade() - 1);
                if (corrida[i]->getVelocidade() < 0) {
                    corrida[i]->setVelocidade(0);
                }
            }
            corrida[i]->setPosicao(corrida[i]->getPosicao() + corrida[i]->getVelocidade());
        }
    }
    //fazer ciclo para ver quem esta com a posicao maior e trocar classificacao
    for (int i = 0; i < classificacao.size() - 1; i++) {
        if (classificacao[i]->getPosicao() < classificacao[i + 1]->getPosicao()) {
            carro = classificacao[i + 1];
            classificacao[i + 1] = classificacao[i];
            classificacao[i] = carro;
            i = -1;
        }
    }
    segundo_actual++;
}

int Autodromo::getSegundoActual() {
    return segundo_actual;
}

Autodromo::~Autodromo() {

}