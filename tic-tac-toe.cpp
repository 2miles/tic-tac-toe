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
    int x,y;

    while(isDone == false)
    {
        printBoard();
        x = getXCoord();
        y = getYCoord();
        placeMove(x, y, currentPlayer);
    }
}


//gets x coord of move form user////////////////////
int ticTacToe::getXCoord()
{
    int x;
    cout << "Enter the x-coorinate: " << endl;
    cin >> x; 
    return x - 1;
}


//gets y coord of move form user////////////////////
int ticTacToe::getYCoord()
{
    int y;
    cout << "Enter the y-coorinate: " << endl;
    cin >> y; 
    return y - 1;
}

//places move on board//////////////////////////////
bool ticTacToe::placeMove(int x, int y, char currentPlayer)
{
    if(board[y][x] != ' ')
    {
        return false;
    }
    board[y][x] = currentPlayer;
    return true;
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

