#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
    Lista * lista = criarLista();
    for(int  i = 0; i<4;i++)
        adicionarFim(lista, i+11);
    
    for(int i = 2; i<6; i++)
        adicionarInicio(lista, i*2);
    mostrarListaDoInicioAoFim(lista);
    printf("===============\n");
    adicionarApos(lista, 18, 4);
    adicionarApos(lista, 1, 14);
    mostrarListaDoInicioAoFim(lista);
    printf("--------------------\n");
    remover(lista, 14);
    remover(lista, 10);
    remover(lista, 1);
    remover(lista, 3);
    mostrarListaDoInicioAoFim(lista);
    printf("/////////////////////////\n");
    
    mostrarListaDoFimAoInicio(lista);
}