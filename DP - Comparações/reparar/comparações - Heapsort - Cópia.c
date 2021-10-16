#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define MaxTam 50001

int ObtemFilhoMenor (int vet[], int FilhoEsquerdo, int FilhoDireito, int n){
    int min, IndiceMin;
    if (FilhoEsquerdo <= n && FilhoDireito <= n){
        min = vet[FilhoEsquerdo];
        IndiceMin = vet[FilhoDireito];
        if (min > vet[FilhoDireito]){
            min = vet[FilhoDireito];
            IndiceMin = FilhoDireito;
        }
        return IndiceMin;
    } else if (FilhoEsquerdo <= n && FilhoDireito > n){
        return FilhoEsquerdo;
    } else if (FilhoDireito <= n && FilhoEsquerdo > n){
        return FilhoDireito;
    } else {
        return n+1;
    }
}

int ObtemFilhoMaior (int vet[], int FilhoEsquerdo, int FilhoDireito, int n){
    int max, IndiceMax;
    if (FilhoEsquerdo <= n && FilhoDireito <= n){
        max = vet[FilhoEsquerdo];
        IndiceMax = vet[FilhoDireito];
        if (max < vet[FilhoDireito]){
            max = vet[FilhoDireito];
            IndiceMax = FilhoDireito;
        }
        return IndiceMax;
    } else if (FilhoEsquerdo <= n && FilhoDireito > n){
        return FilhoEsquerdo;
    } else if (FilhoDireito <= n && FilhoEsquerdo > n){
        return FilhoDireito;
    } else {
        return n+1;
    }
}

int Rebaixa (int i, int vet[], int n){
    int FilhoEsquerdo, FilhoDireito, FilhoMaior, FilhoMenor, aux;
    while (i <= n){
        FilhoEsquerdo = 2 * i;
        FilhoDireito = 2 * i + 1;
        FilhoMaior = ObtemFilhoMaior(vet, FilhoEsquerdo, FilhoDireito, n);
        FilhoMenor = ObtemFilhoMenor(vet, FilhoEsquerdo, FilhoDireito, n);
        if (FilhoMaior <= n && vet[i] < vet[FilhoMaior]){
            aux = vet[FilhoMaior];
            vet[FilhoMaior] = vet[i];
            vet[i] = aux;
            i = FilhoMaior;
        } else if (FilhoMenor <= n && vet[i] < vet[FilhoMenor]){
            aux = vet[FilhoMenor];
            vet[FilhoMenor] = vet[i];
            vet[i] = aux;
            i = FilhoMenor;
        } else {
            return i;
        }
    }
    return i;
}

int RetiraMax (int vet[], int n){
    int Max;
    if (n > 1){
        Max = vet[1];
        vet[1] = vet[n];
        n--;
        Rebaixa(1, vet, n);
    } else if (n == 1){
        Max = vet[1];
        n = 0;
    } else {
        Max = -1;
    }
    return Max;
}

int Promove (int vet[], int i, int n){
    int aux;
    while (i > 1){
        if (vet[i] > vet[i/2]){
            aux = vet[i];
            vet[i] = vet[i/2];
            vet[i/2] = aux;
            i = i/2;
        } else {
            return i;
        }
    }
    return i;
}

int Insere (int x, int vet[], int n){
    int indicex = -1;
    n = n+1;
    if (n < MaxTam){
        vet[n] = x;
        indicex = n;
        indicex = (Promove(vet, indicex, n));
    }
    return (indicex);
}

void Heapsort (int vet[], int n){
    int i = vet[n];
    for (i = n - 1; i >= 0; i--){
        vet [i] = RetiraMax(vet, n);
    }
}

int main (){
    int n, i, k, vet[MaxTam], comp=0, troc=0;
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
    Heapsort(vet, n-1);
    tFim=clock();
    tHeapsort = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    printf ("Tempo gasto: %lf segundos\n", tHeapsort);
    for (i=1;i<=n;i++){
        printf ("%d  ", vet[i]);
    }

    return (0);
}
