#include "carro.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct veiculo
{
    char placa[8];
    char marca[20];
    int ano; 
};

Veiculo*createVeiculo(char*placa, char*marca, int ano){
    Veiculo*car = (Veiculo*)malloc(sizeof(Veiculo));
    if(car!=NULL){
        strcpy((*car).placa, placa);
        strcpy((*car).marca, marca);
        (*car).ano = ano;
    }
    return car;
}

void placaCar(Veiculo*carro, char*nome){
    strcpy(nome, (*carro).placa);
}