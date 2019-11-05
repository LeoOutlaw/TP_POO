/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <valarray>

#include "DVG.h"

DVG::DVG(){
}

vector <Carro> DVG::getCarros(){
    return carros;
}

bool DVG::removeCarro(char id){
    for ( int i= 0; i< carros.size(); i++){
        if (carros[i].getID() == id ){
            carros.erase(carros.begin()+i);
            return true;
        }
    }
    return false;
}

void DVG::addPiloto(Piloto piloto){
    pilotos.push_back(piloto);
}

void DVG::addCarro(Carro carro){
    carros.push_back(carro);
}

void DVG::listarCarros(){
    for (int i = 0; i < carros.size(); i++) {
        carros[i].mostrarCarro();
    }
}

void DVG::listarPilotos(){
    for (int i = 0; i < pilotos.size(); i++) {
        pilotos[i].mostrarPiloto();
    }
}

bool DVG::encontraCarro(char id){
    for ( int i= 0; i< carros.size(); i++){
        if (carros[i].getID() == id ){
            return true;
        }
    }
    return false;
}

bool DVG::encontraPiloto(string nome){
    for ( int i= 0; i< pilotos.size(); i++){
        if (pilotos[i].getNome() == nome ){
            return true;
        }
    }
    return false;
}

Carro *DVG::buscaCarro(char id){
    for ( int i= 0; i< carros.size(); i++){
        if (carros[i].getID() == id ){
            return &carros[i];
        }
    }
    return NULL;
}

Piloto *DVG::buscaPiloto(string nome){
    for ( int i= 0; i< pilotos.size(); i++){
        if (pilotos[i].getNome() == nome ){
            return &pilotos[i];
        }
    }
    return NULL;
}

DVG::~DVG(){
    cout << "ACABA COM TUDO!!" << endl;
}