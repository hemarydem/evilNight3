#include "creatTexture.h"

SDL_Texture * createTexuterImg(const char * imgPath, SDL_Renderer * renderer, SDL_Texture *texture) {
    SDL_Surface * surface;
    surface = IMG_Load(imgPath);
    if(!surface) {
        printf("\nERROR BUILD SURFACE");
        return NULL;
    }
    SDL_SetColorKey(surface, 1,SDL_MapRGB(surface->format, 255, 255, 255));
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture * createTextureText(const char * text, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont(fontFile, fontSize);						//Open the font
    if (font == NULL) {
        printf("error\n TTF_OpenFont for %s \n", text);
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return NULL;
    }
    SDL_Surface *surf = TTF_RenderText_Blended(font, text , color); 		//We need to first render to a surface as that's what TTF_RenderText
    if (surf == NULL) {														//returns, then load that surface into a texture
        TTF_CloseFont(font);		
        printf("error\n TTF_RenderText\n");
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == NULL) {
        printf("error\n CreateTextureFromSurface\n");
    }
    SDL_FreeSurface(surf); 													//Clean up the surface and font
    TTF_CloseFont(font);
    return texture;
}