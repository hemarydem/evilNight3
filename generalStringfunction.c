#include "generalStringfunction.h"

int numOfelementCutByPipe(char* str) {
    int count;
    int i = 0;
    printf("\n number of element string  = %s\n", str);
    while(i < strlen(str)) {
        if(str[i] == '|') count++;
        i++;
    }
    printf("\n numOfelementCutByPipe = %d\n", count);
    return count;
}



char ** buildCharArray(int numOfLine) {
  char ** array = NULL;
  int i;
  array = malloc(sizeof(char*) * numOfLine);
  if(array != NULL) {
    for (i = 0; i < numOfLine; i++) {
      array[i] = malloc(sizeof(char) * 50);// bloquer le nom des maps a 100 char
      printf("\ni = %d\n", i);
    if (array[i] == NULL) {
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
    if(array != NULL)printf("OUILLE");
    return array;
  }
  printf("\n error \n  buildArrayMaplist \n");
  return array = NULL;
}