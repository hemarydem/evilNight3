#ifndef pointTrace_h
#define pointTrace_h
#include <SDL.h>
struct point{
    int num;
    struct point * next;
    SDL_Texture * pointTexure;
    SDL_Rect * spritePoint;
};
typedef struct point point;

struct firstPointNode {
  struct  point * Fpoint;
};
typedef struct  firstPointNode firstPointNode;
#endif