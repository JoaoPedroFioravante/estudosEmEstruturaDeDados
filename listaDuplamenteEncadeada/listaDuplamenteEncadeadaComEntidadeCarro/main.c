#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "carro.h"

int main(){
    Lista*lista = criarLista();
    char * listaNomes[] = {"volkswagen", "fiat", "chevrolet", "ford", "byd", "honda", "tesla"};
    char *listaPlaca[] = {"abc1234", "opa0192", "buv9283", "tyu5684", "pil1275", "mok3579", "njg2365"};
    int anos[] = {2000, 1990, 2010, 2018, 2020, 2005, 2009};
    for(int i = 0; i<7; i++){
        Carro*carro = criarCarro(listaPlaca[i], listaNomes[i], anos[i]);
        if(i<4){
            adicionarFim(lista, carro);
        }
        else{
            adicionarInicio(lista, carro);
        }
    }
    Carro*carro12 = criarCarro("teste12", "teste029", 0101);
    Carro*carro13 = criarCarro("teste13", "teste039", 3101);
    exibirLista(lista);
    printf("\n ==================== \n");
    adicionarApos(lista, carro12, "abc1234");
    adicionarApos(lista, carro13, "tyu5684");
    exibirLista(lista);
    remover(lista, "njg2365");
    remover(lista, "teste12");
    remover(lista, "teste13");
    printf("\n ==================== \n");
    exibirLista(lista);
    printf("\n ==================== \n");
    for(int i = 0; i<7; i++){
        remover(lista, listaPlaca[i]);
    }
    exibirLista(lista);
    freeLista(lista);
}