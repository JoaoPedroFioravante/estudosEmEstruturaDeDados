#define SUCESS 1
#define ERROR 0
#define MAXTAM 10
typedef struct fila Fila;

Fila * criarFila();
int adicionarFila(Fila*f, int valor);
int removerFila(Fila*f);
int getInicioFila(Fila*f, int*valor);
void freeFila(Fila*f);
void verFila(Fila*f); //apenas para debug não usa o conceito de fila
int getQuantidade(Fila*f);