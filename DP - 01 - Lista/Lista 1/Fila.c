/*
** Algoritmos e Estruturas de Dados
** NOME: Prof. Renato Afonso Cota Silva
** DCC - UNIMONTES
** DATA: 01/08/2009
** �ltima Altera��o: 25/11/2010
** DESCRICAO: Implementacao de uma lista encadeada
*/

#include <stdlib.h>
#include <stdio.h>
#define max 10

typedef struct Celula_str *Apontador;

typedef struct TipoItem {
  int Chave;
  char nome[50];
  /* outros componentes */
} TipoItem;

typedef struct Celula_str {
  TipoItem Item;
  Apontador Prox;
} Celula;

typedef struct TipoFila {
  Apontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{
  Fila->Frente = (Apontador) malloc(sizeof(Celula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
}  /* FFVazia */

int Vazia(TipoFila Fila)
{
  return (Fila.Frente == Fila.Tras);
}  /* Vazia */


void Enfileira(TipoItem x, TipoFila *Fila)
{
  Fila->Tras->Prox = (Apontador) malloc(sizeof(Celula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
}  /* Enfileira */


void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
  Apontador q;
  if (Vazia(*Fila))
  { printf(" Erro   fila est  a  vazia\n");
    return;
  }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);
}  /* Desenfileira */

void Imprime(TipoFila Fila)
{
  Apontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL)
    { printf("%d\n", Aux->Item.Chave);
      printf("%s\n", Aux->Item.nome);
      Aux = Aux->Prox;
    }
}

void Verifica (TipoItem x, TipoFila Fila){
    int n=1;
    Apontador Aux;
    Aux = Fila.Frente->Prox;
    while (Aux!=NULL){
        if (Aux->Item.Chave == x.Chave){
            printf ("Item encontrado na posição %d", n);
            getch();
            return;
        }
        Aux = Aux->Prox;
        n++;
    }
    printf ("Item não encontrado");
    getch();
}


int main(){
    int i;
    TipoItem x,y,z, aux;
    TipoFila fila;

    FFVazia(&fila);

    for(i=0;i<5;i++){
        printf("Digite um nome: ");
        gets(x.nome);
        x.Chave=i+1;
        Enfileira(x,&fila);
    }
    Imprime(fila);
    printf ("Entre com a chave do dado que deseja procurar: ");
    scanf ("%d", &aux.Chave);
    Verifica (aux, fila);

    Desenfileira(&fila,&x);
    Desenfileira(&fila,&y);
    Desenfileira(&fila,&z);
    printf("\n\n%d - %s\n",z.Chave,z.nome);
    scanf ("%d", &aux.Chave);
    Verifica (aux, fila);

    Enfileira(z,&fila);
    Enfileira(y,&fila);
    Enfileira(x,&fila);
    Imprime(fila);


    return 0;
}

