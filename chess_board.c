#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to display the chess board
void display_board(char chess[][8])
{
    int i, j;

    printf("   A  B  C  D  E  F  G  H\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for (j = 0; j < 8; j++) {
            printf("|%c|", chess[i][j]);
        }
        printf(" %d\n", i+1);
    }
    printf("   A  B  C  D  E  F  G  H\n");
}

// function to initialize the chess board
void initialize_board(char chess[][8])
{
    int i, j;

    // initialize the white pieces
    chess[0][0] = 'R';
    chess[0][1] = 'N';
    chess[0][2] = 'B';
    chess[0][3] = 'Q';
    chess[0][4] = 'K';
    chess[0][5] = 'B';
    chess[0][6] = 'N';
    chess[0][7] = 'R';

    for (i = 0; i < 8; i++) {
        chess[1][i] = 'P';
    }

    // initialize the black pieces
    chess[7][0] = 'r';
    chess[7][1] = 'n';
    chess[7][2] = 'b';
    chess[7][3] = 'q';
    chess[7][4] = 'k';
    chess[7][5] = 'b';
    chess[7][6] = 'n';
    chess[7][7] = 'r';

    for (i = 0; i < 8; i++) {
        chess[6][i] = 'p';
    }

    // initialize the empty spaces
    for (i = 2; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }
}

// function to check if a move is valid
int is_valid_move(char chess[][8], int from_row, int from_col, int to_row, int to_col)
{
    // check if the from and to positions are within the board
    if (from_row < 0 || from_row > 7 || from_col < 0 || from_col > 7 ||
        to_row < 0 || to_row > 7 || to_col < 0 || to_col > 7) {
        return 0;
    }

    // check if the piece at the from position is not empty
    if (chess[from_row][from_col] == ' ') {
        return 0;
    }

    // check if the destination is not occupied by a piece of the same color
    if (chess[to_row][to_col] != ' ' && isupper(chess[from_row][from_col]) == isupper(chess[to_row][to_col])) {
        return 0;
    }

    // check if the move is valid for the specific piece
    // this part of the code is not implemented in this example

    return 1;
}

// function to make a move
void make_move(char chess[][8], int from_row, int from_col, int to_row, int to_col)
{
        // check if the move is valid
    if (is_valid_move(chess, from_row, from_col, to_row, to_col)) {
        // make the move
        chess[to_row][to_col] = chess[from_row][from_col];
        chess[from_row][from_col] = ' ';

        printf("Move successful!\n");
    } else {
        printf("Invalid move!\n");
    }
}

int main()
{
    char chessboard[8][8];
    char move[5];
    int from_row, from_col, to_row, to_col;

    // initialize the chess board
    initialize_board(chessboard);

    while (1) {
        // display the current state of the chess board
        display_board(chessboard);

        // get the move from the player
        printf("Enter your move (e.g., A2A4): ");
        scanf("%s", move);

        // convert the move to coordinates
        from_col = toupper(move[0]) - 'A';
        from_row = move[1] - '1';
        to_col = toupper(move[2]) - 'A';
        to_row = move[3] - '1';

        // make the move
        make_move(chessboard, from_row, from_col, to_row, to_col);
    }

    return 0;
}
