#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

void Heapsort(int a[], int n)
{
   int i = n/2, pai, filho, t;

   for (;;)
   {
      if (i > 0)
      {
          i--;
          t = a[i];
      }
      else
      {
          n--;
          if (n == 0)
             return;
          t = a[n];
          a[n] = a[0];
      }

      pai = i;
      filho = i*2 + 1;

      while (filho < n)
      {
          if ((filho + 1 < n)  &&  (a[filho + 1] < a[filho]))
              filho++;
          if (a[filho] < t)
          {
             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      a[pai] = t;
   }
}

int main (){
    int n, i, k, vet[50001], comp=0, troc=0;
    clock_t tInicio, tFim;
    double tHeapsort;

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
    printf ("\n\nHeapsort:\n");
    Heapsort(vet, n);
    tFim=clock();
    tHeapsort = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    printf ("\nTempo gasto: %lf segundos\n", tHeapsort);
    for (i=0;i<n;i++){
        printf ("%d  ", vet[i]);
    }

    return (0);
}
