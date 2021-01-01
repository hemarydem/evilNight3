#include "menuStrucfunction.h"

firstmenuLineNode * initList(firstmenuLineNode * list, char * LineName,  SDL_Renderer * renderer, int windowWidth) {
    printf("\ninitList\n");
    menuLine * menuL;
    SDL_Color green = { 0, 200, 0,SDL_ALPHA_OPAQUE};
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
    menuL = malloc(sizeof(menuL));
    if(menuL != NULL) {
        menuL->name = getString(100);
        if(menuL->name != NULL) {
            list->firstMap = menuL;
            menuL->next = NULL;
            menuL->last = NULL;
            menuL->spritBlue = malloc(sizeof(SDL_Rect));
            menuL->spritGreen = malloc(sizeof(SDL_Rect));
            menuL->num = 0;
            strcpy(menuL->name, LineName);
            menuL->selcetedBlue = createTextureText(LineName, "font/gameria/gameria/GAMERIA.ttf", blue, 100, renderer);
            menuL->unselcetedGreen = createTextureText(LineName, "font/gameria/gameria/GAMERIA.ttf", green, 100, renderer);
            SDL_QueryTexture(menuL->selcetedBlue,NULL,NULL, &menuL->spritBlue->w, &menuL->spritBlue->h);
            SDL_QueryTexture(menuL->unselcetedGreen,NULL,NULL, &menuL->spritGreen->w, &menuL->spritGreen->h);
            menuL->spritGreen->x = windowWidth/2 - menuL->spritGreen->w;
            menuL->spritBlue->x = windowWidth/2 - menuL->spritGreen->w;
            menuL->spritGreen->y = 10;
            menuL->spritBlue->y = 10;
            printf("\nfin initList\n");
            return list;
        }
        printf("\nmenuL->name error malloc end\n");
        return list;
    }
    printf("\n menuL error malloc end\n");
    return list;
}

firstmenuLineNode * addMenuLine(firstmenuLineNode * list, char * LineName, SDL_Renderer * renderer) {
    printf("\naddMenuLine\n");
    menuLine * mLine;
    menuLine * ptr;
    printf("\n naddMenuLine repère 1\n");
    SDL_Color green = { 0, 200, 0,SDL_ALPHA_OPAQUE};
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
    mLine = malloc(sizeof(menuLine));
     printf("\n naddMenuLine repère 1\n");
    if(mLine != NULL) {
        printf("\n naddMenuLine repère 2\n");
        mLine->name = malloc(sizeof(char) * 100);
        printf("\n naddMenuLine repère 3\n");
        if (mLine->name != NULL) {
            mLine->next = NULL;
            mLine->last = NULL;
            mLine->spritBlue = malloc(sizeof(SDL_Rect));
            mLine->spritGreen = malloc(sizeof(SDL_Rect));
            printf("\n naddMenuLine repère 4\n");
            strcpy(mLine->name, LineName);
            mLine->selcetedBlue = createTextureText(LineName, "font/gameria/gameria/GAMERIA.ttf", blue, 70, renderer);
            mLine->unselcetedGreen = createTextureText(LineName, "font/gameria/gameria/GAMERIA.ttf", green, 70, renderer);
            SDL_QueryTexture(mLine->selcetedBlue,NULL,NULL, &mLine->spritBlue->w, &mLine->spritBlue->h);
            SDL_QueryTexture(mLine->unselcetedGreen,NULL,NULL, &mLine->spritGreen->w, &mLine->spritGreen->h);
            mLine->spritGreen->x = list->firstMap->spritGreen->x;
            mLine->spritBlue->x = list->firstMap->spritGreen->x;
            ptr = list->firstMap;
            while (ptr->next != NULL) {             //loop to the end of the chain
                ptr = ptr->next;
                printf("ptr->name = %s\n", ptr->name);
            }
            printf("j'accroche ptr->name = %s à mLine->name %s\n", ptr->name, mLine->name);
            mLine->num = ptr->num + 1;
            mLine->spritGreen->y = ptr->spritGreen->y + 75;
            mLine->spritBlue->y = ptr->spritBlue->y + 75;
            ptr->next = mLine;                          //link new map at the and of the chain
            mLine->last = ptr;
            printf("\n////////////////////////////////////\n name du nouvel élément %s", mLine->name);                          
            return list;
        }
        printf("\n  addMenuLine error malloc\n   m->name = malloc(sizeof(char) * 100);");
        free(mLine);
        return list; 
    }
    printf("\n  addMenuLine error malloc\n  initList\n m = malloc(sizeof(m));");
    return list;                   //creat map
}

menuLine * getLastMenuLine(firstmenuLineNode * list) {
    printf("\ngetLastMenuLine\n");
    menuLine * ptr;
    ptr = list->firstMap;
    if(list->firstMap->next == NULL) 
    return list->firstMap->next;
    while (ptr->next != NULL) {             //loop to the end of the chain
        ptr = ptr->next;
        printf("\n////////////////////////////////////\n élément %s\n", ptr->name);
        if(ptr->last != NULL)
            printf("\n élément %p\n", ptr->last);                         
    }
    printf("\nfin getLastMenuLine\n");
    return ptr;
}

firstmenuLineNode * suppMenuLineList(firstmenuLineNode * list) {
    printf("\nsuppMenuLineList\n");
    menuLine * ptr;
    menuLine * tmp;
    ptr = getLastMenuLine(list);
    while (ptr->last != NULL) {
        tmp = ptr->last;
        printf("suppression de %s", ptr->name);
        SDL_DestroyTexture(ptr->selcetedBlue);
        SDL_DestroyTexture(ptr->unselcetedGreen);
        free(ptr->name);
        free(ptr->spritBlue);
        free(ptr->spritGreen);
        free(ptr);
        ptr = tmp;
    }
    printf("suppression de %s", ptr->name);
    SDL_DestroyTexture(ptr->selcetedBlue);
    SDL_DestroyTexture(ptr->unselcetedGreen);
    free(ptr->name);
    free(ptr->spritBlue);
    free(ptr->spritGreen);
    free(ptr);
    printf("\nfin nsuppMenuLineList\n");
    return list;
}
firstmenuLineNode * showMenu(firstmenuLineNode * list, int cursor, SDL_Renderer * renderer) {
    printf("\ndebut showMenu\n");
    menuLine * ptr;
    ptr = list->firstMap;
     printf("\n showMenu repère 1\n");
    while (ptr->next != NULL) {
        if(cursor == ptr->num) {
            printf("\n showMenu repère 1.5\n");
            SDL_RenderCopy(renderer, ptr->selcetedBlue, NULL, ptr->spritBlue);  
        } else {
            printf("\n showMenu repère 1.6\n");
            SDL_RenderCopy(renderer, ptr->unselcetedGreen, NULL, ptr->spritGreen); 
        }
        ptr = ptr->next;//loop to the end of the chain
    }
    printf("\n showMenu repère 2\n");
    if(cursor == ptr->num) {
        SDL_RenderCopy(renderer, ptr->selcetedBlue, NULL, ptr->spritBlue);  
    } else {
        SDL_RenderCopy(renderer, ptr->unselcetedGreen, NULL, ptr->spritGreen); 
    }
    printf("\n showMenu repère 3\n");
    printf("\n%s\n", ptr->name);
    printf("\nfin showMenu\n");
    return list;
}
/*
firstmenuLineNode * mulityAddMenuLine(firstmenuLineNode * list, int nbElementToAdd, SDL_Renderer * renderer) {
    printf("\nnbElementToAdd = %d\n", nbElementToAdd);
    for (int i = 0; i < nbElementToAdd; i++) {
        addMenuLine(list,"LineName",renderer);
        printf("\nje loop\n");
    }
    return list;
}

firstmenuLineNode * giveNameforMenuList(firstmenuLineNode * list, char * string) {
    menuLine * ptr = list->firstMap;
    int i = 0;
    char returnChar = '\0';
    char * str = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(str,string);
    char *sPtr = str;//start ptr
    char *ePtr = str;//end ptr
    while (i < numOfelementCutByPipe(str)) {
        while (*ePtr != '|'){
             ePtr++;
        }
        *ePtr = returnChar;
        printf("\n buildArrayfromCharCutByPipe\n strcpy(array[%d], %s);\n", i, sPtr);
        strcpy(ptr->name, sPtr);
        ePtr++;
        sPtr = ePtr;
        i++;
        if (ptr->next != NULL) {
            ptr = ptr->next;
        } else {
             printf("\n buildArrayfromCharCutByPipe\n il n'y a plus d'élément dans la liste\nle dernier nom initialiser %s\n", ptr->name);
        }
    }
    free(str);
    return list;
}*/