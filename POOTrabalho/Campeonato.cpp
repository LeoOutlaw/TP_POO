/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Campeonato.h"

Campeonato::Campeonato() {

}

void Campeonato::addAutodromo(Autodromo autodromo){
    todas_as_pistas.push_back(autodromo);
}

bool Campeonato::removeAutodromo(string nome){
    for (int i = 0; i < todas_as_pistas.size(); i++) {
        if (todas_as_pistas[i].getNome() == nome) {
            todas_as_pistas.erase(todas_as_pistas.begin() + i);
            return true;
        }
    }
}

void Campeonato::mostraAutodromos() {
    for (int i = 0; i < todas_as_pistas.size(); i++) {
        cout << i+1 <<"º---- " << todas_as_pistas[i].getNome() << endl;
    }
}

vector <Autodromo> * Campeonato::getTodasAsPistas(){
    return &todas_as_pistas;
}

void Campeonato::mostraClassificacaoFinal() {
    cout << " Informacao sobre a classificacao do campeonato\n";
    for (int i = 0; i < classificacao.size(); i++) {
        cout << i+1 <<"º---- " << classificacao[i].getNome() << endl;
    }
}