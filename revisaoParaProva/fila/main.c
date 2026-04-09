#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Fila*fila = criarFila();
    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);
    enfileirar(fila, 4);
    enfileirar(fila, 5);
    enfileirar(fila, 6);
    enfileirar(fila, 7);
    int n; 
    obterPrimeiro(fila, &n);
    printf("\n %d", n);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    obterPrimeiro(fila, &n);
    printf("\n %d", n);
    n = 200;
    desenfileirar(fila);
    enfileirar(fila, 150);
    enfileirar(fila, 201);
    enfileirar(fila, 2);
    enfileirar(fila, 1);
    enfileirar(fila, 9);
    enfileirar(fila, 3);
    enfileirar(fila, 4);
    enfileirar(fila, 5);
    enfileirar(fila, 6);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);
    obterPrimeiro(fila, &n);
    printf("\n %d", n);
}