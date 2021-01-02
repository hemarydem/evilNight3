#include "generalFileFonction.h"

int fileExitste(char * fileName) {
    printf("\nfileExitste\n");
    if( access(fileName, F_OK ) == 0 ) {
        printf("\nfile exists\n");
        return 1;// file exists
    } else {
        printf("\nfile doesn't exist\n");
        return 0;// file doesn't exist
    }
}

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

char * getDataFromFile(char * filename) {
    printf("\ngetDataFromFile\n");
    FILE * f;
    char * dataString;
    if(fileExitste(filename)) {
        f = fopen(filename, "rb");
        printf("\nfichier exist and is open by getDataFromFile\n");
    } else {
       resetFile(filename);
       return "defaultMap|";
    }
    if(f != NULL) {
        printf("\n f != NULL is true\n");
        size_t size = sizeOfFile(filename);
        dataString = malloc (sizeof(char) * size);
        fread(dataString, sizeof(char),  size, f);
        printf("\ndata string from getDataFromFile = %s\n", dataString);
        return dataString;
    } else {
        printf("getDataFromFile\nerror fopen()\n");
        return dataString;
    }
}

void resetFile(char * filename) {
    FILE * f;
    f = fopen(filename, "wb");
    if(f != NULL) {
        char * mDefaultList;
        mDefaultList = malloc(sizeof(char) * 12);
        strcpy(mDefaultList, "defaultMapv");
        fprintf(f,"%s", "defaultMap1|defaultMap2|defaultMap3|defaultMap4|defaultMap5|FIN|");
        fclose(f);
        free(mDefaultList);
    } else { 
        printf("\n ERROR malloc in reset file\n");
    }
}

void creatGAMEPLAYFile(int cursor) { // curso is the num of the map
    FILE * f;
    f = fopen("GAMEPLAY", "wb");
    if(f != NULL) {
        fprintf(f,"%d",cursor);
        fclose(f);
    } else { 
        printf("\n ERROR malloc in reset file\n");
    }
    printf("\n SUCCES creatGAMEPLAYFile\n");
}
//void getandCreatGAMPLAYFile(int *cursor, int *chargeMapMenu) {}