
#include <stdlib.h>
#include <stdio.h>
#include "pilha1.h"




int main()
{
    Pilha *pilha1 = criarPilha();
    if(pilha1 == NULL) return 0;
    FILE *fp;
    char c;
    fp = fopen("arquivo.c", "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo");
        exit(0);
    }
    c = getc(fp);
    while(c != EOF){
        if(c == '{'){
            push(pilha1, c);
        }else if (c == '}')
        {   
            if(getPeek(pilha1) == -1){
                printf("falha de compilação \n");
                return 0;
            }
            pop(pilha1);
        }
        c = getc(fp);
    }
    if(getPeek(pilha1) == -1){
        printf("codigo ok!\n %d", getPeek(pilha1));
    }
    else{
        printf("falha de compilacao\n");
    }

    return 0;
}