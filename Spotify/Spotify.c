/*
Author:Bongiovanni Daniele
4^Arob
*/

#include <stdlib.h>                
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25                     //Numero massimo di cartteri ipotizzato per i titoli delle canzoni e per i nomi degli artisti
#define N_CANZONI 11                //Numero di canzoni presenti nel CSV

typedef struct canzone{             //Struttura delle canzoni
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
    int ord;
}Canzone;

void visualizzaPlaylist(Canzone play[],int num){        //Funzione che ricevendo un vettore di Canzoni, ne stampa il contenuto 
    for(int k=0; k<num; k++){
        printf("->%d %s - %s\n",play[k].num,play[k].nome_canzone,play[k].artista);
    }
}

void letturaCanzArt(FILE *f,Canzone p[], int num){      //Lettura del file CSV.
    int cnt=0;
    char carattere, strProv[LUNG];                      //strProv è un vettore dove vengono salvate provvisoriamente i cartteri letti.

    //Lettura del nome della canzone. La lettura avviene carattere per carattere.La lettura del nome della canzone termina quando viene letto il carattere ","
    fscanf(f,"%c",&carattere);
    while(carattere!=','){
        strProv[cnt]=carattere;
        cnt++;
        fscanf(f,"%c",&carattere);
    }
    strProv[cnt]='\0';
    strcpy(p[num].nome_canzone,strProv);                

    cnt=0;
    memset(strProv,0,LUNG);                             //Viene resettato strProv per la lettura del nome dell'artista//

    //Lettura del nome dell artista. La lettura avviene nello stesso modo della lettura del titolo della canzone
    fscanf(f,"%c",&carattere);
    while(carattere!='\n'){
        strProv[cnt]=carattere;
        cnt++;
        fscanf(f,"%c",&carattere);
    }
    strProv[cnt]='\0';
    strcpy(p[num].artista,strProv);
}

void randomRiproduzione(Canzone p[], int num){          //Funzione per ordinare in modo randomico le canzoni 
    int sort,vNumSort[LUNG];                            //sort è il numero che viene sorteggiato. vNumSort è il vettore dove vengono salvati i numeri già sorteggiati. 
    bool uguale;

    srand(time(NULL));
    for(int k=0;k<num;k++){
        do{
            uguale=false;
            sort=rand()%num;
            for(int i=0; i<k; i++){
                if(vNumSort[i]==sort){
                    uguale=true;
                    break;
                }
            }
        }while(uguale==true);
        vNumSort[k]=sort;
    }
    for(int j=0;j<num;j++){                             //Stampa delle canzoni in ordine randomico
        printf("->%d %s - %s\n",p[vNumSort[j]].num,p[vNumSort[j]].nome_canzone,p[vNumSort[j]].artista);
    }
}

int main(){
    FILE *fp;
    Canzone playlist[N_CANZONI];                        //Vettore per le canzoni lette nel ordine del CSV
    Canzone riproduzione[N_CANZONI];                    //Vettore per le canzoni ordinate in modo randomico
    int cntNumCanz,cnt;                                 

    if((fp=fopen("canzoni.csv","r"))==NULL){            //Apertura del file CSV
        printf("File non esistente");
    }else{
        cntNumCanz=0;//contatore delle canzone inserite
        while(fscanf(fp,"%d,",&playlist[cntNumCanz].num)!=EOF){
            letturaCanzArt(fp,playlist,cntNumCanz);
            //Incremnto cntNumCanz perchè ho completato la lettura della riga
            cntNumCanz++;
        }
        visualizzaPlaylist(playlist,cntNumCanz);
        printf("\n\nElenco riproduzione casuale:\n\n");
        randomRiproduzione(playlist,cntNumCanz);
    }
    return 0;
}
