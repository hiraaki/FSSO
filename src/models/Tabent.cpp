//
// Created by mhi on 18/09/18.
//

#include "Tabent.h"

Tabent::Tabent() {

}

Tabent::Tabent(char status, unsigned int hisize, short losize, unsigned int sector, short time, short date) : status(
        status), hisize(hisize), losize(losize), sector(sector), time(time), date(date) {

}

char Tabent::getStatus() const {
    return status;
}

void Tabent::setStatus(char status) {
    Tabent::status = status;
}

unsigned int Tabent::getHisize() const {
    return hisize;
}

void Tabent::setHisize(unsigned int hisize) {
    Tabent::hisize = hisize;
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

short Tabent::getTime() const {
    return time;
}

void Tabent::setTime(short time) {
    Tabent::time = time;
}

short Tabent::getDate() const {
    return date;
}

void Tabent::setDate(short date) {
    Tabent::date = date;
}
