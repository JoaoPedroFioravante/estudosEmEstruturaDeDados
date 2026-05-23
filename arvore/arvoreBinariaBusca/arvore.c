#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *noEsq;
    struct no *noDir;
} No;

struct arvore
{
    No *raiz;
};

Arvore *createArvore()
{
    Arvore *arvore = malloc(sizeof(Arvore));
    if (arvore == NULL)
        return NULL;
    arvore->raiz = NULL;
    return arvore;
}

void encontraRamoParaONo(No *noRaiz, No *no)
{
    if (noRaiz->valor > no->valor)
    {
        if (noRaiz->noEsq == NULL)
        {
            noRaiz->noEsq = no;
            return;
        }
        encontraRamoParaONo(noRaiz->noEsq, no);
    }
    if (noRaiz->valor < no->valor)
    {
        if (noRaiz->noDir == NULL)
        {
            noRaiz->noDir = no;
            return;
        }
        encontraRamoParaONo(noRaiz->noDir, no);
    }
}

void addValorArvore(Arvore *arvore, int valor)
{
    if (arvore == NULL)
        return;
    No *no = malloc(sizeof(No));
    if (no == NULL)
        return;
    no->valor = valor;
    no->noDir = NULL;
    no->noEsq = NULL;
    if (arvore->raiz == NULL)
    {
        arvore->raiz = no;
        return;
    }
    return encontraRamoParaONo(arvore->raiz, no);
}

No *encontraSucessor(No *no)
{
    if (no->noEsq == NULL)
    {
        return no;
    }
    return encontraSucessor(no->noEsq);
}

No *encontraERemoveNo(No *no, int valorBuscado)
{
    if (no == NULL)
    {
        return NULL;
    }
    if (no->valor > valorBuscado)
    {
        no->noEsq = encontraERemoveNo(no->noEsq, valorBuscado);
    }
    else if (no->valor < valorBuscado)
    {
        no->noDir = encontraERemoveNo(no->noDir, valorBuscado);
    }
    else
    {
        if (no->noDir == NULL && no->noEsq == NULL)
            return NULL;
        else if (no->noDir != NULL && no->noEsq == NULL)
        {
            return no->noDir;
        }
        else if (no->noEsq != NULL && no->noDir == NULL)
        {
            return no->noEsq;
        }
        else
        {
            No *sucessor = encontraSucessor(no->noDir);
            no->noDir = encontraERemoveNo(no->noDir, sucessor->valor);
            sucessor->noDir = no->noDir;
            sucessor->noEsq = no->noEsq;
            free(no);
            return sucessor;
        }
    }
    return no;
}

void removeValorArvore(Arvore *arvore, int valor)
{
    if (arvore == NULL || arvore->raiz == NULL)
        return;
    arvore->raiz = encontraERemoveNo(arvore->raiz, valor);
}

void percorePreOrdem(No *no)
{
    if (no == NULL)
    {
        return;
    }
    printf("%d ", no->valor);
    percorePreOrdem(no->noEsq);
    percorePreOrdem(no->noDir);
}

void exibirArvoreDfsPreOrdem(Arvore *arvore)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        printf("arvore invalida");
    }
    percorePreOrdem(arvore->raiz);
}

void percorreEmOrdem(No *no)
{
    if (no == NULL)
    {
        return;
    }
    percorreEmOrdem(no->noEsq);
    printf("%d ", no->valor);
    percorreEmOrdem(no->noDir);
}

void exibirArvoreEmOrdem(Arvore *arvore)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        printf("arvore invalida");
    }
    percorreEmOrdem(arvore->raiz);
}

void percorreEmPosOrdem(No *no)
{
    if (no == NULL)
    {
        return;
    }
    percorreEmPosOrdem(no->noEsq);
    percorreEmPosOrdem(no->noDir);
    printf("%d ", no->valor);
}

void exibirArvorePosOrdem(Arvore *arvore)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        printf("arvore invalida");
    }
    percorreEmPosOrdem(arvore->raiz);
}