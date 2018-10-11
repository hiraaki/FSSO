//
// Created by MHI on 10/10/2018.
//

#ifndef FSSO_BOOTSAD_H
#define FSSO_BOOTSAD_H


#include <ostream>

class BootSAD {
    unsigned short int sectorSize;
    unsigned int totalEntries; // dado em setores, cada setor 512 bytes
    unsigned char entrySize;
    unsigned char errorForm;
    unsigned int errorHead;
    unsigned int errorSector;
public:
    unsigned short getSectorSize() const;

    void setSectorSize(unsigned short sectorSize);

    unsigned int getTotalEntries() const;

    void setTotalEntries(unsigned int totalEntries);

    unsigned char getEntrySize() const;

    void setEntrySize(unsigned char entrySize);

    unsigned char getErrorForm() const;

    void setErrorForm(unsigned char errorForm);

    unsigned int getErrorHead() const;

    void setErrorHead(unsigned int errorHead);

    unsigned int getErrorSector() const;

    void setErrorSector(unsigned int errorSector);

    friend std::ostream &operator<<(std::ostream &os, const BootSAD &sad);
};


#endif //FSSO_BOOTSAD_H
