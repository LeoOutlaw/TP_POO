/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CrazyPiloto.h
 * Author: Leonardo
 *
 * Created on 10 de Dezembro de 2019, 19:26
 */

#ifndef CRAZYPILOTO_H
#define CRAZYPILOTO_H


#include "Piloto.h"

class CrazyPiloto : public Piloto {
public:
    CrazyPiloto(string nome);
    virtual string getTipo() const;

    virtual int getComecaCorrida() const {
        return comeca_corrida;
    }

    virtual bool caracteristicaPiloto(int segundo) const {
        int rande;
        rande = (rand() % 100) + 1;
        if (rande > 0 && rande <= 5) {
            return false;
        }
        return true;
    }


    virtual ~CrazyPiloto() {

    }

    //    virtual bool modoDeAtuar(); // return false caso ter acidente

};


#endif /* CRAZYPILOTO_H */

