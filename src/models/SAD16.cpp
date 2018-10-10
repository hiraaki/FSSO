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

const BootSAD &SAD16::getBoot() const {
    return boot;
}

void SAD16::setBoot(const BootSAD &boot) {
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
    this->boot.setTotalEntries(numbSectors*0.05);
    this->boot.setEntrySize(16);
    this->boot.setErrorForm(1);
    this->boot.setErrorHead(0);
    this->boot.setErrorSector(0);
//    fseek(this->device,0,SEEK_SET);
//    fwrite(&this->boot, 16 ,1,this->device);
//    fseek(this->device,0,SEEK_SET);
//    cout<<this->boot<<endl;
//    BootSAD aux;
//    cout<<aux<<endl;
//    fread(&aux, sizeof(BootSAD),1,this->device);
//    cout<<aux<<endl;
    FILE *disk = this->device;
    cout<<"------------------------------------------------------"<<endl;
    fseek(disk, 0, SEEK_SET);
    unsigned short a= this->boot.getSectorSize();
    fwrite(&a,2,1,disk);
    fseek(disk, 0, SEEK_SET);
    unsigned short b;
    fread(&b,2,1,disk);
    cout<<a<<endl;
    cout<<b<<endl;


}