#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
    List *list = createList();
    addElement(list, 10, 0);
    addElement(list, 19, 3);
    addElement(list, 12, 1);
    addElement(list, 13, 2);
    addElement(list, 15, 0);
    addElement(list, 17, 4);
    addElement(list, 11, 0);
    addElement(list, 16, 0);
    addElement(list, 18, 0);
    displayList(list);
    int element;
    removeElement(list, 3,&element );
    printf("\n %d \n\n", element);
    displayList(list);
    searchElement(list, 17, &element); 
    printf("\n %d  teste \n\n", element);
    removeValue(list, 17);
    displayList(list);
    freeList(list);
}