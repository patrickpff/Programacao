/*
Nome: Patrick Pierre Fernandes Ferreira
Data: 12/03/2012
Descrição: Trabalho realizado como parte das exigências para avaliação da disciplina de Algorítmos e estruturas de dados II.
Consiste na criação de um editor de textos que reconheça caracteres especiais para a manipulação do mesmo usando o conceito de Pilha.
Data da ultima atualização: 12/03/2012
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXLINE 70

/**************** DEFINIÇÃO DE ESTRUTURAS ****************/
typedef struct {
    char Letra;
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
    TipoItem Item;
    Apontador Prox;
} Celula;

typedef struct {
    Apontador Topo, Fundo;
    int Tamanho;
} TipoPilha;
/**************** DEFINIÇÃO DE ESTRUTURAS ****************/

/********************** PROTOTIPOS **********************/
void FPVazia (TipoPilha *Pilha);
void Empilha (TipoItem x, TipoPilha *Pilha);
void Desempilha (TipoPilha *Pilha, TipoItem *Item);
int Vazia (TipoPilha Pilha);
void Imprime (TipoPilha Pilha, int *i);
void Salvar (TipoPilha Pilha, int *i);
/********************** PROTOTIPOS **********************/

/******************* FUNÇÃO PRINCIPAL *******************/
int main (int argc, char *argv[]){
    int Menu, x=0, n, cont;
    TipoPilha Pilha;
    TipoItem Item;
    Apontador Aux, Aux2;

    FPVazia (&Pilha);
    system("color F0");

    for (;;){
        system("cls");
        printf ("\t\t\tBEM VINDO AO EDITOR DE TEXTOS\n\n\n");
        printf ("\tEscolha uma das opcoes abaixo:\n\n");
        printf ("\t\t1. Iniciar arquivo em branco\n");
        printf ("\t\t2. Verificar instrucoes\n");
        printf ("\t\t3. Sair\n\n");
        scanf ("%d", &Menu);
        system("cls");
        if (Menu == 1){
            while (Item.Letra != '~'){
                Item.Letra = getch();
                x++;
                Empilha(Item, &Pilha);
                if (x == MAXLINE){
                    Item.Letra = '*';
                    Empilha (Item, &Pilha);
                }
                if (Item.Letra == '#'){
                    Desempilha (&Pilha, &Item);
                    Desempilha (&Pilha, &Item);
                    x = x-2;
                    Imprime (Pilha, &x);
                }
                if (Item.Letra == '*'){
                    printf ("\n");
                    x=0;
                }
                if (Item.Letra == '/'){
                    n = ((Pilha.Tamanho) % (MAXLINE));
                    for (cont = 0; cont < n; cont++){
                        Desempilha (&Pilha, &Item);
                        if (Pilha.Topo->Item.Letra == '*'){
                            x = ((Pilha.Tamanho)%(MAXLINE));
                            if (x == 0){
                                Item.Letra = '*';
                                Empilha (Item, &Pilha);
                            }
                            break;
                        }
                    }
                    Imprime (Pilha, &x);
                } else {
                    Imprime (Pilha, &x);
                }
            }
            Salvar(Pilha, &x);
        }
        if (Menu == 2){
            printf ("\n\t\tInstrucoes de uso do ET-Editor de textos:\n\n");
            printf ("\t\t# - Apaga caractere\n");
            printf ("\t\t/ - Apaga linha\n");
            printf ("\t\t* - Saltar linha\n");
            printf ("\t\t~ - Sair/Salvar arquivo\n\n\t");
            system ("pause");
        }

        if (Menu == 3) return (0);
    }
}
/******************* FUNÇÃO PRINCIPAL *******************/

/************************ FUNÇÕES ***********************/
void FPVazia (TipoPilha *Pilha){
    Pilha->Topo = (Apontador) malloc (sizeof(Celula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
} //Faz pilha vazia

void Empilha (TipoItem x, TipoPilha *Pilha){
    Apontador Aux;
    Aux = (Apontador) malloc (sizeof(Celula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
} //Empilha caracteres

void Desempilha (TipoPilha *Pilha, TipoItem *Item){
    Apontador Aux;
    if (Vazia(*Pilha)){
        return;
    }
    Aux = Pilha->Topo;
    Pilha->Topo = Aux->Prox;
    *Item = Aux->Prox->Item;
    free(Aux);
    Pilha->Tamanho--;
} //Desempilha caracteres

int Vazia (TipoPilha Pilha){
    return (Pilha.Topo == Pilha.Fundo);
} //Verifica se a pilha está vazia

void Imprime (TipoPilha Pilha, int *i){
    char x, str[1000];
    int a=0, s=0;
    Apontador Aux;
    s = Pilha.Tamanho;
    Aux = Pilha.Topo;
    system ("cls");
    while (a<=s){
        str[a] = Aux->Item.Letra;
        Aux = Aux->Prox;
        a++;
    }
    for (a=s; a>0; a--){
        if (str[a] == "*" || i == MAXLINE){
            printf ("\n");
            i == 0;
        } else {
            printf ("%c", str[a]);
        }
    }
    free(Aux);
} //Imprime o texto

void Salvar (TipoPilha Pilha, int *i){
    char x, str[1000];
    int a=0, s=0;
    Apontador Aux;
    s = Pilha.Tamanho;
    Aux = Pilha.Topo;

    FILE * etarquivo;
    etarquivo = fopen ("etarquivo.txt", "w");
    while (a<=s){
        str[a] = Aux->Item.Letra;
        Aux = Aux->Prox;
        a++;
    }
    for (a=s; a>1; a--){
        if (str[a] == '*' || i == MAXLINE){
            fprintf (etarquivo, "\n");
            i == 0;
        } else {
            fprintf (etarquivo, "%c", str[a]);
        }
    }
    fclose(etarquivo);
    free(Aux);
} //Salvar em arquivo
/************************ FUNÇÕES ***********************/
