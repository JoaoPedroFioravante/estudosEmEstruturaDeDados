#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Lista*myList = createLista();
    if(myList == NULL) return 0;
    addLista(10, myList, 0);
    addLista(20, myList, 0);
    addLista(30, myList, 0);
    exibirLista(myList);
    printf("==============\n");
    //delLista(1, myList);
    delLista(2, myList);
    //delLista(0, myList);
    delLista(2, myList);
    exibirLista(myList);
    printf("===============\n");
    int i = -66;
    printf("index de 20: %d \nindex de 10: %d \n", searchLista(20, myList), searchLista(10, myList));
    elementInIndex(0, myList, &i);
    printf("================\nnumber in index 0: %d", i);
    freeLista(myList);
}