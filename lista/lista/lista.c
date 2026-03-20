#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int list[MAXSIZE], qtd;
};

List *createList()
{
    List *l = (List *)malloc(sizeof(List));
    if (l != NULL)
    {
        (*l).qtd = 0;
    }
    return l;
}

void insertElement(List *list, int element, int pos)
{
    for (int i = (*list).qtd; i > pos; i--)
    {
        (*list).list[i] = (*list).list[i - 1];
    }
    (*list).list[pos] = element;
    (*list).qtd++;
}

int addElement(List *list, int element, int pos)
{
    if (pos >= 0 && (*list).qtd >= pos && (*list).qtd < MAXSIZE)
    {
        insertElement(list, element, pos);
        return 1;
    }
    return 0;
}

void removeElementList(List *list, int pos, int *elementRemoved)
{
    *elementRemoved = (*list).list[pos];
    for (int i = pos; i < (*list).qtd - 1; i++)
    {
        (*list).list[i] = (*list).list[i + 1];
    }
}

int removeElement(List *list, int pos, int *elementRemoved)
{
    if ((*list).qtd > 0 && pos >= 0 && pos < (*list).qtd)
    {
        removeElementList(list, pos, elementRemoved);
        (*list).qtd--;
        return 1;
    }
    return 0;
}

int removeValue(List *list, int value)
{
    int pos, element;
    if(searchElement(list, value, &pos))
        if (removeElement(list, pos, &element)) 
            return 1;
    
    return 0;
}

int searchElement(List *list, int value, int *pos)
{
    if ((*list).qtd > 0)
    {
        for (int i = 0; i < (*list).qtd; i++)
        {
            if ((*list).list[i] == value)
            {
                *pos = i;
                break;
            }
        }
        return 1;
    }
    return 0;
}

void displayList(List *list){
    if((*list).qtd == 0)printf("lista vazia \n");
    else{
        for(int i = 0; i<(*list).qtd;i++){
            printf("%d \n", (*list).list[i]);
        }
    }
}
void freeList(List*list){
    free(list);
}