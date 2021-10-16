#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

/*==========================DEFINIÇÃO DE TIPOS==========================*/
typedef struct {
    int inscricao, pont;
    char nome[50];
    char gabarito[100];
} DadosCandidato;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
    DadosCandidato Candidato;
    Apontador Prox;
}Celula;

typedef struct {
    Apontador Primeiro, Ultimo;
} TipoLista;

/*==========================DEFINIÇÃO DE TIPOS==========================*/

void Inicializa(TipoLista *Lista){
    Lista->Primeiro = (Apontador)malloc(sizeof(Celula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro==Lista.Ultimo);
}

int quantidade (){
    int q;
    system("cls");
    printf ("\n\nEntre com o numero de questoes:\t");
    scanf ("%d", &q);
    system("cls");
    return (q);
}

int gab_oficial(int qtde){
    int i, q;
    char gabaritooficial[100], alt=NULL;
    if (qtde==0){
        system("cls");
        printf ("ERRO!\n\nO vestibular nao foi configurado. \n\nPor favor, entre com o numero de questoes primeiro.\n");
        getch();
        return(0);
    }
//    gabaritooficial=(char*)malloc(qtde*sizeof(char));
    system("cls");
    printf("\n\nEntre com o gabarito oficial:\n\n\n");
    for(q=0;q<qtde;q++){
        printf ("%d -\t", q+1);
        scanf ("%c", &alt);
        if (alt=='a'||alt=='b'||alt=='c'||alt=='d'||alt=='e'||alt==NULL){
            gabaritooficial[q]=alt;
        } else {
            printf ("Entrada invalida!\n");
            q--;
        }
    }
    return gabaritooficial;
}

void Insere (DadosCandidato x, TipoLista *Lista){
    Lista->Ultimo->Prox = (Apontador)malloc(sizeof(Celula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Candidato = x;
    Lista->Ultimo->Prox = NULL;
}

int main(){

    /*===================DECALRAÇÃO DE VARIAVEIS===================*/

    TipoLista listaAprovados, listaCandidatos;
    DadosCandidato Candidato;
    int escolha, qtde=0, l, c;
    char gaboficial[100], alt='NULL';

    /*===================DECALRAÇÃO DE VARIAVEIS===================*/

    Inicializa(&listaAprovados);
    Inicializa(&listaCandidatos);

    while(escolha!=8){
        system("cls");
        printf ("\t\t\tUnimontes\n\n");
        printf ("1. Configurar vestibular\n");
        printf ("2. Inserir gabarito oficial\n");
        printf ("3. Inserir candidato\n");
        printf ("4. Corrigir provas\n");
        printf ("5. Lista de pontuação\n");
        printf ("6. Lista classificatoria\n");
        printf ("7. Inserir candidatos na fila de espera\n");
        printf ("8. Sair\n");
        scanf ("%d", &escolha);
        if (escolha==1){
            qtde=quantidade();
        }
        if (escolha==2){
            gaboficial = gab_oficial(qtde);
            printf ("%c", alt);
        }
        if (escolha==3){
            printf("Entre com o numero de inscricao do candidato:\t");
            scanf("%d", &Candidato.inscricao);
            printf("Entre com o nome do candidato:\t");
            fflush(stdin);
            gets(Candidato.nome);
            //Candidato.gabarito=(*char)malloc(qtde*sizeof(char));
            printf("Entre o gabarito do candidato:\n");
            fflush(stdin);
            for (c=0;c<qtde;c++){
                printf("%d - ", c+1);
                scanf("%c", &alt);
                if (alt=='a'||alt=='b'||alt=='c'||alt=='d'||alt=='e'){
                    Candidato.gabarito[c]=alt;
                } else {
                    printf ("Entrada invalida!");
                    c--;
                }
                Candidato.gabarito[c]=alt;
                printf ("\n");
            }
            Insere(Candidato, &listaCandidatos);
        }
    }

    return(0);
}
