/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextUI.cpp
 * Author: Leonardo
 *
 * Created on 3 de Novembro de 2019, 1:20
 */

#include "TextUI.h"

TextUI::TextUI() {
    dvg = new DVG();
    camp = new Campeonato();
}

void TextUI::start() {
    //    dvg.push_back(new DVG());
    iter = 0;
    string comando;
    imprimeNome();
    comandoLoadCarros("c.txt");
    comandoLoadPilotos("p.txt");
    comandoLoadAutodromos("a.txt");
    do {
        cout << "Consola Modo1> ";
        getline(cin, comando);
    } while (leComandos(this->toLower(comando)));
   
    iniciaModo2();
    
    //preparamodo2
    
    
    do {
        cout << "Consola Modo2> ";
        getline(cin, comando);
    } while (leComandosModo2(this->toLower(comando)));
}

bool TextUI::iniciaModo2(){
    
    //cout << "------------Entrou no modo 2-----------------\n";
    
    camp->addConcorrentesAoAutodromo();
    camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->carrosParaCorrida();
    
    mostra_janela_inicial();
    //Mostra Janela inicial - mostra competidores e resp carros
    
    //Mostra Janela Corrida - mostra interface atualizada com pista e classificação
    return true;
}
void TextUI::mostra_janela_passatempo(int num)
{   
    Consola::gotoxy(0,1);
    Consola::clrscr();
    cout << "A corrida do " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getNome() << ": "<<  endl;
    
    int n_carros_2 = camp->getConcorrentes().size();
    
    Consola::gotoxy(0,1);    
    
    for(int h=0;h<n_carros_2;h++){
        Consola::setBackgroundColor(Consola::CINZENTO+h);
        for(int k=0;k<100;k++){
            cout << " " ;
        }
        Consola::setBackgroundColor(Consola::PRETO);
        cout << " FINAL\n" ;
    }
   
    //O BACKGORUND COLOR TEM DE SER ESCRITO ANTES DO AVANÇO DOS CARROS
        //FAZER GOTOXY(0,1)
    Consola::gotoxy(0,1);
    //Consola::getch();
    //cout << camp->getConcorrentes()[0]->getPosicao_x();
    //cout << camp->getConcorrentes()[1]->getPosicao_x();
    
    for(int i=0;i<n_carros_2 ;i++)
    {   
        //camp->getConcorrentes()[i]->setPosicao(num);
        //Consola::gotoxy(camp->getConcorrentes()[i]->getPosicao_x(), i+1);
        Consola::gotoxy(camp->getConcorrentes()[i]->getPosicao_x(), i+1);
        cout << camp->getConcorrentes()[i]->getID();
        //Consola::setBackgroundColor(Consola::CINZENTO+i);
        /*
        for(int j=0;j<100;j++)
        {
            cout << " ";
        }*/
        //Consola::getch();
        Consola::setBackgroundColor(Consola::PRETO);
        //cout << " FINAL\n" ;
        //cout << camp->getConcorrentes()[i]->getPosicao_x();
        
    }
    //cout << camp->getConcorrentes()[0]->getPosicao_x();
    //cout << camp->getConcorrentes()[1]->getPosicao_x();
    Consola::gotoxy(0,n_carros_2+1);
    //Consola::getch();
    
    //FALTA NA PARTE FINAL ESCREVER A CLASSIFICAÇÃO
    
}

void TextUI::mostra_janela_inicial(){
        
    cout << "----------------------------------------- Simulador de Corridas -----------------------------------------" << endl;
    //camp->mostraAutodromos()[0];
    //int n_carros = camp->getTodasAsPistas().size();
    int n_carros_2 = camp->getConcorrentes().size();
    //    cout << "N_Carros: " << n_carros <<endl;
    
    Consola::gotoxy(0,1);
   
    //cout << camp->getConcorrentes()[0]->getID() ;
    
    Consola::setScreenSize(15,120);
    //Consola::setBackgroundColor(Consola::CINZENTO);
    
    for(int i=0;i<n_carros_2 ;i++)
    {   
        cout << camp->getConcorrentes()[i]->getID();
        Consola::setBackgroundColor(Consola::CINZENTO+i);
        
        for(int j=0;j<100;j++)
        {
            cout << " ";
        }
        Consola::setBackgroundColor(Consola::PRETO);
        cout << " FINAL\n" ;
    }
    
    cout << "\n\t Pilotos Concorrentes: " << endl;
    
    for(int i=0;i<camp->getConcorrentes().size();i++)
        cout << "Nome: " << camp->getConcorrentes()[i]->getPiloto()->getNome() << " Marca: " << camp->getConcorrentes()[i]->getMarca() << " Modelo :" << camp->getConcorrentes()[i]->getModelo() << endl;
    
        Consola::setBackgroundColor(Consola::PRETO);
        Consola::getch();
        Consola::clrscr();
        
    //FÇ MOSTRA CLASSIFICAÇÃO
   /* cout << "-------Classificacao Atual-----------------" << endl;
    cout << "1o: " << "Andre \n" << endl;
    cout << "2o: " << "Leo \n" << endl;
    cout << "3o: " << "Joao \n" << endl;
    Consola::getch();
    */
}

void TextUI::imprimeNome() {
    cout << "------------Simulador de Corridas------------" << endl;
}

bool TextUI::leComandos(string comando) {
    vector<string> stringSeparada;
    string aux;
    stringSeparada = separaComando(comando, ' ');
    
    if (stringSeparada[0] == "fim") {
        if (dvg->getVectorCarros().size() != 0) {
            if (dvg->getVectorPilotos().size() != 0) {
                if (camp->getTodasAsPistas().size() != 0) {
                    return false;}}}}
    if (stringSeparada[0] == "campeonato") {
        Consola::clrscr();
        if (stringSeparada.size() > 1) {
            int flag = 0;
            for (int i = 1; i < stringSeparada.size(); i++) {
                for (int j = 0; j < camp->getTodasAsPistas().size(); j++) {
                    if (camp->getTodasAsPistas()[j].getNome() == stringSeparada[i]) { // algum tipo de erro aqui
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    cout << "Este autodromo '" << stringSeparada[i] << "' nao existe!\n";
                    return true;

                }
            }
            if (dvg->getVectorCarros().size() != 0) {
                if (dvg->getVectorPilotos().size() != 0) {
                    if (camp->getTodasAsPistas().size() != 0) {
                        return comandoCampeonato(stringSeparada);
                    }
                }
            }
            if (dvg->getVectorCarros().size() == 0) {
                cout << "Nao existe carros\n";
            }
            if (dvg->getVectorPilotos().size() == 0) {
                cout << "Nao existe pilotos\n";
            }
            if (camp->getTodasAsPistas().size() == 0) {
                cout << "Nao existem autodromos\n";
            }
        } else {
            cout << "Numero de argumentos errado! Ex: campeonato <autodromo1> <autodromo2>...\n";
        }
    } else if (stringSeparada[0] == "cria") {
        if (stringSeparada[1] == "c") {
            if (stringSeparada.size() == 5) {
                dvg->addCarro(Carro(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), atoi(stringSeparada[4].c_str()), stringSeparada[4]));
            } else if (stringSeparada.size() == 6) {
                dvg->addCarro(Carro(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), atoi(stringSeparada[4].c_str()), stringSeparada[5], stringSeparada[6]));
            } else {
                cout << "Comando mal implementado -->EX: cria c <cap_min> <cap_max> <marca> <modelo>\n";
            }
        } else if (stringSeparada[1] == "p") {
            if (stringSeparada[2] == "crazy" || stringSeparada[2] == "surpresa" || stringSeparada[2] == "rapido") {
                aux = juntarNome(stringSeparada, 3);
                dvg->addPiloto(Piloto(stringSeparada[2], aux));
            } else {
                cout << "Comando mal implementado -->EX: cria p tipo nome\n";
            }
        } else if (stringSeparada[1] == "a") {
            if (stringSeparada.size() == 5) {
                camp->addAutodromo(Autodromo(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), stringSeparada[4]));
            } else {
                cout << "Comando mal implementado -->EX: cria a <pistas> <comprimento> <nome>\n";
            }
        }
    } else if (stringSeparada[0] == "carregap") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadPilotos(stringSeparada[1])) {
                cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
            }
            } else {
            cout << "Numero de argumentos errado!\n";
        }
    } else if (stringSeparada[0] == "carregac") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadCarros(stringSeparada[1])) {
                cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
            }
        } else {
            cout << "Numero de argumentos errado!\n";
        }
    } else if (stringSeparada[0] == "carregaa") {
        if (stringSeparada.size() == 2) {
            if (!comandoLoadAutodromos(stringSeparada[1])) {
                cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
            }
        } else {
            cout << "Numero de argumentos errado!\n";
        }
    } else if (stringSeparada[0] == "apaga") {
        if (stringSeparada[1] == "c") {
            if (stringSeparada[2].size() == 1) {
                if (comandoRemoveCarro(stringSeparada[2])) {
                    cout << "Carro " << stringSeparada[2] << " eliminado!\n";
                } else {
                    cout << "Carro nao existe!\n";
                }
            } else {
                cout << "Id demasiado grande!\n";
            }
        } else if (stringSeparada[1] == "p") {
            aux = juntarNome(stringSeparada, 2);
            if (comandoRemovePiloto(aux)) {
                cout << "Piloto " << aux << " eliminado!\n";
            } else {
                cout << "Piloto " << aux << " nao existe!\n";
            }
        } else if (stringSeparada[1] == "a") {
            if (comandoRemoveAutodromo(stringSeparada[2])) {
                cout << "Autodromo " << stringSeparada[2] << " eliminado!\n";
            } else {
                cout << "Autodromo " << stringSeparada[2] << " nao existe!\n";
            }
        } else {
            cout << "Comando mal escrito!\n";
        }
    } else if (stringSeparada[0] == "entranocarro") {
        if (stringSeparada.size() > 2) {
            int aux;
            aux = comandoEntraNoCarro(stringSeparada);
            switch (aux) {
                case -1:
                    cout << "Piloto nao existe!\n";
                    break;
                case 0:
                    cout << "Carro nao existe!\n";
                    break;
                case 1:
                    cout << "Piloto entrou no carro com sucesso!\n";
            }
        } else {
            cout << "Comando mal escrito! entranocarro <idCarro> <nomePiloto>\n";
        }
    } else if (stringSeparada[0] == "saidocarro") {
        if (dvg->encontraCarro(stringSeparada[1][0])) {
            if (dvg->buscaCarro(stringSeparada[1][0])->getPiloto() != NULL) {
                dvg->buscaCarro(stringSeparada[1][0])->setPiloto(NULL);
            } else {
                cout << "Carro encontra ja se sem piloto!\n";
            }
        } else {
            cout << "Carro nao existe!\n";
        }
    } else if (stringSeparada[0] == "lista") {
        dvg->listarPilotos();
        cout << "---------------------------\n";
        dvg->listarCarros();
        cout << "---------------------------\n";
        camp->mostraAutodromos();
        
    } else if (stringSeparada[0] == "savedgv") {

    } else if (stringSeparada[0] == "loaddvg") {

    } else if (stringSeparada[0] == "deldvg") {

    } else {
        cout << "Este comando nao existe!\n";
    }
}

bool TextUI::leComandosModo2(string comando) {
    vector<string> stringSeparada;
    stringSeparada = separaComando(comando, ' ');
    if (stringSeparada[0] == "fim") {
        return false;
    } else if (stringSeparada[0] == "passatempo") {
        if ( stringSeparada.size() == 2){
            //ESTE COMANDO AUMENTA A POSICAO CONSOANTE A VELOCIDADE/TRAVAGEM
                //para esta 1a meta foi deixado em comentario
            
            comandoPassaTempo(atoi(stringSeparada[1].c_str()));
            mostra_janela_passatempo(atoi(stringSeparada[1].c_str()));
        }else {
            cout << "Comando mal escrito! passatempo <int>\n";
        }
    } else{
        return true;
    }
}

bool TextUI::comandoCampeonato(vector<string> comando) {
    for (int i = 0; i < dvg->getVectorCarros().size(); i++) {
        if (dvg->getVectorCarros()[i].getPiloto() != NULL) {
            camp->addConcorrentes(dvg->buscaCarro(dvg->getVectorCarros()[i].getID()));
        }
    }
    if (camp->getConcorrentes().size() > 1) {
        for (int i = 1; i < comando.size(); i++) {
            if (camp->getPista(comando[i]) != NULL) {
                camp->addAutodromoParaCampeonato(camp->getPista(comando[i]));
            }
        }
        return false;
    } else {
        cout << "Nao existem pilotos para conduzir os carros!\n";
        cout << "Introduza alguns dos pilotos nos carros existentes!\n";
        return true;
    }

}

int TextUI::comandoEntraNoCarro(vector<string> comando) {
    string aux;
    Carro * c;
    if (dvg->encontraCarro(comando[1][0])) {
        aux = juntarNome(comando, 2);
        if (dvg->encontraPiloto(aux)) {
            dvg->buscaCarro(comando[1][0])->setPiloto(dvg->buscaPiloto(aux));
        } else {
            return -1;
        }
    } else {

        return 0;
    }
    return 1;
}

bool TextUI::comandoRemoveCarro(string id) {
    if (!dvg->removeCarro(id[0])) {

        return false;
    }
    return true;
}

bool TextUI::comandoRemovePiloto(string nome) {
    Carro * c = dvg->verSePilotoEstaAoVolante(nome);
    c->setPiloto(NULL);
    if (!dvg->removePiloto(nome)) {
        return false;
    }
    return true;
}

bool TextUI::comandoRemoveAutodromo(string nome) {
    if (!camp->removeAutodromo(nome)) {
        return false;
    }
    return true;
}

bool TextUI::comandoLoadPilotos(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    string aux;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        if (stringSeparada.size() > 2) {
            aux = juntarNome(stringSeparada, 1);
            dvg->addPiloto(Piloto(stringSeparada[0], this->toLower(aux)));
        } else if (stringSeparada.size() == 2) {
            dvg->addPiloto(Piloto(stringSeparada[0], this->toLower(stringSeparada[1])));
        }
    }
    dados.close();
    return true;
}

bool TextUI::comandoLoadCarros(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        dvg->addCarro(Carro(atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str()), atoi(stringSeparada[2].c_str()), stringSeparada[3], stringSeparada[4]));
    }
    dados.close();

    return true;
}

bool TextUI::comandoLoadAutodromos(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');

        cout << stringSeparada[0] << " " << stringSeparada[1] << " " << stringSeparada[2] << endl;
        camp->addAutodromo(Autodromo(atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str()), stringSeparada[2]));
        
        camp->addAutodromo(Autodromo(atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str()), this->toLower(stringSeparada[2])));

    }
    dados.close();

    return true;
}

vector<string> TextUI::separaComando(string comando, char separador) {
    vector<string> stringSeparada;
    stringstream ss;
    ss.str(comando);
    string token;
    while (getline(ss, token, separador)) {
        if (!token.empty()) {

            stringSeparada.push_back(token);
        }
    }
    return stringSeparada;
}

string TextUI::juntarNome(vector<string> nome, int num) {
    for (int i = num; i < nome.size() - 1; i++) {

        nome[num] += ' ';
        nome[num] += nome[i + 1];
    }
    return nome[num];
}

string TextUI::toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string TextUI::toUpper(string str){
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void TextUI::comandoPassaTempo(int passa) {
    for (int i = passa; i > 0; i--) {
        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->passaUmSegundo();
    }
    camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->mostraClassificacaoCorrida();
}

TextUI::~TextUI() {

}