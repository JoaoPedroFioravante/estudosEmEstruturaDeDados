#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"
struct aluno{
    char name[100], id[10];
};
Aluno *createStudent(char*name, char*id){
    Aluno*x = (Aluno*)malloc(sizeof(Aluno));
    if(x!=NULL){
        strcpy((*x).name,name);
        strcpy((*x).id,id);
    }
    return x;
}
void getId(Aluno*al, char*id){
    strcpy(id,(*al).id);
}
void getName(Aluno*al, char*name){
   strcpy(name, (*al).name);
}
void freeStudent(Aluno*al){
    free(al);
}