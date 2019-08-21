// This program lets the user play rock paper scissors
// against the computer.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

const string name[4] = { " ", "rock", "paper", "scissors" };  // In the array, rock cooresponds to 1, paper to 2, rock to 3

int main()
{
    int computerChoice,
        userChoice,
        computerPoints = 0,
        userPoints = 0;
    
    srand(time(NULL));             // Give the random generator
                                   // a seed to start switch
    
    cout << "Let's play Rock Paper Scissors!" << endl;
    cout << "First player to get 5 points wins!\n" << endl;
    
    do
    {
        // Get a random computer choice
        computerChoice = 1 + rand() % 3;  
        
        cout << "Choose 1 (rock), 2 (paper), or 3 (scissors): ";
        cin  >> userChoice;
        
        if (computerChoice == userChoice)                           // Tie
            cout << "You both chose " << name[computerChoice] 
                 << ", tie!\n";
        
        else if ((userChoice == 1 && computerChoice == 2) ||        // Computer wins
                 (userChoice == 2 && computerChoice == 3) ||
                 (userChoice == 3 && computerChoice == 1))
                 {
                    cout << name[computerChoice] << " beats "
                         << name[userChoice] << "!\n";
                
                    computerPoints++;
                 }
        
        else                                                      // User wins
        {
            cout << name[userChoice] << " beats "
                         << name[computerChoice] << "!\n";
            
            userPoints++;
        }
        
    } while (userPoints < 5 && computerPoints < 5);
    
    cout << "\nThe final score is:" << endl;
    cout << "User: " << userPoints << endl;
    cout << "Computer: " << computerPoints << endl;
    
    if (computerPoints > userPoints)
    {
        cout << "\nThe computer wins!" << endl;
    }
    else
    {
        cout <<"\nYou win!" << endl;
    }
    
    return 0;
}
