class ticTacToe
{
    public:

        ticTacToe(char);

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
        int x;
        int y;   //move coordinates
        int player1Score = 0;
        int player2Score = 0;
        int gameType;


        void setXCoord(char current);
        void setYCoord(char current);
        void setXY(char currentPlayer, char player);
        void placeMove(char currentPlayer,bool& move);
        void changePlayer(char p1, char p2, char& current);
        bool checkForWin();
        bool movesAvailable();
        void incrementScore(char current, char player);
        void clearBoard();
        void printBoard();
        void printScore();
};
