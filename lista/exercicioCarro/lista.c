#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 10

struct lista
{
    Veiculo * lista[MAXSIZE];
    int qtd;

};


Lista* createLista(){
    Lista*l = (Lista*)malloc(sizeof(Lista));
    if(l!=NULL){
        (*l).qtd =0;
    }
    return l;

}

void insertCar(Lista*list, Veiculo * car, int pos){
    for(int i = (*list).qtd; i>pos; i--){
        (*list).lista[i] = (*list).lista[i-1];
    }
    (*list).lista[pos] = car;
}


void inserir (Lista *l, Veiculo * v, int pos){
    if((*l).qtd<MAXSIZE && pos<=(*l).qtd && pos>=0){
        printf("teste \n ");
        insertCar(l, v, pos);
        (*l).qtd++;
    }
}

void removeCar(Lista*list, int pos){
    for(int i = pos; i<(*list).qtd-1; i++){
        (*list).lista[i] = (*list).lista[i+1];
        
    }
}

void remover (Lista *l, int pos){
    if((*l).qtd>0 && pos<(*l).qtd && pos>=0){
        removeCar(l, pos);
        (*l).qtd--;
    }
}

void searchIdentification(Lista * list, int *pos, char*placa){
    *pos = -1;
    char placaCarro[7];
    for(int i = 0; i<(*list).qtd; i++){
        placaCar((*list).lista[i], placaCarro);
        if(strcmp(placaCarro, placa) == 0){
            *pos = i;
            break;
        }
    }
    
}

void removerPlaca(Lista *l, char *placa){
    int pos;
    searchIdentification(l, &pos, placa);
    if(pos!=-1) remover(l, pos);
    else printf("\n placa inexistente \n");

}

void displayList(Lista*list){
    char placa[7];
    
    for(int i = 0; i<(*list).qtd;i++){
        printf("%d ", i);
        placaCar((*list).lista[i], placa);
        printf("%s \n", placa);
    }
}

void freeList(Lista*lista){
    free(lista);
}