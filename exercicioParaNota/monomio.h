typedef struct monomio Mono;

Mono *createMonomio(int coeficiente, int literal);
int valorMonomio(Mono*monomio, double x, double*valor);