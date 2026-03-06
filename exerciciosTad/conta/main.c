#include <stdlib.h>
#include <stdio.h>
#include "conta.h"
#include <time.h>
int main(){
    srand(time(NULL));
    Conta *a = criarConta(),*b = criarConta();
    printf("%d | %d \n", obterNum(a), obterNum(b));
    depositar(a, 100);
    depositar(b, 10);
    printf("saldo: %.2f\n",getSaldo(a));
    transferir(a,b, 90);
    printf("\n b saldo: %.2f | a saldo: %.2f \n", getSaldo(b), getSaldo(a));
    sacar(b, 50);
    printf("\n saldo: %.2f\n ",getSaldo(b));
    transferir(a, b, 20);
    freeConta(a);
    freeConta(b);

    return 0;
}