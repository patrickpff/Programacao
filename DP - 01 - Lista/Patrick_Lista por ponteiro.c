/*
Nome: Patrick Pierre Fernandes Ferreira
Data: 05/03/2012
Descrição: Trabalho realizado como parte das exigências para avaliação da disciplina de Algorítmos e estruturas de dados II.
Este trabalho consiste em um programa para cadastros de alunos e notas em determinadas disciplinas com a utilização de lista por ponteiros.
Data da ultima atualização: 24/02/2012
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/*************** DEFINIÇÃO DE ESTRUTURAS ***************/
typedef struct {
    int Matricula;
    char NomeAluno[50];
    int Nota;
} TipoAluno;

typedef struct Celula_Str *Apontador;

typedef struct Celula_Str {
    TipoAluno Aluno;
    Apontador Prox;
} Cel_Aluno;

typedef struct {
    int CodDisc;
    char NomeDisc[50];
    Apontador Pri, Ult;
} TipoDisciplina;

typedef struct Celula_Str2 *Ponteiro;

typedef struct Celula_Str2 {
    TipoDisciplina Disc;
    Ponteiro Proximo;
} Disciplina;

typedef struct {
    Ponteiro Primeiro, Ultimo;
} TipoLista;
/*************** DEFINIÇÃO DE ESTRUTURAS ***************/

/********************* PROTOTIPOS *********************/
void InicializaLista (TipoLista *Lista);
int VaziaLista (TipoLista Lista);
void InicializaDisc (TipoDisciplina *Disc);
int VaziaDisc (TipoDisciplina Disc);
void InsereDisc (TipoDisciplina x, TipoLista *Lista);
void InsereAluno (TipoAluno x, TipoDisciplina *Disc);
void ImprimeDisciplinas (TipoLista Lista);
void ImprimeAtual (TipoDisciplina Disc);
void Corrige (int escolha, TipoAluno *Aux);
void Retira (int matproc, TipoDisciplina *Disc);
/********************* PROTOTIPOS *********************/

/****************** FUNÇÃO PRINCIPAL ******************/
int main (){
    int Menu=0, cdsel, escolha, altera;
    TipoLista Lista;
    TipoDisciplina Disc;
    Ponteiro Aux;
    Apontador Aux2;
    TipoAluno Al;

    InicializaLista (&Lista);
    InicializaDisc (&Disc);

    system("color F0");

    for(;;){
        system ("cls");
        printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n\n");
        printf ("\t\t1. Inserir disciplina\n");
        printf ("\t\t2. Selecionar disciplina\n");
        printf ("\t\t3. Inserir aluno\n");
        printf ("\t\t4. Imprimir alunos da disciplina atual\n");
        printf ("\t\t5. Corrigir notas / apagar aluno\n");
        printf ("\t\t6. Sair\n\n");
        scanf ("%d", &Menu);

        if (Menu == 1){
            system ("cls");
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
            printf ("Entre com o codigo da disciplina: ");
            scanf ("%d", &Disc.CodDisc);
            printf ("Entre com o nome da disciplina: ");
            fflush(stdin);
            gets (Disc.NomeDisc);
            InsereDisc(Disc, &Lista);
            printf ("\n\nDeseja inserir alunos na disciplina agora?");
            printf ("\n\t1. Sim\t\t2. Nao\n");
            scanf ("%d", &escolha);
            if (escolha == 1){
                Aux = Lista.Primeiro->Proximo;
                while (Aux->Disc.CodDisc != Disc.CodDisc){
                    Aux = Aux->Proximo;
                }
                Menu = 3;
            }
        }

        if (Menu == 2){
            system ("cls");
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
            ImprimeDisciplinas(Lista);
            if (VaziaLista(Lista)){
            printf ("Erro! A lista esta vazia");
            } else {
                printf ("\nEntre com o codigo da disciplina:");
                scanf ("%d", &cdsel);
                Aux = Lista.Primeiro->Proximo;
                while (Aux->Disc.CodDisc != cdsel){
                    Aux = Aux->Proximo;
                    if (Aux == NULL) break;
                }
                if (Aux == NULL){
                    printf ("Erro! Codigo invalido.");
                    getch();
                }
            }
        }

        if (Menu == 3){
            system("cls");
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
            printf ("Matricula: ");
            scanf ("%d", &Al.Matricula);
            printf ("Nome: ");
            fflush(stdin);
            gets (Al.NomeAluno);
            printf ("Nota: ");
            scanf ("%d", &Al.Nota);
            InsereAluno (Al, &Aux->Disc);
        }

        if (Menu == 4){
            system ("cls");
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
            ImprimeAtual (Aux->Disc);
            getch();
        }

        if (Menu == 5){
            system ("cls");
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
            if (VaziaDisc (Aux->Disc)){
                printf ("A disciplina nao possui alunos cadastrados");
                getch();
            } else{
                ImprimeAtual (Aux->Disc);
                printf ("\n\nEntre com a matricula do aluno que deseja alterar: ");
                scanf ("%d", &altera);
                system("cls");
                printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
                Aux2 = Aux->Disc.Pri->Prox;
                while (Aux2->Aluno.Matricula != altera){
                    Aux2 = Aux2->Prox;
                }
                printf ("\t%d", Aux2->Aluno.Matricula);
                printf ("\t\t%s", Aux2->Aluno.NomeAluno);
                printf ("\t\t%d\n", Aux2->Aluno.Nota);
                printf ("Qual informacao deseja alterar?");
                printf ("\n\t1. Matricula\n\t2. Nome\n\t3. Nota\n\t4. Apagar\n\t5. Retornar\n\n");
                scanf ("%d", &escolha);
                if (escolha == 1 || escolha == 2 || escolha == 3 || escolha ==4){
                    Corrige(escolha, &Aux2->Aluno);
                }
                if (escolha == 4){
                    Retira (Aux2->Aluno.Matricula, &Aux->Disc);
                    printf ("Dados removidos com sucesso!");
                    getch();
                }
            }
        }

        if (Menu == 6) {
            return (0);
        }
        if (Menu > 6 || Menu < 1){
            printf ("Opcao Invalida");
            getch();
        }

    }
}
/****************** FUNÇÃO PRINCIPAL ******************/

/******************* OUTRAS FUNÇÕES *******************/
void InicializaLista (TipoLista *Lista){
    Lista->Primeiro = (Ponteiro) malloc (sizeof(Disciplina));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Proximo = NULL;
} //Cria célula cabeça para a lista de disciplinas

int VaziaLista (TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
} //Verifica se a lista está vazia

void InicializaDisc (TipoDisciplina *Disc){
    Disc->Pri = (Apontador) malloc (sizeof(TipoAluno));
    Disc->Ult = Disc->Pri;
    Disc->Pri->Prox = NULL;
} //Cria célula cabeça em disciplina (onde vamos armazenar os 'n' TipoAluno)

int VaziaDisc (TipoDisciplina Disc){
    return (Disc.Pri == Disc.Ult);
} //Verifica se a disciplina está vazia

void InsereDisc (TipoDisciplina x, TipoLista *Lista){
    Lista->Ultimo->Proximo = (Ponteiro) malloc (sizeof(Disciplina));
    Lista->Ultimo = Lista->Ultimo->Proximo;
    Lista->Ultimo->Disc = x;
    Lista->Ultimo->Proximo = NULL;
} //Insere uma nova disciplina no TipoLista utilizado

void InsereAluno (TipoAluno x, TipoDisciplina *Disc){
    Disc->Ult->Prox = (Apontador) malloc (sizeof(TipoAluno));
    Disc->Ult = Disc->Ult->Prox;
    Disc->Ult->Aluno = x;
    Disc->Ult->Prox = NULL;
} //Insere um novo aluno no TipoDisciplina escolhido

void ImprimeDisciplinas (TipoLista Lista){
    Ponteiro Aux;
    Aux = Lista.Primeiro->Proximo;
    if (VaziaLista(Lista)){
        printf ("Erro: A lista esta vazia!");
        getch();
        return;
    }
    printf ("\nDisciplinas atualmente cadastradas:\n\n");
    while (Aux != NULL){
        printf ("\t%d\t\t%s\n", Aux->Disc.CodDisc, Aux->Disc.NomeDisc);
        Aux = Aux->Proximo;
    }
} //Imprime código e nome das disciplinas cadastradas

void ImprimeAtual (TipoDisciplina Disc){
    Apontador Aux;
    Aux = Disc.Pri->Prox;
    if (VaziaDisc(Disc)){
        printf ("Erro: A lista esta vazia!");
        getch();
        return;
    }
    printf ("Alunos cadastrados na disciplina de %s:\n\n", Disc.NomeDisc);
    while (Aux != NULL){
        printf ("\t%d", Aux->Aluno.Matricula);
        printf ("\t\t%s", Aux->Aluno.NomeAluno);
        printf ("\t\t%d\n", Aux->Aluno.Nota);
        Aux = Aux->Prox;
    }
} //Imprime alunos cadastrados na disciplina selecionada atualmente

void Corrige (int escolha, TipoAluno *Aux){
    int mat;
    system ("cls");
    printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
    printf ("Correcao de dados:\n\n");
    if (escolha == 1){
        printf ("\tEntre com a matricula correta: ");
        scanf ("%d", &Aux->Matricula);
    }
    if (escolha == 2){
        printf ("\tEntre com o nome correto: ");
        fflush(stdin);
        gets (Aux->NomeAluno);
    }
    if (escolha == 3){
        printf ("\tEntre com a nota correta: ");
        scanf ("%d", &Aux->Nota);
    }
} //Corrige dados do aluno cadastrado

void Retira (int matproc, TipoDisciplina *Disc){
    int esc;
    Apontador Aux, q;
    Aux = Disc->Pri;
    q = Aux->Prox;
    while (q != NULL){
        if (q->Aluno.Matricula == matproc){
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n\n");
            printf ("Deseja realmente apagar o aluno %s, de matricula %d?", q->Aluno.NomeAluno, q->Aluno.Matricula);
            printf ("\n\n\t1. Sim\n\t2. Nao");
            scanf ("%d", &esc);
            if (esc == 2) return;
            if (esc == 1){
                Aux->Prox = q->Prox;
                if (Aux->Prox == NULL)
                    Disc->Ult = Aux;
                free(q);
                return;
            }
        }
        q = q->Prox;
        Aux = Aux->Prox;
    }
} //Retira aluno da lista
/******************* OUTRAS FUNÇÕES *******************/
