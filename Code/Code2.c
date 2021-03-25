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

int isEmpty(Nodo *struttura){                   //Funzione per vedere se la struttura è vuota o meno
    if(struttura == NULL) return 1;
    return 0;
}

void enqueue(Nodo** head,Nodo** tail,Nodo* element){        //Funzione per vedere se la struttura è vuota o meno
    if(isEmpty(*head)) *head = element;
    else    (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}

Nodo* dequeue(Nodo** head,Nodo** tail){         //Funzione per svuotare la coda di un elemento
    El* ret = *head;
    Nodo* ret = *head;

    if(isEmpty(*head)) return NULL;
    else    *head = ret->next;

    if(*head == NULL) *tail = NULL;
    return ret;
}


void stampaCoda(struct Nodo** head, struct Nodo** tail){        //Metoodo per la stampa della coda. Gli elementi che vengono stampati, prima vengono tolti dalla coda
    while(!isEmpty(*head)){
        printf("%d ", dequeue(head,tail)->valore);
    }
}

void push(Nodo** head, Nodo* element){                          //Metodo per il caricamento di pile
    if(isEmpty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head= element;
    }
}

Nodo* pop(Nodo **head){                                         //Metodo per togliere elementi dalle pile
    Nodo* ret= *head;
    if(isEmpty(*head)){
        return NULL;
    }else{
        *head= ret->next;
    }
    return ret;
}

void invertiCoda(Nodo** head,Nodo** tail){                      //Utilizzando uan pila di appoggio, viene inveritita la coda
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

    headCoda=NULL;                                              //Essendo inizialmente vuota la coda, viene assegnato NULL alla testa e alla coda
    tailCoda=NULL;
    
    do{
        element=(Nodo*)malloc(sizeof(Nodo));                    //Viene allocato lo spazio per ricevere l'input                 
        printf("Inserire un numero: ");
        fflush(stdin);
        scanf("%d",&element->valore);
        enqueue(&headCoda,&tailCoda,element);                   //L'elemento viene caricato nella coda
        printf("Inserire n se si vuole smettere di inserire: ");//Richiesta di terminare l'inserimento di input
        fflush(stdin);
        scanf("%c",&scelta);
    }while(scelta!='n');

    invertiCoda(&headCoda,&tailCoda);                           //La coda viene inverita
    stampaCoda(&headCoda,&tailCoda);                            //La coda oramai invertita viene stampata
    return 0;
}
