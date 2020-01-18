#include <iostream>
#include "tic-tac-toe.h"

using namespace std;


ticTacToe::ticTacToe()
{
    clearBoard();
}



//main game loop////////////////////////////////////
void ticTacToe::playGame()
{
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = 'X';
    bool isDone = false;
    bool move = true;
    int x,y;

    while(isDone == false)
    {
        if(move == true){
            printBoard();
        }
        x = getXCoord(currentPlayer);
        y = getYCoord(currentPlayer);
        placeMove(x, y, currentPlayer, move);
        if( checkForWin(currentPlayer) == true){
            printBoard();
            cout << currentPlayer << " wins!\n\n";
            isDone = true;
        }
        if(move == true){
            changePlayer(player1, player2, currentPlayer);
        }
    }
}



//gets x coord of move form user////////////////////
int ticTacToe::getXCoord( char current)
{
    bool isInputBad = true;
    int x;
    while(isInputBad == true)
    {
        cout << current << "'s turn. \n";
        cout << "Enter the x-coorinate: " << endl;
        cin >> x; 
        
        if(x < 1 || x > 3) {
            cout << "Invalid coordinate!\n";
        }
        else {
            isInputBad = false;
        }
    }
    return x - 1;
}



//gets y coord of move form user////////////////////
int ticTacToe::getYCoord(char current)
{
    bool isInputBad = true;
    int y;
    while(isInputBad == true)
    {
        cout << "Enter the y-coorinate: " << endl;
        cin >> y; 
        
        if(y < 1 || y > 3) {
            cout << "Invalid coordinate!\n";
        }
        else {
            isInputBad = false;
        }
    }
    return y - 1;
}



//places move on board//////////////////////////////
bool ticTacToe::placeMove(int x, int y, char currentPlayer,bool& move)
{
    if(board[y][x] != ' ') {
        cout << "Cant move there!\n";
        move = false;
        return false;
    }
    board[y][x] = currentPlayer;
    move = true;
    return true;
}


//change player/////////////////////////////////////
void ticTacToe::changePlayer(char p1,char p2, char& currentP)
{
    if(currentP == p1) {
        currentP = p2;
    }
    else{
        currentP = p1;
    }
}



bool ticTacToe::checkForWin(char current)
{
    
    //check rows for win
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == current &&
           board[i][0] ==  board[i][1] && 
           board[i][1] == board[i][2]) {
            return true;
        }
    }

    //check columns for win 
    for(int j = 0; j < 3; j++)
    {
        if(board[0][j] == current &&
           board[0][j] == board[1][j] &&
           board[1][j] == board[2][j]) {
            return true;
        }
    } 
    
    // check top left diagonal 
    if(board[0][0] == current &&
       board[1][1] == board[0][0] &&
       board[1][1] == board[2][2]){
        return true;
    }
    
    // check top right diagonal 
    if(board[0][2] == current &&
       board[1][1] == board[0][2] &&
       board[1][1] == board[2][0]){
        return true;
    }
    return false;
    
}




//clears the board//////////////////////////////////
void ticTacToe::clearBoard()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
           board[i][j] = ' ';
        }
    }
}



//prints char board[][] as a board////////////////////////
void ticTacToe::printBoard()
{
    cout << endl;
    cout << "    -------------" << endl;
    cout << "    | " << board[0][0] << " | ";
    cout << board[0][1] << " | ";
    cout << board[0][2] << " |" << endl;
    cout << "    -------------" << endl;
    cout << "    | " << board[1][0] << " | ";
    cout << board[1][1] << " | ";
    cout << board[1][2] << " |" << endl;
    cout << "    -------------" << endl;
    cout << "    | " << board[2][0] << " | ";
    cout << board[2][1] << " | ";
    cout << board[2][2] << " |" << endl;
    cout << "    -------------" << endl;
    cout << endl;
    cout << endl;
}

