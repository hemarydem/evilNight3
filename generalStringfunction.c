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

char ** initArrayFromStringCutByPipe(char* str, char ** array) {
    int count = 0;
    char * ptrStart = str;
    char * ptrEnd = str;
    int i  = 0;
    printf("\n initArrayFromStringCutByPipe string  = %s\n", str);
    printf("\n---------initArrayFromStringCutByPipe---------\n");
    printf("tail de str = %ld", strlen(str));
    int lenght = strlen(str);
    while (count < lenght) {
      while (*ptrEnd != '|') {
        ptrEnd++;
        count++;
         printf("\nwhile count = %d\n", count);
         printf("\nwhile ptrEnd = %c\n", *ptrEnd);
      }
      *ptrEnd = '\0';
      strcpy(array[i], ptrStart);
      printf("\ncopier %s\n", ptrStart);
      count++;
      if(count < lenght){
        ptrStart = ptrEnd + 1;
        ptrEnd++;}
     /** } else {
        break;
      }*/
      printf("\nce qu'il reste %s\n", ptrStart);
      printf("\ncount = %d\n", count);
      printf("\n ptrEnd = %c\n", *ptrEnd);
      i++;
    }
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