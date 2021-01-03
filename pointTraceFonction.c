#include "pointTraceFonction.h"


firstPointNode * initListPoint(firstPointNode * list,  SDL_Renderer * renderer) {
    printf("\ninitList\n");
    point * p;
    p = malloc(sizeof(p));
    if(p != NULL) {
            list->Fpoint = p;
            p->next = NULL;
            p->spritePoint = malloc(sizeof(SDL_Rect));
            p->num = 1;
            p->pointTexure = createTexuterImg("img/point.jpg", renderer, p->pointTexure);
            SDL_QueryTexture(p->pointTexure,NULL,NULL, &p->spritePoint->w, &p->spritePoint->h);
            p->spritePoint->x = 
            p->spritePoint->y = 
            printf("\nfin initList\n");
            return list;
        printf("\np->name error malloc end\n");
        return list;
    }
    printf("\n p error malloc end\n");
    return list;
}

firstPointNode * addPoint(firstPointNode * list, int x, int y,SDL_Renderer * renderer) {
    point * ptr = NULL;
    point * p;
    ptr = list->Fpoint;
    if(ptr->next == NULL){
        ptr->spritePoint->x = x;
        ptr->spritePoint->x = y;
        return list;
    }
    p = malloc(sizeof(p));
    if(p != NULL) {
        p->pointTexure = createTexuterImg("img/point.jpg", renderer, p->pointTexure);
        ptr->spritePoint = malloc(sizeof(SDL_Rect));
        if( ptr->spritePoint != NULL ) {
            SDL_QueryTexture(p->pointTexure,NULL,NULL, &p->spritePoint->w, &p->spritePoint->h);
            p->next = NULL;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            p->num = ptr->num + 1;
            ptr->next = p;
            p->spritePoint->x = x;
            p->spritePoint->y = y;
        }
    }
    return list;
}



firstPointNode * suppPoints(firstPointNode * list) { 
    point * ptr = NULL;
    point * temp = NULL;
    ptr = list->Fpoint;
    while (ptr->next != NULL) {
        temp = ptr->next;
        SDL_DestroyTexture(ptr->pointTexure);
        free(ptr->spritePoint);
        free(ptr);
        ptr = temp;
    }
    SDL_DestroyTexture(ptr->pointTexure);
    free(ptr->spritePoint);
    free(ptr);
    return list;
}

firstPointNode * showPoints(firstPointNode * list, SDL_Renderer * renderer) {
    point * ptr = NULL;
    ptr = list->Fpoint;
    if(ptr->next == NULL) return list;
    while (ptr->next != NULL) {
        SDL_RenderCopy(renderer, ptr->pointTexure, NULL, ptr->spritePoint);
      ptr = ptr->next;
    }
    SDL_RenderCopy(renderer, ptr->pointTexure, NULL, ptr->spritePoint);
    return list;
}
