#include "carro.h"
typedef struct lista Lista;

Lista*criarLista();
int adicionarNoFIm(Lista*lista, Carro*carro);
int adicionarNoInicio(Lista*lista, Carro*carro);
int adicionarApos(Lista*lista, Carro*carro, char *placa);
int remover(Lista*lista, char*placa);
void mostrarLista(Lista*lista);
void freeLista(Lista*lista);