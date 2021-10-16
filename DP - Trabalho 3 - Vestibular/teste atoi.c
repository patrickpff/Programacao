#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int main (){
    char str[30];
    int i;
    printf ("nome: ");
    fflush(stdin);
    gets(str);
    printf ("valor: ");
    i = atoi(str);
    printf ("\n%d", i);
    getch();
    return(0);
}
