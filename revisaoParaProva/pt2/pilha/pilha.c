#include "pilha.h"
#include "stdlib.h"
#define MAX 5
struct pilha{
    Aluno* pilha[MAX];
    int topo;
};

Pilha * createPilha(){
    Pilha*pilha = malloc(sizeof(Pilha));
    if(pilha == NULL) return pilha;
    pilha->topo = -1;
    return pilha;
}

int empilhar(Pilha*pilha, Aluno*aluno){
    if(pilha == NULL) return 0;
    if(aluno == NULL) return 0;
    if(pilha->topo == MAX-1) return 0;
    pilha->pilha[++pilha->topo] = aluno;
    return 1;
}
int desempilhar(Pilha*pilha){
    if(pilha == NULL) return 0;
    if(pilha->topo == -1) return 0;
    pilha->topo--;
    return 1;
}
int getPeek(Pilha*pilha, Aluno ** aluno){
    if(pilha == NULL) return 0;
    if(pilha->topo == -1) return 0;
    *aluno = pilha->pilha[pilha->topo];
    return 1;
}
void freePilha(Pilha*pilha){
    if(pilha == NULL) return;
    Aluno*al;
    for(int i = 0; i<pilha->topo; i++){
        getPeek(pilha, &al);
        liberarAluno(al);
        desempilhar(pilha);
    }
}
