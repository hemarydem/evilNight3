#include "coordo.h"

int isSamePosition(int newPositionX, int newPositionY, int * arrayLastPosition) {
    if(newPositionX == arrayLastPosition[0] && newPositionX == arrayLastPosition[1]) {
        printf("\nn'a pas bouger\n");
        return 1;
    } else { 
        printf("\nbouge\n");
        return 0;
    }
}

int positionIsBeforeX(int position, int xSafeLimit ) {
    if(position < xSafeLimit) return 1;
    return 0;
}

