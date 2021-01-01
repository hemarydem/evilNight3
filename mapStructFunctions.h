#ifndef mapStructFunctions_h
#define mapStructFunctions_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "mapStruct.h"
#include "creatTexture.h"
#include "generalStringfunction.h"
firstMapLineNode * initMapList(firstMapLineNode * list, char * LineName,  SDL_Renderer * renderer, int windowWidth);
firstMapLineNode * addMap(firstMapLineNode * list, char * LineName,int windowWidth, SDL_Renderer * renderer);
firstMapLineNode * showMapMenu(firstMapLineNode * list, int cursor, SDL_Renderer * renderer);
firstMapLineNode * positionMapMenu(firstMapLineNode * list, int mapCursor, int *cursorMapWitness, int windowWidth, SDL_Renderer * renderer);
map * getLastMap(firstMapLineNode * list);
firstMapLineNode * suppMenuMapList(firstMapLineNode * list);
int numOfNodeMap(firstMapLineNode * list);
#endif