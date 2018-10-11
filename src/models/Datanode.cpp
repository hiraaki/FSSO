//
// Created by mhi on 18/09/18.
//

#include "Datanode.h"

Datanode::Datanode(char staus) : staus(staus) {

}

char Datanode::getStaus() const {
    return staus;
}

void Datanode::setStaus(char staus) {
    Datanode::staus = staus;
}

const char *Datanode::getData() const {
    return data;
}

unsigned int Datanode::getSector() const {
    return sector;
}

void Datanode::setSector(unsigned int sector) {
    Datanode::sector = sector;
}

string Datanode::getName() {
    return string(data);
}

Datanode::Datanode() {

}

