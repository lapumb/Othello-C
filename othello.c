//***************************************************
// Filename: othello.c
//
// Author:  Prof. Nandigam
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

    if(board[row][col] != EMPTY){
        return false;
    }


    //moving up/left
    i = row - 1;
    j = col - 1;
    while(board[i][j] != disc && board[i][j] != EMPTY && i >= 1 && j >= 1) {
        if(board[i-1][j-1] == disc) {
            //printf("up/left\n");
            return true; 
        }

        else if(i >= 1 && j >=1 ){
            i--; 
            j--; 
            continue;
        } else{
            break;
        }
    }

    //moving up
    i = row - 1;
    j = col;
    while(board[i][j] != disc && board[i][j] != EMPTY && i >= 1) {
        if(board[i-1][j] == disc) {
            //printf("up\n");
            return true; 
        }
        else if (i >= 1 ) {
            i--; 
            continue;
        } else{
            break;
        }
    }

    //moving left
    i = row;
    j = col - 1;
    while(board[i][j] != disc && board[i][j] != EMPTY && j >= 1) {
        if(board[i][j-1] == disc) {
            //printf("left\n");
            return true; 

        } else if(j >= 1){
            j--; 
            continue;
        } else{
            break;

        }
    }

    //moving right
    i = row;
    j = col + 1;
    while(board[i][j] != disc && board[i][j] != EMPTY && j <= SIZE ) {
        if(board[i][j+1] == disc) {
            //printf("right\n");
            return true; 
        }
        else if(j <= SIZE){
            j++;
            continue; 
        } else{
            break;

        }
    }

    //moving down/left
    i = row + 1;
    j = col - 1;
    while(board[i][j] != disc && board[i][j] != EMPTY && i <= SIZE  && j >= 1) {
        if(board[i+1][j-1] == disc) {
            //printf("down/left\n");
            return true; 
        }
        else if(i <= SIZE && j >= 1){
            i++; 
            j--; 
            continue;
        } else{
            break;

        }
    }

    
    i = row + 1;
    j = col + 1;
    while(board[i][j] != disc && board[i][j] != EMPTY && i <= SIZE && j <= SIZE) {
        if(board[i+1][j+1] == disc) {
            //printf("Down/right\n");
            return true; 
        }
        else if (i <= SIZE && j <= SIZE){
            i++; 
            j++; 
            continue;
        } else{
            break;

        }
    }

    //moving up/right
    i = row - 1;
    j = col + 1;
    while(board[i][j] != disc && board[i][j] != EMPTY && i >= 1 && j <= SIZE ) {
        if(board[i-1][j+1] == disc) {
            //printf("up/right\n");
            return true; 
        }
        else if(i >= 1 && j <= SIZE){
            i--; 
            j++; 
            continue;
        } else{
            break;
        }
    }

    //moving down
    i = row + 1;
    j = col;
    while(board[i][j] != disc && board[i][j] != EMPTY && i <= SIZE) {
        if(board[i+1][j] == disc) {
            //printf("down\n");
            return true; 
        }
        else if(i <= SIZE){
            i++; 
            continue;
        } else{
            break;

        }
    }

    return false;
}

void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
    //row and column
    int i, j; 

    if(isValidMove(board, row, col, disc)) {
 
        //up
        i = row - 1; 
        j = col; 
        
        while(board[i][j] != EMPTY && board[i][j] != disc && i >= 0){
            i--;
        }

        if(board[i][j] == disc){
            i = row - 1; 
            j = col; 

            while(board[i][j] != EMPTY && board[i][j] != disc && i >= 0){
                board[i][j] = disc;
                i--;
            }
        }

        //down
        i = row + 1; 
        j = col; 
        while(board[i][j] != disc && board[i][j] != EMPTY && i <= SIZE) {
            i++; 
        } 

        if(board[i][j] == disc){
            i = row + 1; 
            j = col; 
            
            while(board[i][j] != EMPTY && board[i][j] != disc && i <= SIZE){
                board[i][j] = disc;
                i++;
            }
        }

        //left
        i = row; 
        j = col - 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY && j >= 0) {
            j--; 
        } 

        if(board[i][j] == disc){
            i = row; 
            j = col - 1; 
                
            while(board[i][j] != EMPTY && board[i][j] != disc && j >= 0){
                board[i][j] = disc;
                j--; 
            }
        }

        //right 
        i = row; 
        j = col + 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY && j <= SIZE ) {
            j++;
        } 

        if(board[i][j] == disc){
            i = row; 
            j = col + 1; 
                
            while(board[i][j] != EMPTY && board[i][j] != disc && j <= SIZE){
                board[i][j] = disc;
                j++;
            }
        }

        //moving up/left
        i = row - 1;
        j = col - 1;
        while(board[i][j] != disc && board[i][j] != EMPTY && i >= 0 && j >= 0) {
            i--; 
            j--; 
        } 

        if(board[i][j] == disc){
            i = row - 1; 
            j = col - 1; 
                
            while(board[i][j] != EMPTY && board[i][j] != disc && i >= 0 && j >= 0){
                board[i][j] = disc;
                i--; 
                j--; 

            }
        }

        // moving up/right
        i = row - 1; 
        j = col + 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY && i >= 0 && j <= SIZE ) {
            i--; 
            j++; 
        } 

        if(board[i][j] == disc){
            i = row - 1;  
            j = col + 1; 
                
            while(board[i][j] != EMPTY && board[i][j] != disc && i >= 0 && j <= SIZE ){
                board[i][j] = disc;
                i--; 
                j++;
            }
        }


        /////////---------ISSUE IS HERE--------------/////////
        i = row + 1; 
        j = col - 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY && i <= SIZE && j >= 0) {
            i++;
            j--; 
        } 

        if(board[i][j] == disc){
            //printf("here\n");
            i = row + 1; 
            j = col - 1; 
                
            while(board[i][j] != EMPTY && board[i][j] != disc && i <= SIZE && j >= 0){
                board[i][j] = disc;
                i++;
                j--;

            }
        }

        //down/right
        i = row + 1; 
        j = col + 1; 
        while(board[i][j] != disc && board[i][j] != EMPTY && i <= SIZE && j <= SIZE) {
            i++;  
            j++; 
        } 

        if(board[i][j] == disc){
            //printf("here\n");
            i = row + 1; 
            j = col + 1; 
                
            while(board[i][j] != EMPTY && board[i][j] != disc && i <= SIZE && j <= SIZE){
                board[i][j] = disc;
                i++;
                j++;
            }
        }
        board[row][col] = disc; 
    }
}


// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(isValidMove(board, i, j, disc)) {
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
    int countWhite = 0;
    int countBlack = 0;

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

    printf("White Score: %d\n", countWhite);
    printf("Black Score: %d\n", countBlack);

    if (countWhite > countBlack){
        return WHITE;
    } else if(countBlack > countWhite){
        return BLACK;
    }
    
    return EMPTY;
}