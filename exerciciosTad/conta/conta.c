#include <stdlib.h>
#include <stdio.h>
#include "conta.h"
#include <time.h>
struct contaBancaria
{
    int num;
    float saldo;
};


Conta* criarConta(){
    
    Conta*c = (Conta*)malloc(sizeof(Conta));
    c->num=rand()*100;
    c->saldo=0;
    return c;
}

int depositar(Conta* conta, float valor){
    if(valor > 0){
        (*conta).saldo += valor;
        printf("sucesso ao depositar");
        return 1;
    }
    printf("falha ao depositar");
    return 0;
}
int sacar(Conta* conta, float valor){
    if((*conta).saldo >= valor){
        (*conta).saldo -= valor;
        printf("sucesso ao sacar");
        return 1;
    }
    printf("falha ao sacar");
    return 0;
}
int transferir(Conta* contaEnvia, Conta* contaRecebe, float valor){
    if((*contaEnvia).saldo >= valor){
        (*contaEnvia).saldo -= valor;
        (*contaRecebe).saldo += valor;
        printf("transferencia realizada com sucesso");
        return 1;
    }
    printf("falha na transferencia");
    return 0;
}
int obterNum(Conta* conta){
    return (*conta).num;
}
float getSaldo(Conta* conta){
    return (*conta).saldo;
}    
void freeConta(Conta* conta){
    free(conta);
}