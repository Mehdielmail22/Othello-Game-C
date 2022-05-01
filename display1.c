#include <stdio.h>
#include <stdlib.h>
#include "man_vs_man.c"
#include "man_vs_machine.c"

int main()
{
    int a;

    printf("\n\n\t\t ________________________________________________________________________________________     \n");
    printf("\t\t   ____________________________________________________________________________________     \n");
    printf("\t\t                                                                                            \n");
    printf("\t\t      *******   *********  *        *  **********   *           *          *******             \n");
    printf("\t\t     *       *      *      *        *  *            *           *         *       *           \n");
    printf("\t\t     *       *      *      **********  **********   *           *         *       *             \n");
    printf("\t\t     *       *      *      *        *  *            *           *         *       *             \n");
    printf("\t\t      *******       *      *        *  **********   *********   ********   *******                 \n");
    printf("\t\t   ____________________________________________________________________________________     \n");
    printf("\t\t ________________________________________________________________________________________     \n");
    int b, c, x, y;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t _______________MENU_______________\n");
    printf("\n");
    printf("\t\t\t\t\t       1          2           3\n");
    printf("\t\t\t\t\t      play   how to play     quit\n");
    printf("\t\t\t\t\t ___________________________________\n");
    printf("\n");
    printf("\t\t\t\t\t \n");

    printf("\n");
    scanf("%d", &b);
    if (b == 1)
    {
        system("color E1");//color of background and text
        printf("\t\t  *       *       *   *******  *         *****     ******    *     *  *******    \n");
        printf("\t\t   *     * *     *    *        *        *         *      *   **   **  *\n");
        printf("\t\t    *   *   *   *     *******  *        *         *      *   * * * *  *******\n");
        printf("\t\t     * *     * *      *        *        *         *      *   *  *  *  *\n");
        printf("\t\t      *       *       *******  *******   *****     ******    *     *  *******  \n");
        printf("\n\n");
        printf("\t\t\t\t\t\t 1- man vs man\n");
        printf("\t\t\t\t\t\t 2- man vs machine\n");
        scanf("%d", &c);
        if (c == 1)
        {
            board M;
            int ligne, colone, joueur = 1;

            /* Initialisation du jeu */
            init_board(M);
            display_board(M);
            /* Deroulement d'une partie */
            while (!partie_terminee(M))
            {
                choisir_coup(M, &ligne, &colone, joueur);
                jouer_coup(M, ligne, colone, joueur);
                display_board(M);
                if (peut_jouer(M, joueur_suivant(joueur)))
                    joueur = joueur_suivant(joueur);
                else
                    printf("\nLe joueur %d passe son tour\n", joueur_suivant(joueur));
            }
            return 0;
        }
        else if (c == 2)
        {
            board M;
            int ligne, colone, joueur = 1;

            /* Initialisation du jeu */
            init_board(M);
            display_board(M);
            printf("the game will start in a few seconds,the machine should play");
            sleep(3);
            /* Deroulement d'une partie */
            while (!partie_terminee(M))
            {
                if (joueur == 1)
                {
                    sleep(2);
                    printf("La machine joue son tour :\n");
                    rndmove(M, joueur);

                }
                else
                {
                    choisir_coup(M, &ligne, &colone, joueur);
                    jouer_coup_machine(M, ligne, colone, joueur);
                    display_board(M);
                }
                if (peut_jouer(M, joueur_suivant(joueur)))
                    joueur = joueur_suivant(joueur);
                else
                    printf("\nLe joueur %d joue son tour\n", joueur_suivant(joueur));
            }
            return 0;
        }
    }

    else if (b == 3)
    {
        system("color F4");
        printf("\t\t\t  *******  *******  *******  ******         *******    *     *  ********    \n");
        printf("\t\t\t  *        *     *  *     *  *     *        *      *    *   *   *\n");
        printf("\t\t\t  *  ****  *     *  *     *  *     *        ********     * *    *******\n");
        printf("\t\t\t  *  *  *  *     *  *     *  *     *        *      *      *     *\n");
        printf("\t\t\t  *******  *******  *******  ******         *******       *     ********  \n");
    }
    else if (b==2)
    {
        system("color F0");
        printf("Reversi et Othello sont un meme jeu. Le premier a ete invente en Angleterre au XIXe alors que le dernier nait au Japon, au XXe siecle. Si Reversi est libre de droit, Othello est une marque deposee. Voici les regles de l\'Othello. J\'ai puise mes sources dans le manuel d\'initiation du champion de France Emmanuel Lazard presente sur le site de la Federation Francaise d\'Othello. Vous l\'aurez compris, Othello est un sport de l\'esprit.\n");
        printf("A minute to learn ----> A lifetime to master!\n");
        printf("Nombre de joueurs : 2\n");
        printf("Materiel :\n");
        printf("-->1 Othellier (plateau unicolore de 64 cases)\n");
        printf("-->  64 pions bicolores (noirs d\�une face, blancs de l\�autre).\n");
        printf("Les joueurs possedent un meme nombre de pions devant eux, par commodite. En effet, ces pions n\'appartiennent a personne. Si l\'un des adversaire n\�a plus de pions devant lui, il peut piocher dans la reserve de l\'autre joueur.\n");
        printf("-> But du jeu : Posseder plus de pions de sa couleur en fin de partie\n");
        printf("-> Fin du jeu : Aucun coup legal n\'est possible de la part des deux joueurs. Cela intervient generalement lorsque les 64 cases sont occupees.\n\n");
        printf("\t\t\t\t\t\tCoordonnees et Notation\n\n");
        printf("Le jeu d\'Othello se deroule sur un othellier de 64 cases. On fait reference aux cases grace a un systeme de coordonnees :");
        printf("-->Coordonnees :\n");
        printf("\t -->Les lignes sont numerotees de haut en bas, de 1 a 8 (La notation differe donc du jeu d\'echecs qui numerote ses rangees de bas en haut).:\n");
        printf("\t -->Les colonnes sont etiquetees de gauche a droite, de \'a\' a \'h\'\n");
        printf("Certains types de cases se sont vu, pour des raisons de commodite, attribuer un nom.\n");
        printf("Coins : Les cases a1, h1, a8 et h8\n");
        printf("Cases X : ces cases sont les cases adjacentes aux coins sur la diagonale.\n");
        printf("Cases C : Ces cases sont les autres cases voisines des coins.\n");
        printf("Rose des Vents : Les directions cardinales sont souvent utilisees pour designer des regions de l\'othellier. Par exemple, les cases proches du coin a1 font partie de la region nord-ouest tandis que la ligne 8 sera appelee bord sud.\n\n");
        printf("\t\t\t\t\t\t Noter une partie :\n\n");
        printf("Il n\'est pas necessaire, pour la lecture de cette regle, de savoir noter une partie. Cependant, si vous desirez lire un commentaire de partie ou conserver vos propres parties, voici comment les noter.\nUne partie se note par un diagramme donnant le numero et la position de chaque coup.");
        printf(" Le premier joueur a les noirs, ici Penloup. Le �1� en f5 indique que le premier coup a ete jou� sur cette case. Puis Blanc a repondu d6, suivi de c3-d3-c4. Normalement, les coups impairs sont noirs et les coups pairs sont blancs, mais si l\'un des joueurs passe, cela peut changer. Dans cette partie, nous verrons que le coup 57 est blanc car Noir va passer. D\'ailleurs, Noir passe � nouveau : 58 est blanc, puis Noir joue 59 et Blanc termine avec 60.\n");
        printf("\n\t\t\t\t\t\t Position de depart :\n\n");
        printf("Au debut de la partie :\nDeux pions noirs sont places en e4 et d5.\nDeux pions blancs en d4 et e5 .\n");
        printf("\nPremier joueur : Noir commence toujours. Les deux adversaires jouent ensuite � tour de r�le. .\n");
        printf("\n\t\t\t\t\t\t La Pose d\'un Pion :\n");
        printf("--->Comment poser un pion ?:\n");
        printf("A son tour de jeu, le joueur doit poser un pion de sa couleur. Trois conditions sont necessaires :\n-->1. Le pion doit etre pose sur une case vide.\n-->2. La case doit etre adjacente a un pion adverse (pose possible dans 4 directions donc. Voire 3 puisque le pion qu\'on encadre est deja colle a au moins au autre pion).\n");
        printf("-->3. Retourner obligatoirement un pion en prenant en Sandwich : Le pion pose doit encadrer un (ou plusieurs) pions adverses entre le pion qu\'il pose et un pion de sa couleur, deja place sur l\'othellier.\n");
        printf("\n-->Passer : Si le joueur ne peut repondre a ces 3 conditions, il ne peut poser et doit passer.\n");
        printf("\nRetourner les pions pris en sandwich : Il retourne alors de sa couleur le ou les pions qu�il vient d�encadrer.\nLes pions ne sont ni retir�s de l�othellier, ni d�plac�s d�une case � l�autre.\n");
        printf("\n-->Exemple : Lors de son premier coup, Noir a jou� f5 . Ce coup encadre le pion blanc e5 entre le pion qu�zil pose et un pion noir d�j� pr�sent (ici d5).\nIl retourne alors ce pion . Noir aurait aussi pu jouer en e6, c4 ou d3. Notons que ces quatre coups de Noir sont parfaitement symetriques.\nNoir n\'a donc pas a refl�chir pour choisir\n");
        printf("\nC\'est maintenant a Blanc de jouer. Il a trois coups possibles . En effet, il est obligatoire de retourner au moins un pion adverse a chaque coup (ce qui limite les possibilites). Blanc peut donc jouer en f4, f6 ou en d6.\n");
        printf("Encadrement possible dans les 8 directions : On peut encadrer des pions adverses dans les huit directions.\nSi plusieurs pions sont encadr�s , on doit alors tous les retourner.\n");
        printf("Jamais de reactions en chaine : Les pions retournes ne peuvent pas servir a en retourner d\'autres lors du meme tour de jeu. Ainsi, sur la figure 8, Noir joue en a5 : il retourne b5 et c5 qui sont encadres.\n");
        printf("--->Seul le Pion que l�on vient de poser retourne par encadrement.\n\n");
        printf("Bien que c4 soit alors encadre, il n\'est pas retourne . En effet, il n\'est pas encadre entre le pion que l\'on vient de poser et un autre pion.\n");
        printf("\t\tRappel : Pendant votre tour, si vous ne pouvez poser de pion en retournant un pion adverse, vous devez passer votre tour.\n\t\tPar contre, si un retournement est possible, vous devez le jouer !\n");
        printf("\n\t\t\t\t\t\t Fin de partie :\n\n");
        printf("\nComme je l\'ai explique dans l\'introduction, La partie est terminee lorsque aucun des deux joueurs ne peut plus jouer.\n");
        printf("\tA) Plus de place/Pions : Cela arrive g�n�ralement lorsque les 64 cases sont occup�es.\n");
        printf("\tB)Une seule couleur : Mais il se peut qu\'il reste des cases vides ou personne ne peut jouer : par exemple lorsque tous les pions deviennent d\'une meme couleur apres un retournement (Nous avons vu que l\'une des 3 conditions etait la necessite de poser un pion au contact d\'un pion ennemi).\n");
        printf("\tC) Aucun retournement possible :Ou bien comme sur cette position aucun des deux joueurs ne peut jouer en b1 puisqu\'aucun retournement n\'est possible.\n\n");
        printf("\t\tOn compte alors les pions pour d�terminer le score. Les cases vides sont attribu�es au vainqueur. \t\tDans cette partie, Blanc a 29 pions et Noir 34 et une case vide. Donc Noir gagne 35 � 29.\n");

    }
    else
    {
        printf("error");
    }
    return 0;
}
