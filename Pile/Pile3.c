#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int n;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){
    if (head == NULL)
    {
        return 1;
    }else
    {
        return 0;
    } 
}

void push (Nodo **head, Nodo *element){
    if (*head==NULL){
        element->next = NULL;
		*head = element;
	}else{
		element->next = *head;
		*head = element;
	}
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;

    if (is_empty(*head))
    {
        return NULL;
    }else
    {
        *head = ret->next;
    }

    return ret;
}

void enqueue(Nodo** head, Nodo** tail, Nodo* element){
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next=element;
    }
    *tail = element;
    element->next=NULL;
}

Nodo* dequeue(Nodo** head){
    Nodo* supportHead = NULL;
    Nodo* element2;
    Nodo* ret;

    while (!is_empty(*head)){
        element2 = pop(head);
        push(&supportHead, element2);
    }

    ret=pop(&supportHead);

    while (!is_empty(supportHead)){
        push(head, pop(&supportHead));
    }

    return ret;
}

int main(){
    Nodo* head=NULL;
    Nodo* element=NULL;
    for (int i = 0; i < 10; i++)
    {
        element = (Nodo*) malloc(sizeof(Nodo));
        element->n = i;
        push(&head, element);
    }

    while(!is_empty(head)){
        printf("%d",dequeue(&head)->n);
    }
    return 0;
}
