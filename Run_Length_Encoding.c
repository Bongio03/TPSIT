/*
Author:Bongiovanni Daniele
4^Arob
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 100 //Limite di lunghezze della stinga inserita

void decoding(char s[], int dim){   //Procedura per effettuare decoding 
    int num,cnt=0;  
    char sApp[dim], lett;
    bool trovato=false;

    for(int k=0; k<strlen(s); k++){
        if(trovato==false){
            if((s[k])>'0' && (s[k])<='9'){  
                num=s[k]-'0';
                trovato=true;
            }else{
                sApp[cnt]=s[k];     
                cnt++;
            }
        }else{
            lett=s[k];
            for(int i=0; i<num; i++){
                sApp[cnt]=lett;
                cnt++;
            }
            trovato=false;
        }
    }
    sApp[cnt]='\0';
    strcpy(s,sApp);
}

    void encoding(char s[],int dim){    //Procedura per effettuare l'encoding
    char lett,sApp[dim];
    int cntLet=1,cnt=0;

    lett=s[0];
    for(int k=1; k<strlen(s)+1; k++){
        if(lett!=s[k]){
            if(cntLet==1){
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
    sApp[cnt]='\0';
    strcpy(s,sApp);
}

int main(){
    char stringa[LUNG];
    int scelta;

    do{
        printf("0. Esci\n1. Decoding\n2. Encoding\n");
        scanf("%d",&scelta);

        switch(scelta){     //Menù
            case(0): //Scelta per uscita dal programma
                printf("Uscita\n");
            break;

            case(1):        //Scelta per il decoding
                printf("Inserire la stringa: ");
                fflush(stdin);
                scanf("%s",stringa);
                decoding(stringa,LUNG);
                printf("Decoding: %s\n",stringa);
            break;
            case(2):        //Scelta per l'encoding
                printf("Inserire la stringa: ");
                fflush(stdin);
                scanf("%s",stringa);
                encoding(stringa,LUNG);
                printf("Encoding: %s\n",stringa);
            break;
        }

    }while(scelta != 0);


}
