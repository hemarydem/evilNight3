#include "mapStructFunctions.h"

firstMapLineNode * initMapList(firstMapLineNode * list, char * lineName,  SDL_Renderer * renderer, int windowWidth) {
    printf("\ninitList\n");
    map * m;
    SDL_Color green = { 0, 200, 0,SDL_ALPHA_OPAQUE};
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
    m = malloc(sizeof(m));
    if(m != NULL) {
        m->name = malloc(sizeof(char) * 100);
        if(m->name != NULL) {
            list->firstMap = m;
            m->next = NULL;
            m->last = NULL;
            m->spritBlue = malloc(sizeof(SDL_Rect));
            m->num = 1;
            strcpy(m->name, lineName);
            printf("\n init map list %s\n",lineName);
            m->selcetedBlue = createTextureText(lineName, "font/gameria/gameria/GAMERIA.ttf", blue, 50, renderer);
            SDL_QueryTexture(m->selcetedBlue,NULL,NULL, &m->spritBlue->w, &m->spritBlue->h);
            m->spritBlue->x = windowWidth/2 - m->spritBlue->w;
            m->spritBlue->y = 10;
            printf("\nfin initList\n");
            return list;
        }
        printf("\nm->name error malloc end\n");
        return list;
    }
    printf("\n m error malloc end\n");
    return list;
}

firstMapLineNode * addMap(firstMapLineNode * list, char * lineName, int windowWidth, SDL_Renderer * renderer) {
    printf("\naddmap\n");
    printf("\najout de %s\n", lineName);
    map * m;
    map * ptr;
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
    m = malloc(sizeof(map));
    if(m != NULL) {
        m->name = malloc(sizeof(char) * 100);
        if (m->name != NULL) {
            m->next = NULL;
            m->last = NULL;
            m->spritBlue = malloc(sizeof(SDL_Rect));
            strcpy(m->name, lineName);
            m->selcetedBlue = createTextureText(lineName, "font/gameria/gameria/GAMERIA.ttf", blue, 50, renderer);
            SDL_QueryTexture(m->selcetedBlue,NULL,NULL, &m->spritBlue->w, &m->spritBlue->h);
            ptr = list->firstMap;
            while (ptr->next != NULL) {             //loop to the end of the chain
                ptr = ptr->next;
            }
            m->num = ptr->num + 1;
            m->spritBlue->x = 100;
            m->spritBlue->y = 100;
            ptr->next = m;                          //link new map at the and of the chain
            m->last = ptr;                          
            return list;
        }
        printf("\n  addmap error malloc\n   m->name = malloc(sizeof(char) * 100);");
        free(m);
        return list; 
    }
    printf("\n  addmap error malloc\n  initList\n m = malloc(sizeof(m));");
    return list;                   //creat map
}

firstMapLineNode * showMapMenu(firstMapLineNode * list, int cursor, SDL_Renderer * renderer) {
    printf("\ndebut showmapMenu\n");
    map * ptr;
    ptr = list->firstMap;
    int nbMapNode = numOfNodeMap(list);
    if (cursor >= nbMapNode)
        cursor = nbMapNode - 1;
    if (cursor <= 0)
        cursor = 1;
    printf("\nshowmapMenu repaire 1");
    printf("\n showMapMenu cursor = %d", cursor);
    while (ptr->next != NULL) {
        printf("\n showMapMenu  ptr->num = %d", ptr->num);
        if(cursor == ptr->num){
            printf("\n showMapMenu nom de la map afficher  ptr->name = %s numéro map afficher %d , cursor = %d", ptr->name,  ptr->num, cursor);
            SDL_RenderCopy(renderer, ptr->selcetedBlue, NULL, ptr->spritBlue);  
            printf("\nshowmapMenu\n repaire 4\n");
        }
        ptr = ptr->next;//loop to the end of the chain
    }
    printf("\n%s\n", ptr->name);
    printf("\nfin showMenu\n");
    return list;
}

map * getLastMap(firstMapLineNode * list) {
    printf("\ngetLastMap\n");
    map * ptr;
    ptr = list->firstMap;
    printf("\n1\n");
    if(list->firstMap->next == NULL) 
        return list->firstMap->next;
        printf("\n2\n");
    while (ptr->next != NULL) {             //loop to the end of the chain
        ptr = ptr->next;
        printf("\n////////////////////////////////////\n élément %s\n", ptr->name);
        if(ptr->last != NULL)
            printf("\n élément %p\n", ptr->last);                         
    }
    printf("\nfin getLastMenuLine\n");
    return ptr;
}


int numOfNodeMap(firstMapLineNode * list) {
    printf("\numOfNodeMap\n");
    map * ptr;
    int count = 1;
    ptr = list->firstMap;
    if(list->firstMap->next == NULL) 
        return count;
    while (ptr->next != NULL) {
        count++;             //loop to the end of the chain
        ptr = ptr->next;
        printf("\n////////////////////////////////////\n élément %s\n", ptr->name);
        if(ptr->last != NULL)
            printf("\n élément %p\n", ptr->last);                         
    }
    printf("\nfin numOfNodeMap\n");
    return count;
}

firstMapLineNode * suppMenuMapList(firstMapLineNode * list) {
    if(list->firstMap == NULL) return list;
    printf("\nsuppmapList\n");
    map * ptr;
    map * tmp;
    ptr = getLastMap(list);
    while (ptr->last != NULL) {
        tmp = ptr->last;
        printf("\nsuppression de %s", ptr->name);
        SDL_DestroyTexture(ptr->selcetedBlue);
        free(ptr->name);
        free(ptr->spritBlue);
        free(ptr);
        ptr = tmp;
    }
    printf("\nsuppression de %s", ptr->name);
    SDL_DestroyTexture(ptr->selcetedBlue);
    free(ptr->name);
    free(ptr->spritBlue);
    free(ptr);
    printf("\nfin nsuppmapList\n");
    return list;
}