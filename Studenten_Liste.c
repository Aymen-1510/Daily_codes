#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Student {
    char Nachname[30];
    long Matrikelnummer;
    long Punktzahl;
} Student;

typedef bool(*Testen)(int,Student);

void Einlesen(int n,Student* Student){
    for(int i = 0; i < n; i++){
         printf("Nachname Matrikelnummer Punktzahl: ");
        scanf("%s %ld %ld",Student[i].Nachname,&Student[i].Matrikelnummer,&Student[i].Punktzahl);
    }
}

bool Prüfen(int a,Student Student){
    return Student.Punktzahl > a;
}

void Ausgeben(int a,int n,Student* Student,Testen P){
    printf("Bestanden:\n");
    for(int i = 0; i < n; i++){
        if(P(a,Student[i]))
            printf("%s %ld %ld\n",Student[i].Nachname,Student[i].Matrikelnummer,Student[i].Punktzahl);
    }
    
}

int main(){
    Student student[100];
    int n;
    int g;
    printf("wie viel Student gibt es überhaupt?: ");
    scanf("%d",&n);

    Einlesen(n,student);

    printf("wie viel Punkte brauchen Sie zum Bestehen?: ");
    scanf("%d",&g);
    
    Ausgeben(g,n,student,Prüfen);
      
    }