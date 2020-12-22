#ifndef menuStructcur_h
#define menuStructcur_h
#include <SDL.h>
struct menuLine{
    char * name;
    int num;
    struct menuLine * next;
    struct menuLine * last;
    SDL_Texture * selcetedBlue;
    SDL_Texture * unselcetedGreen;
    SDL_Rect * spritBlue;
    SDL_Rect * spritGreen;
};
typedef struct menuLine menuLine;

struct firstmenuLineNode {
  struct  menuLine *firstMap;
};
typedef struct  firstmenuLineNode firstmenuLineNode;
#endif