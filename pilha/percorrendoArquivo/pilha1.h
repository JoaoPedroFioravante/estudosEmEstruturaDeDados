
#define SUCESS 1
#define FAIL 0

typedef struct pilha Pilha;

Pilha* criarPilha();
int push(Pilha *p, char valor);
int pop(Pilha *p);
int peek(Pilha *p, char*valor);
void freePilha(Pilha *p);
int getPeek(Pilha*p);

