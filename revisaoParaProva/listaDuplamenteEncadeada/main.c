#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Lista*lista = createLista();
    adicionarNoFim(lista, 10);
    adicionarNoFim(lista, 20);
    adicionarNoFim(lista, 30);
    adicionarNoFim(lista, 40);
    exibirLista(lista);
    adicionarNoInicio(lista, 50);
    adicionarNoInicio(lista, 60);
    adicionarNoInicio(lista, 70);
    adicionarNoInicio(lista, 80);
    exibirLista(lista);
    adicionarApos(lista, 20, 25);
    adicionarApos(lista, 80, 75);
    adicionarApos(lista, 40, 45);
    exibirLista(lista);
    removerElemento(lista, 25);
    removerElemento(lista, 25);
    removerElemento(lista, 45);
    removerElemento(lista, 80);
    exibirLista(lista);
}