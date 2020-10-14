/*
Author:Bongiovanni Daniele
4^Arob
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 100

void decoding(char s[], int dim){   //procedura che effettua il decoding
    int num,cnt=0;                  //num: variabile di appoggio per salvare i numeri letti. cnt: contatore utile a inserire in sApp[] per num volte l' ultima lettera letta  
    char sApp[dim], lett;           //sApp: stringa di appoggio per il decoding. lett: variabile utile a salvare l'ultima lettera letta
    bool trovato=false;             //trovato: varibile che diventa vera se si è letto un numero

    for(int k=0; k<strlen(s); k++){ //ciclo che verra eseguito tante volte quanta la lunghezza della stringa s
        if(trovato==false){         //se nel ciclo precendete non è stato letto alcun numero, ci si preparerà alla lettura o di un numero o di una lettera ripetuta una sola volta
            if((s[k])>'0' && (s[k])<='9'){ //lettura numero
                num=s[k]-'0';
                trovato=true;
            }else{                  //lettura della lettera ripetuta una sola volta
                sApp[cnt]=s[k];
                cnt++;
            }
        }else{                      //assegnazione di num volte di lett all'interno di sApp[]
            lett=s[k];
            for(int i=0; i<num; i++){
                sApp[cnt]=lett;
                cnt++;
            }
            trovato=false;
        }
    }
    sApp[cnt]='\0';                 //inserisco \0 nella ultima cella della stringa per darle un limite
    strcpy(s,sApp);                 //copio il contenuto di sApp in s 
}

void encoding(char s[],int dim){    //procedura che effettua l'encoding
    char lett,sApp[dim];            //lett: variabile utile a salvare l'ultima lettera letta. sApp: stringa di appoggio per il decoding.     
    int cntLet=1,cnt=0;             //cntLet: variabile per contare quante volte si ripete una lettera. cnt: variabile utile per scorrere la stringa di appoggio

    lett=s[0];                      //effettuo già la lettura della prima lettera per vedere se è differente dalla seconda.
    for(int k=1; k<strlen(s)+1; k++){
        if(lett!=s[k]){             //se la lettera cambia, si interrompe interrompe l'incremento di cntLet
            if(cntLet==1){          //lett è presente ua sola volta nella stringa
                sApp[cnt]=lett;
                cnt++;
                lett=s[k];
            }else{                  
                sApp[cnt]=cntLet+48;
                cntLet=1;
                cnt++;
                sApp[cnt]=lett;
                lett=s[k];
                cnt++;
            }
        }else{
            cntLet++;
        }
    }
    sApp[cnt]='\0';             //inserisco \0 nella ultima cella della stringa per darle un limite
    strcpy(s,sApp);             //copio il contenuto di sApp in s 
}

int main(){
    char stringa[LUNG];         //strinfa inserita dall'utente
    int scelta;                 //scelta del menu

    do{
        do{                     //stampa del menu fino a che non viene selezionata una scelta
            printf("0. Esci\n1. Decoding\n2. Encoding\n");
            scanf("%d",&scelta);
        }while(scelta<0||scelta>2);

        switch(scelta){
            case(0):            //uscita dal programma 
                printf("Uscita\n");
            break;

            case(1):            //lettura di stringa e in seguito stampa del decoding
                printf("Inserire la stringa: ");
                fflush(stdin);
                scanf("%s",stringa);
                decoding(stringa,LUNG);
                printf("Decoding: %s\n",stringa);
            break;
            case(2):            //lettura di stringa e in seguito stampa del encoding
                printf("Inserire la stringa: ");
                fflush(stdin);
                scanf("%s",stringa);
                encoding(stringa,LUNG);
                printf("Encoding: %s\n",stringa);
            break;
        }

    }while(scelta != 0);


}
