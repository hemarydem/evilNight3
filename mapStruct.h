#ifndef mapStruct_h
#define mapStruct_h
#include <SDL.h>
struct map{
    char * name;
    int num;
    struct map * next;
    struct map * last;
    SDL_Texture * selcetedBlue;
    SDL_Texture * unselcetedGreen;
    SDL_Rect * spritBlue;
    SDL_Rect * spritGreen;
};
typedef struct map map;

struct firstMapLineNode {
  struct  map *firstMap;
};
typedef struct  firstMapLineNode firstMapLineNode;

#endif