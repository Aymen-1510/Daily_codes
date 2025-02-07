


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Teilnehmer {

 char nachname[30];
 int  matrikel_nummer;
 int punkte;

 struct Teilnehmer* nachste;
}Teilnehmer;

Teilnehmer* neuer_teilnehmer(){
    
    //teinehmer herstellen
    Teilnehmer* neuer = malloc(sizeof(Teilnehmer));
    if(neuer == NULL) {
        printf("geht nicht");
        return 0;
    }

    //teilnehmer inizialisieren
    printf("Nachname Matrikelnummer Punktzahl: ");
    scanf("%s %d %d",neuer->nachname,&neuer->matrikel_nummer,&neuer->punkte);
    neuer->nachste = NULL;
    
    return neuer;   
}

void Teilnehmer_hinzufügen(Teilnehmer** kopf){
    Teilnehmer* neuer = neuer_teilnehmer();

    if(*kopf == NULL){
        *kopf = neuer;
        return;
    }
    
    //zum ende der Liste weitergehen und der neue Teilnehmer hinzufügen
    Teilnehmer* tmp = *kopf;
    while (tmp->nachste != NULL) { // Zum letzten Knoten gehen
        tmp = tmp->nachste;
    }
    tmp->nachste = neuer;
    
}

void Prüfen_Ausgeben(int p,Teilnehmer* kopf){
    Teilnehmer* teilnehmer = kopf;
    while (teilnehmer != NULL){
        if(teilnehmer->punkte > p)
            printf("%s %d %d\n",teilnehmer->nachname,teilnehmer->matrikel_nummer,teilnehmer->punkte);
        
        teilnehmer = teilnehmer->nachste;
        }
        
    }

void Liste_Freigeben(Teilnemer** kopf){
    Teilnehmer* tmp;
    while(*kopf != NULL) {
    tmp = *kopf;
    *kopf = (*kopf)->nachste;
    free(tmp);
    }
}
    
int main() {
    Teilnehmer* kopf = NULL;
   
    int p;
    int antwort = 0;
   
    while(antwort == 0){ 
        Teilnehmer_hinzufügen(&kopf);
         printf("Teilnehmer hinzufügen?(ja:0,nein:1): ");
         scanf("%d",&antwort);
    }
     printf("wie viele Punkte werden zum Bestehen gebraucht?");
    scanf("%d",&p);

    Prüfen_Ausgeben(p,kopf);
    Liste_Freigeben(&kopf);
}

