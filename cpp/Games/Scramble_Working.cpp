// Word Scramble
// https://www.geeksforgeeks.org/shuffle-vs-random_shuffle-c/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"apple", "Jerry Smith's marketing campain involves these."},
        {"pokemon", "Cool creatures to battle."},
        {"school", "Stay in ________ kids."},
        {"sunglasses", "Save your eyeballs."},
        {"scrabble", "a fun board game."},
    };
    
    cout << "Choose a word to unscrable: (Enter 1, 2, 3, 4, or 5): ";
    int choice = 0;
    cin >> choice;
    choice--;
    
    string theWord = WORDS[choice][WORD]; // word to guess
    string theHint = WORDS[choice][HINT]; // hint 
    
    /* Scramble the word */
    string scramble = rand() % theWord;
   
    
    cout << "scrambled word is " << scramble;
} // main

