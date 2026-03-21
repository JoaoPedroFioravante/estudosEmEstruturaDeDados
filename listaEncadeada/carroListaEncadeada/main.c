#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "carro.h"

int main(){
    Lista * lista = criarLista();
    char * listaNomes[] = {"volkswagen", "fiat", "chevrolet", "ford", "byd", "honda", "tesla"};
    char *listaPlaca[] = {"abc1234", "opa0192", "buv9283", "tyu5684", "pil1275", "mok3579", "njg2365"};
    int anos[] = {2000, 1990, 2010, 2018, 2020, 2005, 2009};
    for (int i = 0; i<7; i++){
        Carro * carro = criarCarro(listaNomes[i], listaPlaca[i], anos[i]);
        if(i<4){
            adicionarNoInicio(lista, carro);
        }
        else{
            adicionarNoFIm(lista, carro);
        }
    }
    adicionarApos(lista, criarCarro("testte", "tes7300", 1993), "pil1275");
    mostrarLista(lista);
    remover(lista, "opa0192");
    remover(lista, "njg2365");
    remover(lista, "tyu5684");
    printf("\n ================= \n");
    mostrarLista(lista);
    freeLista(lista);
}