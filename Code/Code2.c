/*
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;

void enqueue(Nodo** head,Nodo** tail,Nodo* element){
    if(isEmpty(*head)) *head = element;
    else    (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}

Nodo* dequeue(Nodo** head,Nodo** tail){
    Nodo* ret = *head;

    if(isEmpty(*head)) return NULL;
    else    *head = ret->next;

    if(*head == NULL) *tail = NULL;
    return ret;
}

int isEmpty(Nodo *struttura){
    if(struttura == NULL) return 1;
    return 0;
}

void stampaCoda(struct Nodo** head, struct Nodo** tail){
    while(!isEmpty(*head)){
        printf("%d ", dequeue(head,tail)->valore);
    }
}

void push(Nodo** head, Nodo* element){
    if(isEmpty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head= element;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret= *head;
    if(isEmpty(*head)){
        return NULL;
    }else{
        *head= ret->next;
    }
    return ret;
}

void invertiCoda(Nodo** head,Nodo** tail){
    Nodo* stack=NULL;
    while(!isEmpty(*head)){
        push(&stack,dequeue(head,tail));
    }
    while(!isEmpty(stack)){
        enqueue(head,tail,pop(&stack));
    }
}

int main(){
    Nodo* headCoda;
    Nodo* tailCoda;
    Nodo* element;
    char scelta;

    headCoda=NULL;
    tailCoda=NULL;
    
    do{
        element=(Nodo*)malloc(sizeof(Nodo));
        printf("Inserire un numero: ");
        fflush(stdin);
        scanf("%d",&element->valore);
        enqueue(&headCoda,&tailCoda,element);
        printf("Inserire n se si vuole smettere di inserire: ");
        fflush(stdin);
        scanf("%c",&scelta);
    }while(scelta!='n');

    invertiCoda(&headCoda,&tailCoda);
    stampaCoda(&headCoda,&tailCoda);
    return 0;
}