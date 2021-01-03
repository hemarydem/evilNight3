//skype the line
//by remy Hamed and Léo Pérochon
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
#include "generalFileFonction.h"
#include "mapStruct.h"
#include "mapStructFunctions.h"
#include "arrayInt.h"
#include "pointTrace.h"
#include "pointTraceFonction.h"
#include "coordo.h"
#define WINDOW_WIDTH (620)
#define WINDOW_HEIGHT (440)
#define MENU_OPTION_SIZE (7)
#define SPEED (600)

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
    int exitIng = 5;
    int menuOption[7] = { // array work as a boolean in animation loop
        1,      //menu          =>  0
        0,      //jvj           =>  2
        0,      //online        =>  3
        0,      //editor        =>  4
        0,      //option        =>  5
        0,      //quit          =>  6
        0       //GAMPLAY       =>  7
    };
    /////////////////////////////////
    /*    mapSelector menu         */
    /////////////////////////////////
    int mapCursor = 1;
    int cursorMapWitness = 1;
    char * fileDataString;
    int numOfMaps = 0;
    char ** arrayNameOfMaps;
    firstMapLineNode * listMaps;
    listMaps = malloc(sizeof(firstMapLineNode));
    int chargeMapMenu = 1;
    /////////////////////////////////
    /*    gamplay                  */
    /////////////////////////////////
    int suppMapLisTrigger = 1;
    SDL_Texture * arennaTexture;
    SDL_Rect arennaRect;
    SDL_Texture * perso1Texture;
    SDL_Rect MatricePerso1;
    SDL_Texture * perso2Texture;
    SDL_Rect MatricePerso2;
    SDL_Rect p1Sprite;
    SDL_Rect p2Sprite;
    firstPointNode * pointlist;

    p1Sprite.x = 300;
    p1Sprite.y = 200;
    p2Sprite.x = 0;
    p2Sprite.y = 0;
    p1Sprite.w = WINDOW_WIDTH/5;
    p1Sprite.h = WINDOW_HEIGHT/5;
    p2Sprite.w = WINDOW_WIDTH/5;
    p2Sprite.h = WINDOW_HEIGHT/5;

    float xPosPerso1;
    float yPosPerso1;
    float xPosPerso2;
    float yPosPerso2;

    int perso1LastPostion[2] = {0, 0};
    int perso2LastPostion[2] = {0, 0};

    /////////////////////////////////
    /*    animation loop variable  */
    /////////////////////////////////
    int finish  = 1;
    /////////////////////////////////
    /*          init lib           */
    /////////////////////////////////
    printf("\ninit lib  \n");     
    checkInitLib(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER));
    checkInitLib(TTF_Init());
    win  = SDL_CreateWindow("Skip the Line",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH, WINDOW_HEIGHT,0);
    quitIfNullW(win);  
    renderer = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED);
    quitIfNullRend(renderer);
    /////////////////////////////////
    /*     init menu texure        */
    /////////////////////////////////
    printf("\ninit menu texure \n");
    backgroundTexture = createTexuterImg("img/bckgrndMenu.jpg", renderer, backgroundTexture);
    SDL_QueryTexture(backgroundTexture,NULL,NULL, &backgroundRect.w, &backgroundRect.h);
    arennaTexture = createTexuterImg("img/arenna.png", renderer, arennaTexture);
    SDL_QueryTexture(arennaTexture,NULL,NULL, &arennaRect.w, &arennaRect.h);
    
    perso1Texture = createTexuterImg("img/pikachuTest.jpg", renderer, perso1Texture);
    SDL_QueryTexture(perso1Texture,NULL,NULL, &MatricePerso1.w, &MatricePerso1.h);
    perso2Texture = createTexuterImg("img/pikachuTest.jpg", renderer, perso2Texture);
    SDL_QueryTexture(perso2Texture,NULL,NULL, &MatricePerso2.w, &MatricePerso2.h);
    p1Sprite.h /= 2;
    p1Sprite.w /= 2;
    p2Sprite.h /= 2;
    p2Sprite.w /= 2;
    list = initList(list,"MENU", renderer, WINDOW_WIDTH);
    list = addMenuLine(list,"jvj",renderer);
    list = addMenuLine(list,"online",renderer); 
    list = addMenuLine(list,"editor",renderer); 
    list = addMenuLine(list,"option",renderer); 
    list = addMenuLine(list,"quit",renderer);

    perso1LastPostion[0] = p1Sprite.x;
    perso1LastPostion[1] = p1Sprite.y;

    perso2LastPostion[0] = p2Sprite.x;
    perso2LastPostion[1] = p2Sprite.y;

   pointlist = initListPoint(pointlist,renderer);

    /////////////////////////////////
    /*     animation loop          */
    /////////////////////////////////
    printf("\nanimation loop \n");   
    while (finish) {
        perso1LastPostion[0] = xPosPerso1;
        perso1LastPostion[1] = yPosPerso1;
    
        perso2LastPostion[0] = xPosPerso2;
        perso2LastPostion[1] = yPosPerso2;  
        printf("repaire 1\n");
        SDL_Event event;
        printf("*repaire 2*\n");
        while(SDL_PollEvent(&event)) {
            printf("*repaire 2.2\n");
            if(event.type == SDL_QUIT) {
                finish = 0;
                //oneAndAlltoZero(&exitIng, menuOption, MENU_OPTION_SIZE,&chargeMapMenu);
            }
            printf("3 A\n");
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_RETURN:
                            printf("entrer\n");
                            oneAndAlltoZero(&cursor, menuOption, MENU_OPTION_SIZE, &chargeMapMenu);
                            break;
                        case SDLK_DOWN:
                            ++cursor;
                            ++mapCursor;
                            printf("bas\n");
                            yPosPerso1 += SPEED/30;
                            break;
                        case SDLK_UP:
                            --cursor;
                            --mapCursor;
                            yPosPerso1 -= SPEED/30;
                            printf("haut\n");
                            break;
                                 break;
                        case SDLK_LEFT:
                            xPosPerso1 -= SPEED/30;
                            printf("gauche\n");
                            break;
                        case SDLK_RIGHT:
                            xPosPerso1 += SPEED/30;
                            printf("droite\n");
                            break;
                            //mario
                        case SDLK_s:
                            yPosPerso2 += SPEED/30;
                            printf("bas\n");
                            break;
                        case SDLK_z:
                            yPosPerso2 -= SPEED/30;
                            printf("haut\n");
                            break;
                        case SDLK_q:
                            xPosPerso2 -= SPEED/30;
                            printf("gauche\n");
                            break;
                        case SDLK_d:
                            xPosPerso2 += SPEED/30;
                            printf("droite\n");
                            break;
                    }
                break;
            }
            SDL_FlushEvent(event.type);
        }
        printf("\nSDL_RenderClear\n");
        SDL_RenderClear(renderer);
        printf("\nCursor = %d\n", cursor);
        if(menuOption[0]) {
            if (cursor == 6) cursor = 1;
            if (cursor == 0) cursor = 5;
            printf("\nmenuOption[0]\n");
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            showMenu(list, cursor, renderer);
        }
        printf("\nrepère 3\n");
        if(menuOption[1]) {
            if(chargeMapMenu) {
                printf("\nmenuOption[1]\n");
                cursor = 1;
                fileDataString = getDataFromFile("maps");
                printf("post data from file\nmain\n  fileDataString = %s\n",fileDataString);
                numOfMaps = numOfelementCutByPipe(fileDataString);
                printf("\nmain nombre de carte %d", numOfMaps);
                arrayNameOfMaps = buildCharArray(numOfMaps);
                arrayNameOfMaps = initArrayFromStringCutByPipe(fileDataString,arrayNameOfMaps,numOfMaps);
                listMaps = initMapList(listMaps,"testmap", renderer, WINDOW_WIDTH);
                for (size_t k = 0; k < numOfMaps; k++) {
                    addMap( listMaps, arrayNameOfMaps[k], WINDOW_WIDTH, renderer);
                }
                chargeMapMenu = 0;
                printf("\nis ok\n");
            }
            printf("\nrepère 4\n");
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            showMapMenu(listMaps, cursor, renderer);
        }
        if(menuOption[6]){
            printf("\n suppMapLisTrigger = %d\n", suppMapLisTrigger);
            if(suppMapLisTrigger) {
                suppMapLisTrigger = 0;
                suppMenuMapList(listMaps);
                printf("\nmaplist supprimer\n");
                xPosPerso1 = p1Sprite.x;
                yPosPerso1 = p1Sprite.y; 
                xPosPerso2 = p2Sprite.x;
                yPosPerso2 = p2Sprite.y;
            } else {
                p1Sprite.x = xPosPerso1;
                p1Sprite.y = yPosPerso1; 
                p2Sprite.x = xPosPerso2;
                p2Sprite.y = yPosPerso2;
                if(!isSamePosition(p1Sprite.x, p1Sprite.y, perso1LastPostion)) {
                    if(positionIsBeforeX(p1Sprite.x, 100)) {
                        addPoint( pointlist, perso1LastPostion[0], perso1LastPostion[1],renderer);
                    }
                }
            }
            showPoints(pointlist,renderer);
            SDL_RenderCopy(renderer, arennaTexture, NULL, NULL);
            SDL_RenderCopy(renderer, perso1Texture, NULL, &p1Sprite);
            SDL_RenderCopy(renderer, perso2Texture, NULL, &p2Sprite);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
        if(menuOption[5] == 1) finish = 0;
    }
    suppMenuMapList(listMaps);
    suppMenuLineList(list);
    free(list);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}