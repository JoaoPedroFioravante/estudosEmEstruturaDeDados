#define SUCESS 1
#define ERROR 0
#include "aluno.h"

typedef struct pilha Pilha;

Pilha* createStack();
int push(Pilha*p, Aluno*al);
int pop(Pilha*p);
void getPeek(Pilha*p, char*name, char*id);
int getCounter(Pilha*p);
void listStack(Pilha *p);
void freeStack(Pilha*p);
int ctrlY(Pilha*p);
int ctrlZ(Pilha*p);
void listReturn(Pilha *p);

