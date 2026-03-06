#include <stdlib.h>
#include <stdio.h>
#include "Fracao.h"

int main(){
    Fracao *f = criarFracao(3,4);
    Fracao *f2 = criarFracao(1,2);
    printf("%d%d \n", obterNumerador(f), obterDenominador(f));
    printf("%d%d \n", obterNumerador(f2), obterDenominador(f2));
    Fracao *soma = somarFracao(f, f2);
    printf("%d %d \n", obterNumerador(soma), obterDenominador(soma));
    printf("%.2f \n", converterParaDecimal(f2));

    liberarFracao(f);
    liberarFracao(f2);
    liberarFracao(soma);
    
}