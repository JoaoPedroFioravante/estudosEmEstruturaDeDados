#include <stdlib.h>
#include <stdio.h>
#include "carro.h"
#include "lista.h"


int main(){
    char * placas[] = {"123abcd","142axsd","1js928d","13239wd", "1w09023", "01342mn", "2349284", "testand" , "mourice", "merchan", "exception"};
    char * marcas[] = {"byd", "toyota","lamborghini","porsche","ferrari","mustang","tesla","volks", "fiat", "ford", "chevrolet"};
    int anos[] = {2020, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010};
    Lista*lista = createLista();
    int x = 0;
    
    for(int i = 0; i<11; i++){
        Veiculo * car = createVeiculo(placas[i], marcas[i], anos[i]);
        if(car!= NULL) inserir(lista, car, x);
        if(i == 0){
            Veiculo * carTest =  createVeiculo(placas[10], marcas[10], anos[10]);
            if(carTest!=NULL) inserir(lista, carTest, 3);
        }
        else if(i>2) x=i+1;
    }

    displayList(lista);
    printf("\n ==============================\n");
    removerPlaca(lista,"testand");
    displayList(lista);
    freeList(lista);

}