#include "pilha.h"
#include <stdlib.h>
#define MAX 5
struct pilha
{
    int pilha[MAX];
    int topo;
};


Pilha*createPilha(){
    Pilha * pilha = malloc(sizeof(Pilha));
    if(pilha!=NULL){
        pilha->topo = -1;
    }
    return pilha;
}

int adicionarPilha(Pilha * pilha, int n){
    if(pilha->topo == MAX-1){
        return 0;
    }
    pilha->pilha[++pilha->topo] = n;
    return 1;
}
int removerPilha(Pilha*pilha){
    if(pilha->topo  == -1){
        return 0;
    }
    pilha->topo--;
    return 1;
}

int getPeek(Pilha * pilha, int * peek){
    if(pilha->topo == -1){
        return 0;
    }
    *peek = pilha->pilha[pilha->topo];
    return 1;
}