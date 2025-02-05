// author Aymen Zayen
// Datum: 2/5/2025

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool larger(int x,int y){
    return x > y;
}

bool smaller(int x,int y){
    return x < y;
}

void vertausche(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(int n,int* Feld,bool (*comp)(int,int)){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(comp(Feld[j-1],Feld[j]))
                vertausche(&Feld[j-1],&Feld[j]);
        }
    }
}

int main(){
    bool (*comp)(int,int);
    int n;
    char ant = 0;
    
    
    printf("wie viele Zahlen sollen eingelesen werden?");
    scanf("%d",&n);

    int* Zahlen = malloc(sizeof(int)*n);

   
    printf("Soll aufsteigend (a) oder absteigend (b) sortiert werden?");
    scanf(" %c", &ant);

    printf("Geben Sie %d zahlen ein:\n",n);
    for(int i = 0; i < n; i++)
        scanf("%d",&Zahlen[i]);

    if(ant == 'a')
        comp = larger;
    else if(ant == 'b')
        comp = smaller;
    
    sort(n,Zahlen,comp);

    for(int i = 0; i < n; i++)
        printf("%d,",Zahlen[i]);

    free(Zahlen);
}

