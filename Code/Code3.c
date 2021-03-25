/*
Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue()
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;

int isEmpty(Nodo *struttura){
    if(struttura == NULL) return 1;
    return 0;
}
Nodo* dequeue(Nodo** head,Nodo** tail){
    Nodo* ret = *head;

    if(isEmpty(*head)) return NULL;
    else    *head = ret->next;

    if(*head == NULL) *tail = NULL;
    return ret;
}

void enqueue(Nodo** head,Nodo** tail,Nodo* element){
    if(isEmpty(*head)) *head = element;
    else    (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}

void push (Nodo **head, Nodo** tail, Nodo *element){
    Nodo* supportHead = NULL;
    Nodo* supportTail = NULL;
    Nodo* element2;
    
    while (!isEmpty(*head)){
        element2 = dequeue(head,tail);
        enqueue(&supportHead, &supportTail, element2);
    }
    enqueue(head, tail, element);
    while (!isEmpty(supportHead)){
        enqueue(head, tail, dequeue(&supportHead, &supportTail));
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;
    if (isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}

void stampaPila(Nodo** head){
    printf("\nStampa la pila:\n");
    while(!isEmpty(*head)){
        printf("%d\n",pop(head)->valore);
    }
}

void main(){
    Nodo *head = NULL;
    Nodo *tail = NULL;
    Nodo* element = NULL;
    int n;
    
    printf("Inserire 5 numeri (uno alla volta) :");
    for (int i = 0; i < 5; i++)
    {
        element = (Nodo*) malloc(sizeof(Nodo));

        scanf("%d",&n);
        element->valore= n;
        push(&head, &tail, element);
    }
    stampaPila(&head);

}