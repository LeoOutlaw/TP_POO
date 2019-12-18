/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SurpresaPiloto.h
 * Author: Leonardo
 *
 * Created on 16 de Dezembro de 2019, 17:00
 */

#ifndef SURPRESAPILOTO_H
#define SURPRESAPILOTO_H

#include "Piloto.h"

class SurpresaPiloto : public Piloto {
    
public:
    SurpresaPiloto(string nome);
    virtual string getTipo() const;

    virtual int getComecaCorrida() const {
        return comeca_corrida;
    }

    virtual bool caracteristicaPiloto(int segundo) const {
        int rande;
        rande = (rand() % 100) + 1;
        if (rande > 0 && rande <= 25) {
            return false;
        }
        return true;
    }


    virtual ~SurpresaPiloto() {

    }
};

#endif /* SURPRESAPILOTO_H */

