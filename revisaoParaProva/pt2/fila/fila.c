#include "fila.h"
#include "stdlib.h"
#define MAX 5
struct fila{
    int fila[MAX];
    int inicio;
    int fim;
    int quantidade;
};

Fila*createFila(){
    Fila*fila = malloc(sizeof(Fila));
    if(fila==NULL) return fila;
    fila->inicio =0;
    fila->fim = -1;
    fila->quantidade = 0;
    return fila;
}
int enfileirar(Fila*fila,int num){
    if(fila==NULL) return 0;
    if(fila->quantidade == MAX) return 0;
    fila->fim = (++fila->fim)%MAX;
    fila->fila[fila->fim] = num;
    fila->quantidade++;
    return 1;
}
int desenfileirar(Fila*fila){
    if(fila==NULL) return 0;
    if(fila->quantidade == 0) return 0;
    fila->inicio = (++fila->inicio)%MAX;
    fila->quantidade--;
    return 1;
}
int pegarPrimeiro(Fila*fila, int * num){
    if(fila == NULL) return 0;
    if(fila->quantidade == 0) return 0;
    *num = fila->fila[fila->inicio];
    return 1;
}
void freeFila(Fila*fila){
    if(fila == NULL) return;
    free(fila);
}