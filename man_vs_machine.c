

/////////////////// aleatoire ////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "man_vs_machine.h"

void jouer_coup_machine(board M, int ligne, int colone, int joueur)
{
    int i, j;
    char p1, p2;
    if (joueur == 1)
    {
        p1 = black;
        p2 = white;
    }
    else
    {
        p1 = white;
        p2 = black;
    }
    M[ligne][colone] = p1;
    i = ligne - 1;
    while (in_board(i, colone) && M[i][colone] == p2)
        i--;
    if (in_board(i, colone) && M[i][colone] == p1)
    {
        i = ligne - 1;
        while (M[i][colone] == p2)
        {
            M[i][colone] = p1;
            i--;
        }
    }
    i = ligne + 1;
    while (in_board(i, colone) && M[i][colone] == p2)
        i++;
    if (in_board(i, colone) && M[i][colone] == p1)
    {
        i = ligne + 1;
        while (M[i][colone] == p2)
        {
            M[i][colone] = p1;
            i++;
        }
    }

    j = colone - 1;
    while (in_board(ligne, j) && M[ligne][j] == p2)
        j--;
    if (in_board(ligne, j) && M[ligne][j] == p1)
    {
        j = colone - 1;
        while (M[ligne][j] == p2)
        {
            M[ligne][j] = p1;
            j--;
        }
    }

    j = colone + 1;
    while (in_board(ligne, j) && M[ligne][j] == p2)
        j++;
    if (in_board(ligne, j) && M[ligne][j] == p1)
    {
        j = colone + 1;
        while (M[ligne][j] == p2)
        {
            M[ligne][j] = p1;
            j++;
        }
    }
    i = ligne - 1;
    j = colone - 1;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i--;
        j--;
    }
    if (in_board(i, j) && M[i][j] == p1)
    {
        i = ligne - 1;
        j = colone - 1;
        while (M[i][j] == p2)
        {
            M[i][j] = p1;
            i--;
            j--;
        }
    }

    i = ligne + 1;
    j = colone + 1;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i++;
        j++;
    }
    if (in_board(i, j) && M[i][j] == p1)
    {
        i = ligne + 1;
        j = colone + 1;
        while (M[i][j] == p2)
        {
            M[i][j] = p1;
            i++;
            j++;
        }
    }

    i = ligne - 1;
    j = colone + 1;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i--;
        j++;
    }
    if (in_board(i, j) && M[i][j] == p1)
    {
        i = ligne - 1;
        j = colone + 1;
        while (M[i][j] == p2)
        {
            M[i][j] = p1;
            i--;
            j++;
        }
    }

    i = ligne + 1;
    j = colone - 1;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i++;
        j--;
    }
    if (in_board(i, j) && M[i][j] == p1)
    {
        i = ligne + 1;
        j = colone - 1;
        while (M[i][j] == p2)
        {
            M[i][j] = p1;
            i++;
            j--;
        }
    }
}

//////////////generer nbre aleatoire
int Randommove(int lower, int upper, int count)
{
    int i, num;
    for (i = 0; i < count; i++)
    {
        num = (rand() % 8);
        return num;
    }
}

// Driver code
int rndplay()
{
    int lower = 0, upper = 8, count = 1;
    srand(time(0));
    return Randommove(lower, upper, count);
}

void rndmove(board M, int player)
{
    // int good = good_position(M, ligne, colone, 1);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (good_position(M, i, j, player))
            {
                jouer_coup(M, i, j, player);
                display_board(M);
                switch (j)
                {
                case 0:
                    printf("l'ordinateur a joue :A%d", i + 1);
                    break;
                case 1:
                    printf("l'ordinateur a joue :B%d", i + 1);
                    break;
                case 2:
                    printf("l'ordinateur a joue :C%d", i + 1);
                    break;
                case 3:
                    printf("l'ordinateur a joue :D%d", i + 1);
                    break;
                case 4:
                    printf("l'ordinateur a joue :E%d", i + 1);
                    break;
                case 5:
                    printf("l'ordinateur a joue :F%d", i + 1);
                    break;
                case 6:
                    printf("l'ordinateur a joue :G%d", i + 1);
                    break;
                case 7:
                    printf("l'ordinateur a joue :H%d", i + 1);
                    break;
                default:
                    break;
                }
                return;
            }
        }
    }
}
////////////////// play until you find a valid move
