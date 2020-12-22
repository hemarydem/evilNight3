//skype the line
//by remy Hamed and Léo Perochon
//gcc *.c -o test.app $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "wOrRfreeAndQuit.h"
#include "creatTexture.h"
#include "menuStrucfunction.h"
#include "menuStructcur.h"
#include "generalStringfunction.h"
#define WINDOW_WIDTH (620)
#define WINDOW_HEIGHT (440)

int main(int argc, char ** argv) {
    /////////////////////////////////
    /*    SDLfundamental variable  */
    /////////////////////////////////    
    SDL_Window * win = NULL;
    SDL_Renderer * renderer = NULL;
    /////////////////////////////////
    /*    menu variable            */
    /////////////////////////////////
    //graphique
    SDL_Texture * backgroundTexture;
    SDL_Rect backgroundRect;
    firstmenuLineNode * list;
    list = malloc(sizeof(firstmenuLineNode));
    //interaction
    int cursor = 1;
    int menuOption[7] = { // array work as a boolean in animation loop
    1,      //menu 
    0,      //mapSelector
    0,      //jvj
    0,      //online
    0,      //editor
    0,      //option
    0       //quit
    };
    /////////////////////////////////
    /*    animation loop variable  */
    /////////////////////////////////
    int finish  = 1;
    /////////////////////////////////
    /*          init lib           */
    /////////////////////////////////     
    checkInitLib(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER));
    checkInitLib(TTF_Init());
    win  = SDL_CreateWindow("Skip the Line",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH, WINDOW_HEIGHT,0);
    quitIfNullW(win);  
    renderer = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED);
    quitIfNullRend(renderer);
    /////////////////////////////////
    /*     init menu texure        */
    /////////////////////////////////
    backgroundTexture = createTexuterImg("img/bckgrndMenu.jpg", renderer, backgroundTexture);
    SDL_QueryTexture(backgroundTexture,NULL,NULL, &backgroundRect.w, &backgroundRect.h);
    list = initList(list,"MENU", renderer, WINDOW_WIDTH);
    list = addMenuLine(list,"jvj",renderer);
    list = addMenuLine(list,"online",renderer); 
    list = addMenuLine(list,"editor",renderer); 
    list = addMenuLine(list,"option",renderer); 
    list = addMenuLine(list,"quit",renderer);
    /////////////////////////////////
    /*     animation loop          */
    /////////////////////////////////   
    while (finish) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            //if(event.type == SDL_QUIT) {
            //    finish = 1;
            //}
            printf("3 A\n");
            switch (event.type) {
                case SDL_QUIT:
                    finish = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_RETURN:
                            printf("entrer\n");
                            if (cursor == 6) cursor = 1;
                            if (cursor == 0) cursor = 5;
                            menuOption[cursor]= 1;
                            menuOption[0]= 0;
                            break;
                        case SDLK_DOWN:
                            ++cursor;
                            printf("bas\n");
                            break;
                        case SDLK_UP:
                            --cursor;
                            printf("haut\n");
                            break;
                    }
                break;
            }
        }
        if (cursor == 6) cursor = 1;
        if (cursor == 0) cursor = 5;
        SDL_RenderClear(renderer);
        if(menuOption[0]) {
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            showMenu(list, cursor, renderer);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}