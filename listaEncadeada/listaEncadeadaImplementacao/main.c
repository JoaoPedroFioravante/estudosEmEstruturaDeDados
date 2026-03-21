#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main(){
    ListaEncadeada * lista = criarLista();
    adicionarNoFim(lista, 5);
    adicionarNoFim(lista,6);
    adicionarNoFim(lista,7);
    adicionarNoFim(lista,8);
    adicionarNoInicio(lista, 1);
    adicionarNoInicio(lista, 2);
    adicionarNoInicio(lista, 3);
    adicionarNoInicio(lista, 4);
    adicionarAposElemento(lista, 10, 7);
    exibirLista(lista);
    printf("\n===========\n");
    remover(lista, 10);
    remover(lista, 4);
    remover(lista, 8);
    exibirLista(lista);
}