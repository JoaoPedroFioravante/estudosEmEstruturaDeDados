#include "aluno.h"
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char prontuario[12];
    char nome[10];
};

Aluno* criarAluno(char*nome, char*prontuario){
    Aluno*aluno = malloc(sizeof(Aluno));
    if(aluno==NULL) return aluno;
    if(strlen(nome) > 9 || strlen(prontuario)>11) return NULL;
    strcpy(aluno->nome, nome);
    strcpy(aluno->prontuario, prontuario);
    return aluno;
}

int obterProntuario(Aluno * aluno, char*prontuario){
    if(aluno == NULL) return 0;
    strcpy(prontuario, aluno->prontuario);
    return 1;
}

int obterNome(Aluno*aluno, char*nome){
    if(aluno == NULL) return 0;
    strcpy(nome, aluno->nome);
    return 1;
}
void liberarAluno(Aluno*aluno){
    free(aluno);
}
