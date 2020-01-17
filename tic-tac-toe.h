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

        void clearBoard();
        void printBoard();

};
