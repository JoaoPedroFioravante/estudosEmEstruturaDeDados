#include "pilha.h"
#include "aluno.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    Aluno *al1 = criarAluno("joao", "12345678910");
    Aluno *al2 = criarAluno("joaozinho", "123456789101");
    if (al2 == NULL)
    {
        printf("nulo\n");
    }
    Aluno *al3 = criarAluno("maria3", "12345678910");
    Aluno *a4 = criarAluno("maria4", "12345678910");
    Aluno *a5 = criarAluno("maria5", "12345678910");
    Aluno *a6 = criarAluno("maria6", "12345678910");
    Aluno *a7 = criarAluno("maria7", "12345678910");
    Pilha *myPilha = createPilha();
    empilhar(myPilha, al1);
    empilhar(myPilha, al2);
    empilhar(myPilha, al3);
    empilhar(myPilha, a4);
    empilhar(myPilha, a5);
    empilhar(myPilha, a6);
    empilhar(myPilha, a7);
    Aluno *peek = NULL;
    char nome[20];
    char prontuario[20];
    getPeek(myPilha, &peek);
    obterNome(peek, nome);
    obterProntuario(peek, prontuario);
    printf("%s %s \n", nome, prontuario);
    desempilhar(myPilha);
    peek = NULL;
    getPeek(myPilha, &peek);
    obterNome(peek, nome);
    obterProntuario(peek, prontuario);
    printf("%s %s \n", nome, prontuario);
    desempilhar(myPilha);
    peek = NULL;
    getPeek(myPilha, &peek);
    obterNome(peek, nome);
    obterProntuario(peek, prontuario);
    printf("%s %s \n", nome, prontuario);
    desempilhar(myPilha);
    peek = NULL;
    getPeek(myPilha, &peek);
    obterNome(peek, nome);
    obterProntuario(peek, prontuario);
    printf("%s %s \n", nome, prontuario);
    desempilhar(myPilha);
    peek = NULL;
    getPeek(myPilha, &peek);
    obterNome(peek, nome);
    obterProntuario(peek, prontuario);
    printf("%s %s \n", nome, prontuario);
    desempilhar(myPilha);
    peek = NULL;
    getPeek(myPilha, &peek);
    obterNome(peek, nome);
    obterProntuario(peek, prontuario);
    if (peek == NULL)
        printf("invalido");
}