//
// Created by mhi on 18/09/18.
//

#include <ostream>
#ifndef FSSO_TABENT_H
#define FSSO_TABENT_H

struct __attribute__ ((__packed__)) totalSize
{
    char alinhamento[3];
    unsigned int numero;
};


/*
 * Entrada de tabela (arquivo/diretório)
 */
class __attribute__ ((__packed__)) Tabent {

private:
    char status; // 4bits altos arquivo/diretório, 4 bits baixos (uso ou vazio)
    struct totalSize totalSize1; // tamanho total da pasta ou do arquivo
    short int losize; //
    unsigned int sector; //Setor do cabeçalho do arquivo
    char hora; // Hora da criação/escrita do arquvo/diretório
    char minuto;
    char dia; // Data da criação/escrita do arquvo/diretório
    char mes;

public:
    Tabent();

    char getStatus() const;

    void setStatus(char status);

    short getLosize() const;

    void setLosize(short losize);

    unsigned int getSector() const;

    void setSector(unsigned int sector);

    void criaRoot();

    unsigned int getTotalSize1();

    void setTotalSize1(unsigned int tam);

    char getHora() const;

    void setHora(char hora);

    char getMinuto() const;

    void setMinuto(char minuto);

    char getDia() const;

    void setDia(char dia);

    char getMes() const;

    void setMes(char mes);

    friend std::ostream &operator<<(std::ostream &os, const Tabent &tabent);
};


#endif //FSSO_TABENT_H
