#include <stdlib.h>
#include <string.h>
#include "carro.h"

struct carro
{
    char placa[8], marca[20];
    int ano;
};


Carro*criarCarro(char*placa, char*marca, int ano){
    Carro* carro = (Carro*)malloc(sizeof(Carro));
    if(carro!=NULL){
        strcpy(carro->marca, marca);
        strcpy(carro->placa, placa);
        carro->ano = ano;
    }
    return carro;
}

int getPlaca(Carro*carro, char*placa){
    if(carro!=NULL){
        strcpy(placa, carro->placa);
        return 1;
    }
    return 0;
}

void freeCarro(Carro*carro){
    free(carro);
}