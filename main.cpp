#include <iostream> 
#include "tic-tac-toe.h"


using namespace std;

int main(){
    
    char choice;  //Play again?
    char gameTypeChoice;
    bool isDone = false; //game loop

    cout << "Press 1 for Player vs. Player, press 2 for Player vs. AI: ";
    cin >> gameTypeChoice;
    cin.ignore(100,'\n');

    ticTacToe gameObject(gameTypeChoice); 
    
    while(isDone == false)
    {
        gameObject.playGame();  

        cout << "Play again? (Y/N) ";
        cin >> choice;

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        
        if (choice == 'N' || choice == 'n')
            isDone = true;
    }
    return 0;
}
