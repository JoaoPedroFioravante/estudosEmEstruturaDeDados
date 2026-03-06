#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila
{
  int fileira[MAXTAM], inicio, fim, qtd; //qtd quantidade de elementos  
};

Fila * criarFila(){
    Fila * f = (Fila*) malloc(sizeof(Fila));
    if(f!=NULL){
        (*f).fim = -1;
        (*f).inicio = 0;
        (*f).qtd = 0;
    }

}
int adicionarFila(Fila*f, int valor){
    if((*f).qtd<MAXTAM){
        (*f).fim = ((*f).fim+1)%MAXTAM;
        (*f).fileira[(*f).fim] = valor;
        (*f).qtd++;
        return SUCESS; 
    }
    return ERROR;
}
int removerFila(Fila*f){
    if((*f).qtd>0){
        (*f).inicio = ((*f).inicio+1)%10;
        (*f).qtd--;
        return SUCESS;
    }
    return ERROR;
}
int getInicioFila(Fila*f, int*valor){
    if((*f).qtd){
         *valor = (*f).fileira[(*f).inicio];
         return SUCESS;
    }
    return ERROR;
}
void freeFila(Fila*f){
    free(f);
}

int getQuantidade(Fila*f){
    return (*f).qtd;
}
void verFila(Fila*f){
    int count = (*f).inicio;
    int x = (*f).qtd;
    while (x)
    {   
        
        printf("%d \n", (*f).fileira[count]);
        count = (count+1)%MAXTAM;
        x--;

    }
    printf("========================\n");

}