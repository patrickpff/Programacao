/*
Universidade Estadual de Montes Claros
Centro de Ciencias Exatas e Tecnológicas
Departamento de Ciencias da Computação
Sistemas de Informação - 2º Periodo
Programa Editor de Textos
Acadêmico: Luciano Antunes Rocha
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 70

typedef struct celulas *apontador;

typedef struct celulas{
    char caractere,linhat[max];
    apontador prox;
}celula;

typedef struct{
    apontador topo, fundo;
    int tamanho;
}tipopilha;

void fpvazia(tipopilha *pilha){
    pilha->topo = (apontador) malloc (sizeof(celula));
    pilha->fundo =  pilha->topo;
    pilha->fundo->prox = NULL;
    pilha->tamanho = 0;
}

int vazia(tipopilha pilha){
    return(pilha.topo==pilha.fundo);
}

void empilha(tipopilha *pilha, char x){
    apontador aux;
    aux = (apontador) malloc (sizeof(celula));
    pilha->topo->caractere = x;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void desempilha(tipopilha *pilha, char *x){
    apontador q;
    if (vazia(*pilha)){
        printf(" Erro   lista vazia\n");
        return;
    }
    q = pilha->topo;
    pilha->topo = q->prox;
    *x = q->prox->caractere;
    free(q);
    pilha->tamanho--;
}

void imprime(char vetor[], int c){
    c=c-1;
    for(;c>0;c--){
        if(c%70==0 || vetor[c]=='*'){
            c=c-1;
            printf("\n");
        }
        if (vetor[c]!='*'){
            printf("%c",vetor[c]);
        }
    }
}

void salvar(tipopilha linha){
    int c=1, t;
    t = linha.tamanho;
    char vetor[t];
    apontador b;
    b=linha.topo;
    FILE * arquivo;
    arquivo = fopen ("arquivo.txt", "w");
    while (b->prox!=NULL){
        vetor[c]=b->prox->caractere;
        b=b->prox;
        c++;
    }
    c=c-1;
    for(;c>0;c--){
        if(c%70==0 || vetor[c]=='*'){
            c=c-1;
            fprintf (arquivo, "\n");
        }
        if(vetor[c]!='*'){
            fprintf (arquivo, "%c", vetor[c]);
        }
    }
    fclose (arquivo);
}

void inverte(tipopilha linha){
    int c=1,t;
    t=linha.tamanho;
    char vetor[t];
    apontador b;
    b=linha.topo;
    while(b->prox!=NULL){
        vetor[c]=b->prox->caractere;
        b=b->prox;
        c++;
    }
   imprime(vetor,c);
}


int main(){
    tipopilha linha,texto;
    int menu,i;
    char x,a;

    fpvazia(&texto);
    fpvazia(&linha);
    printf("\t\t\tWelcome to text editor\n");
    for(;menu!=2;){
        printf("\n\n\t\t\tOptions:\n[1] Para digitar\n[2] Para Sair do Editor\n\n");
        scanf("%d",&menu);
        switch(menu){
            case 1:
                printf ("\t\t@ - para encerrar o seu texto:\n");
                printf ("\t\t# - Apaga caractere\n");
                printf ("\t\t/ - Apaga linha\n");
                printf ("\t\t* - Saltar linha\n");
                for(;x!='@';){
                    fflush(stdin);
                    x=getch();
                    if(x!='#' && x!='/' && x!='~'){
                        empilha(&linha, x);
                    }
                    else if(x=='~'){
                        salvar(linha);
                        break;
                    }
                    else if (x=='#'){
                    desempilha(&linha,&a);
                    }
                    else if (x=='/'){
                        for(i=0;i<max;i++){
                            desempilha(&linha,&a);
                        }
                    }
                    system("cls");
                inverte(linha);
                }
                break;
            default:
                break;
        }
    }
    getch();
    return(0);
}

