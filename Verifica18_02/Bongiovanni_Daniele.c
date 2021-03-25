/*
Verfica TPSIT sulle pile e le code
Bongiovanni Daniele 4^AROB
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define CARTE_TOT 52        //Numero di carte in un mazzo
#define MAX_NUMERI 13       //Le carte hanno un valore che va da 1 a 13
#define CUORI 'C'
#define PICCHE 'P'
#define DENARI 'D'
#define FIORI 'F'

typedef struct carta{       //Struttura della carta
    int num;
    char seme;
    struct carta* next;
}Carta;

int is_empty(Carta *head){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Carta** head, Carta* element){        //inserisce l'elmento in fondo alla pila;
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head= element;
    }
}

Carta* pop(Carta **head){       //Restituisce l'ultimo elmento inserito nella pila;
    Carta* ret= *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head= ret->next;
    }
    return ret;
}

void stampaPIla(Carta** head){   //Stampa la pila:il primo elemento che verrà stampato sarà l'ultimo che è stato inserito 
    Carta *appoggio;
    appoggio =pop(head);
    while(appoggio!=NULL){  
        printf("%d %c\n",appoggio->num, appoggio->seme);
        free(appoggio);
        appoggio=pop(head); 
    }
}

void caricaMazzo(Carta** head, char semeIn){
    Carta* element;
    for(int k=1;k<=MAX_NUMERI;k++){
        element=(Carta*)malloc(sizeof(Carta));
        element->num=k;
        element->seme=semeIn;
        push(head,element);
    }
}

int main(){
    Carta* headMazzo=NULL;      //Mazzo di carte
    Carta* headAlice=NULL;      //Mazzo di Alice
    Carta* headBob=NULL;        //Mazzo di Bob
    int turno;

    //Caricamento del mazzo con tutti e quattro i semi
    caricaMazzo(&headMazzo,CUORI);
    caricaMazzo(&headMazzo,FIORI);
    caricaMazzo(&headMazzo,DENARI);
    caricaMazzo(&headMazzo,PICCHE);

    srand(time(NULL));
    //Caricamento dei mazzi dei due giocatori
    for(int k=0; k<CARTE_TOT/2;k++){
        turno=rand()%2;
        if(turno==0){
            //precendeza a Alice
            push(&headAlice,pop(&headMazzo));
            push(&headBob,pop(&headMazzo));
        }else{
            //precenda a BOB
            push(&headBob,pop(&headMazzo));
            push(&headAlice,pop(&headMazzo));
        }
    }
    printf("Stampa del mazzo di Alice:\n");
    stampaPIla(&headAlice);
    printf("\nStampa del mazzo di Bob:\n");
    stampaPIla(&headBob);
    return 0;
}