/*
Nome: Patrick Pierre Fernandes Ferreira
Nome: Messias Ferreira Muniz
Data: 30/04/2011
Descrição: Este reversi foi um trabalho desenvolvido para a disciplina de Algoritimos e programação I
Data da ultima atualização: 30/04/2011
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void regras (void){
    int k;
    printf("\n\t** Regras do jogo Reversi **\n");
     printf("\t. As pecas iniciam-se alternadas no centro do tabuleiro.\n");
     printf("\t. As pecas \"O\" comecam jogando, sendo \"X\" a cor contraria.\n");
     printf("\t. Uma peca e transformada (trocando de cor) quando estiver no\n");
     printf("\t  espaco entre duas pecas da cor contraria a sua, sendo uma\n");
     printf("\t  delas a ultima peca colocada no tabuleiro.\n");
     printf("\t. Uma jogada valida e aquela em que, com a nova peca colocada,\n");
     printf("\t  haja pelo menos uma peca adversaria transformada.\n");
     printf("\t. O jogador da vez escolhe uma casa vazia (que tem um \".\")\n");
     printf("\t  contanto que seja uma jogada valida, e coloca sua peca ali,\n");
     printf("\t  fornecendo suas coordenadas (Linha e Coluna, nessa ordem).\n");
     printf("\t. Apos jogar, o outro jogador faz seu movimento tambem.\n");
     printf("\t. Caso nao haja movimentos validos para um dos jogadores,\n");
     printf("\t  o outro jogador joga. Caso ambos fiquem sem movimentos possiveis\n");
     printf("\t  o jogo termina.\n");
     printf("\t. Se nao houverem espacos vazios, o jogo termina.\n");
     printf("\t. Se nao houver pelo menos 1 peca de cada uma das cores, o jogo termina\n");
     printf("\t. Vence o jogador que, ao termino do jogo, possuir mais pecas.\n");
     printf ("\n\nPrecione qualquer tecla para voltar.");
     getch();
     system("cls");
     main ();
}

int main (){
    int tab[8][8], l, tl, c, tc, val=0, val1, val2, jpont1, jpont2, nval=0, escolha;
    clock_t temp1, temp2;
    double tempt;
    char jog1[10], jog2[10];
    system("color F8");
    printf ("-------    ---------  ---      ---  ---------  -------     --------    ----\n");
    printf ("--------   ---------  ---      ---  ---------  --------   ----------   ----\n");
    printf ("---------  ---------  ---      ---  ---------  ---------  ---    ---   ----\n");
    printf ("--    ---  --         ---      ---  --         --    ---  ---          ----\n");
    printf ("--    ---  ------     ---      ---  ------     --    ---   --------    ----\n");
    printf ("--------   ------     ---      ---  ------     --------     --------   ----\n");
    printf ("------     ------     ---      ---  ------     ------             ---  ----\n");
    printf ("-- ---     --          ---    ---   --         -- ---              --- ----\n");
    printf ("--  ---    ---------    ---  ---    ---------  --  ---    ---      --- ----\n");
    printf ("--   ---   ---------     ------     ---------  --   ---    ----------  ----\n");
    printf ("--    ---  ---------      ----      ---------  --    ---    --------   ----\n\n");
    printf ("\tPatrick Pierre Fernandes Ferreira\tMessias Ferreira Muniz\n\n\n");
    printf ("\t\t\t( 1 ) Jogar\n");
    printf ("\t\t\t( 2 ) Instruções\n");
    scanf ("%d", &escolha);
    system("cls");
    switch (escolha){
    case 1:
    temp1 = clock();
    printf ("\n\n\n\t\t\tEntre com o nome do jogador 1:");
    scanf ("%s", &jog1);
    printf ("\n\n\n\t\t\tEntre com o nome do jogador 2:");
    scanf ("%s", &jog2);
    printf ("\n\n");
    system ("cls");
    for (tl=0; tl<8; tl++){
        for (tc=0; tc<8; tc++){
            tab[tl][tc]=0;//iguala todos os quadros do tabuleiro a 0, para que nao recebam valores aleatórios
        }
    }
    tab[3][3]=1; //valores inicialmente conhecidos do tabuleiro
    tab[3][4]=2;
    tab[4][3]=2;
    tab[4][4]=1;
    temp1=clock();
    while (val1!=0 && val2!=0){
        for (tl=0; tl<8; tl++){
            for (tc=0; tc<8; tc++){
                if (tab[tl][tc]!=0){
                    if ((tab[tl][tc-1]==2)||(tab[tl-1][tc]==2)||(tab[tl-1][tc-1]==2)||(tab[tl+1][tc]==2)||(tab[tl][tc+1]==2)||(tab[tl+1][tc+1]==2)||(tab[tl+1][tc-1]==2)||(tab[tl-1][tc+1]==2)){
                        val1=0; //verifica se existe alguma jogada válida
                        } else{
                            printf ("Nenhuma jogada válida");
                            val1=1;
                            break;
                        }
                }
            }
        }
        while(val1==0){ //testa a validade da jogada
            printf("\t");
            for (tc=0; tc<8; tc++){
                printf("%d\t", tc);
            }
            printf ("\n");
            for (tl=0; tl<8; tl++){ //imprime sempre a tabela antes da jogada do jogador 1
                printf ("%d -\t", tl);
                for (tc=0; tc<8; tc++){
                    if (tab[tl][tc]==0){
                        printf ("-\t");
                        } else {
                            printf ("%d\t", tab[tl][tc]);
                            }
                }
                printf ("\n");
            }
            printf ("Entre com as coordenadas da casa, %s (linha coluna)", jog1);
            scanf ("%d %d", &l, &c); //determina a posição da jogada do jogador 1
            switch(tab[l][c]){ //testa se a casa em questão está vazia
                case 0:
                    tl=l-1; //acrescenta a tl o valor de l-1
                    while (tab[tl][c]==2 || tl>-1){
                        if (tab[tl][c]==1){
                            val=1;
                            break;
                            }
                        tl--;
                    }
                    if (val==1){
                        tl=l-1;
                        tab[l][c]=1;
                        while(tab[tl][c]==2){
                            tab[tl][c]=1;
                            tl--;
                        }
                    } else {
                        nval++;
                        }
                    val=0; //zerar a variavel de teste de validade de jogada (presente antes de todos os testes)
                    tl=l+1; //tl ou tc recebem l e c decrementados ou encrementados, para testar as casas ao redor da casa escolhida
                    while (tab[tl][c]==2 || tl<8){
                        if (tab[tl][c]==1){
                            val=1;
                            break;
                            }
                            tl++;
                        }
                        if (val==1){
                            tl=l+1;
                            tab[l][c]=1;
                            while(tab[tl][c]==2){
                                tab[tl][c]=1;
                                tl++;
                            }
                        } else {
                            nval++;
                            }
                        val=0;
                        tc=c-1;
                        while (tab[l][tc]==2 || tc>-1){
                            if (tab[l][tc]==1){
                                val=1;
                                break;
                                }
                                tc--;
                        }
                        if (val==1){
                            tc=c-1;
                            tab[l][c]=1;
                            while(tab[l][tc]==2){
                                tab[l][tc]=1;
                                tc--;
                                }
                        } else{
                            nval++;
                            }
                        val=0;
                        tc=c+1;
                        while (tab[l][tc]==2 || tc<8){
                            if (tab[l][tc]==1){
                                val=1;
                                break;
                                }
                                tc++;
                            }
                        if (val=1){
                            tl=l-1;
                            tab[l][c]=1;
                            while (tab[tl][c]==2){
                                tab[tl][c]=1;
                                tl--;
                            }
                        } else {
                            nval++;
                            }
                        val=0;
                        tc=c-1;
                        tl=l+1;
                        while (tab[tl][tc]==2 || (tc>-1 && tl<8)){
                            if (tab[tl][tc]==1){
                                val=1;
                                break;
                            }
                            tc--;
                            tl++;
                        }
                        if (val=1){
                            tc=c-1;
                            tl=l+1;
                            while (tab[tl][tc]==2){
                                tab[tl][tc]=1;
                                tc--;
                                tl++;
                            }
                        } else {
                            nval++;
                            }
                        val=0;
                        tc=c+1;
                        tl=l+1;
                        while (tab[tl][tc]==2 || (tc<8 && tl<8)){
                            if (tab[tl][tc]==1){
                                val=1;
                                break;
                                }
                            tl++;
                            tc++;
                        }
                        if (val=1){
                            tc=c+1;
                            tl=l+1;
                            while (tab[tl][tc]==2){
                                tab[tl][tc]=1;
                                tl++;
                                tc++;
                                }
                        } else {
                            nval++;
                            }
                        val=0;
                        tc=c+1;
                        tl=l-1;
                        while (tab[tl][tc]==2 || (tc<8 && tl>-1)){
                            if (tab[tl][tc]==1){
                                val=1;
                                break;
                                }
                            tl--;
                            tc++;
                        }
                        if (val=1){
                            tc=c+1;
                            tl=l-1;
                            while (tab[tl][tc]==2){
                                if (tab[tl][tc]==1){
                                    val=1;
                                    tl--;
                                    tc++;
                                }
                            }
                        } else {
                            nval++;
                            }
                        val=0;
                        tc=c-1;
                        tl=l-1;
                        while (tab[tl][tc]==2 || (tc>-1 && tl>-1)){
                            if (tab[tl][tc]==1){
                                val=1;
                                break;
                            }
                            tl--;
                            tc--;
                        }
                        if (val=1){
                            tc=c-4;
                            tl=l-1;
                            while (tab[tl][tc]==2){
                                if (tab[tl][tc]==1){
                                    val=1;
                                    tl--;
                                    tc--;
                                }
                            }
                        } else {
                            nval++;
                            }
                        if (nval==8){
                            printf ("Jogada invalida\n");
                            }
                break;
            case 1:
                regras();
            case 2:
                printf ("Jogada invalida\n");
          }
          if (val=1){
            val1=1;
          }
        }
        nval=0;
        system("cls");
        for (tl=0; tl<8; tl++){
            for (tc=0; tc<8; tc++){
                if (tab[tl][tc]!=0){
                    if ((tab[tl][tc-1]==1)||(tab[tl-1][tc]==1)||(tab[tl-1][tc-1]==1)||(tab[tl+1][tc]==1)||(tab[tl][tc+1]==1)||(tab[tl+1][tc+1]==1)||(tab[tl+1][tc-1]==1)||(tab[tl-1][tc+1]==1)){
                        val2=0; //verifica se existe alguma jogada válida
                        break;
                        }
                }
            }
        }
        for (tl=0; tl<8; tl++){
            for (tc=0; tc<8; tc++){
                if (tab[tl][tc]!=0){
                    if ((tab[tl][tc-1]==1)||(tab[tl-1][tc]==1)||(tab[tl-1][tc-1]==1)||(tab[tl+1][tc]==1)||(tab[tl][tc+1]==1)||(tab[tl+1][tc+1]==1)||(tab[tl+1][tc-1]==1)||(tab[tl-1][tc+1]==1)){
                        val2=0; //verifica se existe alguma jogada válida
                        break;
                        } else{
                            printf ("Nenhuma jogada válida");
                            val1=1;
                            break;
                        }
                }
            }
        }
        val=0;
        while (val2==0){
            for (tl=0; tl<8; tl++){
                for (tc=0; tc<8; tc++){
                    if (tab[tl][tc]!=0){
                        if ((tab[tl][tc-1]==1)||(tab[tl-1][tc]==1)||(tab[tl-1][tc-1]==1)||(tab[tl+1][tc]==1)||(tab[tl][tc+1]==1)||(tab[tl+1][tc+1]==1)||(tab[tl+1][tc-1]==1)||(tab[tl-1][tc+1]==1)){
                            val2=0; //"reinicia" as variaveis que testam a validade da jogada
                        }
                    }
                }
            }
            printf("\t");
            for (tc=0; tc<8; tc++){
                printf("%d\t", tc);
            }
            printf ("\n");
            for (tl=0; tl<8; tl++){ //imprime sempre a tabela antes da jogada do jogador 1
                printf ("%d -\t", tl);
                for (tc=0; tc<8; tc++){
                    if (tab[tl][tc]==0){
                        printf ("-\t");
                        } else {
                            printf ("%d\t", tab[tl][tc]);
                            }
                }
                printf ("\n");
            }
            val=0;
            printf ("Entre com as coordenadas da casa, %s (linha coluna)", jog2);
            scanf ("%d %d", &l, &c); //determina a posição da jogada do jogador 2
            switch(tab[c][l]){ //testa a possibilidade da jogada e incrementa o valor na matriz
                case 0:
                    tl=l-1; //acrescenta a tl o valor de l-1
                    while (tab[tl][c]==1 || tl>-1){
                        if (tab[tl][c]==2){
                            val=1;
                            break;
                            }
                            tl--;
                    }
                    if (val==1){
                        tl=l-1;
                        tab[l][c]=2;
                        while(tab[tl][c]==1){
                            tab[tl][c]=2;
                            tl--;
                            }
                        } else {
                            nval++;
                            }
                    val=0; //zerar a variavel de teste de validade de jogada (presente antes de todos os testes)
                    tl=l+1; //tl ou tc recebem l e c decrementados ou encrementados, para testar as casas ao redor da casa escolhida
                    while (tab[tl][c]==1 || tl<8){
                        if (tab[tl][c]==2){
                            val=1;
                            break;
                            }
                            tl++;
                        }
                        if (val==1){
                            tl=l+1;
                            tab[l][c]=2;
                            while(tab[tl][c]==1){
                                tab[tl][c]=2;
                                tl++;
                            }
                        } else {
                            nval++;
                        }
                        val=0;
                        tc=c-1;
                        while (tab[l][tc]==1 || tc>-1){
                            if (tab[l][tc]==2){
                                val=1;
                                break;
                            }
                            tc--;
                        }
                        if (val==1){
                            tc=c-1;
                            tab[l][c]=2;
                            while(tab[l][tc]==1){
                                tab[l][tc]=2;
                                tc--;
                                }
                        } else{
                            nval++;
                        }
                        val=0;
                        tc=c+1;
                        while (tab[l][tc]==1 || tc<8){
                            if (tab[l][tc]==2){
                                val=1;
                                break;
                            }
                            tc++;
                        }
                        if (val=1){
                            tl=l-1;
                            tab[l][c]=2;
                            while (tab[tl][c]==1){
                                tab[tl][c]=2;
                                tl--;
                                }
                            } else {
                                nval++;
                            }
                        val=0;
                        tc=c-1;
                        tl=l+1;
                        while (tab[tl][tc]==1 || (tc>-1 && tl<8)){
                            if (tab[tl][tc]==2){
                                val=1;
                                break;
                            }
                            tc--;
                            tl++;
                        }
                        if (val=1){
                            tc=c-1;
                            tl=l+1;
                            while (tab[tl][tc]==1){
                                tab[tl][tc]=2;
                                tc--;
                                tl++;
                            }
                        } else {
                            nval++;
                        }
                        val=0;
                        tc=c+1;
                        tl=l+1;
                        while (tab[tl][tc]==1 || (tc<8 && tl<8)){
                            if (tab[tl][tc]==2){
                                val=1;
                                break;
                            }
                            tl++;
                            tc++;
                        }
                        if (val=1){
                            tc=c+1;
                            tl=l+1;
                            while (tab[tl][tc]==1){
                                tab[tl][tc]=2;
                                tl++;
                                tc++;
                            }
                        } else {
                            nval++;
                        }
                        val=0;
                        tc=c+1;
                        tl=l-1;
                        while (tab[tl][tc]==1 || (tc<8 && tl>-1)){
                            if (tab[tl][tc]==2){
                                val=1;
                                break;
                            }
                            tl--;
                            tc++;
                        }
                        if (val=1){
                            tc=c+1;
                            tl=l-1;
                            while (tab[tl][tc]==1){
                                if (tab[tl][tc]==2){
                                    val=1;
                                    tl--;
                                    tc++;
                                }
                            }
                        } else {
                            nval++;
                        }
                        val=0;
                        tc=c-1;
                        tl=l-1;
                        while (tab[tl][tc]==1 || (tc>-1 && tl>-1)){
                            if (tab[tl][tc]==2){
                                val=1;
                                break;
                            }
                            tl--;
                            tc--;
                        }
                        if (val=1){
                            tc=c-4;
                            tl=l-1;
                            while (tab[tl][tc]==1){
                                if (tab[tl][tc]==2){
                                    val=1;
                                    tl--;
                                    tc--;
                                }
                            }
                        } else {
                            nval++;
                            }
                if (nval==8){
                    printf ("Jogada invalida\n");
                }
                break;
                case 1:
                case 2:
                    printf ("Jogada invalida\n");
            }
            if (val=1){
                val1=1;
            }
        }
        system("cls");
        val1=0;
        val2=0;
    }
    for (tl=0; tl<8; tl++){
        for (tc=0; tc<8; tc++){
            if (tab[tl][tc]==1){
                jpont1++;
            }
            if (tab[tl][tc]==2){
                jpont2++;
            }
        }
    }
    temp2=clock();
    tempt = ((double)(temp2-temp1))/CLOCKS_PER_SEC;
    if (jpont1>jpont2){
        printf ("%s venceu a partida", jog1);
    }
    if (jpont2>jpont1){
        printf ("%s venceu a partida", jog2);
    }
    if (jpont1=jpont2){
        printf ("A partida entre %s e %s terminou em empate", jog1, jog2);
    }
    printf ("Tempo total: %lf", tempt);
    break;
    case 2:
        regras ();
        break;
    }
    getch();
    return(0);
}
