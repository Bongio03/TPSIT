/* 
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct el{
    int valore;
    struct el* next;
}El;

int isEmpty(El *struttura){
    if(struttura == NULL) return 1;
    return 0;
}

void enqueue(El** head,El** tail,El* element){
    if(isEmpty(*head)) *head = element;
    else    (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}

El* dequeue(El** head,El** tail){
    El* ret = *head;

    if(isEmpty(*head)) return NULL;
    else    *head = ret->next;

    if(*head == NULL) *tail = NULL;
    return ret;
}


int main(){
    El* head;
    El* tail;
    El* input;
    
    head=NULL;
    tail=NULL;
    
    do{
        input= (El*) malloc(sizeof(El));
        printf("Inserire un numero intero a piacere(Inseire -1 per terminare): ");
        fflush(stdin);
        scanf("%d",&(input->valore));
        enqueue(&head,&tail,input);
    }while(tail->valore!=-1);
    

    while(isEmpty(head->next)==0){ 
        printf("%d",(dequeue(&head,&tail))->valore);
    }
    return 0;
}