// Word Scramble - Scrambles a given string
// https://www.geeksforgeeks.org/shuffle-vs-random_shuffle-c/

#include <iostream>
#include <string>

using namespace std;

string scrambledWord = "";

string Scramble(string word, int length)
{
    scrambledWord = word;

    for (int i = 0; i < length; i++)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = scrambledWord[index1];
        scrambledWord[index1] = scrambledWord[index2];
        scrambledWord[index2] = temp;
    }
    
    return scrambledWord;
}

int main()
{
    cout << "Enter a string: ";
    string word = "";
    cin >> word;
    
    int length = word.length();
    
    Scramble(word, length);
    
    cout << "original word: " << word << endl;
    cout << "scrambled word: " << scrambledWord << endl;
    
     return 0;  
     
} // main
