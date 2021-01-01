#ifndef generalFileFonction_h
#define generalFileFonction_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
long sizeOfFile(const char * filename);
int fileExitste(char * fileName);
void resetFile(char * filename); 
char * getDataFromFile(char * filename);
void creatGAMEPLAYFile(int cursor);
#endif

