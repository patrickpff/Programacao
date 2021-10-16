#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int matricula;
	char nome[50];
	char gabarito[50];
	int nota;
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
	TipoItem Item;
	Apontador Prox;
	Apontador Ant;
} Celula;

typedef struct {
  	Apontador Primeiro, Ultimo;
} TipoLista;

void Inicializa(TipoLista *Lista){
	Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Ant = NULL;
	Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
  	return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
    Apontador Aux;
    Aux=Lista->Ultimo;
	Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = x;
	Lista->Ultimo->Prox = NULL;
	Lista->Ultimo->Ant = Aux;
}

void Imprime(TipoLista Lista){
	Apontador Aux;
	Aux = Lista.Primeiro->Prox;
	if (Vazia(Lista)){
		printf("Erro:Lista vazia!\n");
		return;
	}
    system("cls");
    printf("===============================================================================\n");
    printf("=                              Vestibular Unimontes                           =\n");
    printf("===============================================================================\n\n");
    printf("Lista de candidatos:\n");
	while (Aux != NULL){
		printf("Matricula: %d\n", Aux->Item.matricula);
		printf("Nome: %s\n", Aux->Item.nome);
		printf("Nota: %d\n", Aux->Item.nota);
		printf("Gabarito: %s\n\n", Aux->Item.gabarito);
		Aux = Aux->Prox;
	}
	getch();
	system("cls");
};

void corrigirprovas(TipoLista Lista, char gaba[]){
	Apontador Aux;
	Aux = Lista.Primeiro->Prox;
	int teste=0;
	while(Aux != NULL){
        teste=0;
        Aux->Item.nota=0;
	    while (1){
	        if ((gaba[teste] == 'a' || gaba[teste] == 'A') &&(Aux->Item.gabarito[teste]== 'a' || Aux->Item.gabarito[teste] == 'A')){
	            Aux->Item.nota=Aux->Item.nota+2;
	        }
	        else if ((gaba[teste] == 'b' || gaba[teste] == 'B') &&(Aux->Item.gabarito[teste]== 'b' || Aux->Item.gabarito[teste] == 'B')){
	            Aux->Item.nota=Aux->Item.nota+2;
	        }
	        else if ((gaba[teste] == 'c' || gaba[teste] == 'C') &&(Aux->Item.gabarito[teste]== 'c' || Aux->Item.gabarito[teste] == 'C')){
	            Aux->Item.nota=Aux->Item.nota+2;
	        }
	        else if ((gaba[teste] == 'd' || gaba[teste] == 'D') &&(Aux->Item.gabarito[teste]== 'd' || Aux->Item.gabarito[teste] == 'D')){
	            Aux->Item.nota=Aux->Item.nota+2;
	        }
	        else if ((gaba[teste] == 'e' || gaba[teste] == 'E') &&(Aux->Item.gabarito[teste]== 'e' || Aux->Item.gabarito[teste] == 'E')){
	            Aux->Item.nota=Aux->Item.nota+2;
	        }
	        else if ((gaba[teste] == 'n' || gaba[teste] == 'N') &&(Aux->Item.gabarito[teste]== 'n' || Aux->Item.gabarito[teste] == 'N')){
	            Aux->Item.nota=Aux->Item.nota+0;
	        }
	        else if(gaba[teste] =='S' || gaba[teste]=='s'){
	            break;
	        }
            else{
	            Aux->Item.nota=Aux->Item.nota-1;
            }
            teste++;
	    }
	    Aux = Aux->Prox;
	}
}

void Salvar(TipoLista Lista,int numQ, int mat, char gab[], int cand){
        char nomeTmp[50];
        int x;
        Apontador Aux;
	    Aux = Lista.Primeiro->Prox;
        FILE * arquivo;
        arquivo = fopen ("arquivo.txt","w");
        fprintf(arquivo,"%d\n%d\n%d\n",numQ, mat, cand);
        fprintf(arquivo,"%s\n",gab);
        while(Aux != NULL)
        {
            fprintf(arquivo,"%d\n%d\n",Aux->Item.matricula,Aux->Item.nota);
            for (x=0;x <= numQ; x++)
            {
                fprintf(arquivo,"%c",Aux->Item.gabarito[x]);
            }
            fprintf(arquivo,"\n");
            fprintf(arquivo,"%s\n",Aux->Item.nome);
            Aux = Aux->Prox;
        }
        printf("\n\nSalvo!");
                getch();
        fprintf(arquivo,"%d",-1);
        fclose(arquivo);
}

void Carregar(TipoLista *Lista, int *numQ, int *mat, char *gab, int *cand){
    TipoItem aluno;
    *numQ=0;
    *mat=0;
    *cand=0;
    *gab='\0';
    int verificador=0;
    char tmp[100];
    FILE * arquivo;
    if( (arquivo = fopen ("arquivo.txt","r")) != NULL){
        fscanf(arquivo,"%d",&*numQ);
        fscanf(arquivo,"%d",&*mat);
        fscanf(arquivo,"%d",&*cand);
        fscanf(arquivo,"%s",&*gab);
        while(verificador != -1){
            fscanf(arquivo,"%d",&verificador);
            if(verificador!= -1){
                aluno.matricula=verificador;
                fscanf(arquivo,"%d",&aluno.nota);
                fscanf(arquivo,"%s",&aluno.gabarito);
                fscanf(arquivo,"%s",&aluno.nome);
                Insere(aluno,Lista);
            }
            if(verificador == -1)
                break;
        }

    }
    printf("\n\nCarregado!");
                getch();
	fclose (arquivo);
}

void Selecao(TipoLista *Lista){
	TipoItem Item;
	Apontador Aux, Tmp;
	Aux = Lista->Primeiro->Prox;
	while(Aux->Prox!=NULL){
		Tmp = Aux->Prox;
		while(Tmp!=NULL){
			if(Tmp->Item.nota>Aux->Item.nota){
				Item = Aux->Item;
				Aux->Item=Tmp->Item;
				Tmp->Item=Item;
			}
			Tmp = Tmp->Prox;
		}
		Aux = Aux->Prox;
	}
}

typedef struct TipoFila {
    Apontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila){
    Fila->Frente = (Apontador) malloc(sizeof(Celula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}  /* FFVazia */

int Vazia2(TipoFila Fila){
    return (Fila.Frente == Fila.Tras);
}  /* Vazia */

void Enfileira(TipoItem *x, TipoFila *Fila){
    Fila->Tras->Prox = (Apontador) malloc(sizeof(Celula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = *x;
    Fila->Tras->Prox = NULL;
}

void Retira(TipoLista *Lista, TipoItem *Item){
	Apontador q, Aux;
	Aux = Lista->Primeiro;
	q = Aux->Prox;
	if (Vazia(*Lista) || Aux == NULL || Aux->Prox == NULL) {
		printf(" Erro   Lista vazia ou posicao nao existe!\n");
		return;
	}
	while (q != NULL){
			*Item = q->Item;
			Aux->Prox = q->Prox;
			if (Aux->Prox == NULL)
				Lista->Ultimo = Aux;
			free(q);
			return;
		q = q->Prox;
		Aux = Aux->Prox;
	}
}
void imprime_F (TipoFila Fila){
    Apontador Aux;
    int cont=1;
    Aux = Fila.Frente->Prox;
    printf("\n\nLista de aprovados:\n");
    while(Aux != NULL){
        printf("%d  %s\n",cont,Aux->Item.nome);
        Aux=Aux->Prox;
        cont++;
    }
    getch();
}
int main (){
    int menu=0, quantq=0, mat=999, x, numAprovados, y;
    char goficial[1000];
    TipoLista listaAlunos, listaRepetentes;
    TipoItem aluno, aluno2;
    TipoFila fila;
    FFVazia(&fila);
    Inicializa(&listaAlunos);
    Inicializa(&listaRepetentes);
    while(1){
        system("cls");
        printf("===============================================================================\n");
        printf("=                              Vestibular Unimontes                           =\n");
        printf("===============================================================================\n\n");
        printf(" (1) - Configurar vestibular.\n");
        printf(" (2) - Inserir candidatos.\n");
        printf(" (3) - Corrigir provas.\n");
        printf(" (4) - Lista pontuacao.\n");
        printf(" (5) - Lista classificatoria.\n");
        printf(" (6) - Inserir Candidatos na Fila de Matrícula.\n");
        printf(" (7) - Salvar.\n");
        printf(" (8) - Carregar.\n");
        printf(" (9) - Sair.\n Opcao: ");
        scanf("%d",&menu);
        system("cls");
        if(menu==1){
            printf("===============================================================================\n");
            printf("=                              Vestibular Unimontes                           =\n");
            printf("===============================================================================\n\n");
            printf("Digite a quantidade de vagas: ");
            scanf("%d",&numAprovados);
            printf("Digite a quantidade de questoes: ");
            scanf("%d",&quantq);
            printf("\n\nDigite o gabarito:");
            for (x=0;x<quantq;x++){
                printf("\nQuestao %d) ",x+1);
                fflush(stdin);
                scanf("%c",&goficial[x]);
                if (goficial[x]=='a' || goficial[x]=='b' || goficial[x]=='c' || goficial[x]=='d' || goficial[x]=='e' || goficial[x]=='A' || goficial[x]=='B' || goficial[x]=='C' || goficial[x]=='D' || goficial[x]=='E' || goficial[x]=='n' || goficial[x]=='N'){
                    goficial[x+1]='S';
                }
                else{
                    x--;
                    printf("Resposta invalida!");
                }
            }
            goficial[x+2]='\0';
            system("cls");
        }
        if(menu==2){
            mat++;
            printf("===============================================================================\n");
            printf("=                              Vestibular Unimontes                           =\n");
            printf("===============================================================================\n\n");
            printf("\n Matricula aluno: %d",mat);
            aluno.matricula=mat;
            printf("\n Digite o nome: ");
            fflush(stdin);
            gets(aluno.nome);
            printf("\n Digite o gabarito:");
            for (x=0;x<quantq;x++){
                printf("\n%d) ",x+1);
                fflush(stdin);
                scanf("%c",&aluno.gabarito[x]);
                if (aluno.gabarito[x]=='a' || aluno.gabarito[x]=='b' || aluno.gabarito[x]=='c' || aluno.gabarito[x]=='d' || aluno.gabarito[x]=='e' || aluno.gabarito[x]=='A' || aluno.gabarito[x]=='B' || aluno.gabarito[x]=='C' || aluno.gabarito[x]=='D' || aluno.gabarito[x]=='E' || aluno.gabarito[x]=='0'){
                }
                else{
                    x--;
                    printf("\nResposta invalida.");
                }
            }
            aluno.gabarito[x]='\0';
            aluno.nota = 0;
            system("cls");
            Insere(aluno,&listaAlunos);
        }
        if(menu==3){
            printf("===============================================================================\n");
            printf("=                              Vestibular Unimontes                           =\n");
            printf("===============================================================================\n\n");
            corrigirprovas(listaAlunos,goficial);
            printf("\n\nProvas corrigidas.");
            getch();
        }
        if(menu==4){
            Imprime(listaAlunos);
            getch();
        }
        if(menu==5){
            Selecao(&listaAlunos);
        }
        if (menu==6){
            y=0;
            while(y<numAprovados){
                Retira(&listaAlunos,&aluno2);
                Enfileira(&aluno2,&fila);
                y++;
            }
            imprime_F(fila);
        }
        if(menu==7){
            Salvar(listaAlunos,quantq,mat,goficial,numAprovados);
        }
        if(menu==8){
            Carregar(&listaAlunos,&quantq,&mat,goficial,&numAprovados);
        }
        if(menu==9){
            break;
        }
    }

}
