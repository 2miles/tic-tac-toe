class ticTacToe
{
    public:
        void playGame();

        //print score
        //if move valid:
        //-print board
        //
        //get coordinates
        //clear screen
        //
        //place the move down
        //if move not valid print board
        //
        //check for win------
        //if win
        //-increment score
        //-print score
        //-print board
        //-print win message
        //
        //check for tie------
        //if tie
        //ends game if tie
        //
        //if move was not occupied:
        //-switch player and increment turn

    private:
        char board[3][3];

        int getXCoord(char current);
        int getYCoord(char current);
        bool placeMove(int x, int y, char currentPlayer,bool& move);
        void changePlayer(char p1, char p2, char& current);
        bool checkForWin(char current);
        bool checkForTie(int turn);
        void clearBoard();
        void printBoard();

};
