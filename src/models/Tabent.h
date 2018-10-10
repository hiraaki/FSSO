//
// Created by mhi on 18/09/18.
//

#ifndef FSSO_TABENT_H
#define FSSO_TABENT_H

/*
 * Entrada de tabela (arquivo/diretório)
 */
class __attribute__ ((__packed__)) Tabent {

private:
    char status; // 4bits altos arquivo/diretório, 4 bits baixos (uso ou vazio)
    unsigned int hisize; // tamanho total da pasta ou do arquivo
    short int losize; //
    unsigned int sector; //Setor do cabeçalho do arquivo
    short int time; // Hora da criação/escrita do arquvo/diretório
    short int date; // Data da criação/escrita do arquvo/diretório

public:
    Tabent();

    Tabent(char status, unsigned int hisize, short losize, unsigned int sector, short time, short date);

    char getStatus() const;

    void setStatus(char status);

    unsigned int getHisize() const;

    void setHisize(unsigned int hisize);

    short getLosize() const;

    void setLosize(short losize);

    unsigned int getSector() const;

    void setSector(unsigned int sector);

    short getTime() const;

    void setTime(short time);

    short getDate() const;

    void setDate(short date);




};


#endif //FSSO_TABENT_H
