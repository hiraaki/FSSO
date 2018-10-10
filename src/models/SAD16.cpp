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
    FILE *disk = this->device;
    cout<<"------------------------------------------------------"<<endl;
    char buffer[512];
    fseek(disk, 0, SEEK_SET);
//    fread(buffer, sizeof(char), sizeof(buffer),disk);
//    for(int i=0;i<512;i++){
//        printf("%x ", buffer[i]);
//    }
//    cout<<"------------------------------------------------------"<<endl;
//    fseek(disk, 0, SEEK_SET);
//    unsigned short int dumb=0;

//    fseek(disk, 0, SEEK_SET);
//    fread(buffer, sizeof(char), sizeof(buffer),disk);
    fread(buffer, sizeof(char), sizeof(buffer),disk);
    for(int i=0;i<512;i++){
        printf("%x ", buffer[i],i);
    }
    cout<<endl<<"------------------------------------------------------"<<endl;
    fseek(disk, 0, SEEK_SET);
//    fwrite(&this->boot, sizeof(BootSAD),1,disk);
    unsigned long int dumb= 0;
    for (int i = 0; i < 512;i++) {
        fwrite(&dumb, sizeof(long),1,disk);
    }
    fseek(disk, 0, SEEK_SET);
    fread(buffer, sizeof(char), sizeof(buffer),disk);
    for(int i=0;i<512;i++){
        printf("%x ", buffer[i],i);
    }

}