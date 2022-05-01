#include <stdio.h>
#include "man_vs_man.h"

/* initialisation de la grille */
void init_board(board M)
{
    int i,
        j;

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            M[i][j] = ' ';

    M[3][3] = black, M[3][4] = white, M[4][3] = white, M[4][4] = black;
}
/* l'affichage de la grille */
void display_board(board M)
{
    int i, j;
    printf("  A   B   C   D   E   F   G   H ");
    printf("\n");
    printf("+---+---+---+---+---+---+---+---+");
    printf("\n");
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            if (M[i][j] == white)
                printf("| %c ", M[i][j]);
            else
                printf("| %c ", M[i][j]);
        printf("|%d\n+", i + 1);

        printf("---+---+---+---+---+---+---+---+\n");
    }
}
/* Fonction pour verifier qu'une case existe */
int ligne, colone;
int in_board(int ligne, int colone)
{
    return ((colone >= 0) && (colone < 8) && (ligne >= 0) && (ligne < 8));
}
/* Fonction pour verifier qu'un coup est valide */

int good_position(board M, int ligne, int colone, int player)
{
    int i, j, ok;
    char p1, p2;
    /* On definit la couleur du joueur et celle de l'adversaire */
    if (player == 1)
    {
        p1 = black;
        p2 = white;
    }
    else
    {
        p1 = white;
        p2 = black;
    }
    if (!in_board(ligne, colone) || M[ligne][colone] != ' ')
        return 0;
    i = ligne - 1;
    ok = 0;
    while (in_board(i, colone) && M[i][colone] == p2)
    {
        i--;
        ok = 1;
    }
    if (in_board(i, colone) && M[i][colone] == p1 && ok == 1)
        return 1;
    i = ligne + 1;
    ok = 0;
    while (in_board(i, colone) && M[i][colone] == p2)
    {
        i++;
        ok = 1;
    }
    if (in_board(i, colone) && M[i][colone] == p1 && ok == 1)
        return 1;
    j = colone - 1;
    ok = 0;
    while (in_board(ligne, j) && M[ligne][j] == p2)
    {
        j--;
        ok = 1;
    }
    if (in_board(ligne, j) && M[ligne][j] == p1 && ok == 1)
        return 1;
    j = colone + 1;
    ok = 0;
    while (in_board(ligne, j) && M[ligne][j] == p2)
    {
        j++;
        ok = 1;
    }
    if (in_board(ligne, j) && M[ligne][j] == p1 && ok == 1)
        return 1;
    i = ligne - 1;
    j = colone - 1;
    ok = 0;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i--;
        j--;
        ok = 1;
    }
    if (in_board(i, j) && M[i][j] == p1 && ok == 1)
        return 1;
    i = ligne + 1;
    j = colone + 1;
    ok = 0;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i++;
        j++;
        ok = 1;
    }
    if (in_board(i, j) && M[i][j] == p1 && ok == 1)
        return 1;
    i = ligne - 1;
    j = colone + 1;
    ok = 0;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i--;
        j++;
        ok = 1;
    }
    if (in_board(i, j) && M[i][j] == p1 && ok == 1)
        return 1;
    i = ligne + 1;
    j = colone - 1;
    ok = 0;
    while (in_board(i, j) && M[i][j] == p2)
    {
        i++;
        j--;
        ok = 1;
    }
    if (in_board(i, j) && M[i][j] == p1 && ok == 1)
        return 1;

    return 0;
}
/* Fonction qui determine si un joueur peut encore jouer */
int peut_jouer(board M, int joueur)
{
    int i, j;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if (good_position(M, i, j, joueur))
                return 1;
    /*la Fonction qui determine Le joueur ne peut plus jouer */
    return 0;
}
int joueur_suivant(int joueur)
{
    return (joueur % 2 + 1);
}
/* Permet au joueur de choisir un coup */
void choisir_coup(board M, int *ligne, int *colone, int joueur)
{
    char c;
    char couleur;
    if (joueur == 1)
    {
        couleur = 'B';
    }
    else if (joueur == 2)
    {
        couleur = 'W';
    }

    printf("\nC'est le tour du joueur %d de jouer ( Couleur: %c )\n", joueur, couleur);
    printf("Choisissez une case (ex: A1) :\n");
    scanf("\n%c", &c);
    if ((c >= 'a') && (c < 'a' + 8))
        c = c + 'A' - 'a';
    (*colone) = c - 'A';
    scanf("%d", ligne);
    (*ligne)--;
    /* On redemande de choisir tant que l
    e coup n'est pas accepte */
    while (!good_position(M, *ligne, *colone, joueur))
    {
        printf("\nCe coup n'est pas valide\n");
        display_board(M);
        printf("Choisissez une autre case (ex: A1) :\n");
        scanf("\n%c", &c);
        if ((c >= 'a') && (c < 'a' + 8))
            c = c + 'A' - 'a';
        (*colone) = c - 'A';
        scanf("%d", ligne);
        (*ligne)--;
    }
}
/* Verifie si la partie est terminee */
int partie_terminee(board M)
{
    int i, j, nb_noir, nb_blanc, cpt;
    nb_noir = 0;
    nb_blanc = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (M[i][j] == ' ' && (peut_jouer(M, 1) || peut_jouer(M, 2)))
            {
                return 0;
            }
            else
            {
                if (M[i][j] == black)
                    nb_noir++;
                else if (M[i][j] == white)
                    nb_blanc++;
            }
        }
    }
    /* La partie est terminee, on affiche le gagnant */
    if (nb_noir > nb_blanc)
        printf("\nscore : \n  black:%d\n  white :%d'%\nLe joueur 1 a gagne !!!\n",nb_noir,nb_blanc);
    else if (nb_blanc > nb_noir)
        printf("\nscore : \n  black:%d\n  white :%d'%\nLe joueur 2 a gagne !!!\n",nb_noir,nb_blanc);
    else
        printf("\nLes deux joueurs sont a egalite\n");
    cpt = 0;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {
            if (cpt < nb_noir)
                M[i][j] = black;
            else if ((cpt >= nb_noir) && (cpt < nb_noir + nb_blanc - 1))
                M[i][j] = white;
            else
                M[i][j] = ' ';
            cpt++;
        }
    display_board(M);
    printf("\n");
    return 1;
}
/* Fonction qui permet de jouer un coup */
void jouer_coup(board M, int ligne, int colone, int joueur)
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


