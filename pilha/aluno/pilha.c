#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXTAM 20
#include "pilha.h"
struct pilha{
    Aluno * empilha[20];
    Aluno * pilhaRetorno[20];
    int index, indexctrl;
};

Pilha* createStack(){
    Pilha*p = (Pilha*)malloc(sizeof(Pilha));
    if(p!=NULL){
        (*p).index = -1;
        (*p).indexctrl = -1;
    }
    return p;
}

void getPeek(Pilha*p, char*name, char*id){
    if((*p).index>-1){
        getName((*p).empilha[(*p).index], name);
        getId((*p).empilha[(*p).index], id);
    }

}
int push(Pilha*p, Aluno*al){
    if((*p).index<MAXTAM-1){
        (*p).index++;
        (*p).indexctrl = -1;
        (*p).empilha[(*p).index] = al;
        return SUCESS;
    }
    return ERROR;
}

int pop(Pilha*p){
    if((*p).index>-1){
        (*p).index--;
        
        return SUCESS;
    }
    return ERROR;
}

int ctrlZ(Pilha*p){
    if(!((*p).indexctrl<MAXTAM-1 && (*p).index>-1)) return ERROR;
    (*p).indexctrl++;
    (*p).pilhaRetorno[(*p).indexctrl] = (*p).empilha[(*p).index];
    (*p).index--;
    return SUCESS; 
}

int ctrlY(Pilha*p){
    if(!((*p).indexctrl>-1 && (*p).index<MAXTAM-1)) return ERROR;
    (*p).index++;
    (*p).empilha[(*p).index] = (*p).pilhaRetorno[(*p).indexctrl];
    (*p).indexctrl--;
    return SUCESS;
}

void getindex(Pilha*p, char*name, char*id){
    if((*p).index>-1){
        getName((*p).empilha[(*p).index], name);
        getId((*p).empilha[(*p).index], id);
    }

}
void listStack(Pilha *p){
    int inicio = (*p).index;
    if((*p).index == -1) printf("vazio\n");
    while((*p).index>-1){
        char nome[100],id[10];
        getName((*p).empilha[(*p).index],nome);
        getId((*p).empilha[(*p).index], id);
        printf("1 nome: %s\n prontuario: %s\n ",nome, id);
        ctrlZ(p);
    }
    while((*p).index!=inicio)ctrlY(p);
    
    printf("=============\n");
}

void listReturn(Pilha *p){
    if((*p).indexctrl == -1) printf("vazio\n");
    int inicio = (*p).indexctrl;
    while((*p).indexctrl>-1){
        char nome[100],id[10];
        getName((*p).pilhaRetorno[(*p).indexctrl],nome);
        getId((*p).pilhaRetorno[(*p).indexctrl], id);
        printf(" nome: %s\n prontuario: %s\n ",nome, id);
        ctrlY(p);
    }
    while ((*p).indexctrl!=inicio)ctrlZ(p);
    printf("=============\n");
}


int getCounter(Pilha*p){
    return (*p).index;
}
void freeStack(Pilha*p){
    free(p);
}
