#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"
#include "pilha.h"

int main(){
    Aluno *a1 = createStudent("joao", "1"), *a2 = createStudent("pedro", "12"), *a3 = createStudent("lucas", "123"), *a4=createStudent("isabela", "1234");
    Pilha *p1 = createStack();
    if(p1!=NULL){
    if(a1!=NULL) push(p1, a1);
    if(a2!=NULL) push(p1, a2);
    if(a3!=NULL) push(p1, a3);
    if(a4!=NULL) push(p1, a4);
    listStack(p1);
    listReturn(p1);
    /*
    pop(p1);
    pop(p1);
    */
    ctrlZ(p1);
    ctrlZ(p1);
    listStack(p1);
    listReturn(p1);
    /*
    pop(p1);
    pop(p1);
    */
    ctrlZ(p1);
    ctrlZ(p1);
    listStack(p1);
    listReturn(p1);
    ctrlY(p1);
    ctrlY(p1);
    ctrlY(p1);
    listStack(p1);
    listReturn(p1);
    freeStack(p1);
    freeStudent(a1);
    freeStudent(a2);
    freeStudent(a3);
    freeStudent(a4);
    }
    return 0;

}