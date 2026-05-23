#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Arvore * arvore = createArvore();
    if(arvore == NULL) return 0;
    addValorArvore(arvore, 42);
    addValorArvore(arvore, 16);
    addValorArvore(arvore, 57);
    addValorArvore(arvore, 8);
    addValorArvore(arvore, 35);
    addValorArvore(arvore, 5);
    addValorArvore(arvore, 11);
    addValorArvore(arvore, 48);
    printf("em pre-ordem: ");
    exibirArvoreDfsPreOrdem(arvore);
    printf("\n em ordem: ");
    exibirArvoreEmOrdem(arvore);
    printf("\n em pos-ordem: ");
    exibirArvorePosOrdem(arvore);
    removeValorArvore(arvore, 16);
    printf("\n em ordem: ");
    exibirArvoreEmOrdem(arvore);
}