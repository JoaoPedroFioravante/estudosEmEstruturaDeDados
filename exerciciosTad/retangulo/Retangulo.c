#include <stdlib.h>
#include "Retangulo.h"

struct retangulo{
    int altura, largura;
};

Retangulo* criarRetangulo(int altura, int largura){
    Retangulo*x =(Retangulo*) malloc(sizeof(Retangulo));
    (*x).altura = altura;
    (*x).largura = largura;
    return x;
}
int calcularArea(Retangulo* retangulo){
    int area = ((*retangulo).largura)*((*retangulo).altura); 
    return area;
}
int calcularPerimetro(Retangulo* retangulo){
    int perimetro = 2*(((*retangulo).largura)+((*retangulo).altura));
    return perimetro;
}
void liberarRetangulo(Retangulo* retangulo){
    free(retangulo);
}
