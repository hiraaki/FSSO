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
    Dirnode(char staus);

    unsigned int *getref(); //retorna multiplas referẽncias

    string getName(); //retorna o nome

    void addref(unsigned int ref); // adiciona referencias

    char getStaus() const;

    void setStaus(char staus);

    const char *getData() const;

    unsigned int getSector() const;

    void setSector(unsigned int sector);

};


#endif //FSSO_DIRNODE_H
