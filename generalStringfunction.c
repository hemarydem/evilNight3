#include "generalStringfunction.h"

int numOfelementCutByPipe(char* str) {
    int count = 0;
    int i = 0;
    printf("\n number of element string  = %s\n", str);
    while(i < strlen(str)) {
        if(str[i] == '|') count++;
        i++;
    }
    printf("\n numOfelementCutByPipe = %d\n", count);
    return count;
}

char ** initArrayFromStringCutByPipe(char* str, char ** array, int numofmap) {
  int i = 0;
  char * delim;
  delim = malloc(sizeof(char) * 2);
  strcpy(delim,"|");
  char *ptr = strtok(str, delim);
  while(ptr != NULL) {
    if(i >= numofmap) {
        printf("fin\n");
        free(delim);
        for (int k = 0; k < numofmap; k++) {
          printf("array[%d] = %s\n", k,array[k]);
        }
        return array;
    }
    printf("'%s'\n", ptr);
    strcpy(array[i],ptr);
    //printf("array[i] =%s\n", i,array[i]);
    i++;
    ptr = strtok(NULL, delim);
  }
  free(delim);
   return array;
}


char ** buildCharArray(int numOfLine) {
  char ** array = NULL;
  int i;
  array = malloc(sizeof(char*) * numOfLine);
  if(array != NULL) {
    for (i = 0; i < numOfLine; i++) {
      array[i] = malloc(sizeof(char) * 50);// bloquer le nom des maps a 100 char
      printf("\ni = %d\n", i);
    if(array[i] == NULL) {
        int j = 0;
        while (j < i) {
          free(array[i]);
          j++;
        }
        free(array);
        printf("error malloc\n buildArrayMaplist\n");
        return array= NULL;
      }
    }
    printf("\nbuildCharArray ok\n");
    if(array == NULL)printf("array is NULL");
    return array;
  }
  printf("\n error \n  buildArrayMaplist \n");
  return array = NULL;
}

char * getString(int lenghtString) {
  char *  str;
  str = malloc(sizeof(char) * lenghtString);
  if(str != NULL) return str;
  printf("\n getString error malloc\n");
  return str;
}