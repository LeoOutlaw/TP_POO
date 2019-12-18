/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "CrazyPiloto.h"

CrazyPiloto::CrazyPiloto(string nome) : Piloto("crazy", nome) {
    int a =(rand()%6)+1;
    this->comeca_corrida = a-1;
    this->acelera = false;
    this->trava = false;
    this->tipo = "crazy";
    srand((int)time(0));
}

string CrazyPiloto::getTipo() const {
    return this->tipo;
}



/*bool CrazyPiloto::modoDeAtuar(vector<Carro *> clas) {
    for (int i = 0; i < clas.size(); i++) {
        if (clas[i]->getPiloto()->getNome() == getNome()) {
            if (i == 0) {
                setAcelera(false);
                setTrava(false);
            } else if (i == clas.size() - 1) {
                setAcelera(false);
                setTrava(true);
            } else if (i > classif) {
                setAcelera(true);
                setTrava(false);
            }
            break;
        }
    }
    if ((rand() % 100 + 1) > 5) {
        return true;
    } else {
        return false;
    }
}*/