#include "wOrRfreeAndQuit.h"

int quitIfNullW( SDL_Window * win) {
    if(win == NULL) {
        printf("error window initialisation\n");
        return EXIT_FAILURE;
    }
    return 0;
}

int quitIfNullRend(SDL_Renderer * renderer) {
    if(renderer == NULL) {
        printf("error renderer initialisation\n");
        return EXIT_FAILURE;
    }
    return 0;
}

int checkInitLib(int initFunctionReturn) {
    if(initFunctionReturn != 0){
        printf("error initialisation");
        return EXIT_FAILURE;
    }
    return 0;
}

  