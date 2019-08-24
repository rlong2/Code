/* Write a function named FallingDistance that accepts an object's falling time (in seconds)
 * as an argument. The function should return the distance, in meters, that the object
 * has fallen during that time. Write a program that demonstrates the function by
 * calling it in a loop that passes the values 1 - 10 as arguments and displays the return value.
 *
 * Recall d = .5gt^2
 */

#include <iostream>
#include <cmath>
using namespace std;

// Function prototype
double FallingDistance(double time);

// Global constant
const double GRAVITY = 9.8;

int main()
{
    double fallTime;
    double distance;

    cout << "Enter the object's falling time (in seconds): "; 
    cin  >> fallTime;

    distance = FallingDistance(fallTime);

    cout << "\nThe object has fallen " << distance << " meters." << endl;

    cout << "\nHere is a table of data:" << endl;
    for (int i = 1; i <= 10; i++)
    {    
        double tempDist = FallingDistance(i);
	cout << "After " << i << " seconds, the object has fallen " << tempDist << " meters." << endl;
    }

    return 0;
}

// Function implementation
double FallingDistance(double time)
{
    double distance = 0.5 * GRAVITY * pow(time, 2);
    return distance;    
}


