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

    printf("%d\n", SIZE/2);

    //initial placement of BLACK and WHITE discs
    board[SIZE/2][SIZE/2] = BLACK; //(B at 4, 4)
    board[SIZE/2 + 1][SIZE/2 + 1] = BLACK; //(B at 5, 5)
    board[SIZE/2][SIZE/2 + 1] = WHITE; //(W at 4, 5)
    board[SIZE/2 + 1][SIZE/2] = WHITE; //(W at 5, 4)
}

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
    int rowIndex = row - 1; 
    int colIndex = col - 1; 

    if(board[rowIndex][colIndex] == EMPTY) {
        //checking to see if one or more of surrounding 
        for(int i = rowIndex-1; i <= rowIndex+1; i++) { //checking 
            for(int j = colIndex-1; j <= colIndex+1; j++) {
                if(board[i][j] != EMPTY && board[i][j] != disc) {
                    
                }
            }
        }
    }

    else {
        return false;
    }

    return true; 
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
    //placing disc
    if(isValidMove(board, row, col, disc)) {
        board[row][col] = disc; //placing disc at real location (index -1)
    }

    //flipping other discs
    
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

    int count; 
    bool boardFull; 
    int boardSize = SIZE * SIZE; 

    //traversing through each space to see if it contains a disc
     for(int i = 0; i < SIZE; i++) {
          for(int j = 0; j< SIZE; j++) {
                //Need logic for this 
               if(board[i][j] == BLACK || board[i][j] == WHITE) {
                    count += 1; 
               }
          }
     }

     if(count == boardSize) {
         boardFull = true;  
     }
     else {
         boardFull = false; 
     }

     return boardFull;	
}

// Returns true if either the board is full OR a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{
    if(isBoardFull(board)) { 
        return true; 
    }
    else if(!isValidMoveAvailable(board, WHITE) && !isValidMoveAvailable(board, BLACK)) {
        return true; 
    }
    else {
        return false; 
    }
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTY
char checkWinner(char board[][SIZE])
{

    /***********NOT SURE IF THE IF'S ARE CORRECT************/
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
