#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 20

struct lista
{
    int vetor[MAX];
    int fim;
};

Lista* createLista(){
    Lista*lista = malloc(sizeof(Lista));
    if(lista != NULL ){
        lista->fim = 0;
    }
    return lista;
}

void insertLista(int num, Lista*lista, int index){
    // 0 1 2 3 4 5
    // 6 indices
    // 7 posições
    // adicionar o 4 apos o 1
    // 5 index 6 -> 7
    for(int i = lista->fim; i>index; i--){
        lista->vetor[i] = lista->vetor[i-1];
    }
    lista->vetor[index] = num;
    lista->fim++;
}

int addLista(int num, Lista*lista, int index){
    if(lista == NULL) return 0;
    if(lista->fim == MAX) return 0;
    if(lista->fim < index) return 0;    
    insertLista(num, lista, index);
    return 1;
}

void shiftLista(int index, Lista*lista){
    for(int i = index; i<lista->fim-1; i++){
        lista->vetor[i] = lista->vetor[i+1];
    }
}

int delLista(int index, Lista*lista){
    if(lista == NULL) return 0;
    if(lista->fim == 0) return 0;
    if(lista->fim <= index) return 0;
    shiftLista(index, lista);
    lista->fim--;
    return 1;
}

int searchLista(int num, Lista*lista){
    if(lista == NULL) return -1;
    if(lista->fim == 0) return -1;
    for(int i = 0; i<lista->fim; i++){
        if(lista->vetor[i] == num){
            return i;
        }
    }
    return -1;
}

int elementInIndex(int index, Lista*lista, int*num){
    if(lista == NULL) return 0;
    if(lista->fim <= index) return 0;
    if(lista->fim == 0) return 0;
    *num = lista->vetor[index];
    return 1;
}
void exibirLista(Lista*lista){
    if(lista == NULL) return;
    for(int i  = 0; i<lista->fim; i++){
        printf("%d \n", lista->vetor[i]);
    }
}

void freeLista(Lista*lista){
    free(lista);
}


