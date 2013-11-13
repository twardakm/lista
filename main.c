#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    struct element *next;
    int data;
}element;

element * push(element * first, element * newone);
void wyswietl(element * first);
element * clear(element *first);

int main(void)
{
    element *lista = NULL;
    element *temp;

    int i;

    for(i = 0; i < 10; i++)
    {
        temp=(element *)malloc(sizeof(element));
        temp->next=NULL;
        temp->data=i;
        lista = push(lista, temp);
    }

    wyswietl(lista);
    lista=clear(lista);
    wyswietl(lista);

    return 0;
}

element * push(element *first, element *newone)
{
    element * temp = first;
    if(first == NULL)
        return newone;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=newone;
    return first;
}

void wyswietl(element *first)
{
    if(first==NULL)
    {
        printf("Lista jest pusta\n");
    }
    else
    {
        do
        {
            printf("[%d]->", first->data);
            first = first->next;
        }while(first != NULL);
        printf("NULL\n");
    }
}

element * clear(element *first)
{
    if (first == NULL)
        return NULL;
    clear(first->next);
    free(first);

    return NULL;
}
