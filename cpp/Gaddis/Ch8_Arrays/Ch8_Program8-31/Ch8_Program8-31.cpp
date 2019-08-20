// This program uses an array of objects
// The objects are instances of the Circle class.

#include<iostream>
#include<iomanip>
#include "Circle.h"

using namespace std;

const int NUM_CIRCLES = 4;

int main()
{
    Circle circle[NUM_CIRCLES];    // Define an array of Circle objects

    // Use a loop to initialize the radius of each object
    for (int i = 0; i < NUM_CIRCLES; i++)
    {
        double r;
	cout << "Enter the radius for circle " << (i + 1) << ": ";
	cin  >> r;
	circle[i].SetRadius(r);
    }

    // Use a loop to get and print out the area of each object
    cout  << fixed << showpoint << setprecision(2);
    cout  << "\nHere are the areas of the " << NUM_CIRCLES << " circles.\n";

    for (int i = 0; i < NUM_CIRCLES; i++)
    {
        cout << "circle " << (i + 1) << setw(8)
	     << circle[i].FindArea() << endl;
    }

    return 0;
}
