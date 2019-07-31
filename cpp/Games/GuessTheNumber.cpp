/// Guess My Number (1 - 100)
// Modified from Beginning C++ Through Game Programming, 4th Edition
// http://www.delmarlearning.com/companions/content/1305109910/datafiles/index.asp?isbn=1305109910
// Random number generation: http://www.cplusplus.com/reference/cstdlib/rand/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char playAgain = 'y';
    
    do // playAgain loop
    { 
        srand (time(NULL)); // Generate random seed
        int number = rand() % 100 + 1; // generate random number
        int guess = 0;
        int tries = 0;
    
        cout << "Random number generated (1 - 100)" << endl;
    
    do // guess loop
    {
        cout << "Enter your guess: " ;
        cin >> guess;
        
        if (guess < number)
        {
            cout << "Too low!" << endl;
            tries++;
        }
        else if (guess > number)
        {
            cout << "Too high!" << endl;
            tries++;
        }
        else
        {
            cout << "You guessed the random number in " << tries << " tries!" << endl;
        }
    } while (guess != number);
    
    
    /* After Player has guessed correct number */
    
        cout << "\nPlay again? (y/n)" << endl;
        cin >> playAgain;
    
    } while (playAgain == 'y');
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}
