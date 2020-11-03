/*
Author:Bongiovanni Daniele
4^Arob
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
#define N_CANZONI 11

typedef struct canzone{
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
    int ord;
}Canzone;

void visualizzaPlaylist(Canzone play[],int num){
    for(int k=0; k<num; k++){
        printf("->%d %s - %s\n",play[k].num,play[k].nome_canzone,play[k].artista);
    }
}

void letturaCanzArt(FILE *f,Canzone p[], int num){
    int cnt=0;
    char carattere, strProv[LUNG];

    //Lettura del nome della canzone
    fscanf(f,"%c",&carattere);
    while(carattere!=','){
        strProv[cnt]=carattere;
        cnt++;
        fscanf(f,"%c",&carattere);
    }
    strProv[cnt]='\0';
    strcpy(p[num].nome_canzone,strProv);

    cnt=0;
    memset(strProv,0,LUNG);

    //Lettura del nome dell artista
    fscanf(f,"%c",&carattere);
    while(carattere!='\n'){
        strProv[cnt]=carattere;
        cnt++;
        fscanf(f,"%c",&carattere);
    }
    strProv[cnt]='\0';
    strcpy(p[num].artista,strProv);
}

void randomRiproduzione(Canzone p[], int num){
    int sort,vNumSort[LUNG];
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
    for(int j=0;j<num;j++){
        printf("->%d %s - %s\n",p[vNumSort[j]].num,p[vNumSort[j]].nome_canzone,p[vNumSort[j]].artista);
    }
}

int main(){
    FILE *fp;
    Canzone playlist[N_CANZONI];
    Canzone riproduzione[N_CANZONI];
    int cntNumCanz,cnt;
    char carattere,canzProv[LUNG],artProv[LUNG];

    if((fp=fopen("canzoni.csv","r"))==NULL){
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
