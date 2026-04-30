#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Lista *lista = criarLista();
    addNum(lista, 0, 10);
    addNum(lista, 0, 20);
    addNum(lista, 2, 30);
    addNum(lista, 1, 40);
    addNum(lista, 1, 50);
    exibir(lista);
    printf("tem numero 40? %d \n", buscarNum(lista, 40));
    printf("tem numero 100? %d \n", buscarNum(lista, 100));
    printf("tem numero 10? %d \n", buscarNum(lista, 10));
    delIndex(lista, 0);
    delIndex(lista, 3);
    exibir(lista);
    printf("=========================\n");
    delIndex(lista, 3);
    delIndex(lista, 1);
    exibir(lista);
}