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

int avaliarPolinomio(Lista *lista, double x)
{
    if (lista == NULL || lista->fim == NULL)
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
    printf("\n valor do Polinomio com X = %.2f e igual a %.2f ", x, polinomioAvaliado);
    return 1;
}