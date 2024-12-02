#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void displayBoard(char board[3][3]);
void makeMove(char board[3][3], char player);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char currentPlayer = 'X';
    bool gameRunning = true;

    while (gameRunning) {
        displayBoard(board);
        makeMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            gameRunning = false;
        } else if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            gameRunning = false;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Switch player
        }
    }

    return 0;
}

// Function to display the game board
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to make a move
void makeMove(char board[3][3], char player) {
    int move;
    bool validMove = false;

    while (!validMove) {
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &move);

        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = player;
                validMove = true;
            } else {
                printf("Invalid move! Spot already taken. Try again.\n");
            }
        } else {
            printf("Invalid input! Enter a number between 1 and 9.\n");
        }
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // If there are empty spots, it's not a draw
            }
        }
    }
    return true;
}
