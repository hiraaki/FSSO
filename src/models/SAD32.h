//
// Created by mhi on 30/09/18.
//

#ifndef FSSO_SAD32_H
#define FSSO_SAD32_H


#include "Datanode.h"
#include "Tabent.h"

class SAD32 {
    Tabent *fileEntry;
    Tabent *dirEntry;
public:
    Tabent *getFileEntry();
    void setFileEntry(Tabent *entry);
    Tabent *getdirEntry();
    void setdirEntry(Tabent *entry);
    void *formatDevice(unsigned int *numbSectors,FILE *device);
    void *addFile(unsigned int *numbSectors,FILE *device);
    void *getFile(unsigned int *numbSectors,FILE *device);
    void *removFile(unsigned int *numbSectors,FILE *device);
    void *addDir(unsigned int *numbSectors,FILE *device);
    void *getDir(unsigned int *numbSectors,FILE *device);
    void *removDir(unsigned int *numbSectors,FILE *device);


};


#endif //FSSO_SAD32_H
