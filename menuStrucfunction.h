#ifndef menuStrucfunction_h
#define menuStrucfunction_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "menuStructcur.h"
#include "creatTexture.h"
#include "generalStringfunction.h"
firstmenuLineNode * initList(firstmenuLineNode * list, char * LineName,  SDL_Renderer * renderer, int windowWidth);
firstmenuLineNode * addMenuLine(firstmenuLineNode * list, char * LineName, SDL_Renderer * renderer);
firstmenuLineNode * suppMenuLineList(firstmenuLineNode * list, char * LineName);
menuLine * getLastMenuLine(firstmenuLineNode * list);
firstmenuLineNode * mulityAddMenuLine(firstmenuLineNode * list, int nbElementToAdd, SDL_Renderer * renderer);
firstmenuLineNode * giveNameforMenuList(firstmenuLineNode * list, char * string);
firstmenuLineNode * showMenu(firstmenuLineNode * list, int cursor, SDL_Renderer * renderer);
#endif