/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.
*/
#include <stdio.h>
#include <stdlib.h>
#define LUNG 100
typedef struct nodo{
    int n;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Nodo** head, Nodo* element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head= element;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret= *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head= ret->next;
    }
    return ret;
}

void stampaPIla(Nodo** head){
    Nodo *appoggio;
    appoggio =pop(head);
    while(appoggio!=NULL){   //ripeto finchè ci sono elementi
        printf("%d\n",appoggio->n);
        free(appoggio);
        appoggio=pop(head); 
    }
}

int main(){
    Nodo* head;
    Nodo* input;
    Nodo* headInvertito;
    int num;

    head= NULL;
    headInvertito=NULL;
    printf("Inserire il numero: ");
    fflush(stdin);
    scanf("%d",&num);
    
    while(num>0){
        input = (Nodo*) malloc(sizeof(Nodo));
        input->n= num%10;
        push(&head,input);

        num= num/10;
    }

    while(head!=NULL){
        push(&headInvertito,pop(&head));
    }
    
    stampaPIla(&headInvertito);
    return 0;
}