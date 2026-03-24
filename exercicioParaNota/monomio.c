#include "monomio.h"
#include <stdlib.h>
#include <stdio.h>

struct monomio
{
    int coeficiente;
    int literal;
};

Mono * createMonomio(int coeficiente, int literal){
    Mono*novoMonomio = (Mono*)malloc(sizeof(Mono));

    if(novoMonomio!=NULL){
        novoMonomio->coeficiente = coeficiente;
        novoMonomio->literal = literal;    
    }
    return novoMonomio;
}

void potencia(double x, int literal, double *potenciaResultado){
    for(int i = 0; i<literal; i++){
        *potenciaResultado *= x;
    }
}

int valorMonomio(Mono*monomio, double x, double*valor){
    if(monomio != NULL){
        double potenciaResultado = 1;
        potencia(x, monomio->literal, &potenciaResultado);
        (*valor) = monomio->coeficiente * potenciaResultado;
        return 1;
    }
    return 0;
}

