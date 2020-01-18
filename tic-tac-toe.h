class ticTacToe
{
    public:
        void playGame();

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
