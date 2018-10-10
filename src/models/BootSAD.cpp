//
// Created by MHI on 10/10/2018.
//

#include "BootSAD.h"

unsigned short BootSAD::getSectorSize() const {
    return sectorSize;
}

void BootSAD::setSectorSize(unsigned short sectorSize) {
    BootSAD::sectorSize = sectorSize;
}

unsigned int BootSAD::getTotalEntries() const {
    return totalEntries;
}

void BootSAD::setTotalEntries(unsigned int totalEntries) {
    BootSAD::totalEntries = totalEntries;
}

unsigned char BootSAD::getEntrySize() const {
    return entrySize;
}

void BootSAD::setEntrySize(unsigned char entrySize) {
    BootSAD::entrySize = entrySize;
}

unsigned char BootSAD::getErrorForm() const {
    return errorForm;
}

void BootSAD::setErrorForm(unsigned char errorForm) {
    BootSAD::errorForm = errorForm;
}

unsigned int BootSAD::getErrorHead() const {
    return errorHead;
}

void BootSAD::setErrorHead(unsigned int errorHead) {
    BootSAD::errorHead = errorHead;
}

unsigned int BootSAD::getErrorSector() const {
    return errorSector;
}

void BootSAD::setErrorSector(unsigned int errorSector) {
    BootSAD::errorSector = errorSector;
}
