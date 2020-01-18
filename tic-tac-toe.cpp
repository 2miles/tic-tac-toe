#include <iostream>
#include "tic-tac-toe.h"

using namespace std;



    int player1Score = 0;
    int player2Score = 0;


//main game loop////////////////////////////////////
void ticTacToe::playGame()
{
    
    clearBoard();
    
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    bool isDone = false;
    bool move = true;
    int x,y;
    int turn = 1;
 

    while(isDone == false)
    {

        //prints board unless move space occupied
        if(move == true){
            printBoard();
        }
        
        //ask and get coordinates from user
        x = getXCoord(currentPlayer);
        y = getYCoord(currentPlayer);

        //clear the terminal screen
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        
        //place the move down. print board if move occupied
        placeMove(x, y, currentPlayer, move);

        //check for win. prints board if win and increments score and ends game
        if( checkForWin(currentPlayer) == true){
            printBoard();
            cout << currentPlayer << " wins!\n\n";
            if(currentPlayer == player1){
                player1Score++;
            }
            else{
                player2Score++;
            }
            isDone = true;
        }
        
        //prints score
        cout << "Score: X - " << player1Score << "   ";
        cout << "O - " << player2Score << endl << endl;

        //check for tie, ends game if tie
        if(checkForTie(turn) == true && isDone == false){
            cout << endl << "Tie game! \n ";
            cout << endl;
            isDone = true;
        }
        
        //if move was not occupied switch  player and increment turn
        if(move == true){
            changePlayer(player1, player2, currentPlayer);
            turn++;
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
            cout << endl;
            cout << "Invalid coordinate!\n";
            cout << endl;

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

        printBoard();
        cout << "\nCant move there!\n";
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


//check for win/////////////////////////////////////
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

//check for tie////////////////////////////////////
bool ticTacToe::checkForTie(int turn)
{
    if(turn == 9)
    {
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
    cout << "     x1  x2  x3   " << endl;
    cout << "    -------------" << endl;
    cout << " y1 | " << board[0][0] << " | ";
    cout << board[0][1] << " | ";
    cout << board[0][2] << " |" << endl;
    cout << "    -------------" << endl;
    cout << " y2 | " << board[1][0] << " | ";
    cout << board[1][1] << " | ";
    cout << board[1][2] << " |" << endl;
    cout << "    -------------" << endl;
    cout << " y3 | " << board[2][0] << " | ";
    cout << board[2][1] << " | ";
    cout << board[2][2] << " |" << endl;
    cout << "    -------------" << endl;
    cout << endl;
    cout << endl;
}

