#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void selecao (int vet[], int n, int *comp, int *troc){
    int i, j, Min, aux, l;
    for (i=0;i<n;i++){
        for(j=i+1; j<n; j++){
            if (vet[j]<vet[i]){
                aux=vet[j];
                vet[j]=vet[i];
                vet[i]=aux;
                (*troc)++;
            }
            (*comp)++;
        }
    }
}

int main (){
    int n, i, k, vet[50000], comp=0, troc=0;
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
    printf("\n\nSelecao:\n");
    selecao(vet, n, &comp, &troc);
    printf("\n");
    tFim=clock();
    tSelecao = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    printf ("Tempo gasto: %lf segundos", tSelecao);
    return (0);
}
