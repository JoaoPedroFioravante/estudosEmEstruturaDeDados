#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "carro.h"

struct carro
{
    char marca[20], placa[8];
    int ano;
};


Carro * criarCarro(char*marca, char*placa, int ano){
    Carro*carro = (Carro*)malloc(sizeof(Carro));
    if(carro!=NULL){
        strcpy((*carro).placa, placa);
        strcpy((*carro).marca, marca);
        (*carro).ano = ano;
    }
    return carro;
}

char* getPlacaCarro(Carro*carro){
    char placa[8];
    strcpy(placa, carro->placa);
    return placa;
}

void freeCarro(Carro * carro){
    free(carro);
}
