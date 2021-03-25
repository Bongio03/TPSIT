/*
Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse: (,),[,],{,} e
che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG  100

typedef struct nodo{
    char parentesi;
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
        printf("%d\n",appoggio->parentesi);
        free(appoggio);
        appoggio=pop(head); 
    }
}

int main(){
    Nodo* head;
    Nodo* input;
    char* espressione = (char*) malloc(sizeof(char) * LUNG);
    bool corretta = true;
    char parAppoggio;
    head=NULL;
    int k=0;

    printf("Inserire l'espressione: ");
    fflush(stdin);
    scanf("%s",espressione);

    while(k < strlen(espressione) && corretta==true){
        if(*(espressione+k)=='('|| *(espressione+k)=='['|| *(espressione+k)=='{' ){
            input = (char*) malloc (sizeof(char));
            input->parentesi=*(espressione+k);
            push(&head,input);
        }else{
            if(*(espressione+k)==')'){
                if(pop(&head)->parentesi!='('){
                    corretta=false;
                }               
            }else{
                if(*(espressione+k)==']'){
                    if(pop(&head)->parentesi!='['){
                        corretta=false;
                    }               
                }else{
                    if(*(espressione+k)=='}'){
                        if(pop(&head)->parentesi!='{'){
                        corretta=false;
                        }               
                    }       
                }
            }
        }
        k++;
    }
    if(head!=NULL){
        corretta=false;
    }
    if(corretta){
        printf("Espressione scritta correttamente!");
    }else{
        printf("Hai sbagliato");
    }
    return 0;
}
