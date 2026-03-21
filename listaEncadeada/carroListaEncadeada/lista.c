#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    Carro *valor;
    struct no *proximo;
} No;

struct lista
{
    No *inicio;
    No *fim;
};

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
    {
        (*lista).fim = NULL;
        (*lista).inicio = NULL;
    }
    return lista;
}

int adicionarNoFIm(Lista *lista, Carro *carro)
{
    if (lista != NULL && carro != NULL)
    {

        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            (*novoNo).valor = carro;
            (*novoNo).proximo = NULL;
            if ((*lista).fim != NULL)
            {
                (*(*lista).fim).proximo = novoNo;
            }
            else
            {
                (*lista).inicio = novoNo;
            }
            (*lista).fim = novoNo;
            return 1;
        }
    }
    return 0;
}

int adicionarNoInicio(Lista *lista, Carro *carro)
{
    if (lista != NULL && carro != NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            // tentei utilizar da forma simplificada
            novoNo->valor = carro;
            if (lista->inicio != NULL)
            {
                novoNo->proximo = lista->inicio;
            }
            else
            {
                lista->fim = novoNo;
            }
            lista->inicio = novoNo;
            return 1;
        }
    }
}

int buscarPlaca(Lista *lista, char *placa, No **carro)
{
    if (lista != NULL && lista->inicio != NULL)
    {
        No *aux = lista->inicio;
        while (aux != NULL)
        {
            char placaCarro[8];
            getPlacaCarro(aux->valor, placaCarro);
            if (strcmp(placaCarro, placa) == 0)
            {
                break;
            }
            aux = aux->proximo;
        }
        if (aux != NULL)
        {
            *carro = aux;
        }
        return 1;
    }
    return 0;
}

int adicionarApos(Lista *lista, Carro *carro, char *placa)
{
    No *elemento;
    if (buscarPlaca(lista, placa, &elemento))
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            novoNo->valor = carro;
            novoNo->proximo = elemento->proximo;
            elemento->proximo = novoNo;
            if (lista->fim == elemento)
                lista->fim = novoNo;
            return 1;
        }
    }
    return 0;
}

int remover(Lista *lista, char *placa)
{
    if (lista != NULL && lista->fim != NULL)
    {
        No *aux = lista->inicio, *aux2 = NULL;
        while (aux != NULL)
        {
            char placaCarro[8];
            getPlacaCarro(aux->valor, placaCarro);
            if (strcmp(placaCarro, placa) == 0)
            {
                break;
            }
            aux2 = aux;
            aux = aux->proximo;
        }
        if (aux != NULL)
        {
            if(lista->inicio == aux){
                lista->inicio = aux->proximo;
                if(aux->proximo == NULL){
                    lista->fim = NULL;
                }
            }
            else if(lista->fim == aux){
                aux2->proximo = aux->proximo;
                lista->fim = aux2;
            }
            else{
                aux2->proximo = aux->proximo;
            }
            freeCarro(aux->valor);
            free(aux);
            return 1;
        }
    }
    return 0;
}

void mostrarLista(Lista *lista)
{
    if (lista != NULL && lista->inicio != NULL)
    {
        No *aux = lista->inicio;
        while (aux != NULL)
        {
            char placa[8];
            getPlacaCarro(aux->valor, placa);
            printf(" %s \n", placa);
            aux = aux->proximo;
        }
    }
}

void freeLista(Lista *lista)
{
    if (lista != NULL)
    {
        if (lista->inicio != NULL)
        {
            No *carro = lista->inicio, *carroFree = NULL;
            while (carro != NULL)
            {
                carroFree = carro;
                carro = carro->proximo;
                freeCarro(carroFree->valor);
                free(carroFree);
            }
        }
        free(lista);
    }
}
