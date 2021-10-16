#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void bubblesort(int *v, int n){
int i, j, aux;
  for(i=0; i<n; i++){
     for(j=0; j<n-1; j++){
         if(v[j]>v[j+1]) {
         aux=v[j];
         v[j]=v[j+1];
         v[j+1]=aux;
         }
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
    printf ("\n\nbubblesort:\n");
    bubblesort(vet, n);
    tFim=clock();
    tQuickSort = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    for (i=0;i<n;i++){
        printf ("%d  ", vet[i]);
    }
    printf ("\nTempo gasto: %lf segundos\n", tQuickSort);

    return (0);
}
