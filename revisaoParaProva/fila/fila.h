typedef struct fila Fila;

Fila*criarFila();
int enfileirar(Fila*fila, int n);
int desenfileirar(Fila*fila);
int obterPrimeiro(Fila*fila, int *n);