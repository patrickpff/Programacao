#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct hash{
char nome;
struct hash *prox;
};
typedef struct hash Hash;

void init(Hash *tabela[], int tam){
for (int i=0; i<tam; i++){
tabela[i] = NULL;
}
}

int f_hash(char nome){
return (int) num%10; //Função Hash
}

void imprimir(Hash *tabela[], int tam){
for (int i=0; i<tam; i++){
printf("\nIndice: %d ->", i);
Hash *aux = tabela[i];
while (aux != NULL){
printf("\t%.1f", aux->num);
aux = aux->prox;
}
printf("\n\n");
}
system("PAUSE");
}

void inserir(Hash *tabela[], char nome){
Hash *novo = (Hash*)malloc(sizeof(Hash));
novo->nome = nome;
int pos = f_hash(nome);
printf("\nPosicao: %d", pos);
novo->prox = tabela[pos];
tabela[pos] = novo;
getch();
}

void excluir(Hash *tabela[], float x){
int pos = f_hash(x);
Hash *aux;
if(tabela[pos] != NULL){
if(tabela[pos]->num == x){
aux = tabela[pos];
tabela[pos] = tabela[pos]->prox;
free(aux);
printf("\nNumero excluido!");
getch();
}else{
aux = tabela[pos]->prox;
Hash *ant = tabela[pos];
while(aux != NULL && aux->prox != NULL && aux->num != x){
ant = aux;
aux = aux->prox;
}
if(aux != NULL){
ant->prox = aux->prox;
free(aux);
}
else{
printf("\nNumero nao encontrado");
getch();
}
}
}else{
printf("\nNumero nao encontrado");
getch();
}
}

void busca(Hash *tabela[], float num){
int pos = f_hash(num);
Hash *aux = tabela[pos];
while(aux != NULL){
if(aux->num == num){
printf("\nIndice: %d ->", pos);
printf("\t%.1f", aux->num);
}
aux = aux->prox;
}
getch();
}

int main(void){
int tam=10, pos=0, x;
float num;
char op;
Hash *tabela[tam];
init(tabela, tam); //inicia tabela com NULL
//----- > MENU
while (op!='5'){
system("cls");
printf("-= Programa Tabela Hash em C =-\n\n");
printf(" Para inserir digite 1\n");
printf(" Para remover digite 2\n");
printf(" Para pesquisar digite 3\n");
printf(" Para imprimir digite 4\n\n");
printf(" Para sair 5\n");
printf("\n\n\nEscolha uma opcao (1-5): ");
op = getche();
printf("\n");
switch(op){
case '1' :
printf("\n\nDigite o numero a ser inserido: ");
scanf("%f",&num);
inserir(tabela, num);
break;
case '2' :
printf("\n\nDigite o numero a ser removido: ");
scanf("%f",&num);
excluir(tabela, num);
break;
case '3' :
printf("\n\nDigite o numero a ser pesquisado: ");
scanf("%f",&num);
busca(tabela, num);
break;
case '4' :
imprimir(tabela, tam);
break;
}
}
}
