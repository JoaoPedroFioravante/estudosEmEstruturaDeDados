#include "aluno.h"

typedef struct pilha Pilha;

Pilha*createPilha();
int empilhar(Pilha*pilha, Aluno*aluno);
int desempilhar(Pilha*pilha);
int getPeek(Pilha*pilha, Aluno ** aluno);
void freePilha(Pilha*pilha);