#ifndef wOrRfreeAndQuit_h
#define wOrRfreeAndQuit_h
#include <SDL.h>
#endif

int quitIfNullW( SDL_Window * win);         //check window init

int quitIfNullRend(SDL_Renderer * renderer); //check renderer init

int checkInitLib(int initFunctionReturn);   ////check lib init