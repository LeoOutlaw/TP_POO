/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <valarray>

#include "DVG.h"

DVG::DVG() {
}

char DVG::letra = '1';

bool DVG::removeCarro(char id) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros[i].getID() == id) {
            if (carros.at(i).getOcupado()){
                carros.at(i).getPiloto()->setCarro(false);
            }
            carros.erase(carros.begin() + i);
            return true;
        }
    }
    return false;
}

bool DVG::removePiloto(string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos.at(i).getNome().compare(nome) == 0 || pilotos.at(i).getNome().compare(nome) == 1) {
            pilotos.erase(pilotos.begin() + i);
            return true;
        }
    }
    return false;
}

void DVG::addPiloto(string tipo, string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos.at(i).getNome().compare(nome) == 0 || pilotos.at(i).getNome().compare(nome) == 1) {
            nome += letra;
            letra++;
            break;
        }
    }
    Piloto piloto(tipo, nome);
    pilotos.push_back(piloto);
}

void DVG::addCarro(Carro carro) {
    carros.push_back(carro);
}

void DVG::listarCarros() {
    for (int i = 0; i < carros.size(); i++) {
        carros[i].mostrarCarro();
    }
}

void DVG::listarPilotos() {
    for (int i = 0; i < pilotos.size(); i++) {
        pilotos[i].mostrarPiloto();
    }
}

Carro * DVG::verSePilotoEstaAoVolante(string nome) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros.at(i).getPiloto() != NULL) {
            if (carros.at(i).getPiloto()->getNome().compare(nome)) {
                return &carros.at(i);
            }
        }
    }
    return NULL;
}

bool DVG::encontraCarro(char id) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros[i].getID() == id) {
            return true;
        }
    }
    return false;
}

bool DVG::encontraPiloto(string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos.at(i).getNome().compare(nome) == 0 || pilotos.at(i).getNome().compare(nome) == 1) {
            return true;
        }
    }
    return false;
}

Carro *DVG::buscaCarro(char id) {
    for (int i = 0; i < carros.size(); i++) {
        if (carros[i].getID() == id) {
            return &carros[i];
        }
    }
    return NULL;
}

Piloto *DVG::buscaPiloto(string nome) {
    for (int i = 0; i < pilotos.size(); i++) {
        if (pilotos.at(i).getNome().compare(nome) == 0 || pilotos.at(i).getNome().compare(nome) == 1) {
            return &pilotos.at(i);
        }
    }
    return NULL;
}

vector <Carro> DVG::getVectorCarros() {
    return carros;
}

vector <Piloto> DVG::getVectorPilotos() {
    return pilotos;
}

DVG::~DVG() {
    cout << "ACABA COM TUDO!!" << endl;
}