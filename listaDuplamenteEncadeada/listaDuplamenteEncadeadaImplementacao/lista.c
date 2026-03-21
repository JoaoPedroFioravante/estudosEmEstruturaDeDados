#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int valor;
    struct no *anterior, *proximo;
} No;

struct lista
{
    No *inicio, *fim;
};

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

int adicionarInicio(Lista *lista, int valor)
{
    if (lista != NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            novoNo->valor = valor;
            if (lista->inicio != NULL)
            {
                novoNo->proximo = lista->inicio;
                novoNo->proximo->anterior = novoNo;
            }
            else
            {
                novoNo->proximo = NULL;
                lista->fim = novoNo;
            }
            lista->inicio = novoNo;
            novoNo->anterior = NULL;
            return 1;
        }
    }
    return 0;
}

int adicionarFim(Lista *lista, int valor)
{
    if (lista != NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            novoNo->valor = valor;
            if (lista->fim != NULL)
            {
                novoNo->anterior = lista->fim;
                lista->fim->proximo = novoNo;
            }
            else
            {
                lista->inicio = novoNo;
                novoNo->anterior = NULL;
            }
            lista->fim = novoNo;
            novoNo->proximo = NULL;
            return 1;
        }
        return 0;
    }
}

int adicionarApos(Lista *lista, int valor, int elemento)
{
    if (lista != NULL && lista->inicio != NULL)
    {
        No *noProcurado = lista->inicio;
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            novoNo->valor = valor;
            while (noProcurado != NULL && noProcurado != elemento)
            {
                noProcurado = noProcurado->proximo;
            }
            if(noProcurado!=NULL){
                novoNo->proximo = noProcurado->proximo;
                novoNo->anterior = noProcurado;
                noProcurado->proximo = novoNo;
                if(novoNo->proximo == NULL){
                    lista->fim = novoNo;
                }
                else{
                    novoNo->proximo->anterior = novoNo;
                }
                return 1;
            }
        }
    }
    return 0;
}

int remover(Lista *lista, int valor)
{
    if (lista != NULL && lista->inicio != NULL)
    {
        No *buscador = lista->inicio;
        while (buscador != NULL)
        {
            if (buscador->valor == valor)
                break;
            buscador = buscador->proximo;
        }
        if (buscador != NULL)
        {
            if (buscador->anterior == NULL)
            {
                lista->inicio = buscador->proximo;
                if (buscador->proximo == NULL)
                    lista->fim = buscador->proximo;
            }
            else if (buscador->proximo == NULL)
            {
                lista->fim = buscador->anterior;
                if (buscador->anterior != NULL)
                {
                    buscador->anterior->proximo = NULL;
                }
                else
                {
                    lista->inicio = NULL;
                }
            }
            else
            {
                buscador->anterior->proximo = buscador->proximo;
                buscador->proximo->anterior = buscador->anterior;
            }
            return 1;
        }
    }
    return 0;
}

void mostrarListaDoInicioAoFim(Lista *lista)
{
    if (lista != NULL && lista->inicio != NULL)
    {
        No *exibe = lista->inicio;
        while (exibe != NULL)
        {
            printf("%d \n", exibe->valor);
            exibe = exibe->proximo;
        }
    }
}

void mostrarListaDoFimAoInicio(Lista *lista)
{
    if (lista != NULL && lista->fim != NULL)
    {
        No *exibe = lista->fim;
        while (exibe != NULL)
        {
            printf("%d \n", exibe->valor);
            exibe = exibe->anterior;
        }
    }
}

void freeLista(Lista *lista)
{
    if (lista != NULL)
    {
        if (lista->inicio != NULL)
        {
            No *freeNo = NULL, *no = lista->inicio;
            while (freeNo != NULL)
            {
                freeNo = no;
                no = no->proximo;
                free(freeNo);
            }
        }
        free(lista);
    }
}