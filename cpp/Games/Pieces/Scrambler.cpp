// Word Scramble
// https://www.geeksforgeeks.org/shuffle-vs-random_shuffle-c/

#include <iostream>
#include <string>

using namespace std;

string scrambledWord = "";

string Scramble(string word)
{
    word = scrambledWord;
    scrambledWord = "gregreafcdg";
    return scrambledWord;
}

int main()
{
    cout << "Enter a string: ";
    string word = "";
    cin >> word;
    
    Scramble(word);
    
    cout << "original word: " << word;
    cout << "scrambled word: " << scrambledWord;
    
     return 0;  
     
} // main
