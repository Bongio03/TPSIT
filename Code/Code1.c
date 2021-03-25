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

int isEmpty(El *struttura){                         //Funzione per vedere se la struttura è vuota o meno
    if(struttura == NULL) return 1;
    return 0;
}

void enqueue(El** head,El** tail,El* element){      //Funzione per il caricamento di una coda
    if(isEmpty(*head)) *head = element;
    else    (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}

El* dequeue(El** head,El** tail){                   //Funzione per svuotare la coda di un elemento
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
    
    head=NULL;                                      //Essendo inizialmente vuota la coda, viene assegnato NULL alla testa e alla coda
    tail=NULL;
        
    do{                                             //Ciclo per l'inserimento degli input
        input= (El*) malloc(sizeof(El));            //Viene allocato lo spazio per ricevere l'input
        printf("Inserire un numero intero a piacere(Inseire -1 per terminare): ");
        fflush(stdin);
        scanf("%d",&(input->valore));
        enqueue(&head,&tail,input);                 //L'elemento viene caricato nella coda
    }while(tail->valore!=-1);
    

    while(isEmpty(head->next)==0){                 //Stampa della coda. Durante la stampa viene anche svuotata la coda
        printf("%d",(dequeue(&head,&tail))->valore);
    }
    return 0;
}
