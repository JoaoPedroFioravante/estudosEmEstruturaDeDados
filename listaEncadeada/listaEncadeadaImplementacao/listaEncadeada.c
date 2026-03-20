#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{ 
    int valor; 
    No* proximo;
}No;

struct listaEncadeada
{
    No*inicio;
    No*fim;
};

ListaEncadeada * criarLista(){
    ListaEncadeada*lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    if(lista!=NULL){
        (*lista).inicio=NULL;
        (*lista).fim=NULL;
    }
    return lista;
}

int adicionarNoFim(ListaEncadeada*lista, int valor){
    No * novoNo = (No*)malloc(sizeof(No));
    if(novoNo!= NULL){
        if((*lista).inicio!=NULL){
            No*ultimo = (*lista).fim;
            (*ultimo).proximo = novoNo;
        }
        else{
            (*lista).inicio = novoNo;
        }
        (*lista).fim = novoNo;
        (*novoNo).proximo = NULL;
        return 1;
    }
    return 0;
}

int adicionarNoInicio(ListaEncadeada*lista, int valor){
    No * novoNo = (No*)malloc(sizeof(No));
    if(novoNo!= NULL){
        if((*lista).inicio!=NULL){
            No*primeiroNo = (*lista).inicio;
            (*novoNo).proximo = primeiroNo;
        }
        else{
            (*lista).fim = novoNo;
            (*novoNo).proximo = NULL;
        }
        (*lista).inicio = novoNo;
        return 1;
    }
    return 0;
}

int remover(ListaEncadeada*lista, int valor){
    No*auxiliar = NULL, *auxiliar2 = (*lista).inicio;
    while(auxiliar2 != NULL || valor != (*auxiliar2).valor){
        auxiliar = auxiliar2;
        auxiliar2 = (*auxiliar2).proximo;
    }
    if(auxiliar2 != NULL){
        (*auxiliar).proximo = (*auxiliar2).proximo;
        free(auxiliar2);
        return 1;
    }
    return 0;
}

int buscar(ListaEncadeada*lista, int valor){
    No*busca = (*lista).inicio;
    while(busca!=NULL || valor != (*busca).valor){
        busca = (*busca).proximo;
    }
    if(busca!=NULL){
        return 1;
    }
    return 0;
}

int buscarNo(ListaEncadeada*lista, int valor, No*elemento){
    No*busca = (*lista).inicio;
    while(busca!=NULL || valor != (*busca).valor){
        busca = (*busca).proximo;
    }
    if(busca!=NULL){
        elemento = busca;
        return 1;
    }
    return 0;
}

int adicionarAposElemento(ListaEncadeada*lista, int valor, int elemento){
    No*ponteiroElemento;
    if(buscarNo(lista, elemento, ponteiroElemento)){
        No* novoNo = (No*)malloc(sizeof(No));
        if(novoNo!=NULL){
            if((*lista).fim == ponteiroElemento)
                (*lista).fim = novoNo;
            (*novoNo).proximo = (*ponteiroElemento).proximo;
            (*novoNo).valor = valor;
            (*ponteiroElemento).proximo = novoNo;
            return 1;
        }
        return 0;
    }
}

void exibirLista(ListaEncadeada*lista){
    No*pointer = (*lista).inicio;
    while(pointer != NULL){
        printf("%d ",(*pointer).valor);
        pointer = (*pointer).proximo;
    }
}