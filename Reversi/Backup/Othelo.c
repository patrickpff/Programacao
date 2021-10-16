/*
*/
#include <stdio.h>
#include <conio.h>

int main (){
    int tab[8][8], l, tl, c, tc, jog=1, val=0, val1, val2, jpont1, jpont2, win=0, nval=0, escolha;
    char jog1[10], jog2[10];
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
    printf ("\t\t( 1 ) Jogar\n");
    printf ("\t\t( 2 ) Instruções\n");
    printf ("\t\t( 3 ) Recorde\n");
    scanf ("%d", &escolha);
    system("cls");
    switch (escolha){
    case 1:
    printf ("Entre com o nome do jogador 1:");
    scanf ("%s", &jog1);
    printf ("Entre com o nome do jogador 2:");
    scanf ("%s", &jog2);
    printf ("\n\n");
    for (tl=0; tl<8; tl++){
        for (tc=0; tc<8; tc++){
            tab[tl][tc]=0;//iguala todos os quadros do tabuleiro a 0, para que nao recebam valores aleatórios
        }
    }
    tab[3][3]=1; //valores inicialmente conhecidos do tabuleiro
    tab[3][4]=2;
    tab[4][3]=2;
    tab[4][4]=1;
    while (win==0){
        val1=0; //"reinicia" as variaveis que testam a validade da jogada
        val2=0;
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
          switch(tab[c][l]){ //testa se a casa em questão está vazia
            case 0:
                tl=l-1;
                while (tab[tl][c]==2 || tl>-1){
                    if (tab[tl][c]==1){
                        val=1;
                        break;
                    }
                    tl--;
                }
                tl=l-1;
                if (val=1){
                    tab[l][c]=1;
                    while(tab[tl][c]==2){
                        tab[tl][c]=1;
                        tl--;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l-1;
                tc=c-1;
                val=0; //reinicia o valor de "val" a cada nova possibilidade
                while (tab[tl][tc]==2 || (tl>-1 && tc>-1)){
                    if (tab[tl][c]==1){
                        val=1;
                        break;
                    }
                    tl--;
                    tc--;
                }
                tl=l-1;
                tc=c-1;
                if (val=1){
                    tab[l][c]=1;
                    while (tab[tl][tc]==2){
                        tab[tl][tc]=1;
                        tl--;
                        tc--;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l-1;
                tc=c+1;
                val=0;
                while (tab[tl][tc]==2 || (tl>-1 && tc<8)){
                    if (tab[tl][tc]==1){
                        val=1;
                        break;
                    }
                    tl--;
                    tc++;
                }
                tl=l-1;
                tc=c+1;
                if (val=1){
                    tab[l][c]=1;
                    while (tab[tl][tc]==2){
                        tab[tl][tc]=1;
                        tl--;
                        tc++;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tc=c-1;
                val=0;
                while (tab[l][tc]==2 || tc>-1){
                    if (tab[l][tc]==1){
                        val=1;
                        break;
                    }
                    tc--;
                }
                tc=c-1;
                if (val=1){
                    tab[l][tc]=1;
                    while (tab[l][tc]==2){
                        tab[l][tc]=1;
                        tc--;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tc=c+1;
                val=0;
                while (tab[l][tc]==2 || tc<8){
                    if (tab[l][tc]==1){
                        val=1;
                        break;
                    }
                    tc++;
                }
                tc=c+1;
                if (val=1){
                    tab[l][c]=1;
                    while (tab[l][tc]==2){
                        tab[l][tc]=1;
                        tc++;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l+1;
                tc=c-1;
                val=0;
                while (tab[tl][tc]==2 || (tc>-1 && tl<8)){
                    if (tab[tl][tc]==1){
                        val=1;
                        break;
                    }
                    tc--;
                    tl++;
                }
                tl=l+1;
                tc=c-1;
                if (val=1){
                    tab[l][c]=1;
                    while (tab[tl][tc]==2){
                        tab[tl][c]=1;
                        tl++;
                        tc--;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l+1;
                val=0;
                while (tab[tl][c]==2 || tl<8){
                    if (tab[tl][c]==1){
                        val=1;
                        break;
                    }
                    tl++;
                }
                tl=l+1;
                if (val=1){
                    tab[l][c]=1;
                    while(tab[tl][c]==2){
                        tab[tl][c]=1;
                        tl++;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l+1;
                tc=c+1;
                while (tab[tl][tc]==2 || tl<8 || tc<8){
                    if (tab[tl][tc]==1){
                        val=1;
                        break;
                    }
                    tl++;
                    tc++;
                }
                if (tab[tl][tc]==2){
                    tab[l][c]=1;
                    while (tab[tl][tc]==2){
                        tab[tl][tc]=1;
                        tl++;
                        tc++;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                if (nval=8){
                    printf ("Jogada invalida\n");
                }
                break;
            case 1:
            case 2:
                printf ("Jogada invalida\n");
          }
        }
        nval=0;
        system("cls");
        while (val2==0){
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
          printf ("Entre com as coordenadas da casa, %s (linha coluna)", jog2);
          scanf ("%d %d", &l, &c); //determina a posição da jogada do jogador 2
            switch(tab[c][l]){ //testa a possibilidade da jogada e incrementa o valor na matriz
                case 0:
                val=0;
                tl=l-1;
                while (tab[tl][c]==1 || tl>-1){
                    if (tab[tl][c]==2){
                        val2=1;
                        break;
                    }
                    tl--;
                }
                tl=l-1;
                if (val=1){
                    tab[l][c]=2;
                    while(tab[tl][c]==1){
                        tab[tl][c]=2;
                        tl--;
                        val2=1;
                    }
                } else {
                    nval++;
                }
                tl=l-1;
                tc=c-1;
                val=0;
                while (tab[tl][tc]==1 || (tl>-1 && tc>-1)){
                    if (tab[tl][c]==2){
                        val2=1;
                        break;
                    }
                    tl--;
                    tc--;
                }
                tl=l-1;
                tc=c-1;
                if (val=1){
                    tab[l][c]=2;
                    while (tab[tl][tc]==1){
                        tab[tl][tc]=2;
                        tl--;
                        tc--;
                        val2=1;
                    }
                } else {
                    nval++;
                }
                tl=l-1;
                tc=c+1;
                val=0;
                while (tab[tl][tc]==1 || (tl>-1 && tc<8)){
                    if (tab[tl][tc]==2){
                        val=1;
                        break;
                    }
                    tl--;
                    tc++;
                }
                tl=l-1;
                tc=c+1;
                if (val=1){
                    tab[l][c]=2;
                    while (tab[tl][tc]==1){
                        tab[tl][tc]=2;
                        tl--;
                        tc++;
                        val2=1;
                    }
                } else {
                    nval++;
                }
                tc=c-1;
                val=0;
                while (tab[l][tc]==1 || tc>-1){
                    if (tab[l][tc]==2){
                        val=1;
                        break;
                    }
                    tc--;
                }
                tc=c-1;
                if (val=1){
                    tab[l][c]=2;
                    while (tab[l][tc]==1){
                        tab[l][tc]=2;
                        tc--;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tc=c+1;
                val=0;
                while (tab[l][tc]==1 || tc<8){
                    if (tab[l][tc]==2){
                        val=1;
                        break;
                    }
                    tc++;
                }
                tc=c+1;
                if (val=1){
                    tab[l][c]=2;
                    while (tab[l][tc]==1){
                        tab[l][tc]=2;
                        tc++;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l+1;
                tc=c-1;
                val=0;
                while (tab[tl][tc]==1 || (tc>-1 && tl<8)){
                    if (tab[tl][tc]==2){
                        val=1;
                        break;
                    }
                    tc--;
                    tl++;
                }
                tl=l+1;
                tc=c-1;
                if (val=1){
                    tab[l][c]=2;
                    while (tab[tl][tc]==1){
                        tab[tl][c]=2;
                        tl++;
                        tc--;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l+1;
                val=0;
                while (tab[tl][c]==1 || tl<8){
                    if (tab[tl][c]==2){
                        val=1;
                        break;
                    }
                    tl++;
                }
                tl=l+1;
                if (val=1){
                    tab[l][c]=2;
                    while(tab[tl][c]==1){
                        tab[tl][c]=2;
                        tl++;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                tl=l+1;
                tc=c+1;
                val=0;
                while (tab[tl][tc]==1 || tl<8 || tc<8){
                    if (tab[tl][tc]==2){
                        val=1;
                        break;
                    }
                    tl++;
                    tc++;
                }
                if (val=1){
                    tab[l][c]=2;
                    while (tab[tl][tc]==1){
                        tab[tl][tc]=2;
                        tl++;
                        tc++;
                        val1=1;
                    }
                } else {
                    nval++;
                }
                if (nval=8){
                    printf ("Jogada invalida\n");
                }
                break;
                case 1:
                case 2:
                    printf ("Jogada invalida\n");
            }
        }
        system("cls");
    }
    break;
    case 2:
    printf ("Regras do jogo<<");
    break;
    case 3:
    printf ("pesquisar ainda");
    break;
    }
    getch();
    return(0);
}
