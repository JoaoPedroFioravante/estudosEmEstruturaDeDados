#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
/*Faça um programa que fique lendo números inteiros até que seja
digitado o número 0 (zero).
Para cada número lido, deve-se verificar se ele é par ou ímpar.
Seu programa deverá ter 2 filas: par e impar
Os números pares lidos deverão ser inseridos na fila “par”
Os números ímpares lidos deverão ser inseridos na fila “impar”
Após o término da entrada dos dados, retirar um elemento de cada
fila alternadamente.*/
int main(){
    Fila*par= criarFila();
    Fila*impar= criarFila();
    int x =22;
    while(x){
        
        if(x%2 ==0) adicionarFila(par, x);
        else adicionarFila(impar, x);
        x--;
    }
    verFila(par);
    verFila(impar);
    while(getQuantidade(par)||getQuantidade(impar)){
        removerFila(par);
        removerFila(impar);
    }
    verFila(par);
    verFila(impar);
    freeFila(par);
    freeFila(impar);
    
}