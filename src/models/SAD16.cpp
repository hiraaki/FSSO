//
// Created by mhi on 30/09/18.
//

#include "SAD16.h"

FILE *SAD16::getDevice() const {
    return device;
}

void SAD16::setDevice(FILE *device) {
    SAD16::device = device;
}

const BootSad &SAD16::getBoot() const {
    return boot;
}

void SAD16::setBoot(const BootSad &boot) {
    SAD16::boot = boot;
}

Tabent *SAD16::getFileEntries() const {
    return fileEntries;
}

void SAD16::setFileEntries(Tabent *fileEntries) {
    SAD16::fileEntries = fileEntries;
}

Tabent *SAD16::getDirEntries() const {
    return dirEntries;
}

void SAD16::setDirEntries(Tabent *dirEntries) {
    SAD16::dirEntries = dirEntries;
}

void SAD16::formatDevice(unsigned int numbSectors) {
    this->boot.setSectorSize(512);
    this->boot.setTotalEntryes(numbSectors*0.05);
    this->boot.setEntrySize(16);
    this->boot.setFormatError(1);
    this->boot.setErrorHeader(0);
    this->boot.setErrorSector(0);
    fseek(this->device,0,SEEK_SET);
    fwrite(&this->boot, sizeof(BootSad),1,this->device);
    fseek(this->device,0,SEEK_SET);
    BootSad aux;
    fread(&aux, sizeof(BootSad),1,this->device);
    cout<<aux;

}