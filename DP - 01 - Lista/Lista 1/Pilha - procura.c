#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct {
  int Chave;
  /* --- outros componentes --- */
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
  TipoItem Item;
  Apontador Prox;
} Celula;

typedef struct {
  Apontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha){
  Pilha->Topo = (Apontador) malloc(sizeof(Celula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}  /* FPVazia */

int Vazia(TipoPilha Pilha){
  return (Pilha.Topo == Pilha.Fundo);
}  /* Vazia */

void Empilha(TipoItem x, TipoPilha *Pilha){
  Apontador Aux;

  Aux = (Apontador) malloc(sizeof(Celula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}  /* Empilha */


void Desempilha(TipoPilha *Pilha, TipoItem *Item){
  Apontador q;

  if (Vazia(*Pilha))
  { printf(" Erro   lista vazia\n");
    return;
  }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = Pilha->Topo->Item;
  free(q);
  Pilha->Tamanho--;
}  /* Desempilha */


int Tamanho(TipoPilha Pilha){
  return (Pilha.Tamanho);
}  /* Tamanho */

int Verifica (TipoItem x, TipoPilha Pilha){
    int n=1;
    Apontador Aux;
    Aux = Pilha.Topo;
    while (Aux != NULL){
        if (Aux->Item.Chave == x.Chave){
            printf ("O item está presente na posição %d", n);
            getch();
            return 1;
        }
        Aux = Aux->Prox;
        n++;
    }
    printf ("Item não encontrado na pilha");
    return 0;
}

void Imprime (TipoPilha Pilha){
    Apontador Aux;
    Aux = Pilha.Topo;
    while (Aux != NULL){
        printf ("%d", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

int main(int argc, char *argv[]){
    int n=0;
    TipoPilha Pilha;
    TipoItem x;
    while(n<10){
        scanf ("%d", &x.Chave);
        Empilha (x, &Pilha);
        n++;
    }
    Imprime(Pilha);
    return(0);
}


