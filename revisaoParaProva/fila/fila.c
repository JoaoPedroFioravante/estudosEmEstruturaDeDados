#include "fila.h"
#include <stdlib.h>
#define MAX 5
struct fila
{
    int filaV[MAX];
    int inicio; 
    int fim;
    int qtd;
};

Fila*criarFila(){
    Fila*fila = malloc(sizeof(Fila));
    if(fila!=NULL){
        fila->inicio = 0;
        fila->fim = -1;
        fila->qtd = 0;
    }
    return fila;
}
int enfileirar(Fila*fila, int n){
    if(fila->qtd == MAX){
        return 0;
    }
    fila->fim++;
    if(fila->fim == MAX){
        fila->fim = 0;
    }
    fila->filaV[fila->fim] = n;
    fila->qtd++;
    return 1;
}
int desenfileirar(Fila*fila){
    if(fila->qtd == 0){
        return 0;
    }
    fila->inicio++;
    if(fila->inicio == MAX){
        fila->inicio = 0;
    }
    fila->qtd--;
}
int obterPrimeiro(Fila*fila, int *n){
    if(fila->qtd == 0){
        return 0;
    }
    *n = fila->filaV[fila->inicio];
}
