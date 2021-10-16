/*
Nome: Patrick Pierre Fernandes Ferreira
Data: 27/02/2012
Descrição: Trabalho realizado como parte das exigências para avaliação da disciplina de Algorítmos e estruturas de dados II.
Este trabalho consiste em um programa para cadastros de alunos e notas em determinadas disciplinas, levando-se em consideração
que o número de disciplinas é 10, e o número máximo de alunos por disciplina, 50.
Data da ultima atualização: 24/02/2012
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#define InicioArranjo 0
#define Disciplinas    10
#define QtdeAlunos    50

/*************** DEFINIÇÃO DE ESTRUTURAS ***************/
typedef int TipoChave;

typedef int Apontador;

typedef struct {
    TipoChave Matricula;
    char Nome_Aluno[50];
    int Nota;
} TipoAluno;

typedef struct {
    TipoAluno Aluno[QtdeAlunos];
    Apontador Pri, Ult;
} TipoDisciplina;

typedef struct {
    TipoDisciplina Disciplina[Disciplinas];
    Apontador Primeiro, Ultimo;
} TipoLista;
/*************** DEFINIÇÃO DE ESTRUTURAS ***************/

/********************* PROTOTIPOS *********************/
void FLVazia (TipoLista *Lista);
void FDVazia (TipoDisciplina *Disc);
int Vazia (TipoLista Lista);
int DVazia (TipoDisciplina Disc);
void InsereAluno (TipoAluno x, int d, TipoDisciplina *Aux);
void ImprimeDisciplinaAtual (TipoLista Lista, int x);
void ImprimeTudo (TipoLista Lista);
void Corrige (int a, TipoDisciplina *Aux);
/********************* PROTOTIPOS *********************/

/****************** FUNÇÃO PRINCIPAL ******************/
int main (){
    TipoLista Lista;
    int Menu=0, n, d=-1;
    int altera;
    TipoAluno x;
    TipoDisciplina Disc;

    FLVazia(&Lista);
    FDVazia(&Disc);

    system("color F0");
    for(;;){
        system("cls");
        printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========");
        printf ("\n\n\n");
        printf ("\t 1. Selecionar disciplina\n");
        printf ("\t 2. Inserir aluno/notas\n");
        printf ("\t 3. Alunos cadastrados na disciplina selecionada\n");
        printf ("\t 4. Corrigir notas/apagar aluno\n");
        printf ("\t 5. Alunos cadastrados em todas as disciplinas\n");
        printf ("\t 6. Sair\n\n");
        scanf ("%d", &Menu);
        if (Menu == 1){
            system("cls");
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n");
            printf("\n\nSelecione a disciplina:\n");
            printf("\t0. Disciplina 00\n");
            printf("\t1. Disciplina 01\n");
            printf("\t2. Disciplina 02\n");
            printf("\t3. Disciplina 03\n");
            printf("\t4. Disciplina 04\n");
            printf("\t5. Disciplina 05\n");
            printf("\t6. Disciplina 06\n");
            printf("\t7. Disciplina 07\n");
            printf("\t8. Disciplina 08\n");
            printf("\t9. Disciplina 09\n\n");
            printf("Opção: ");
            scanf("%d", &d);
            if (d > 9 || d <0){
                system ("cls");
                printf ("\nDisciplina não cadastrada, favor verificar as opções listadas.");
            }
        }
        if (Menu == 2 && d != -1){
            system("cls");
            printf ("\n=========== SOFTWARE DE SUPORTE A MANIPULACAO DE NOTAS - UNIMONTES ===========\n");
            printf ("\n\n\tMatricula: ");
            scanf ("%d", &x.Matricula);
            printf ("\tNome: ");
            fflush(stdin);
            gets(x.Nome_Aluno);
            printf ("\tNota: ");
            scanf ("%d", &x.Nota);
            InsereAluno (x, d, &Lista.Disciplina[d]);
        }
        if (Menu == 3 && d != -1){
            system("cls");
            ImprimeDisciplinaAtual(Lista, d);
            getch();
        }
        if (Menu == 4 && d!= -1){
            system("cls");
            ImprimeDisciplinaAtual(Lista, d);
            printf ("\n\nEntre com a matricula do aluno que deseja alterar: ");
            scanf ("%d", &altera);
            Corrige(altera, &Lista.Disciplina[d]);
        }
        if (Menu == 5 && d!= -1){
            system("cls");
            ImprimeTudo (Lista);
        }
        if (Menu == 6) return(0);
        if (Menu != 0 && d == -1){
            printf ("\n\n\tERRO: Selecione a disciplina primeiro");
            getch();
        }
    }
}
/****************** FUNÇÃO PRINCIPAL ******************/

/******************* OUTRAS FUNÇÕES *******************/
void FLVazia (TipoLista *Lista){
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
} //Faz Lista Vazia

void FDVazia (TipoDisciplina *Disc){
    Disc->Pri = InicioArranjo;
    Disc->Ult = Disc->Pri;
} //Faz Disciplina Vazia

int Vazia (TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
} //Verifica se a lista está vazia

int DVazia (TipoDisciplina Disc){
    return (Disc.Pri == Disc.Ult);
}//Verifica se há alunos cadastrados na disciplina

void InsereAluno (TipoAluno x, int d, TipoDisciplina *Aux){
    if (Aux->Ult > QtdeAlunos){
        printf("\n\tErro: A lista está cheia!\n");
        getch();
    } else {
        Aux->Aluno[Aux->Ult] = x;
        Aux->Ult++;
    }
} //Insere aluno na disciplina

void ImprimeDisciplinaAtual (TipoLista Lista, int x){
    int aux;
    if (DVazia(Lista.Disciplina[x])){
        printf("\n\tErro: Disciplina %d não contem dados cadastrados!\nPressione qualquer tecla para retornar...", x);
        getch();
        return;
    }
    printf ("Disciplina %d", x);
    for (aux = Lista.Disciplina[x].Pri; aux < Lista.Disciplina[x].Ult; aux++){
        printf ("\n%d\t\t%s\t\t%d\n", Lista.Disciplina[x].Aluno[aux].Matricula, Lista.Disciplina[x].Aluno[aux].Nome_Aluno, Lista.Disciplina[x].Aluno[aux].Nota);
    }
    printf ("\n\n\tPrecione qualquer tecla para retornar...");
} //Imprime a disciplina selecionada atualmente

void ImprimeTudo (TipoLista Lista){
    int n;
    for (n = InicioArranjo; n < 10; n++){
        if (DVazia(Lista.Disciplina[n])){
            printf ("Disciplina %d ainda não possui alunos cadastrados\n\n", n);
        } else {
            printf ("\n");
            ImprimeDisciplinaAtual (Lista, n);
            printf ("\n");
        }
    }
    getch();
} //Imprime todas as disciplinas e os alunos cadastrados

void Corrige (int a, TipoDisciplina *Aux){
    int n, escolha, m;
    TipoAluno AlAux;

    for (n = Aux->Pri; n < Aux->Ult; n++){
        if (Aux->Aluno[n].Matricula == a){
            system ("cls");
            printf ("\n\tO que deseja fazer em relacao as informacoes do aluno %s?", Aux->Aluno[n].Nome_Aluno);
            printf ("\n\n\t\t1. Corrigir nota\n\t\t2. Apagar aluno\n");
            scanf ("%d", &escolha);
            if (escolha == 1){
                printf ("\n\nNota do aluno: ");
                scanf ("%d", &Aux->Aluno[n].Nota);
            }
            if (escolha == 2){
                for(AlAux = Aux->Aluno[n+1]; n < Aux->Ult; n++){
                    Aux->Aluno[n] = AlAux;
                }
                Aux->Ult--;
                printf ("\n\nDados alterados com sucesso!\n");
                printf ("Pressione qualquer tecla para retornar...");
                getch();
            }
            return;
        }
    }
    printf ("Matricula nao encontrada!\n");
    getch();
} //Altera dados sobre alunos cadastrados (altera nota ou apaga)
/******************* OUTRAS FUNÇÕES *******************/
