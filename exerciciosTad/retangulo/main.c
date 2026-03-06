#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

int main(){

    Retangulo *a = criarRetangulo(10, 20);
    printf("area: %d perimetro: %d ", calcularArea(a), calcularPerimetro(a));
    return 0;
}