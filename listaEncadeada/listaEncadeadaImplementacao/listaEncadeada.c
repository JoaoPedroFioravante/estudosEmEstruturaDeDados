#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

struct listaEncadeada
{
    No *inicio;
    No *fim;
};

ListaEncadeada *criarLista()
{
    ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if (lista != NULL)
    {
        (*lista).inicio = NULL;
        (*lista).fim = NULL;
    }
    return lista;
}

int adicionarNoFim(ListaEncadeada *lista, int valor)
{
    if (lista != NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            if ((*lista).inicio != NULL)
            {
                (*lista).fim->proximo = novoNo;
            }
            else
            {
                (*lista).inicio = novoNo;
            }
            (*novoNo).valor = valor;
            (*lista).fim = novoNo;
            (*novoNo).proximo = NULL;
            return 1;
        }
    }
    return 0;
}

int adicionarNoInicio(ListaEncadeada *lista, int valor)
{
    if (lista != NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            if ((*lista).inicio != NULL)
            {
                (*novoNo).proximo = (*lista).inicio;
            }
            else
            {
                (*novoNo).proximo = NULL;
                (*lista).fim = novoNo;
            }
            (*novoNo).valor = valor;
            (*lista).inicio = novoNo;
            return 1;
        }
    }
    return 0;
}

int remover(ListaEncadeada *lista, int valor)
{
    if (lista != NULL)
    {
        No *auxiliar = NULL, *auxiliar2 = (*lista).inicio;
        while (auxiliar2 != NULL && valor != (*auxiliar2).valor)
        {
            auxiliar = auxiliar2;
            auxiliar2 = (*auxiliar2).proximo;
        }
        if (auxiliar2 != NULL)
        {
            (*auxiliar).proximo = (*auxiliar2).proximo;
            free(auxiliar2);
            return 1;
        }
    }
    return 0;
}

int buscar(ListaEncadeada *lista, int valor)
{
    if (lista != NULL)
    {
        No *busca = (*lista).inicio;
        while (busca != NULL)
        {
            if (valor == (*busca).valor)
            {
                break;
            }
            busca = (*busca).proximo;
        }
        if (busca != NULL)
        {
            return 1;
        }
    }
    return 0;
}

int buscarNo(ListaEncadeada *lista, int valor, No **elemento)
{
    if (lista != NULL)
    {
        No *busca = (*lista).inicio;
        while (busca != NULL)
        {
            if (valor == (*busca).valor)
            {
                break;
            }

            busca = (*busca).proximo;
        }
        if (busca != NULL)
        {
            *elemento = busca;
            return 1;
        }
    }
    return 0;
}

int adicionarAposElemento(ListaEncadeada *lista, int valor, int elemento)
{
    if (lista != NULL)
    {
        No *ponteiroElemento = NULL;
        if (buscarNo(lista, elemento, &ponteiroElemento))
        {
            No *novoNo = (No *)malloc(sizeof(No));
            if (novoNo != NULL)
            {
                if ((*lista).fim == ponteiroElemento)
                    (*lista).fim = novoNo;
                (*novoNo).proximo = (*ponteiroElemento).proximo;
                (*novoNo).valor = valor;
                (*ponteiroElemento).proximo = novoNo;
                return 1;
            }
            return 0;
        }
    }
}

void exibirLista(ListaEncadeada *lista)
{
    if (lista != NULL)
    {
        No *pointer = (*lista).inicio;
        while (pointer != NULL)
        {
            printf("%d \n", (*pointer).valor);
            pointer = (*pointer).proximo;
        }
    }
}

void freeLista(ListaEncadeada *lista)
{
    if (lista != NULL)
    {
        No *pointer = (*lista).inicio, *pointerFree = NULL;
        while (pointer != NULL)
        {
            pointerFree = pointer;
            pointer = (*pointer).proximo;
            free(pointerFree);
        }
        free(lista);
    }
}