#define black 'B'
#define white 'W'

typedef char board[8][8];

void init_matrice(board M);
int ligne, colone;
int in_board(int ligne, int colone);
int good_position(board M, int ligne, int colone, int player);
int peut_jouer(board M, int joueur);
int joueur_suivant(int joueur);
void choisir_coup(board M, int *ligne, int *colone, int joueur);
int partie_terminee(board M);
void jouer_coup(board M, int ligne, int colone, int joueur);
