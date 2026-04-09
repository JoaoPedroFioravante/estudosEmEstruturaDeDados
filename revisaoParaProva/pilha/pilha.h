typedef struct pilha Pilha;

Pilha*createPilha();
int adicionarPilha(Pilha*pilha, int n);
int removerPilha(Pilha*pilha);
int getPeek(Pilha*pilha, int * peek);