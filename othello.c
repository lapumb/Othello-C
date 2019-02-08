//***************************************************
// Filename: othello.c
//
// Author:  Nandigam
//          Blake Lapum 
//          Cole Sellers
//***************************************************

#include "othello.h"

// Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf((i == 0 ? "%5d" : "%3d"), i+1);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d", i+1);
        for (int j = 0; j < SIZE; j++) {
            printf("%3c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE])
{
    //initializing all empty discs (8x8)
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY; 
        }
    }

    //printf("%d\n", SIZE/2);

    //initial placement of BLACK and WHITE discs
    board[SIZE/2][SIZE/2] = BLACK;
    board[SIZE/2 - 1][SIZE/2 - 1] = BLACK;
    board[SIZE/2][SIZE/2 - 1] = WHITE;
    board[SIZE/2 - 1][SIZE/2] = WHITE;
}

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
        //row and column
    int i, j; 

    //moving up/left
    i = row - 1;
    j = col - 1;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i-1][j-1] == disc) {
            return true; 
        }
        else {
            i--; 
            j--; 
        }
    }

    //moving up
    i = row - 1;
    j = col;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i-1][j] == disc) {
            return true; 
        }
        else {
            i--; 
        }
    }

    //moving up/right
    i = row - 1;
    j = col + 1;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i-1][j+1] == disc) {
            return true; 
        }
        else {
            i--; 
            j++; 
        }
    }

    //moving left
    i = row;
    j = col - 1;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i][j-1] == disc) {
            return true; 
        }
        else {
            j--; 
        }
    }

    //moving right
    i = row;
    j = col + 1;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i][j+1] == disc) {
            return true; 
        }
        else {
            j++; 
        }
    }

    //moving down/left
    i = row + 1;
    j = col - 1;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i+1][j-1] == disc) {
            return true; 
        }
        else {
            i++; 
            j--; 
        }
    }

    //moving up/right
    i = row + 1;
    j = col + 1;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i+1][j+1] == disc) {
            return true; 
        }
        else {
            i++; 
            j++; 
        }
    }

    //moving down
    i = row + 1;
    j = col;
    while(board[i][j] != disc && board[i][j] != EMPTY) {
        if(board[i+1][j] == disc) {
            return true; 
        }
        else {
            i++; 
        }
    }

    return false;
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
    //row and column
    int i, j; 

    if(isValidMove(board, row, col, disc)) {
        //moving up/left
        i = row - 1;
        j = col - 1;
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            i--; 
            j--; 
        } 

        //moving strait up
        i = row - 1; 
        j = col; 
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            i--; 
        } 

        // moving up/right
        i = row - 1; 
        j = col + 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            i--; 
            j++; 
        } 

        //left
        i = row; 
        j = col - 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            j--; 
        } 

        //right 
        i = row; 
        j = col + 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            j++; 
        } 

        //down/left
        i = row + 1; 
        j = col - 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            i++;
            j--; 
        } 

        //down
        i = row + 1; 
        j = col; 
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            i++; 
        } 

        //down/right
        i = row + 1; 
        j = col + 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY) {
            board[i][j] = disc;
            i++;  
            j++; 
        } 
        
        board[row][col] = disc; 
    }
}

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            //giving index + 1 row/ col as if user was entering location
            if(isValidMove(board, (i+1), (j+1), disc)) {
                return true; 
            }
        }
    }

    if(isBoardFull(board)) {
        return false; 
    }

    return true; 
}

// Returns true if the board is fully occupied with discs; else returns false
bool isBoardFull(char board[][SIZE])
{
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j< SIZE; j++){
            if (board[i][j] == EMPTY){
               return false; 
            }
        }
    }

    return true;
}

// Returns true if either the board is full OR a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{
    if(isBoardFull(board) || 
                (!isValidMoveAvailable(board, WHITE) && !isValidMoveAvailable(board, BLACK))) { 
        return true; 
    } 

    return false; 
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTY
char checkWinner(char board[][SIZE])
{
    int countWhite;
    int countBlack;

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == WHITE){
                countWhite +=1; 
            } else if(board[i][j] == BLACK) {
                countBlack +=1;
            }
            continue; 
        }
    }

    if (countWhite > countBlack){
        return WHITE;
    } else if(countBlack > countWhite){
        return BLACK;
    }
    
    return EMPTY;
}