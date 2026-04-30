#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 5
struct lista
{
    int lista[MAX];
    int qtd;
};


Lista*criarLista(){
    Lista*lista = malloc(sizeof(Lista));
    if(lista==NULL) return lista;
    lista->qtd = 0;
    return lista;
}

void abrirEspaco(Lista*lista, int index){
    for(int i = lista->qtd; i>index; i--){
        lista->lista[i] = lista->lista[i-1];
    }
}

int addNum(Lista*lista, int index, int num){
    if(lista == NULL) return 0;
    if(lista->qtd == MAX) return 0;
    if(index >= MAX || index > lista->qtd) return 0;
    abrirEspaco(lista, index);
    lista->lista[index] = num;
    lista->qtd++;
    return 1;
}

void puxarVetor(Lista*lista, int index){
    for(int i =index; i<lista->qtd-1; i++){
        lista->lista[i] = lista->lista[i+1];
    }
}

int delIndex(Lista*lista, int index){
    if(lista == NULL) return 0;
    if(lista->qtd == 0) return 0;
    if(index>=lista->qtd) return 0;
    if(0>index) return 0;
    puxarVetor(lista, index);
    lista->qtd--;
}

int buscarNum(Lista*lista, int num){
    if(lista == NULL) return -1;
    if(lista->qtd == 0) return -1;
    for(int i = 0; i<lista->qtd; i++){
        if(lista->lista[i] == num){
            return i;
        }
    }
    return -1;
}
void exibir(Lista*lista){
    if(lista == NULL) return;
    for(int i = 0; i<lista->qtd; i++){
        printf("%d -> %d\n", lista->lista[i], i);
    }
}

void freeLista(Lista*lista){
    free(lista);
}