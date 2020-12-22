#include "generalFileFonction.h"

long sizeOfFile(const char * filename) {
    FILE *f = fopen(filename, "ab");
    if(f != NULL) {
        long size;
        fseek(f, 0, SEEK_END);
        size = ftell(f);
        printf("\n size   = %ld\n", size);
        fclose(f);
        return size;
    }
    return -1;
}//fstat();