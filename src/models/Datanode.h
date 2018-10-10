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
    Datanode(char staus);

    string getName(); //retorna o nome

    char getStaus() const;

    void setStaus(char staus);

    const char *getData() const;

    unsigned int getSector() const;

    void setSector(unsigned int sector);
    //pegar proximo setor
};
#endif //FSSO_DATANODE_H
