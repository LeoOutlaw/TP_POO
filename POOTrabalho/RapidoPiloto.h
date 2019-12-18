/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RapidoPiloto.h
 * Author: Leonardo
 *
 * Created on 11 de Dezembro de 2019, 0:32
 */

#ifndef RAPIDOPILOTO_H
#define RAPIDOPILOTO_H

#include "Piloto.h"

class RapidoPiloto : public Piloto {
    int primeiro;
public:
    RapidoPiloto(string nome);
    virtual string getTipo() const;

    virtual int getComecaCorrida()const {
        return comeca_corrida;
    }
    
    int getPrimeiro();
    void setPrimeiro(int primeiro);

    virtual bool caracteristicaPiloto(int segundo) const {
        int rande;
        if (segundo % 10 == 0) {
            rande = rand() % 100 + 1;
            if (rande > 0 && rande <= 10) {
                return false;
            }
        }
        return true;
    }

    virtual ~RapidoPiloto() {

    }

    //    virtual bool modoDeAtuar(); // return false caso ter acidente

};


#endif /* RAPIDOPILOTO_H */

