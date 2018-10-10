//
// Created by mhi on 30/09/18.
//

#ifndef FSSO_SAD32_H
#define FSSO_SAD32_H


#include "Datanode.h"
#include "Tabent.h"
#include "Dirnode.h"
#include "BootSad.h"
#include <iostream>
using namespace std;

class SAD16 {
    FILE *device;
    BootSad boot;
    Tabent *fileEntries;
    Tabent *dirEntries;
public:
    FILE *getDevice() const;

    void setDevice(FILE *device);

    const BootSad &getBoot() const;

    void setBoot(const BootSad &boot);

    Tabent *getFileEntries() const;

    void setFileEntries(Tabent *fileEntries);

    Tabent *getDirEntries() const;

    void setDirEntries(Tabent *dirEntries);

    void addFile(FILE *file);
    void addRemovFile(string fileName);
    void addDir(string dirName);
    void removDir(string dirName);
    void adRemovFile(string fileName);
    void formatDevice(unsigned int numbSectors);

};


#endif //FSSO_SAD32_H
