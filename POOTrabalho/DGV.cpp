/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <valarray>

#include "DGV.h"

DGV::DGV() {
    this->nome = "";
}

DGV::DGV(const DGV & dgv) {
    nome = dgv.nome;
    for (int i = 0; i < dgv.pilotos.size(); i++) {
        Piloto * p = dgv.pilotos[i];
        pilotos.push_back(p);
    }
    for (int i = 0; i < dgv.carros.size(); i++) {
        Carro c = dgv.carros[i];
        carros.push_back(c);
    }
}

char DGV::letra = '1';

string DGV::getNome() {
    return nome;
}

void DGV::setNome(string nome) {
    this->nome = nome;
}

bool DGV::removeCarro(char id) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros[i].getID() == id) {
            if (carros.at(i).getOcupado()) {
                carros.at(i).getPiloto()->setCarro(false);
            }
            carros.erase(carros.begin() + i);
            return true;
        }
    }
    return false;
}

bool DGV::removePiloto(string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos[i]->getNome().compare(nome) == 0) {
            pilotos.erase(pilotos.begin() + i);
            return true;
        }
    }
    return false;
}

void DGV::addPiloto(string tipo, string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos[i]->getNome().compare(nome) == 0) {
            nome += letra;
            letra++;
            break;
        }
    }

    if (tipo.compare("crazy") == 0) {
        pilotos.push_back(new CrazyPiloto(nome));
    } else if (tipo.compare("rapido") == 0) {
        pilotos.push_back(new RapidoPiloto(nome));
    } else if (tipo.compare("surpresa") == 0) {
        pilotos.push_back(new SurpresaPiloto(nome));
    }
}

void DGV::addCarro(Carro carro) {
    carros.push_back(carro);
}

void DGV::listarCarros() {
    for (int i = 0; i < carros.size(); i++) {
        carros[i].mostrarCarro();
    }
}

void DGV::listarPilotos() {
    for (int i = 0; i < pilotos.size(); i++) {
        pilotos[i]->mostrarPiloto();
    }
}

Carro * DGV::verSePilotoEstaAoVolante(string nome) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros.at(i).getPiloto() != NULL) {
            if (carros.at(i).getPiloto()->getNome().compare(nome) == 0) {
                return &carros.at(i);
            }
        }
    }
    return NULL;
}

bool DGV::encontraCarro(char id) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros[i].getID() == id) {
            return true;
        }
    }
    return false;
}

bool DGV::encontraPiloto(string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos[i]->getNome().compare(nome) == 0) {
            return true;
        }
    }
    return false;
}

Carro * DGV::buscaCarro(char id) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros[i].getID() == id) {
            return &carros[i];
        }
    }
    return NULL;
}

Piloto * DGV::buscaPiloto(string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos[i]->getNome().compare(nome) == 0) {
            return pilotos[i];
        }
    }
    return NULL;
}

vector <Carro> DGV::getVectorCarros() {
    return carros;
}

vector <Piloto*> DGV::getVectorPilotos() {
    return pilotos;
}

DGV & DGV::operator=(DGV * dgv) {
    if (this != dgv) {
        this->carros.erase(this->carros.begin(), this->carros.begin() + this->carros.size());
        this->pilotos.erase(this->pilotos.begin(), this->pilotos.begin() + this->pilotos.size());
        for (int i = 0; i < dgv->carros.size(); i++) {
            if (this->carros[i].getMarca().empty()) {
                break;
            }
            this->carros[i] = dgv->carros[i];
        }
        for (int i = 0; i < dgv->pilotos.size(); i++) {
            if (this->pilotos[i]->getNome().empty()) {
                break;
            }
            this->pilotos[i] = dgv->pilotos[i];
        }
        this->letra = dgv->letra;
    }
    return *this;
}

DGV::~DGV() {
    for (int i = 0; i < pilotos.size(); i++) {
        delete pilotos[i];
    }
    pilotos.clear();
}