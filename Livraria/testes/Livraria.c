#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/******************** DEFINICAO DE ESTRUTURAS ********************/
typedef struct {
    int chave;
    char nome_livro[50];
    int qtde;
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
    TipoItem Item;
    Apontador Prox;
    Apontador Ant;
} Celula;

typedef struct {
    Apontador Primeiro, Ultimo;
    int Tamanho;
} TipoLista;
/******************** DEFINICAO DE ESTRUTURAS ********************/

/******************** PROTOTIPOS ********************/
void Menu (void);
void Venda(TipoLista *Lista);
//====================== LISTA =======================
void Inicializa (TipoLista *Lista);
int Vazia (TipoLista Lista);
void Insere (TipoItem x, TipoLista *Lista);
void Imprime (TipoLista Lista);
int Verifica (TipoLista Lista, int ver);
//============= MANIPULACAO DE ARQUIVO ===============
void Salvar (TipoLista Lista);
void Carregar (TipoLista *Lista);
//==================== QUICKSORT =====================
void Particao (int Esq, int Dir, int *i, int *j, TipoLista *Lista);
void QuickSort (TipoLista *Lista, int n);
void Ordena (int Esq, int Dir, TipoLista *Lista);
//======================= HASH =======================

/******************** PROTOTIPOS ********************/

/******************** FUNCAO PRINCIPAL ********************/
int main (){
    TipoLista Lista;
    TipoItem x;
    int menu, alterac=0;

    Inicializa(&Lista);
    Carregar (&Lista);

    for(;;){
        Menu();
        printf ("\n\n\t\tEscolha uma opcao acima: ");
        scanf ("%d", &menu);
        system("cls");
        if (menu==1){
                printf ("Entre com um numero de registro para o livro: ");
                scanf ("%d", &x.chave);
                if (Verifica(Lista, x.chave)){
                    fflush(stdin);
                    printf ("\nNome do livro: ");
                    gets(x.nome_livro);
                    printf ("\nQuantidade de volumes: ");
                    scanf ("%d", &x.qtde);
                    Insere (x, &Lista);
                    alterac=1;
                } else {
                    printf ("\nErro! O registro escolhido ja existe.");
                    getch();
                }
        }
        if (menu==2){
            Imprime(Lista);
            printf ("\n\nNumero de cadastros: %d", Lista.Tamanho);
            getch();
        }
        if (menu==3){
            Salvar(Lista);
            alterac=0;
        }
        if (menu==4){

        }
        if (menu==5){
            QuickSort(&Lista, Lista.Tamanho);
        }
        if (menu==6){

        }
        if (menu==7){
            if (alterac){
                printf ("Deseja salvar as alterações feitas?\n");
                printf ("\t1. Sim\t\t2. Nao\t\t3. Cancelar\n");
                scanf ("%d", &menu);
                if (menu==1){
                    Salvar(Lista);
                    break;
                }
                if (menu==2) break;
            } else {
                break;
            }
        }
    }
    return(0);
}
/******************** FUNCAO PRINCIPAL ********************/

/******************** MENU ********************/
void Menu (void){
    int o;
    system("cls");
    printf ("  %c", 201);
    for (o=0;o!=72;o++){
        printf ("%c", 205);
    }
    printf ("%c", 187);
    printf ("\n  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n");
    printf ("  %c\t\t\t\t    LIVRARIA\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c", 204);
    for (o=0;o!=72;o++){
        printf ("%c", 205);
    }
    printf ("%c", 185);
    printf ("\n  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n  %c\t\t\t\t\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t   1. Inserir livro\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n  %c\t\t   2. Livros disponiveis\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n  %c\t\t   3. Salvar\t\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n  %c\t\t   4. Efetuar venda\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n  %c\t\t   5. Ordenar \t\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n  %c\t\t   6. Buscar \t\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c", 186, 186);
    printf ("\n  %c\t\t   7. Sair \t\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c\t\t\t\t\t\t\t\t\t   %c\n", 186, 186);
    printf ("  %c", 200);
    for (o=0;o!=72;o++){
        printf ("%c", 205);
    }
    printf ("%c", 188);
}
/******************** MENU ********************/

/******************** MANIPULACAO DA LISTA DUPLAMENTE ENCADEADA ********************/

void Inicializa (TipoLista *Lista){
    Lista->Primeiro = (Apontador) malloc (sizeof(Celula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Ant = NULL;
    Lista->Primeiro->Prox = NULL;
    Lista->Tamanho = 0;
}

int Vazia (TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere (TipoItem x, TipoLista *Lista){
    Apontador Aux;
    Aux = Lista->Ultimo;
    Lista->Ultimo->Prox = (Apontador) malloc (sizeof(Celula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    Lista->Ultimo->Ant = Aux;
    Lista->Tamanho++;
}

void Imprime (TipoLista Lista){
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;
    system("cls");
    if (Vazia(Lista)){
        printf("ERRO: Lista Vazia.");
        return;
    }
    while (Aux != NULL){
        printf ("Registro: %d\n", Aux->Item.chave);
        printf ("Nome do livro: %s\n", Aux->Item.nome_livro);
        printf ("Quantidade: %d\n\n", Aux->Item.qtde);
        printf ("-----------------------------------------------------------\n\n");
        Aux = Aux->Prox;
    }
}

int Verifica (TipoLista Lista, int ver){
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;
    while (Aux != NULL){
        if (Aux->Item.chave == ver || ver>=9000 || ver<-1){
            return (0);
        }
        Aux = Aux->Prox;
    }
    return (1);
}
/* IMPLEMENTAR HASH COM ESTA FUNÇÃO
void Venda (TipoLista *Lista){
    printf ("Livro a ser vendido: ");
    scanf ("%d", vend &);
}*/
/******************** MANIPULACAO DA LISTA DUPLAMENTE ENCADEADA ********************/

/******************** MANIPULACAO DE ARQUIVO ********************/
//=================== SALVAR EM ARQUIVO ===================
void Salvar (TipoLista Lista){
    Apontador Aux;
    int x;
    Aux = Lista.Primeiro->Prox;
    FILE * DataBase;
    DataBase = fopen ("DataBase.txt", "w");
    while (Aux!=NULL){
        fprintf (DataBase, "%d\n%s\n%d\n", Aux->Item.chave, Aux->Item.nome_livro, Aux->Item.qtde);
        Aux = Aux->Prox;
    }
    fprintf (DataBase, "%d", -1);
    printf ("Arquivo salvo!");
    getch();
    fclose(DataBase);
}
//=================== CARREGAR DADOS DO ARQUIVO ===================
void Carregar (TipoLista *Lista){
    TipoItem Aux;
    int ver=0;
    FILE * DataBase;
    if ((DataBase = fopen ("DataBase.txt", "r")) != NULL){
        fscanf (DataBase, "%d", &Aux.chave);
        fscanf (DataBase, "%s", &Aux.nome_livro);
        fscanf (DataBase, "%d", &Aux.qtde);
        Insere (Aux, Lista);
        while (ver != -1){
            fscanf (DataBase, "%d", &ver);
            if (ver != -1){
                Aux.chave = ver;
                fscanf (DataBase, "%s", &Aux.nome_livro);
                fscanf (DataBase, "%d", &Aux.qtde);
                Insere (Aux, Lista);
            }
        }
    }
    fclose(DataBase);
}
/******************** MANIPULACAO DE ARQUIVO ********************/

/******************** QUICKSORT ********************/
void Particao (int Esq, int Dir, int *i, int *j, TipoLista *Lista){
    int PPivot, Ant, Pos, Aux;
    Apontador AuxAnt, AuxPos, Pivot;
    TipoItem AuxItem;

    AuxAnt = Lista->Primeiro->Prox;
    AuxPos = Lista->Primeiro->Prox;
    *i = Esq;
    *j = Dir;

    for (Ant=1; Ant!=(*i); Ant++){
        AuxAnt = AuxAnt->Prox;
    }
    for (Pos=1; Pos!=(*j); Pos++){
        AuxPos = AuxPos->Prox;
    }

    PPivot = (*i+*j)/2;
    Aux=*i;
    Pivot = AuxAnt;

    while(Aux!=PPivot){
        Pivot = Pivot->Prox;
        Aux++;
    }
    PPivot = Pivot->Item.chave;
    do{
        while (PPivot > AuxAnt->Item.chave){
            AuxAnt = AuxAnt->Prox;
            (*i)++;
        }
        while (PPivot < AuxPos->Item.chave){
            AuxPos = AuxPos->Ant;
            (*j)--;
        }
        if ((*i)<=(*j)){
            AuxItem = AuxAnt->Item;
            AuxAnt->Item = AuxPos->Item;
            AuxPos->Item = AuxItem;
            (*i)++;
            AuxAnt = AuxAnt->Prox;
            (*j)--;
            AuxPos = AuxPos->Ant;
        }
    }while ((*i)<=(*j));
}

void QuickSort (TipoLista *Lista, int n){
    Ordena (1, n, Lista);
}

void Ordena (int Esq, int Dir, TipoLista *Lista){
    int i, j;
    Particao (Esq, Dir, &i, &j, Lista);
    if (Esq<j) Ordena (Esq, j, Lista);
    if (i<Dir) Ordena (i, Dir, Lista);
}
/******************** QUICKSORT ********************/

/********************** HASH **********************/

/********************** HASH **********************/
