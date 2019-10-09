/*
Ryan Long
10/10/2019
CS 3060 Exercise 8
This program includes periodic_table.txt included in the directory containing the compiled cpp file.
To view output properly, you may have to zoom out of the output so there is no wrap distortion.

Instructions:
Write a program that displays the periodic table of elements using a source data file with the correct information in it.
You can use the example I sent out a few days ago, find another, or make your own.
The output should have cells that contain the abbreviation for the element, as well as its molecular weight.
The output does not have to be "empty" in the upper middle, but should overlay with a proper table.
The program should use a 2-dimensional array, at a minimum.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const int TOTAL_ROWS = 7;
    const int TOTAL_COLS = 19;
    string myArray[TOTAL_ROWS][TOTAL_COLS];

    ifstream inputFile;
    inputFile.open("periodic_table.txt");
    string line;

            for (int i =0; i < TOTAL_ROWS; i++)
            {
                for (int j = 0; j < TOTAL_COLS; j++)
                {
                        getline (inputFile, line);

                        if (line == "na")
                            myArray[i][j] = "[        ]";
                        else
                            myArray[i][j] = "[" + line + "]";

                        cout << myArray[i][j];
                }

              cout << endl;
            }
}
