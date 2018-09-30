//
// Created by mhi on 18/09/18.
//

#ifndef FSSO_DATANODE_H
#define FSSO_DATANODE_H

/*
  * Area de dados
 * Classe para dados de arquivo
 * Setor
 */
#include <string>
using namespace std;
class __attribute__ ((__packed__)) Datanode {
    char staus; //setor vazio/cheio
    char data[507]; // Caso pirmeiro nodo da cadeia de byte é nome do arquivo, se não dado do arqivo
    unsigned int sector; // proximo setor a ser lido, caso 0 ultimo setor
public:
    unsigned int *getBytes(); //retorna multiplas referẽncias
    string getName(); //retorna o nome
    unsigned int getProxSector(); //pegar proximo setor
    void setBytes(unsigned int *bytes); //retorna multiplas referẽncias
    void setName(string name); //retorna o nome
    void getProxSector(unsigned int proxSector); //pegar proximo setor
};
#endif //FSSO_DATANODE_H
