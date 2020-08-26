#include <iostream>
#include "tic-tac-toe.h"

using namespace std;


//main game loop////////////////////////////////////
void ticTacToe::playGame()
{
    clearBoard();
    
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1; //X starts the game
    bool isDone = false;  //is the game over
    bool moveIsValid = true;  //is the move valid
    int x,y;   //move coordinates
    int turn = 1; // count turns to determine tie (turn == 9)
     

    while(isDone == false)
    {
        printScore();
        if(moveIsValid) printBoard();

        x = getXCoord(currentPlayer);
        y = getYCoord(currentPlayer);
        
        //place the move down. print board if move occupied
        placeMove(x, y, currentPlayer, moveIsValid);

        //check for win. if win: 
        //increments score, prints score, prints board, prints win message and ends game
        if (checkForWin(currentPlayer)) 
        {
            if(currentPlayer == player1)
                player1Score++;
            else  
                player2Score++;

            printScore();
            printBoard();
            cout << currentPlayer << " wins!\n\n";
            isDone = true;
        }
        
        //check for tie, ends game if tie
        if(checkForTie(turn))
        {
            cout << endl << "Tie game! \n " << endl;
            isDone = true;
        }
        
        //if move was not occupied switch  player and increment turn
        if(moveIsValid)
        {
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

    while(isInputBad)
    {
        cout << current << "'s turn. \n";
        cout << "Enter the x-coorinate: " << endl;
        cin >> x; 
        
        if(x < 1 || x > 3)
        {
            cout << endl;
            cout << "Invalid coordinate!\n";
            cout << endl;
        }
        else 
            isInputBad = false;
    }
    return x - 1;
}


//gets y coord of move form user////////////////////
int ticTacToe::getYCoord(char current)
{
    bool isInputBad = true;
    int y;

    while(isInputBad) 
    {
        cout << "Enter the y-coorinate: " << endl;
        cin >> y; 
        
        if(y < 1 || y > 3)
            cout << "Invalid coordinate!\n";
        else 
            isInputBad = false;
    }
    return y - 1;
}


//places move on board//////////////////////////////
bool ticTacToe::placeMove(int x, int y, char currentPlayer,bool& moveIsValid)
{
    if(board[y][x] != ' ') 
    {
        printBoard();
        cout << "\nCant move there!\n";
        moveIsValid = false;
        return false;
    }
    board[y][x] = currentPlayer;
    moveIsValid = true;
    return true;
}



//PARAMETERS     char player1, char player2, char& currentPlayer
//updates currentPlayer to the other player
void ticTacToe::changePlayer(char p1,char p2, char& currentP)
{
    if(currentP == p1) 
        currentP = p2;
    else
        currentP = p1;
}


//PARAMETERS    char current players icon i.e. X or O
//              defined as player1 or player2
//RETURNS true if argument's symbol is a winning state
//otherwise returns false
bool ticTacToe::checkForWin(char current)
{
    //check rows for win
    for(int i = 0; i < 3; i++) 
    {
        if(board[i][0] == current && 
            board[i][0] ==  board[i][1] && 
             board[i][1] == board[i][2])
            return true;
    }

    //check columns for win 
    for(int j = 0; j < 3; j++) 
    {
        if(board[0][j] == current &&
            board[0][j] == board[1][j] &&
             board[1][j] == board[2][j]) 
            return true;
    } 

    // check top left diagonal 
    if(board[0][0] == current &&
        board[1][1] == board[0][0] &&
         board[1][1] == board[2][2])
        return true;
            
    // check top right diagonal 
    if(board[0][2] == current &&
        board[1][1] == board[0][2] &&
         board[1][1] == board[2][0])
        return true;

    return false;
}


//returns true if game is a tie
//otherwise returns false
bool ticTacToe::checkForTie(int turn)
{
    if(turn == 9) 
        return true;
    return false;
}


void ticTacToe::clearBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
           board[i][j] = ' ';
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

//prints the score////////////////////////////////////////
void ticTacToe::printScore()
{
    cout << "Score: X - " << player1Score << "   ";
    cout << "O - " << player2Score << endl << endl;
}


//clear the terminal screen
void ticTacToe::clearScrean()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}


