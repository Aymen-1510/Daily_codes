// Diese Program ist eine Alt_Klausur Aufgabe in Programmierung mit C.

#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct Bergen{
    char Name[20];
    char Ort[20];
    float höhe;
    int Erstbes;
} Bergen;

bool Gebirge(Bergen berg1, Bergen berg2){
    return !(strcmp(berg1.Ort,berg2.Ort)); // wert '0' gleich false '1' gleich true.
}

int main(){
    
    Bergen berg1,berg2;

    strcpy(berg1.Name,"Zugpitze");
    strcpy(berg1.Ort,"Alpen");
    berg1.höhe = 2962.02;
    berg1.Erstbes = 1820;

    strcpy(berg2.Name,"Aconcagua");
    strcpy(berg2.Ort,"Anden");
    berg2.höhe = 6960.8;
    berg2.Erstbes = 1897; 

    if(Gebirge(berg1,berg2))
        printf("Die beiden haben die gleiche Gebirge");
    else
        printf("Die beiden haben nicht die gleiche Gebirge");


    Bergen* berg = calloc(sizeof(Bergen),100);

    if(berg == NULL){
        printf("geht nicht");
        return 1;
    }

    strcpy(berg[0].Name,berg1.Name);
    strcpy(berg[0].Name,berg1.Name);
    berg[0].höhe = berg1.höhe;
    berg[0].Erstbes = berg1.Erstbes;
    
    strcpy(berg[1].Name,berg2.Name);
    strcpy(berg[1].Name,berg2.Name);
    berg[1].höhe = berg2.höhe;
    berg[1].Erstbes = berg2.Erstbes;

    free(berg);
    
}
 
