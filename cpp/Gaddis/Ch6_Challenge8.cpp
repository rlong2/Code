/* This program calculates the average of a group of 5 test scores,
* where the lowest score in the group is dropped. Follow this guide:
* 
* 1. void GetScore() asks user for a test score, stores it in a ref param,
* and checks that score is not less than 0 or greater than 100.
* GetScore() is called by main once for each of the 5 test scores to be entered.
* 
* 2. void CalcAverage() calculates and displays the average of the 4 highest scores.
* This function is just called once by main and should be passed the 5 scores.
*
* 3. int FindLowest() should find and return the lowest of the 5 scores passed to it.
* It should be called by CalcAverage, which uses the function to determine which score to drop.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void GetScore(int &score);
void CalcAverage(int score1, int score2, int score3, int score4, int score5);
int FindLowest  (int score1, int score2, int score3, int score4, int score5);

int main()
{
    int score1, score2, score3, score4, score5;
    
    GetScore(score1);
    GetScore(score2);
    GetScore(score3);
    GetScore(score4);
    GetScore(score5);
    
    CalcAverage(score1, score2, score3, score4, score5);
    
    return 0;
}

void GetScore(int &score)
{
    cout << "Enter score: ";
    cin >> score;
    while (score < 0 || score > 100)
    {
        cout << "Invlid input: Enter score: ";
        cin >> score;
    }
}

void CalcAverage(int score1, int score2, int score3, int score4, int score5)
{
    double average;
    int lowest = FindLowest(score1, score2, score3, score4, score5);
    average = (score1 + score2 + score3 + score4 + score5 - lowest) / 4.0;
    cout << "The average of the four highest scores is: " << average << endl;
}

// FIXME //
int FindLowest(int score1, int score2, int score3, int score4, int score5) 
{
    int lowestScore = score1;
    
    if (score2 < lowestScore)
    {
        score2 = lowestScore;
    } else if (score3 < lowestScore)
    {
        score3 = lowestScore;
    } else if (score4 < lowestScore)
    {
        score4 = lowestScore;
    } else if (score5 < lowestScore)
    {
        score5 = lowestScore;
    }
    
    cout << "Lowest score is " << lowestScore << endl;
    return lowestScore;
}
