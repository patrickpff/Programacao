/*Nome
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define tes1 500
#define tes2 5000
#define tes3 50000

/**********Inserção**********/
void insercao (int vet[], int n, int *comp, int *troc){
    int i, j, x;
    for (i=1;i<n;i++){
        x = vet[i];                          //define um ponto para começarmos a comparar salvando vet[i] na variavel x
        j = i-1;                             //j será a unidade a ser comparada com o i
        vet[n] = x; /*sentinela*/
        (*comp)++;
        while (x > vet[j] && j >= 0){        //desloca os dados para "encaixar" o valor encontrado
            vet[j+1] = vet[j];
            j--;
            (*troc)++;
        }
        vet[j+1] = x;
        (*troc)++;
    }
}
/**********Inserção**********/


void Zerar_func (int vet[], int pri[], int n){
    int i;
    for (i=0;i<n;i++){
        vet[i]=pri[i];
    }
}

int main (){
    int n, i, k, vet[501], pri[501], comp=0, troc=0;
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
    for (i=0;i<n;i++){
        pri[i]=vet[i];
    }
    for (i=0; i<n; i++){
        printf ("%d  ", vet[i]);
    }

    /**********Inserção**********/
    tInicio=clock();
    printf ("\n\nInsercao:\n");
    insercao(vet, n, &comp, &troc);
    for (i=0; i<n; i++){
        printf ("%d  ", vet[i]);
    }
    tFim=clock();
    tInsercao = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
    printf ("\n\nTempo gasto: %lf segundos", tInsercao);
    /**********Inserção**********/

    Zerar_func(vet, pri, n); //Reinicia o vetor "vet" para que possa ser testada a mesma sequência para os outros algorítmos de ordenação



    return (0);
}
