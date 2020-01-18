#include <iostream> 
#include "tic-tac-toe.h"


using namespace std;

int main(){
    
    char choice;
    bool isDone = false;

    ticTacToe gameObject; 

    while(isDone == false)
    {
        gameObject.playGame();

        cout << "Play again? (Y/N) ";
        cin >> choice;

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        
        if (choice == 'N' || choice == 'n')
        {
            isDone = true;
        }


    }


    return 0;
}
