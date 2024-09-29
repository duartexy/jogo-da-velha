#include <stdio.h>
#define TAM 3

char hash[TAM][TAM], xo='x';
int jogada=0, vencedor=0, armNum[TAM*TAM];

void desenho()
{
    printf("\n   %c | %c | %c \n", hash[0][0], hash[0][1], hash[0][2]);
    printf(" -------------\n");
    printf("   %c | %c | %c \n", hash[1][0], hash[1][1], hash[1][2]);
    printf(" -------------\n");
    printf("   %c | %c | %c \n", hash[2][0], hash[2][1], hash[2][2]);
}

int returnIndex(int index, char xo)
{
    switch(index)
    {
    case 1:
        hash[0][0] = xo;
        return 1;

    case 2:
        hash[0][1] = xo;
        return 1;

    case 3:
        hash[0][2] = xo;
        return 1;

    case 4:
        hash[1][0] = xo;
        return 1;

    case 5:
        hash[1][1] = xo;
        return 1;

    case 6:
        hash[1][2] = xo;
        return 1;

    case 7:
        hash[2][0] = xo;
        return 1;

    case 8:
        hash[2][1] = xo;
        return 1;

    case 9:
        hash[2][2] = xo;
        return 1;

    default:
        printf("\nInsira um numero de 1 a 9.\n\n");
        return 0;
    }
}

void winner()
{
    int win=-1;
    //LINHA E COLUNA X
    for(int i=0; i<3; i++)
    {
        if(hash[i][0] == 'x' && hash[i][1] == 'x' && hash[i][2] == 'x') win = 0;
        if(hash[0][i] == 'x' && hash[1][i] == 'x' && hash[2][i] == 'x') win = 0;
    }
    //DIAGONAL X
    if(hash[0][0] == 'x' && hash[1][1] == 'x' && hash[2][2] == 'x') win = 0;
    else if(hash[0][2] == 'x' && hash[1][1] == 'x' && hash[2][0] == 'x') win = 0;

    //LINHA E COLUNA O
    for(int i=0; i<3; i++)
    {
        if(hash[i][0] == 'o' && hash[i][1] == 'o' && hash[i][2] == 'o') win = 1;
        if(hash[0][i] == 'o' && hash[1][i] == 'o' && hash[2][i] == 'o') win = 1;
    }
    //DIAGONAL O
    if(hash[0][0] == 'o' && hash[1][1] == 'o' && hash[2][2] == 'o') win = 1;
    else if(hash[0][2] == 'o' && hash[1][1] == 'o' && hash[2][0] == 'o') win = 1;

    //X vencedor
    if(win == 0)
    {
        vencedor = 1;
        desenho();
        printf("x venceu!");
    }
    //O vencedor
    else if(win == 1)
    {
        vencedor = 1;
        desenho();
        printf("o venceu!");
    }
    //VELHA
    else if(jogada == 9)
    {
        vencedor = 1;
        desenho();
        printf("velha!");
    }
}

void jogo()
{
    int index=0, existe=0;

    printf("Jogo da velha\n");
    while(vencedor == 0)
    {
        desenho();
        printf("Vez de %c: ", xo);
        scanf("%d", &index);
        for(int i=0; i<jogada; i++)
        {
            if(index == armNum[i])
            {
                printf("Essa posicao ja foi escolhida!\n");
                existe = 1;
            }
        }
        if(existe == 0)
        {
            if(returnIndex(index, xo) == 1)
            {
                if(jogada%2 == 0) xo='o'; else xo='x';
                armNum[jogada] = index;
                jogada++;
                winner();
            }
        }
        existe = 0;
    }
}

int main()
{
    jogo();
    return 0;
}
