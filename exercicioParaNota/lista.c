#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    Mono *valor;
    struct no *proximoNo;
} No;

struct lista
{
    No *inicio;
    No *fim;
};

Lista *createLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->fim = NULL;
        lista->inicio = NULL;
    }
    return lista;
}

int addMonomio(Lista *lista, Mono *monomio)
{
    if (lista == NULL || monomio == NULL)
    {
        return 0;
    }
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        return 0;
    }
    novoNo->valor = monomio;
    novoNo->proximoNo = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = novoNo;
    }
    No *anterior = lista->fim;
    if (anterior != NULL)
    {
        anterior->proximoNo = novoNo;
    }
    lista->fim = novoNo;
    return 1;
}

double avaliarPolinomio(Lista *lista, double x)
{
    if (lista == NULL || lista->inicio == NULL)
    {
        return 0;
    }
    double polinomioAvaliado = 0;
    No *percorredor = lista->inicio;
    while (percorredor != NULL)
    {
        double valor = 0;
        valorMonomio(percorredor->valor, x, &valor);
        polinomioAvaliado += valor;
        percorredor = percorredor->proximoNo;
    }
    return polinomioAvaliado;
}

void freeLista(Lista*lista){
    if(lista == NULL){
        return;
    }
    No*percorredor = lista->inicio;
    No*freePercorrido = NULL;
    while (percorredor!=NULL)
    {
        freePercorrido = percorredor;
        percorredor = percorredor->proximoNo;
        free(freePercorrido->valor);
        free(freePercorrido);
    }
    free(lista);
}