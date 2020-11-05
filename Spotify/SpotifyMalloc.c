/*
Author:Bongiovanni Daniele
4^Arob
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG_R 100
#define LUNG 25
#define N_CANZONI 11

typedef struct canzone{
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
}Canzone;

void visualizzaPlaylist(Canzone play[],int num){
    for(int k=0; k<num; k++){
        printf("->%d %s - %s\n",play[k].num,play[k].nome_canzone,play[k].artista);
    }
}

int letNumRighe(FILE *f){
    char *riga= malloc(50*sizeof(char));
    int cnt=0;

    while(fgets(riga,LUNG_R,f)){
        cnt++;
    }
    free(riga);
    fclose(f);
    return cnt;
}
void lettura(FILE *f, Canzone *p, int num){
    char *riga =malloc(50*sizeof(char));

    for(int k=0;k<num; k++){
        fgets(riga,50*sizeof(char),f);
        p->num=atoi(strtok(riga,","));
        strcpy(p->nome_canzone,strtok(NULL,","));
        strcpy(p->artista,strtok(NULL,"\n"));
        p++;
    }
}

void randomRiproduzione(Canzone *p, int num){
    int sort;
    int *vNumSort= malloc(num*sizeof(int));
    bool uguale;

    srand(time(NULL));
    for(int k=0;k<num;k++){
        do{
            uguale=false;
            sort=rand()%num;
            for(int i=0; i<k; i++){
                if((sort+1)==*(vNumSort+i)){
                    uguale=true;
                    break;
                }
            }
        }while(uguale==true);
        *vNumSort=sort;
        printf("->%d %s - %s\n",(p+(*vNumSort))->num,(p+(*vNumSort))->nome_canzone,(p+(*vNumSort))->artista);
        vNumSort++;
    }
}

int main(){
    FILE *fp;
    Canzone *playlist=malloc(N_CANZONI*sizeof(Canzone));
    int cntNumCanz;

    if((fp=fopen("canzoni.csv","r"))==NULL){
        printf("File non esistente");
    }else{
        cntNumCanz= letNumRighe(fp);//contatore delle canzone inserite
        fp=fopen("canzoni.csv","r");
        lettura(fp,playlist,cntNumCanz);
        visualizzaPlaylist(playlist,cntNumCanz);
        printf("\n\nElenco riproduzione casuale:\n\n");
        randomRiproduzione(playlist,cntNumCanz);
    }
    return 0;
}
