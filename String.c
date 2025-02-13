// Autor: Aymen Zayen

#include<stdio.h>
#include<string.h>
#include<ctype.h>

enum {n = 20,N = 100};

//Zeiger auf Funktionen
typedef void (*Funktion)(char* Text);


// Drei Funktionen für Ersetzen
void Lesen(char* alt,char* neu){

    printf("geben Sie bitte den altString:\n");
    fgets(alt,n,stdin);
    alt[strlen(alt) - 1] = '\0';

    printf("geben Sie bitte den neuString:\n");
    fgets(neu,n,stdin);
    neu[strlen(neu) - 1] = '\0';
     
}

int Anfang(char* Text,char* alt){
    int i = 0;
    int grenze = strlen(Text) - strlen(alt);
    
    while(Text[i] != '\0'){
        if(strncmp(Text + i,alt,strlen(alt)) == 0)
            break;
        if(i >= grenze)
            return -1;
        i++;
    }
    return i;
}

void Ersetzen(char* Text){

    char alt[n];
    char neu[n];

    Lesen(alt,neu);

    int a = Anfang(Text,alt);
    
     if(a == -1){
        printf("Der alt String nicht gefunden");
        return;
    }
    
    for(int i = 0; i < strlen(neu);i++)
        Text[a + i] = neu[i];
}

// text schreiben
void Ausgeben(char* Text){
    printf("%s",Text);
}

void ToUpper(char* Text){
    for(int i = 0; i < strlen(Text); i++)
        if(!isupper(Text[i]))
            Text[i] = toupper(Text[i]);
}

void ToLower(char* Text){
    for(int i = 0; i < strlen(Text); i++)
        if(!islower(Text[i]))
            Text[i] = tolower(Text[i]);
}

// digits im Text zählen
void digit_Zahl(char* Text){
    int Zahl = 0;
    for(int i = 0; i < strlen(Text); i++){
        if(isdigit(Text[i]))
            Zahl++;
    }
    printf("Es gibt %d Zahlen in diesem Text.",Zahl);
}

//Zeichnen in Text zählen
void alpha_Zahl(char* Text){
    int Zahl = 0;
    for(int i = 0; i < strlen(Text); i++){
        if(isalpha(Text[i]))
            Zahl++;
    }
    printf("Es gibt %d Buchstaben in diesem Text:\n",Zahl);
}

int main(){

    Funktion funk;

    int antwort;
    
    char Text[N];

    printf("Welche Funktion möchten Sie nutzen?\n1.Ersetzen.\n2.Alle Buchstaben groß machen.\n3.Alle Buchstaben klein machen.\n4.Zahlen im Text zählen.\n5.Buchstaben im Text zählen.\n");
    scanf("%d",&antwort);

    while(getchar() != '\n');

     printf("geben Sie bitte den Text:\n");
    fgets(Text,N,stdin);
    Text[strlen(Text) - 1] = '\0';


    switch(antwort){
        case 1: funk = Ersetzen; break;
        case 2: funk = ToUpper; break;
        case 3: funk = ToLower; break;
        case 4: funk = digit_Zahl; break;
        case 5: funk = alpha_Zahl; break;
        
    }
    funk(Text);
    Ausgeben(Text);
    
}
