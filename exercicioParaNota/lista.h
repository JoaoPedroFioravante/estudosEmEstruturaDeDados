#include "monomio.h"

typedef struct lista Lista;

Lista*createLista();
int addMonomio(Lista*lista, Mono*monomio);
double avaliarPolinomio(Lista*lista, double x);
void freeLista(Lista*lista);
