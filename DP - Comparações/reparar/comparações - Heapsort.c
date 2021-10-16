#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

void Refaz (int esq, int dir, int vet[]){
    int i=esq, j, x;
    j=i*2;
    x=vet[i];
    while (j <= dir){
        if (j<dir){
            if (vet[j]<vet[j+1]){
                j++;
            }
            if (x<vet[j]){
                vet[i]=vet[j];
                i=j;
                j=i*2;
            }
        }
        vet[i] = x;
    }
}

void Constroi (int vet[], int n){
    int esq;
    esq = n / 2 + 1;
    while (esq > 0){
        esq--;
        Refaz(esq, n, vet);
    }
}

int RetiraMax (int vet[], int *n){
    int Max;
    if (*n < 0){
        printf ("Erro: Heap vazio!\n");
    } else {
        Max = vet[0];
        vet[0]=vet[*n];
        (*n)--;
        Refaz(0, *n, vet);
    }
    return Max;
}

void AumentaChave (int i, int NovaChave, int vet[]){
    int x;
    if (NovaChave < vet[i]){
        printf ("Erro: ChaveNova menor que a chave atual.\n");
        return;
    }
    vet[i] = NovaChave;
    while (i > 0 && vet[i/2] < vet[i]){
        x = vet[i/2];
        vet[i/2] = vet[i];
        vet[i] = x;
        i /= 2;
    }
}

void Insere (int *x, int vet[], int *n){
    (*n)++;
    vet[*n]=*x;
    vet[*n]= INT_MIN;
    AumentaChave(*n, *x, vet);
}

void Heapsort (int vet[], int n){
    int esq, dir, x;

    Constroi(vet, n);
    esq = 0;
    dir = n-1;

    while (dir>0){
        x = vet[0];
        vet[0] = vet[dir];
        vet[dir] = x;
        dir--;
        Refaz(esq, dir, vet);
    }
}

int main (){
    int n, i, k, vet[50000], comp=0, troc=0;
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
    Heapsort(&vet, n-1);
    tFim=clock();
    tHeapsort = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    printf ("Tempo gasto: %lf segundos\n", tHeapsort);
    for (i=1;i<=n;i++){
        printf ("%d  ", vet[i]);
    }

    return (0);
}
