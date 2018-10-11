//
// Created by mhi on 30/09/18.
//

#include "SAD16.h"
#include "BootSAD.h"
#include <stdio.h>
#include <ctime>

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
    this->boot.setTotalEntries((numbSectors*0.05)+1);
    this->boot.setEntrySize(16);
    this->boot.setErrorForm(1);
    this->boot.setErrorHead(0);
    this->boot.setErrorSector(0);
    FILE *disk = this->device;

    //cout<<"------------------------------------------------------"<<endl;
    //char buffer[512];
    fseek(disk, 0, SEEK_SET);


//PURIFICAÇÃO DO ABIGUINHO


    int i,j;

    char dumb=0;

    //Limpar completamente o pendrive
    //cout << boot.getTotalEntries() << " cansei\n";

    for(i=0;i<this->boot.getTotalEntries();i++){
        for(j=0;j<512;j++){
            fwrite(&dumb, sizeof(dumb),1,disk);
        }
    }

    //Escreve o boot
    fwrite(&this->boot,sizeof(BootSAD),1,disk);

    //Agora vamos criar a tabela de entradas

    fseek(disk, 0, SEEK_SET); // volta pro início
    fseek(disk, 16, SEEK_SET); // depois do boot record

    time_t timer;
    struct tm *horarioLocal;
    time(&timer); // Obtem informações de data e hora
    horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

    Tabent entradaRoot;
    entradaRoot.setStatus(240);
    entradaRoot.setTotalSize1(1);
    entradaRoot.setSector(1); //primeiro setor da área de dados é o root
    entradaRoot.setHora(horarioLocal->tm_hour);
    entradaRoot.setMinuto(horarioLocal->tm_min);
    entradaRoot.setDia(horarioLocal->tm_mday);
    entradaRoot.setMes(horarioLocal->tm_mon + 1);

    fwrite(&entradaRoot,sizeof(entradaRoot),1,disk);


//    printf("status: %x",entradaRoot.getStatus());
//    printf("tamanho: %x",entradaRoot.getTotalSize1());
//    printf("setor: %x",entradaRoot.getSector());
//    printf("hora: %x",entradaRoot.getHora());
//    printf("min: %x",entradaRoot.getMinuto());
//    printf("dia: %x",entradaRoot.getDia());
//    printf("mes: %x",entradaRoot.getMes());


    //Agora vamos mexer na partição de dados
    fseek(disk, 16+(boot.getTotalEntries()*16), SEEK_SET);

    Dirnode dirnode, dirnode2;

    dirnode.setStaus(85);
    dirnode.setSector(2);
    dirnode.setData("root");

    fwrite(&dirnode,sizeof(dirnode),1,disk);

    fseek(disk, 512+16+(boot.getTotalEntries()*16), SEEK_SET);

    dirnode2.setStaus(85);
    dirnode2.setSector(0);

    fwrite(&dirnode2,sizeof(dirnode2),1,disk);





    //APENAS PARA DEBUG
    fseek(disk, 0, SEEK_SET);
    BootSAD aux;
    fread(&aux, sizeof(BootSAD),1,disk);

    fseek(disk, 16, SEEK_SET); // depois do boot record

    Tabent entradaRoot1;

    fread(&entradaRoot1, sizeof(entradaRoot1),1,disk);

//    printf("status: %x ",entradaRoot1.getStatus());
//    printf("tamanho: %x ",entradaRoot1.getTotalSize1());
//    printf("setor: %x ",entradaRoot1.getSector());
//    printf("hora: %x ",entradaRoot1.getHora());
//    printf("min: %x ",entradaRoot1.getMinuto());
//    printf("dia: %x ",entradaRoot1.getDia());
//    printf("mes: %x ",entradaRoot1.getMes());

    //cout << aux;
    //fread(buffer, sizeof(char), sizeof(buffer),disk);
//    for(int i=0;i<512;i++){
//        printf("%x ", buffer[i],i);
//    }

    char aleatorio;

//    while (getchar() != EOF){
//      fread(&aleatorio, sizeof(char), 1,disk);
//        printf("%x ", aleatorio);
//    }

//    for(i=0;i<this->boot.getTotalEntries();i++){
//        for(j=0;j<512;j++){
//            fread(&aleatorio, sizeof(char), 1,disk);
//            printf("%x ", aleatorio);
//        }
//    }

}

void SAD16::listar() {

    FILE *disk = this->device;

}