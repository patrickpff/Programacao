/*
Nome: Patrick Pierre Fernandes Ferreira
Descrição: Trabalho desenvolvido para a disciplina de Algoritimos e Estruras de Dados II
Data da ultima atualização: 18/10/2011
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
/******************* PROTOTIPOS *********************/
//==================== QUICKSORT NORMAL ====================
void Particao (int esq, int dir, int *i, int *j, int vet[], int *comp, int *troc);
void Ordena (int esq, int dir, int vet[], int *comp, int *troc);
void QuickSort(int vet[], int n, int *comp, int *troc);
//==================== QUICKSORT ESTAVEL ====================
int pivot_estavel (int n, int vet[]);
void Particao_estavel (int esq, int dir, int *i, int *j, int vet[], int *comp, int *troc);
void Ordena_estavel (int esq, int dir, int vet[], int *comp, int *troc);
void QuickSort_estavel(int vet[], int n, int *comp, int *troc);
//==================== QUICKSORT - MEDIANA DE TRES ====================
int pivot_mediana_de_tres (int vet[], int esq, int dir);
void Particao_mediana_de_tres (int esq, int dir, int *i, int *j, int vet[], int *comp, int *troc);
void Ordena_mediana_de_tres (int esq, int dir, int vet[], int *comp, int *troc);
void QuickSort_mediana_de_tres(int vet[], int n, int *comp, int *troc);
//==================== OUTRAS FUNÇÕES ====================
void Reinicia_vet (int vet[], int pri[], int n);

int main (){
    int n, i, k, comp=0, troc=0, vet[50000], pri[50000];
    clock_t tInicio, tFim;
    double tQuickSort;
    FILE * Resultados_Quicksort;
    Resultados_Quicksort = fopen ("Resultados_Quicksort.txt", "w"); //Cria arquivo com permissão de escrita

    srand(time(NULL));

    for (k=0; k<3; k++){
        if (k == 0) n = 500;
        if (k == 1) n = 5000;
        if (k == 2) n = 50000;
        printf ("TESTE COM %d ELEMENTOS", n);
        printf (Resultados_Quicksort, "\nTESTE COM %d ELEMENTOS", n);
        for (i=0; i<n; i++){
            vet[i] = rand()%n;
            pri[i] = vet[i];
        }
        tInicio=clock();
        printf ("\n\nQuickSort Comum\n");
        fprintf (Resultados_Quicksort, "\nQuickSort Comum\n");
        QuickSort(vet, n-1, &comp, &troc);
        tFim=clock();
        tQuickSort = (((int)(tFim-tInicio))/CLOCKS_PER_SEC)*1000;
        printf ("\nTempo gasto: %lf Milesimos de segundo", tQuickSort);
        printf ("\nNumero de comparacoes: %d", comp);
        printf ("\nNumero de trocas: %d\n", troc);
        fprintf (Resultados_Quicksort, "\nTempo gasto: %lf  Milesimos de segundo", tQuickSort);
        fprintf (Resultados_Quicksort, "\nNumero de comparacoes: %d", comp);
        fprintf (Resultados_Quicksort, "\nNumero de trocas: %d\n", troc);

        Reinicia_vet (vet, pri, n);
        comp = 0; troc = 0;

        tInicio=clock();
        printf ("\n\nQuickSort Estavel\n");
        fprintf (Resultados_Quicksort, "\nQuickSort Estavel\n");
        QuickSort_estavel(vet, n-1, &comp, &troc);
        tFim=clock();
        tQuickSort = ((int)(tFim-tInicio))/CLOCKS_PER_SEC;
        printf ("\nTempo gasto: %lf Milesimos de segundo", tQuickSort);
        printf ("\nNumero de comparacoes: %d", comp);
        printf ("\nNumero de trocas: %d", troc);
        fprintf (Resultados_Quicksort, "\nTempo gasto: %lf Milesimos de segundo", tQuickSort);
        fprintf (Resultados_Quicksort, "\nNumero de comparacoes: %d", comp);
        fprintf (Resultados_Quicksort, "\nNumero de trocas: %d", troc);

        Reinicia_vet (vet, pri, n);
        comp = 0; troc = 0;

        tInicio=clock();
        printf ("\n\nQuickSort - Mediana de tres elementos\n");
        fprintf (Resultados_Quicksort, "\n\nQuickSort - Mediana de tres elementos\n");
        QuickSort_mediana_de_tres(vet, n-1, &comp, &troc);
        tFim=clock();
        tQuickSort = ((int)(tFim-tInicio))/CLOCKS_PER_SEC;
        printf ("\nTempo gasto: %lf  Milesimos de segundo", tQuickSort);
        printf ("\nNumero de comparacoes: %d", comp);
        printf ("\nNumero de trocas: %d", troc);
        fprintf (Resultados_Quicksort, "\nTempo gasto: %lf Milesimos de segundo", tQuickSort);
        fprintf (Resultados_Quicksort, "\nNumero de comparacoes: %d", comp);
        fprintf (Resultados_Quicksort, "\nNumero de trocas: %d", troc);
        printf ("\n\n");
        fprintf (Resultados_Quicksort, "\n\n");
        fclose(Resultados_Quicksort);
    }
    getch();
    return (0);
}

/******************* QUICKSORT NORMAL *********************/
void Particao (int esq, int dir, int *i, int *j, int vet[], int *comp, int *troc){
    int pivo, aux, k;
    *i=esq;
    *j=dir;
    pivo = vet[(*i+*j)/2]; /*OBTEM O PIVÔ*/
    do{
        while (pivo>vet[*i]){
            (*i)++;
            (*comp)++;
        }
        while (pivo<vet[*j]){
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

/******************* QUICKSORT ESTÁVEL *********************/
int pivot_estavel (int n, int vet[]){
    return (vet[n]);
}

void Particao_estavel (int esq, int dir, int *i, int *j, int vet[], int *comp, int *troc){
    int pivo, aux, k, a;
    *i=esq;
    *j=dir;
    pivo = pivot_estavel(dir, vet); /*OBTEM O PIVÔ*/
    do{
        while (pivo>vet[*i]){
            (*i)++;
            (*comp)++;
        }
        while (pivo<vet[*j]){
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

void Ordena_estavel (int esq, int dir, int vet[], int *comp, int *troc){
    int i, j;
    Particao_estavel (esq, dir, &i, &j, vet, comp, troc);
    (*comp)++;
    if (esq<j) Ordena_estavel (esq, j, vet, comp, troc);
    (*comp)++;
    if (i<dir) Ordena_estavel (i, dir, vet, comp, troc);
}

void QuickSort_estavel(int vet[], int n, int *comp, int *troc){
    Ordena_estavel (0, n, vet, comp, troc);
}
/******************* QUICKSORT - MEDIANA DE TRÊS *********************/

int pivot_mediana_de_tres (int vet[], int esq, int dir){
    return ((vet[esq]+vet[dir]+vet[(esq+dir)/2])/3); //Acha o valor médio entre o primeiro, ultimo e o valor mediano do vetor desordenado
}

void Particao_mediana_de_tres (int esq, int dir, int *i, int *j, int vet[], int *comp, int *troc){
    int pivo, aux, k;
    *i=esq;
    *j=dir;
    pivo = pivot_mediana_de_tres (vet, esq, dir); /*OBTEM O PIVÔ*/
    do{
        while (pivo>vet[*i]){
            (*i)++;
            (*comp)++;
        }
        while (pivo<vet[*j]){
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

void Ordena_mediana_de_tres (int esq, int dir, int vet[], int *comp, int *troc){
    int i, j;
    Particao_mediana_de_tres (esq, dir, &i, &j, vet, comp, troc);
    (*comp)++;
    if (esq<j) Ordena_mediana_de_tres (esq, j, vet, comp, troc);
    (*comp)++;
    if (i<dir) Ordena_mediana_de_tres (i, dir, vet, comp, troc);
}

void QuickSort_mediana_de_tres(int vet[], int n, int *comp, int *troc){
    Ordena_mediana_de_tres (0, n, vet, comp, troc);
}
//==================== OUTRAS FUNÇÕES ====================
void Reinicia_vet (int vet[], int pri[], int n){ //Função criada para "reiniciar" o vetor, igualando-o ao vetor primário (pri)
    int i;
    for (i=0;i<n;i++){
        vet[i]=pri[i];
    }
}
