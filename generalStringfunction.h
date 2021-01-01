#ifndef generalStringfunction_h
#define generalStringfunction_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int numOfelementCutByPipe(char* str);
char ** initArrayFromStringCutByPipe(char* str, char ** array);
char ** buildCharArray(int numOfLine);
char * getString(int lenghtString);
#endif
