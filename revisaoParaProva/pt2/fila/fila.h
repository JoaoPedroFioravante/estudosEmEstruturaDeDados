typedef struct fila Fila;

Fila*createFila();
int enfileirar(Fila*fila,int num);
int desenfileirar(Fila*fila);
int pegarPrimeiro(Fila*fila, int * num);
void freeFila(Fila*fila);