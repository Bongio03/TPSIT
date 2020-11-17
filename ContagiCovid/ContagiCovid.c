/*Creare un programma in C che facendo uso di array dinamici e della aritmetica dei puntatori (OBBLIGATORIO), legga il file https://raw.githubusercontent.com/conradis/TPSIT-classi-quarte/main/Esercitazioni/data.csv
e lo carichi in memoria.
Successivamente calcolare:
1) top 3 delle regioni per numero di ricoveri in terapia intensiva
2) totale dei ricoverati in terapia intensiva
3) top 3 delle regioni con meno casi totali positivi.
Daniele Bongiovanni
4^AROB
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_REG 3
#define NOME_REG 25
#define LUNG_R 1000

typedef struct datiContagio{
    char *nomeRegione;
    int numRicoveriTerInt;
    int casiTotaliPositivi;
}DatiContagio;

int contReg(FILE *fin){
    int cnt=0;
    char *riga = malloc(LUNG_R*sizeof(char));
    

    while (fgets(riga,LUNG_R,fin)){
        cnt++;
    }
    free(riga);
    fclose(fin);
    return cnt;
}


void lettura(FILE *fin, DatiContagio *r, int num){
    int cnt;
    char *riga = malloc(LUNG_R*sizeof(char));
    char *datiNonUsati= malloc(50*sizeof(char));

    fgets(riga,LUNG_R,fin);
    for(int k=0; k<num-1; k++){
        fgets(riga,LUNG_R,fin);
        strcpy(datiNonUsati,strtok(riga,","));
        strcpy(datiNonUsati,strtok(NULL,","));
        strcpy(datiNonUsati,strtok(NULL,","));
        r->nomeRegione=malloc(NOME_REG*sizeof(char));
        strcpy(r->nomeRegione,strtok(NULL,","));
        strcpy(datiNonUsati,strtok(NULL,","));
        strcpy(datiNonUsati,strtok(NULL,","));
        strcpy(datiNonUsati,strtok(NULL,","));
        r->numRicoveriTerInt=atoi(strtok(NULL,","));
        strcpy(datiNonUsati,strtok(NULL,","));
        strcpy(datiNonUsati,strtok(NULL,","));
        r->casiTotaliPositivi=atoi(strtok(NULL,","));
        printf("%s %d %d\n",r->nomeRegione,r->numRicoveriTerInt,r->casiTotaliPositivi);
        r++;
    }
    free(datiNonUsati);
    free(riga);
}

void regPiuRic(DatiContagio *r, int num){
    int max1=0, max2=0, max3=0, totali_ricoverati=0;
    int *posReg= malloc(MAX_REG*sizeof(int));
    
    totali_ricoverati+=(r+max1)->numRicoveriTerInt;
    for(int i=1; i<num-1;i++){
        if((r+max1)->numRicoveriTerInt<(r+i)->numRicoveriTerInt){
            max1=i;
        }
        totali_ricoverati+=(r+i)->numRicoveriTerInt;
    }
    for(int i=1; i<num-1;i++){
        if((r+max2)->numRicoveriTerInt<(r+i)->numRicoveriTerInt && i!=max1){
            max2=i;
        }
    }
    for(int i=1; i<num-1;i++){
        if((r+max3)->numRicoveriTerInt>(r+i)->numRicoveriTerInt && i!=max1 && i!=max2){
            max3=i;
        }
    }
    *posReg=max1;
    *(posReg+1)=max2;
    *(posReg+2)=max3;
    printf("\nRegioni con piu ricoveri in terapia intensiva:\n1. %s %d\n2. %s %d\n3. %s %d\n",(r+*(posReg))->nomeRegione,(r+*(posReg))->numRicoveriTerInt,(r+*(posReg+1))->nomeRegione,(r+*(posReg+1))->numRicoveriTerInt,(r+*(posReg+2))->nomeRegione,(r+*(posReg+2))->numRicoveriTerInt);
    printf("\nTotali ricoverati in terapia intensiva: %d\n",totali_ricoverati);
    free(posReg);
}

void regMenoCasi(DatiContagio *r, int num){
    int min1=0, min2=0, min3=0;
    int *posReg= malloc(MAX_REG*sizeof(int));
    
    for(int i=1; i<num-1;i++){
        if((r+min1)->casiTotaliPositivi>(r+i)->casiTotaliPositivi){
            min1=i;
        }
    }
    for(int i=1; i<num-1;i++){
        if((r+min2)->casiTotaliPositivi>(r+i)->casiTotaliPositivi && i!=min1){
            min2=i;
        }
    }
    for(int i=1; i<num-1;i++){
        if((r+min3)->casiTotaliPositivi>(r+i)->casiTotaliPositivi && i!=min1 && i!=min2){
            min3=i;
        }
    }
    *posReg=min1;
    *(posReg+1)=min2;
    *(posReg+2)=min3;
    printf("\nRegioni con meno casi positivi:\n1. %s %d\n2. %s %d\n3. %s %d\n",(r+*(posReg))->nomeRegione,(r+*(posReg))->casiTotaliPositivi,(r+*(posReg+1))->nomeRegione,(r+*(posReg+1))->casiTotaliPositivi,(r+*(posReg+2))->nomeRegione,(r+*(posReg+2))->casiTotaliPositivi);
    free(posReg);
}

int main(){
    DatiContagio *regioni; 
    FILE *f;
    int nReg;

    if((f=fopen("data.csv","r"))!=NULL){
        nReg = contReg(f);
        regioni = malloc((nReg-1)*sizeof(DatiContagio));
        f=fopen("data.csv","r");
        lettura(f,regioni,nReg);
        regPiuRic(regioni,nReg);
        regMenoCasi(regioni,nReg);
    }else{
        printf("Nessun file in input");
    }

    return 0;
}