/*
Nome: Patrick Pierre Fernandes Ferreira
Nome: Luciano Antunes Rocha
Data: 27/04/2012
Descri��o: Trabalho apresentado ao professor Renato Cota como parte das exig�ncias para
avalia��o da disciplina de AEDII, 2� per�odo, consistindo em um programa para compara��o
de algoritmos de ordena��o.
Data da ultima atualiza��o: 26/04/2012
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

/**************** PROT�TIPOS DAS FUN��ES ****************/
void Criar_vet_Decrescente(double vet[], int n);
void Reiniciar_vet (double *vet, double *pri, int n);
void CalcTime (double SecTime, int *TempoMim, int *TempoSec);
//Metodo de Inser��o
void insercao (double vet[], int n, double *comp, double *troc);
//Metodo de Sele��o
void selecao (double vet[], int n, double *comp, double *troc);
//Metodo Shellsort
void shellsort (double vet[], int n, double *comp, double *troc);
//Metodo Quicksort
void Particao (int esq, int dir, int *i, int *j, double vet[], double *comp, double *troc);
void Ordena (int esq, int dir, double vet[], double *comp, double *troc);
void QuickSort(double vet[], int n, double *comp, double *troc);
//Metodo Heapsort
void Heapsort(double vet[], int n, double *comp, double *troc);
/**************** PROT�TIPOS DAS FUN��ES ****************/

int main (){
    system("title Compara��o entre algoritmos de ordena��o");
    int tes, i, k, TempoMim, TempoSec, n;
    double vet[500001], pri[500001], comp=0, troc=0;
    clock_t tInicio, tFim;
    double Tempo;
    FILE * Resultados;
    Resultados = fopen ("Resultados.txt", "w"); //Cria arquivo com permiss�o de escrita

    srand(time(NULL));
    for (tes=0;tes<3;tes++){
        if (tes==0) n = 500;            //fazer os testes com 500 numeros
        if (tes==1) n = 50000;          //fazer os testes com 50000 numeros
        if (tes==2) n = 500000;         //fazer os testes com 500000 numeros
        for (i=0; i<n; i++){
            vet[i] = ((double)(rand()%n));       //pegar valores aleat�rios para vet[i]
            for (k=0; k<i; k++){     //verificar se o valor j� foi inserido antes,
                if(vet[k] == vet[i]){  //no caso de a afirma��o ser verdadeira, buscar outro valor rand�mico
                    vet[i]=((double)(rand()%n));
                    k-=1;
                }
            }
        }
        for (i=0;i<n;i++){           //Copia o vetor criado para um outro vetor para poder salvar a condi��o inicial e realizarmos
            pri[i]=vet[i];           //os testes com a mesma seq�encia num�rica
        }

        printf ("\n\nCONJUNTO DE %d REGISTROS:\n", n);              //Imprime na tela
        fprintf (Resultados, "\nCONJUNTO DE %d REGISTROS:\n", n);   //Imprime no arquivo

        /**********Inser��o**********/
        //Aleat�rio
        tInicio=clock();                                    //Salva o estado inicial do Clock
        insercao(vet, n, &comp, &troc);
        tFim=clock();                                       //Salva o estado final do Clock
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;     //calcula o tempo gasto em segundos baseado nos pulsos de clock
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Insercao (aleatorio): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Insercao (aleatorio): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado
        tInicio=clock();
        insercao(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Insercao (ordenado): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Insercao (ordenado): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado em ordem decrescente
        Criar_vet_Decrescente(vet, n);
        tInicio=clock();
        insercao(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Insercao (em ordem decrescente): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Insercao (em ordem decrescente): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        /**********Inser��o**********/

        Reiniciar_vet(vet, pri, n); //Reinicia o vetor "vet" para que possa ser testada a mesma sequ�ncia para os outros algor�tmos de ordena��o
        comp=0; troc=0; //Reinicia contador de compara��es e trocas

        /**********Sele��o**********/
        //Aleat�rio
        tInicio=clock();
        selecao(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Selecao (aleatorio): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Selecao (aleatorio): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado
        tInicio=clock();
        selecao(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Selecao (ordenado): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Selecao (ordenado): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado em ordem decrescente
        Criar_vet_Decrescente(vet, n);
        tInicio=clock();
        selecao(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Selecao (em ordem decrescente): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Selecao (em ordem decrescente): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        /**********Sele��o**********/

        Reiniciar_vet(vet, pri, n);
        comp=0; troc=0;

        /**********Shellsort**********/
        //Aleat�rio
        tInicio=clock();
        shellsort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Shellsort (aleatorio): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Shellsort (aleatorio): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado
        tInicio=clock();
        shellsort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Shellsort (ordenado): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Shellsort (ordenado): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado em ordem decrescente
        Criar_vet_Decrescente(vet, n);
        tInicio=clock();
        shellsort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Shellsort (em ordem decrescente): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Shellsort (em ordem decrescente): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        /**********Shellsort**********/

        Reiniciar_vet(vet, pri, n);
        comp=0; troc=0;

        /**********Quicksort**********/
        //Aleat�rio
        tInicio=clock();
        QuickSort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Quicksort (aleatorio): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Quicksort (aleatorio): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado
        tInicio=clock();
        QuickSort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Quicksort (ordenado): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Quicksort (ordenado): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado em ordem decrescente
        Criar_vet_Decrescente(vet, n);
        tInicio=clock();
        QuickSort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Quicksort (em ordem decrescente): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Quicksort (em ordem decrescente): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        /**********Quicksort**********/

        Reiniciar_vet(vet, pri, n);
        comp=0; troc=0;
        /**********Heapsort**********/
        //Aleat�rio
        tInicio=clock();
        Heapsort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Heapsort (aleatorio): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Heapsort (aleatorio): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado
        tInicio=clock();
        Heapsort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Heapsort (ordenado): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Heapsort (ordenado): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        //Ordenado em ordem decrescente
        Criar_vet_Decrescente(vet, n);
        tInicio=clock();
        Heapsort(vet, n, &comp, &troc);
        tFim=clock();
        Tempo = ((double)(tFim-tInicio))/CLOCKS_PER_SEC;
        CalcTime (Tempo, &TempoMim, &TempoSec);
        printf ("Heapsort (em ordem decrescente): tempo de execucao: %d min e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        fprintf (Resultados, "Heapsort (em ordem decrescente): tempo de execucao: %d mim e %d seg - comparacoes: %d - trocas: %d\n", TempoMim, TempoSec, comp, troc);
        /**********Heapsort**********/
    }
    getch();
    fclose (Resultados);
    return (0);
}
/**********Outras fun��es**********/
void Criar_vet_Decrescente(double *vet, int n){ //Cria um vetor com valores em ordem decrescente
    int k;
    double j;
    for (k = 0, j = n-1; k < n; k++, j--){
        vet[k] = j;
    }
}

void Reiniciar_vet (double vet[], double *pri, int n){ //Fun��o criada para "reiniciar" o vetor, igualando-o ao vetor prim�rio (pri)
    int i;
    for (i=0;i<n;i++){
        vet[i]=pri[i];
    }
}

void CalcTime (double SecTime, int *TempoMim, int *TempoSec){ //Fun��o criada para calcular o tempo colhido, inicialmente em segundos, em minutos e segundos
    *TempoMim = ((int)SecTime)/60;
    *TempoSec = ((int)SecTime)%60;
}
/**********Outras fun��es**********/

/**********Inser��o**********/
void insercao (double vet[], int n, double *comp, double *troc){
    int i, j, x;
    for (i=1;i<n;i++){
        x = vet[i];                          //define um ponto para come�armos a comparar salvando vet[i] na variavel x
        j = i-1;                             //j ser� a unidade a ser comparada com o i
        vet[n] = x; /*sentinela*/
        (*comp)++;
        while (x < vet[j] && j >= 0){        //desloca os dados para "encaixar" o valor encontrado
            vet[j+1] = vet[j];
            j--;
            (*troc)++;
        }
        vet[j+1] = x;
        (*troc)++;
    }
}
/**********Inser��o**********/

/**********Sele��o**********/
void selecao (double vet[], int n, double *comp, double *troc){
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
/**********Sele��o**********/

/**********Shellsort**********/
void shellsort (double vet[], int n, double *comp, double *troc){
    int i, j, h=1, x;

    do h = h*3+1; while (h<n); //Calcula o valor total de "h", h=4; h=13; h=40...at� que h se torne maior ou igual a "n"
    do{
        h/=3;                  //Divide o valor de h por tres, para assim gerarmos o "salto" inicial da fun��o. Ex.: para n=10, h=4 (13/3=4)
        for (i=h; i<n; i++){   //ou seja, iremos verificar inicialmente as posi��es 0-4, 1-5, 2-6, 3-7, 4-8, 5-9;
            x=vet[i];
            j=i-h;
            while(j>=0 && vet[j]>x){
                vet[j+h] = vet[j];
                j-=h;
                (*troc)++;
                (*comp)++;
            }                 //Enquanto o h for diferente de 0, essa fun��o ir� se repetir. Isso acontecer� quando a divis�o de h por tres
            vet[j+h]=x;       //resultar em um valor abaixo de 1. Ex.: h=13; h=4; h=1; h=0.
        }
    }while(h!=0);
}
/**********Shellsort**********/

/**********Quicksort**********/
void Particao (int esq, int dir, int *i, int *j, double vet[], double *comp, double *troc){
    int pivo, aux;
    *i=esq;                             //Como *i ser� o valor que iremos comparar com os numeros abaixo do pivo, ele recebe esq (inicialmente 0)
    *j=dir;                             //o mesmo acontece com *j
    pivo = vet[(*i+*j)/2];              //Obtem o piv�
    do{
        while (pivo>vet[*i]){           //verifica se os numeros acima do piv� s�o maiores que ele, enquanto for verdadeiro *i � acrescido
            (*i)++;
            (*comp)++;
        }
        while (pivo<vet[*j]){           //verifica se os numeros abaixo do piv� s�o menores que ele, enquanto for verdadeiro *j � decrescido
            (*j)--;
            (*comp)++;
        }
        if (*i <= *j){                  //Aqui � realizada a troca entre o elemento vet[*i] e vet[*j]
            aux=vet[*i];
            vet[*i]=vet[*j];
            vet[*j]=aux;
            (*i)++;
            (*j)--;
            (*troc)++;
        }
    } while (*i <= *j);
}

void Ordena (int esq, int dir, double vet[], double *comp, double *troc){
    int i, j;
    Particao (esq, dir, &i, &j, vet, comp, troc);   //Divide o vetor compara das estremidades at� encontrar o piv�
    (*comp)++;
    if (esq<j) Ordena (esq, j, vet, comp, troc);    //Forma recursiva de se reiniciar a fun��o particionando o vetor em "vetores menores",
    (*comp)++;                                      //daqui a funcao ir� reiniciar a fun��o Ordena, se se fizer necess�rio
    if (i<dir) Ordena (i, dir, vet, comp, troc);
}

void QuickSort(double vet[], int n, double *comp, double *troc){
    Ordena (0, n, vet, comp, troc);                 //Inicia o processo de ordena��o do vetor
}
/**********Quicksort**********/

/**********Heapsort**********/
void Heapsort(double vet[], int n, double *comp, double *troc){
   int i = n/2, pai, filho, t;
   for (;;){
       if (i > 0){
           i--;
           t = vet[i];
        } else {
            n--;
            if (n == 0) return;
            t = vet[n];
            vet[n] = vet[0];
            (*troc)++;
        }
        pai = i;                                                        //Define "pai" como sendo o meio do vetor
        filho = i*2 + 1;
        while (filho < n){
            if ((filho + 1 < n)  &&  (vet[filho + 1] > vet[filho])){
                filho++;
            }
            if (vet[filho] > t) {
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai*2 + 1;
            } else break;
            (*comp)++;
        }
        vet[pai] = t;
    }
}
/**********Heapsort**********/
