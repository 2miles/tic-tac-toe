class ticTacToe
{
    public:
        ticTacToe();
        void playGame();

    private:
        char board[3][3];

        int getXCoord();
        int getYCoord();
        bool placeMove(int x, int y, char currentPlayer);
        void changePlayer(char p1, char p2, char& current);
        void clearBoard();
        void printBoard();

};
