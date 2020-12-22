#ifndef creatTexture_h
#define creatTexture_h
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
SDL_Texture * createTexuterImg(const char * imgPath, SDL_Renderer * renderer, SDL_Texture *texture);
SDL_Texture * createTextureText(const char * text, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);
#endif