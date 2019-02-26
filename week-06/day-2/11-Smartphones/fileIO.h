//
// Created by Egri Zoltán on 2019. 02. 26..
//

#ifndef INC_11_SMARTPHONES_FILEIO_H
#define INC_11_SMARTPHONES_FILEIO_H

#include <stdio.h>
#include <string.h>
#include "phoneRegister.h"

int countLines(const char* filename);
void loadPhones(const char* filename, smartphone_t* phones, int numOfPhones);
void generatePriceList(const char* filename, smartphone_t* phones, int numOfPhones);

#endif //INC_11_SMARTPHONES_FILEIO_H
