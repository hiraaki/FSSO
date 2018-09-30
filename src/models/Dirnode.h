//
// Created by mhi on 18/09/18.
//

#ifndef FSSO_DIRNODE_H
#define FSSO_DIRNODE_H
#include "Tabent.h"
#include <string>
using namespace std;
class __attribute__ ((__packed__)) Dirnode {
    char staus; //setor vazio/cheio
    char data[507]; // Caso pirmeiro nodo da cadeia de byte é nome do diretório, se não é referência de arqivo/diretório
    unsigned int sector; // proximo setor a ser lido, caso 0 ultimo setor
public:
    unsigned int *getref(); //retorna multiplas referẽncias
    string getName(); //retorna o nome
    unsigned int getProxsector(); //pegar proximo setor
    void addref(unsigned int ref); //retorna multiplas referẽncias
    void setName(string name); //retorna o nome
    void setProxsector(unsigned int sector); //pegar proximo setor
};


#endif //FSSO_DIRNODE_H
