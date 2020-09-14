#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "tic-tac-toe.h"

using namespace std;


ticTacToe::ticTacToe(char type)
{
    gameType = type;
}

//main game loop////////////////////////////////////
void ticTacToe::playGame()
{
    clearBoard();
    
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1; //X starts the game
    bool gameOver = false;  //is the game over
    bool moveIsValid = true;  //is the move valid

    srand(time(NULL));

     

    while(gameOver == false)
    {
        printScore();
        if(moveIsValid) 
            printBoard();


        if(gameType == '1') //player vs player
        {
            setXCoord(currentPlayer);
            setYCoord(currentPlayer);
        }
        else   //player vs computer
        {
            if(currentPlayer == player1)
            {
                setXCoord(currentPlayer);
                setYCoord(currentPlayer);
            }
            else if(gameType == '2') //very easy 
            {
                int xTemp, yTemp;
                xTemp = rand() % 3 + 1; 
                yTemp = rand() % 3 + 1; 
                while (board[xTemp][yTemp] != ' ')
                {
                    xTemp = rand() % 3 + 1; 
                    yTemp = rand() % 3 + 1; 
                }
                x = xTemp;
                y = yTemp;
            }

            else if(gameType == '3') //very hard
            {

            }
        }

        placeMove(currentPlayer, moveIsValid);//if bad move:  prints board, sets moveIsValid to false
                                              //if good move: makes move, sets moveIsValid to true
                                              
        if (checkForWin()) 
        {
            incrementScore(currentPlayer, player1);
            printScore();
            printBoard();
            cout << currentPlayer << " wins!\n\n";
            gameOver = true;
        }
        else if(!movesAvailable())
        {
            cout << endl << "Tie game! \n " << endl;
            gameOver = true;
        }
        if(moveIsValid)
            changePlayer(player1, player2, currentPlayer);
    }
}



//gets x coord of move form user////////////////////
void ticTacToe::setXCoord( char current)
{
    bool isInputBad = true;
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
}


//gets y coord of move form user////////////////////
void ticTacToe::setYCoord(char current)
{
    bool isInputBad = true;
    while(isInputBad) 
    {
        cout << "Enter the y-coorinate: " << endl;
        cin >> y; 
        
        if(y < 1 || y > 3)
            cout << "Invalid coordinate!\n";
        else 
            isInputBad = false;
    }
}


//places move on board//////////////////////////////
void ticTacToe::placeMove(char currentPlayer, bool& moveIsValid)
{
    if(board[y - 1][x - 1] != ' ') 
    {
        printBoard();
        cout << "\nCant move there!\n";
        moveIsValid = false;
        return;
    }
    board[y - 1][x - 1] = currentPlayer;
    moveIsValid = true;
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
bool ticTacToe::checkForWin()
{
    //check rows for win
    for(int i = 0; i < 3; i++) 
        if(board[i][0] != ' ' && 
           board[i][0] == board[i][1] && 
           board[i][1] == board[i][2])
           return true;

    //check columns for win 
    for(int j = 0; j < 3; j++) 
        if(board[0][j] != ' ' && 
           board[0][j] == board[1][j] && 
           board[1][j] == board[2][j]) 
           return true;

    // check top left diagonal 
    if(board[1][1] != ' ' && 
       board[1][1] == board[0][0] && 
       board[1][1] == board[2][2])
       return true;

    // check top right diagonal 
    if(board[1][1] != ' ' && 
       board[1][1] == board[0][2] && 
       board[1][1] == board[2][0])
       return true;

    return false;
}



//return true if the are still moves available
//return false if no more moves left to make
bool ticTacToe::movesAvailable()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
           if (board[i][j] == ' ')
               return true;
    return false;
}


void ticTacToe::clearBoard()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
           board[i][j] = ' ';
}


void ticTacToe::incrementScore(char currentPlayer, char player)
{
    if(currentPlayer == player)
        player1Score++;
    else  
        player2Score++;
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



