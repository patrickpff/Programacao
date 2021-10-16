#include <stdlib.h>
#include <stdio.h>
#define max 10

typedef struct Celula_str *Apontador;

typedef struct TipoItem {
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct Celula_str {
  TipoItem Item;
  Apontador Prox;
} Celula;

typedef struct TipoFila {
  Apontador Frente, Tras;
} TipoFila;

typedef struct {
    Apontador Fundo, Topo;
    int Tamanho;
} TipoPilha;

void FFVazia (TipoFila *Fila){
    Fila->Frente = (Apontador) malloc (sizeof(Celula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

void FPVazia (TipoPilha *Pilha){
  Pilha->Topo = (Apontador) malloc(sizeof(Celula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}

void Enfileira (TipoItem x, TipoFila *Fila){
    Fila->Tras->Prox = (Apontador) malloc (sizeof(Celula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
}

void Empilha(TipoItem x, TipoPilha *Pilha){
  Apontador Aux;

  Aux = (Apontador) malloc(sizeof(Celula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}  /* Empilha */

int VerificaPalindromo (TipoFila Fila, TipoPilha Pilha){
    Apontador Aux, Aux2;
    int n = 0;
    Aux = Fila.Frente->Prox;
    Aux2 = Pilha.Topo->Prox;
    while (n < Pilha.Tamanho){
        if (Aux->Item.Chave != Aux2->Item.Chave){
            return 0;
        }
        n++;
        Aux = Aux->Prox;
        Aux2 = Aux2->Prox;
    }
    return 1;
}

void FImprime(TipoFila Fila)
{
  Apontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL)
    { printf("%d\n", Aux->Item.Chave);
      Aux = Aux->Prox;
    }
}

void PImprime (TipoPilha Pilha){
    Apontador Aux;
    Aux = Pilha.Topo;
    while (Aux != NULL){
        printf ("%d", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

int main (){
    TipoFila Fila;
    TipoPilha Pilha;
    TipoItem Item;
    int n;

    FFVazia(&Fila);
    FPVazia(&Pilha);

        printf ("Digite a palavra que deseja verificar se e um palindromo:\n\n");
        fflush(stdin);
        Item.Chave = getch();
        printf ("%c", Item.Chave);
        while (Item.Chave != 13){
            fflush(stdin);
            Enfileira (Item, &Fila);
            Empilha (Item, &Pilha);
            Item.Chave = getch();
            printf ("%c", Item.Chave);
        }
        if (VerificaPalindromo(Fila, Pilha)){
            printf ("\n\nPalindromo!");
        } else {
            printf ("\n\nNao palindromo!");
        }
        return (0);
}
