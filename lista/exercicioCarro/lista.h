#include "carro.h"

typedef struct lista Lista;

Lista* createLista();
void inserir (Lista *l, Veiculo* v, int pos);
void remover (Lista *l, int pos);
void removerPlaca(Lista *l, char* placa);
void displayList(Lista*list);
void freeList(Lista*lista);