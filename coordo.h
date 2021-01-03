#ifndef coordo_h
#define coordo_h
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
int isSamePosition(int newPositionX, int newPositionY, int * arrayLastPosition);
int positionIsBeforeX(int position, int xSafeLimit );
#endif