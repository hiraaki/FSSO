//
// Created by mhi on 18/09/18.
//

#ifndef FSSO_TABENT_H
#define FSSO_TABENT_H

/*
 * Entrada de tabela (arquivo/diretório)
 */
class __attribute__ ((__packed__)) Tabent {
    char status; // 4bits altos arquivo/diretório, 4 bits baixos (uso ou vazio)
    unsigned int hisize; // tamanho total da pasta ou do arquivo
    short int losize; //
    unsigned int sector; //Setor do cabeçalho do arquivo
    short int time; // Hora da criação/escrita do arquvo/diretório
    short int date; // Data da criação/escrita do arquvo/diretório
public:

};


#endif //FSSO_TABENT_H
