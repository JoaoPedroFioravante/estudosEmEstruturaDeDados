#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    struct no *anterior, *proximo;
    Carro *valor;
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
        lista->fim = NULL;
        lista->inicio = NULL;
    }
    return lista;
}

int adicionarFim(Lista *lista, Carro *carro)
{
    if (lista != NULL && carro != NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            novoNo->valor = carro;
            novoNo->proximo = NULL;
            if (lista->fim == NULL)
            {
                lista->inicio = novoNo;
                novoNo->anterior = NULL;
            }
            else
            {
                novoNo->anterior = lista->fim;
                lista->fim->proximo = novoNo;
            }
            lista->fim = novoNo;
            return 1;
        }
    }
    return 0;
}

int adicionarInicio(Lista *lista, Carro *carro)
{
    if (lista != NULL && carro != NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo != NULL)
        {
            novoNo->anterior = NULL;
            novoNo->valor = carro;
            if (lista->inicio == NULL)
            {
                novoNo->proximo = NULL;
                lista->fim = novoNo;
            }
            else
            {
                novoNo->proximo = lista->inicio;
                novoNo->proximo->anterior = novoNo;
            }
            lista->inicio = novoNo;
            return 1;
        }
    }
    return 0;
}

int adicionarApos(Lista *lista, Carro *carro, char *placaProcurada)
{
    if (lista != NULL && carro != NULL && strlen(placaProcurada) == 7 && lista->inicio != NULL)
    {
        No *buscador = lista->inicio;
        char placa[8];
        while (buscador != NULL)
        {
            getPlaca(buscador->valor, placa);
            if (strcmp(placa, placaProcurada) == 0)
            {
                break;
            }
            buscador = buscador->proximo;
        }
        if (buscador != NULL)
        {
            No *novoNo = (No *)malloc(sizeof(No));
            if (novoNo != NULL)
            {
                novoNo->valor = carro;
                novoNo->proximo = buscador->proximo;
                novoNo->anterior = buscador;
                buscador->proximo = novoNo;
                if (novoNo->proximo == NULL)
                {
                    lista->fim = novoNo;
                }
                else
                {
                    novoNo->proximo->anterior = novoNo;
                }
                return 1;
            }
        }
    }
    return 0;
}

int remover(Lista *lista, char *placaBuscada)
{
    if (lista != NULL && strlen(placaBuscada) == 7 && lista->inicio != NULL)
    {
        No *buscador = lista->inicio;
        char placa[8];
        while (buscador != NULL)
        {
            getPlaca(buscador->valor, placa);
            if (strcmp(placa, placaBuscada) == 0)
                break;
            buscador = buscador->proximo;
        }
        if (buscador != NULL)
        {
            if (buscador->anterior == NULL)
            {
                lista->inicio = buscador->proximo;
                if (buscador->proximo == NULL)
                    lista->fim = NULL;
                else
                    lista->inicio->anterior = NULL;
            }
            else if (buscador->proximo == NULL)
            {
                lista->fim = buscador->anterior;
                buscador->anterior->proximo = NULL;
            }
            else
            {
                buscador->anterior->proximo = buscador->proximo;
                buscador->proximo->anterior = buscador->anterior;
            }
            freeCarro(buscador->valor);
            free(buscador);
            return 1;
        }
    }
    return 0;
}

void exibirLista(Lista *lista)
{
    if (lista != NULL && lista->inicio != NULL)
    {
        No *exibe = lista->inicio;
        char placa[8];
        while (exibe != NULL)
        {
            getPlaca(exibe->valor, placa);
            printf("%s\n", placa);
            exibe = exibe->proximo;
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