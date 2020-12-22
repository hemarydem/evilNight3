#include "menuStrucfunction.h"

firstmenuLineNode * initList(firstmenuLineNode * list, char * LineName,  SDL_Renderer * renderer, int windowWidth) {
    menuLine * menuL;
    SDL_Color green = { 0, 200, 0,SDL_ALPHA_OPAQUE};
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
    menuL = malloc(sizeof(menuL));
    if(menuL != NULL) {
        menuL->name = malloc(sizeof(char) * 100);
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
            return list;
        }
        return list;
    }
    return list;
}

firstmenuLineNode * addMenuLine(firstmenuLineNode * list, char * LineName, SDL_Renderer * renderer) {
    menuLine * mLine;
    menuLine * ptr;
    SDL_Color green = { 0, 200, 0,SDL_ALPHA_OPAQUE};
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
    mLine = malloc(sizeof(menuLine));
    if(mLine != NULL) {
        mLine->name = malloc(sizeof(char) * 100);
        if (mLine->name != NULL) {
            mLine->next = NULL;
            mLine->last = NULL;
            mLine->spritBlue = malloc(sizeof(SDL_Rect));
            mLine->spritGreen = malloc(sizeof(SDL_Rect));
            strcpy(mLine->name, LineName);
            mLine->selcetedBlue = createTextureText(LineName, "font/gameria/gameria/GAMERIA.ttf", blue, 100, renderer);
            mLine->unselcetedGreen = createTextureText(LineName, "font/gameria/gameria/GAMERIA.ttf", green, 100, renderer);
            SDL_QueryTexture(mLine->selcetedBlue,NULL,NULL, &mLine->spritBlue->w, &mLine->spritBlue->h);
            SDL_QueryTexture(mLine->unselcetedGreen,NULL,NULL, &mLine->spritGreen->w, &mLine->spritGreen->h);
            mLine->spritGreen->x = list->firstMap->spritGreen->x;
            mLine->spritBlue->x = list->firstMap->spritGreen->x;
            
            ptr = list->firstMap;
            while (ptr->next != NULL) {             //loop to the end of the chain
                ptr = ptr->next;
            }
            mLine->num = ptr->num + 1;
            mLine->spritGreen->y = ptr->spritGreen->y + 75;
            mLine->spritBlue->y = ptr->spritBlue->y + 75;
            ptr->next = mLine;                          //link new map at the and of the chain
            mLine->last = ptr;                          
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
    menuLine * ptr;
    ptr = list->firstMap;
    while (ptr->next != NULL) {             //loop to the end of the chain
        ptr = ptr->next;
    }
    return ptr;
}

firstmenuLineNode * suppMenuLineList(firstmenuLineNode * list, char * LineName) {
    menuLine * ptr;
    ptr = getLastMenuLine(list);
    while (ptr->last != NULL) {
        ptr = ptr->last;
        if(ptr->last->selcetedBlue != NULL) 
            SDL_DestroyTexture(ptr->last->selcetedBlue);
        
        if(ptr->last->unselcetedGreen != NULL)
            SDL_DestroyTexture(ptr->last->unselcetedGreen);

        if(ptr->last->name!= NULL)
            free(ptr->last->name);

        if(ptr->last->spritBlue != NULL) 
           free(ptr->last->spritBlue);
        
        if(ptr->last->spritGreen != NULL) 
            free(ptr->last->spritGreen);
        free(ptr->last);
    }
     if(ptr->selcetedBlue != NULL) 
            SDL_DestroyTexture(ptr->selcetedBlue);
        
        if(ptr->unselcetedGreen != NULL) 
            SDL_DestroyTexture(ptr->unselcetedGreen);
        
        if(ptr->name!= NULL) 
            free(ptr->name);
        
        if(ptr->spritBlue != NULL) 
           free(ptr->spritBlue);
        
        if(ptr->spritGreen != NULL) 
            free(ptr->spritGreen);
        
    free(ptr);
    return list;
}
firstmenuLineNode * showMenu(firstmenuLineNode * list, int cursor, SDL_Renderer * renderer) {
    printf("\ndebut showMapList\n");
    menuLine * ptr;
    ptr = list->firstMap;
    while (ptr->next != NULL) {
        if(cursor == ptr->num) {
            SDL_RenderCopy(renderer, ptr->selcetedBlue, NULL, ptr->spritBlue);  
        } else {
            SDL_RenderCopy(renderer, ptr->unselcetedGreen, NULL, ptr->spritGreen); 
        }
        ptr = ptr->next;//loop to the end of the chain
    }
    printf("\n%s\n", ptr->name);
    printf("\nfin showMapList\n");
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