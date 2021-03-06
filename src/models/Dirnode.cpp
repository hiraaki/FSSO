//
// Created by mhi on 18/09/18.
//

#include <cstring>
#include "Dirnode.h"

Dirnode::Dirnode() : staus(staus) {

}

char Dirnode::getStaus() const {
    return staus;
}

void Dirnode::setStaus(char staus) {
    Dirnode::staus = staus;
}

const char *Dirnode::getData() const {
    return data;
}

unsigned int Dirnode::getSector() const {
    return sector;
}

void Dirnode::setSector(unsigned int sector) {
    Dirnode::sector = sector;
}

string Dirnode::getName(){
    return string(data);
}

void Dirnode::setData(string banana) {
    strncpy(data, banana.c_str(), sizeof(data));
}