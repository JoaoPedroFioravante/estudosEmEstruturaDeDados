#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Lista*lista = createLista();
    adicionarNoFim(lista, 10);
    adicionarNoFim(lista, 9);
    adicionarNoFim(lista, 8);
    exibirLista(lista);
    adicionarNoInicio(lista, 5);
    adicionarNoInicio(lista, 6);
    adicionarNoInicio(lista, 7);
    exibirLista(lista);
    adicionarApos(lista, 8, 11);
    adicionarApos(lista, 7, 12);
    exibirLista(lista);
    removerElemento(lista, 7);
    removerElemento(lista, 11);
    removerElemento(lista, 8);
    removerElemento(lista, 10);
    removerElemento(lista, 5);
    exibirLista(lista);
}