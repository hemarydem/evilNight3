#ifndef pointTraceFonction_h
#define pointTraceFonction_h
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "pointTrace.h"
#include "creatTexture.h"
firstPointNode * initListPoint(firstPointNode * list,  SDL_Renderer * renderer);
firstPointNode * addPoint(firstPointNode * list, int x, int y,SDL_Renderer * renderer);
firstPointNode * suppPoints(firstPointNode * list);
firstPointNode * showPoints(firstPointNode * list, SDL_Renderer * renderer);
#endif