/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leonardo
 *
 * Created on 28 de Outubro de 2019, 16:56
 */

#include <cstdlib>
#include <string>
#include <iostream>

#include "TextUI.h"
#include "Carro.h"
#include "DVG.h"

using namespace std;

int main(int argc, char** argv) {
    TextUI * textUi = new TextUI();
    textUi->start();
    delete [] textUi;
    return 0;
}

