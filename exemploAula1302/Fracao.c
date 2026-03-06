#include <stdlib.h>
#include "Fracao.h"

struct fracao
{
    int denominador, numerador;
};

Fracao * criarFracao(int numerador, int denominador){
    Fracao * f = (Fracao*) malloc(sizeof(Fracao));
    if(f != NULL){
        (*f).denominador = denominador;
        (*f).numerador  = numerador;
    }

    return f;
}

Fracao* somarFracao(Fracao* f1, Fracao*f2){
    int numerador = (((*f1).numerador)*((*f2).denominador)) + (((*f2).numerador)*((*f1).denominador));
    int denominador =  ((*f1).denominador)*((*f2).denominador);
    Fracao * f = criarFracao(numerador, denominador);
    return f;
}

float converterParaDecimal(Fracao * f){
    float x = (float)((*f).numerador)/((*f).denominador);
    return x;
}

int obterNumerador(Fracao *f){
    return ((*f).numerador);
}

int obterDenominador(Fracao *f){
    return ((*f).denominador);
}

void liberarFracao(Fracao *f){
    free(f);
}