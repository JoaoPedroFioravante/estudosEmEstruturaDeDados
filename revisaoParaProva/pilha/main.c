#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Pilha * pilha = createPilha();
    adicionarPilha(pilha, 1);
    adicionarPilha(pilha, 2);
    adicionarPilha(pilha, 3);
    adicionarPilha(pilha, 4);
    adicionarPilha(pilha, 20);
    adicionarPilha(pilha, 6);
    int peek = 10;
    getPeek(pilha, &peek);
    printf("%d\n", peek);
    removerPilha(pilha);
    getPeek(pilha, &peek);
    printf("%d\n", peek);
    removerPilha(pilha);
    removerPilha(pilha);
    removerPilha(pilha);
    removerPilha(pilha);
    if(getPeek(pilha, &peek) == 0){
        printf(" pilha vazia");
    }
}