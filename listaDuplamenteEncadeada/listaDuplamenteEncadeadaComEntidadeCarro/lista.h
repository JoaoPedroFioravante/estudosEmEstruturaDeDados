#include "carro.h"
typedef struct lista Lista;

Lista*criarLista();
int adicionarFim(Lista*lista, Carro* carro);
int adicionarInicio(Lista*lista, Carro* carro);
int adicionarApos(Lista*lista, Carro* carro, char* placa);
int remover(Lista*lista, char*placa);
void exibirLista(Lista*lista);
void freeLista(Lista*lista);

