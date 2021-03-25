//Verifica Bongiovanni
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LUNG_R 50
#define LUNG_ERR 25

//struttura del volo, vengono assegnati i valori di "Volo_drone.csv"
typedef struct volo{
    int tempo;
    float latitudine;
    float longitudine;
}Volo;

//struttura delle anomalie, vengono assegnati i valori di "Anomalie_drone.csv"
typedef struct anomalie{
    int tempo;
    char *tipo;
}Anomalie;

//funzione utile a contare e restituire il numero intero di righe
int letNumRighe(FILE *f){
    char *riga= malloc(LUNG_R*sizeof(char));    //Alloco dello spazio in memoria per salvare le righe lette;
    int cnt=0;                                  //Contatore delle righe;

    while(fgets(riga,LUNG_R,f)){
        cnt++;
    }
    free(riga);                                 //Libero lo spazio allocato per riga
    fclose(f);
    return cnt;                                 //Restituisco il contatore
}

//Funzione per la lettura e l'assegnamento dei dati presenti in Volo_drone.csv nella struttura droneVolo
void letturaVoloDrone(FILE *f,Volo *d,int num){
    char *riga =malloc(LUNG_R*sizeof(char));    //Alloco dello spazio in memoria per salvare le righe lette;

    fgets(riga,LUNG_R,f);                       //Eseguo una fgets esterna al ciclo per la lettura dell'intestazione
    for(int k=0;k<num-1; k++){                  //num-1 perché una riga è occupata dall'intestazione
        fgets(riga,LUNG_R,f);
        d->tempo=atoi(strtok(riga,","));        
        d->latitudine=atof(strtok(NULL,","));
        d->longitudine=atof(strtok(NULL,"\n"));
        d++;
    }
    free(riga);                                 //Libero lo spazio allocato per riga
}

//Funzione per la lettura e l'assegnamento dei dati presenti in Anomalie_drone.csv nella struttura erorri
void letturaAnomalie(FILE *f,Anomalie *e,int num){
    char *riga =malloc(LUNG_R*sizeof(char));    //Alloco dello spazio in memoria per salvare le righe lette;

    fgets(riga,LUNG_R,f);                       //Eseguo una fgets esterna al ciclo per la lettura dell'intestazione            
    for(int k=0;k<num-1; k++){                  //num-1 perché una riga è occupata dall'intestazione
        fgets(riga,LUNG_R,f);
        e->tempo=atoi(strtok(riga,","));        
        e->tipo=malloc(LUNG_ERR*sizeof(char));  //devo allocare ora perché non ho ancora alllocato lo spazio per la lettura della stringa in precedenza 
        strcpy(e->tipo,strtok(NULL,"\n"));
        e++;
    }
    free(riga);                                 //Libero lo spazio allocato per riga
}

//Stampa della latitudine e longitudine delle anomalie
void latLongAnomalie(Volo *d, Anomalie *e, int numD, int numE){
    bool trovato;                               //Variabile booleane che diventa true quando trovo la corrispondenza tra il tempo di volo e quelllo di errori
    int i;                                      //contatore per lo scorrimento della struttura volo
    printf("\nErrori: (tempo, lat, long, tipo)\n");
    for(int k=0; k<numE-1; k++){                //scorrimento della strttura errori
        trovato=false;
        i=0;
        while(trovato==false || i<numD-1 ){     //Scorrimento della struttura volo
            if((e+k)->tempo==(d+i)->tempo){
                printf("%d %f %f %s\n",(e+k)->tempo,(d+i)->latitudine,(d+i)->longitudine,(e+k)->tipo);
                trovato=true;
            }
            i++;
        }
    }
}
int main(){
    FILE *fVolo, *fAnom;
    int cntNumDati,cntNumAnom;
    Volo *droneVolo;
    Anomalie *errori;

    if((fVolo=fopen("Volo_drone.csv","r"))==NULL){
        printf("File Volo_drone non esistente");
    }else{
        cntNumDati=letNumRighe(fVolo);          //conto quanti dati devo salvare per poi allocare lo spazio esatto
        fclose(fVolo);
        fVolo=fopen("Volo_drone.csv","r");
        droneVolo = malloc((cntNumDati-1)*sizeof(Volo));
        letturaVoloDrone(fVolo,droneVolo,cntNumDati);
        fclose(fVolo);
        if((fAnom=fopen("Anomalie_drone.csv","r"))==NULL){
            printf("File Anomalie_drone non esistente");
        }else{
            cntNumAnom=letNumRighe(fAnom);      //conto quanti dati devo salvare per poi allocare lo spazio esatto
            fclose(fAnom);
            fAnom=fopen("Anomalie_drone.csv","r");
            errori=malloc((cntNumAnom-1)*sizeof(Anomalie));
            letturaAnomalie(fAnom,errori,cntNumAnom);
            fclose(fAnom);
            latLongAnomalie(droneVolo,errori,cntNumDati,cntNumAnom);
            free(droneVolo);
            free(errori);
        }
    }
    
    return 0;
}