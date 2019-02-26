//
// Created by Egri Zoltán on 2019. 02. 26..
//

#ifndef INC_07_PRINT_EACH_LINE_WRITEFILE_H
#define INC_07_PRINT_EACH_LINE_WRITEFILE_H

#include <stdio.h>

void createLorem(const char* filename, FILE* filePointer)
{
    filePointer = fopen(filename, "w");
    fputs("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
          "Maecenas rhoncus consectetur iaculis.\n"
          "Maecenas rhoncus elit velit, vitae ultrices augue porttitor ac.\n"
          "Etiam tincidunt quam sit amet risus volutpat finibus.\n"
          "Nunc ac luctus erat, eleifend mattis nulla.\n"
          "Etiam pulvinar ultrices diam, vel bibendum lectus pellentesque pellentesque.\n"
          "Aenean sollicitudin fermentum velit, quis.", filePointer);
    fclose(filePointer);
}

#endif //INC_07_PRINT_EACH_LINE_WRITEFILE_H
