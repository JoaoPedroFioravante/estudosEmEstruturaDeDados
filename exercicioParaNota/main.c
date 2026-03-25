/*Implemente um programa em C para armazenar o polinômios (com apenas uma variável: x)
em uma lista simplesmente encadeada. Para cada termo do polinômio digitado pelo usuário,
um nó na lista é criado para armazená-lo.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "monomio.h"

int main()
{
    double valorDoPolinomio;
    Mono *mono1 = createMonomio(3, 5);
    Mono *mono2 = createMonomio(6, 2);
    Mono *mono3 = createMonomio(1, 0);
    Lista *lista = createLista();
    addMonomio(lista, mono1);
    addMonomio(lista, mono2);
    addMonomio(lista, mono3);
    valorDoPolinomio = avaliarPolinomio(lista, 2);
    printf("\n %.2f ", valorDoPolinomio);
    printf("\n\n");
    Lista *lista2 = createLista();
    int coeficiente, literal, counter = 0;
    do
    {
        scanf("%d", &coeficiente);
        scanf("%d", &literal);
        Mono *novoMononio = createMonomio(coeficiente, literal);
        addMonomio(lista2, novoMononio);
        if (literal == 0)
        {
            break;
        }
    } while (1);
    valorDoPolinomio = avaliarPolinomio(lista2, 3);
    printf("\n %.2f ", valorDoPolinomio);
    freeLista(lista); 
    freeLista(lista2);
}