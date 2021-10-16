#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


void shellsort (int vet[], int n){
    int i, j, h=1, x;

    do h = h*3+1; while (h<n);
    do{
        h/=3;
        for (i=h; i<n; i++){
            x=vet[i];
            j=i-h;
            while(j>=0 && vet[j]<x){
                vet[j+h] = vet[j];
                j-=h;
            }
            vet[j+h]=x;
        }
    }while(h!=0);

    for (i=0;i<n;i++){
        printf ("%d  ", vet[i]);
    }
}

int main (){
    int n, i, k, vet[50000];
    clock_t tInicio, tFim;
    double tSelecao, tInsercao, tShellsort, tQuickSort;

    srand(time(NULL));

    printf ("Entre com a quantidade de numeros a ser testada:   ");
    scanf ("%d", &n);

    for (i=0; i<n; i++){
        vet[i] = rand()%n;
        for (k=0; k<i; k++){
            if(vet[k]==vet[i]){
                vet[i]=rand()%n;
                k=-1;
            }
        }
    }

    for (i=0; i<n; i++){
        printf ("%d  ", vet[i]);
    }

    tInicio=clock();
    printf ("\n\nShellsort:\n");
    shellsort (vet, n);
    tFim=clock();
    tShellsort = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    printf ("\nTempo gasto: %lf segundos", tShellsort);

    return (0);
}
