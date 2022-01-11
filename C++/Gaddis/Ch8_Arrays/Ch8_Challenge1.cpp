/* Write a modular program that accepts up to 20 integer test scores
* in the range from 0 to 100 from the user and stores them in an array.
* Then main should report how many perfect scores were entered,
* using a value-returning CountountPerfect function to help it.
*/

#include <iostream>
using namespace std;

// Function prototype
int CountPerfect(int myArray[], int size);

// Global variable
const int MAX = 20;

int main()
{
    int Scores[MAX];
    int testScore;
    int perfectScores = 0;
    
    cout << "Enter up to 20 integer test scores. Type -1 when finished" << endl;
    
    for (int i = 0; i < MAX; i++)
    {
        cout << "Test " << (i + 1) << " score : ";
        cin  >> testScore;
        
        if (testScore == -1)
            break;
        
        else
            Scores[i] = testScore;
    }
    
    // Display perfect Scores
    perfectScores = CountPerfect(Scores, MAX);

    cout << "\nThere were " << perfectScores << " perfect scores.\n";
    return 0;
}

// Function Implementation
int CountPerfect(int myArray[], int size)
{
    int perfect = 0;
    
    for (int i = 0; i < MAX; i++)
    {
       if (myArray[i] == 100) 
           perfect++;
    }

    return perfect;
}
