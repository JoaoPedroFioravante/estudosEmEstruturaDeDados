#include <stdlib.h>
#include <stdio.h>
#include "pilha1.h"
#define MAXTAM 10
struct pilha
{
    char empilhado[MAXTAM];
    int peek;
};

Pilha* criarPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p!=NULL){
        (*p).peek = -1;
        return p;
    }
    return NULL;
}
int push(Pilha *p, char valor){
    if((*p).peek < MAXTAM-1){
        (*p).peek++;
        (*p).empilhado[(*p).peek] = valor;
        return SUCESS;
    }
    else return FAIL;
}
int pop(Pilha *p){
    if((*p).peek >= 0){
        (*p).peek--;
        return SUCESS;
    }
    return FAIL;
}
int peek(Pilha *p, char*valor){
    if((*p).peek >= 0){
        *valor = (*p).empilhado[(*p).peek];
        return SUCESS;
    }
    return FAIL;
}
int getPeek(Pilha*p){
    return (*p).peek;
}
void freePilha(Pilha *p){
    free(p);
}