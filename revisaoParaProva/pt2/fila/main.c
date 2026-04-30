#include "fila.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Fila*impar = createFila();
    Fila*par = createFila();
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,0};
    int i = 1;
    int x = array[0];
    do{
        if(x %2 == 0){
            enfileirar(par, x);
        }
        else{
            enfileirar(impar, x);
        }
        x = array[i++];
    }
    while(x != 0);
    for(int j = 0; j<6; j++){
    pegarPrimeiro(par, &x);
    pegarPrimeiro(impar, &i);
    printf("par: %d \nimpar: %d\n", x,i);
    desenfileirar(par);
    desenfileirar(impar);
    }
    freeFila(par);
    freeFila(impar);
}