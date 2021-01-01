#include "arrayInt.h"

int * oneAndAlltoZero(int * cursor, int * array, int size, int * chargeMapMenu) {
    int i = 0;
    while (i < size) {
        array[i] = 0;
        i++;
    }
    if(!chargeMapMenu) {
        creatGAMEPLAYFile(cursor);
        array[7] = 1;
        return array;
    }
    array[*cursor] = 1;
    // NOTE supprimer la boucle  qui montre le tableau après vérification 
     while (i < size) {
        printf("\noneAndAlltoZero\n array[%d] = %d\n" , i, array[i]);
    }
    return array;
}