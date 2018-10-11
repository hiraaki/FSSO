//
// Created by mhi on 18/09/18.
//

#include "Tabent.h"

Tabent::Tabent() {

}


char Tabent::getStatus() const {
    return status;
}

void Tabent::setStatus(char status) {
    Tabent::status = status;
}


short Tabent::getLosize() const {
    return losize;
}

void Tabent::setLosize(short losize) {
    Tabent::losize = losize;
}

unsigned int Tabent::getSector() const {
    return sector;
}

void Tabent::setSector(unsigned int sector) {
    Tabent::sector = sector;
}


void Tabent::criaRoot() {

}

unsigned int Tabent::getTotalSize1(){
    return totalSize1.numero;
}

void Tabent::setTotalSize1(unsigned int tam) {
    totalSize1.numero=tam;
    totalSize1.alinhamento[0]=0;
    totalSize1.alinhamento[1]=0;
    totalSize1.alinhamento[2]=0;
}

char Tabent::getHora() const {
    return hora;
}

void Tabent::setHora(char hora) {
    Tabent::hora = hora;
}

char Tabent::getMinuto() const {
    return minuto;
}

void Tabent::setMinuto(char minuto) {
    Tabent::minuto = minuto;
}

char Tabent::getDia() const {
    return dia;
}

void Tabent::setDia(char dia) {
    Tabent::dia = dia;
}

char Tabent::getMes() const {
    return mes;
}

void Tabent::setMes(char mes) {
    Tabent::mes = mes;
}

std::ostream &operator<<(std::ostream &os, const Tabent &tabent) {
    os << "status: " << tabent.status << " totalSize1: " << tabent.totalSize1.numero << " losize: " << tabent.losize
       << " sector: " << tabent.sector << " hora: " << tabent.hora << " minuto: " << tabent.minuto << " dia: "
       << tabent.dia << " mes: " << tabent.mes;
    return os;
}
