/*
Nome: Patrick Pierre Fernandes Ferreira
Descrição: Trabalho desenvolvido para a disciplina de Algoritimos e Estruras de Dados II
Data da ultima atualização: 18/10/2011
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void Particao (int esq, int dir, int *i, int *j, int vet[], int *comp, int *troc){
    int pivo, aux, k;
    *i=esq;
    *j=dir;
    pivo = vet[(*i+*j)/2]; /*OBTEM O PIVÔ*/
    do{
        while (pivo<vet[*i]){
            (*i)++;
            (*comp)++;
        }
        while (pivo>vet[*j]){
            (*j)--;
            (*comp)++;
        }
        if (*i <= *j){
            aux=vet[*i];
            vet[*i]=vet[*j];
            vet[*j]=aux;
            (*i)++;
            (*j)--;
            (*troc)++;
        }
    } while (*i < *j);
}

void Ordena (int esq, int dir, int vet[], int *comp, int *troc){
    int i, j;
    Particao (esq, dir, &i, &j, vet, comp, troc);
    (*comp)++;
    if (esq<j) Ordena (esq, j, vet, comp, troc);
    (*comp)++;
    if (i<dir) Ordena (i, dir, vet, comp, troc);
}

void QuickSort(int vet[], int n, int *comp, int *troc){
    Ordena (0, n, vet, comp, troc);
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
    printf ("\n\nQuickSort:\n");
    QuickSort(vet, n-1, &comp, &troc);
    tFim=clock();

    for (i=0; i<n; i++){
        printf ("%d  ", vet[i]);
    }


    tQuickSort = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    printf ("\nTempo gasto: %lf segundos\n", tQuickSort);
    printf ("\nNumero de comparacoes: %d", comp);
    printf ("\nNumero de trocas: %d", troc);

    return (0);
}
