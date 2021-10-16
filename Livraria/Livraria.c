#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

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
//====================== LISTA =======================
void Inicializa (TipoLista *Lista);
int Vazia (TipoLista Lista);
void Insere (TipoItem x, TipoLista *Lista);
void Imprime (TipoLista Lista);
int Verifica (TipoLista Lista, int ver);
void Venda(TipoLista *Lista);
//============= MANIPULACAO DE ARQUIVO ===============
void Salvar (TipoLista Lista);
void Carregar (TipoLista *Lista);
//==================== QUICKSORT =====================
void Particao (int Esq, int Dir, int *i, int *j, TipoLista *Lista);
void QuickSort (TipoLista *Lista, int n);
void Ordena (int Esq, int Dir, TipoLista *Lista);
//=============== PESQUISA POR HASHING ===============
//void HashPesquisaChave (TipoLista *Hashing, TipoItem *x);
/******************** PROTOTIPOS ********************/

/******************** FUNCAO PRINCIPAL ********************/
int main (){
    TipoLista Lista;
    TipoLista HashingChave[MAX];
    TipoLista HashingNome;
    TipoItem x;
    int menu, alterac=0, tipobusca=0, buscarpor=0, i, op;
    system("color F0");
    //=============== LISTA PRINCIPAL ===============
    Inicializa(&Lista);
    Carregar (&Lista);
    //=============== TABELA HASH ===============
    for (i=0;i<10;i++){
        Inicializa (&HashingChave[i]);
    }
    for(;;){
        Menu();
        printf ("\n\n\t\tEscolha uma opcao acima: ");
        scanf ("%d", &menu);
        system("cls");
        switch (menu){
        case 1 :
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
                break;
        case 2:
            Imprime(Lista);
            printf ("\n\nNumero de cadastros: %d", Lista.Tamanho);
            getch();
            break;
        case 3:
            Salvar(Lista);
            alterac=0;
            break;
        case 4:
            //fazer ainda venda
            break;
        case 5:
            QuickSort(&Lista, Lista.Tamanho);
            break;
        case 6:
            system("cls");
            L95: printf ("Qual o tipo de busca desejada:\n");
            printf ("1. Hashing\t2. Arvore SBB\t3. Cancelar\n");
            scanf ("%d", &tipobusca);
            if (tipobusca==1){
                for (i=0;i<10;i++){

            }
            if (tipobusca==3) break;
            if (tipobusca!=1 && tipobusca!=2){
                printf ("ERRO:\tEntrada invalida\nPrecione qualquer tecla para continuar...");
                getch();
                system("cls");
                goto L95;
            }
            printf ("Buscar por:\n");
            printf ("1. Cadastro\t2. Nome\n");
            if (tipobusca!=1 && tipobusca!=2){
                printf ("ERRO:\tEntrada invalida\nPrecione qualquer tecla para continuar...");
                getch();
                system("cls");
                goto L95;
            }
            scanf ("%d", &buscarpor);
            if (tipobusca==1){
                if (buscarpor==1){ //Hashing por chave
                    HashPesquisaChave(&HashingChave, &x);
                }
            }
            break;
        case 7:
            if (alterac){
                printf ("Deseja salvar as alteracoes feitas?\n");
                printf ("\t1. Sim\t\t2. Nao\t\t3. Cancelar\n");
                scanf ("%d", &menu);
                if (menu==1){
                    Salvar(Lista);
                    break;
                }
                if (menu==2) break;
                if (menu!=3){
                    printf ("ERRO: Entrada invalida!\nPrecione qualquer tecla para retornar ao programa...");
                    getch();
                    break;
                }
            } else {
                break;
            }
        default:
            printf ("ERRO:\tEntrada invalida!");
            getch();
    }
    }
    return(0);
}

/******************** FUNCAO PRINCIPAL ********************/
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
/******************** FUNCAO PRINCIPAL ********************/

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
        printf ("Nome do livro: %s\n\n", Aux->Item.nome_livro);
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

/******************** QUICKSORT ********************//*
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

/********************** HASH ***********************/
//=============== PESQUISA POR CHAVE ===============
/*void HashPesquisaChave (TipoLista *Hashing, TipoItem *x){
    Apontador Aux;
    int i;
    if (Vazia(*Hashing)==1){
        printf ("ERRO:\tPosicao vazia\n");
        getch();
        return;
    }
    Aux = Hashing->Primeiro->Prox;
    while (Aux!=NULL){
        if (Aux->Item.chave == (*x).chave){
            (*x) = Aux->Item;
            printf ("Livro: %s", x->nome_livro);
            printf ("Quantidade disponivel: %d", x->qtde);
            getch();
            return;
        }
        Aux = Aux->Prox;
    }
}*/
/********************** HASH ***********************/
