/* Author: Ryan Long
 * Class: CS 3060
 * Date: August 26, 2019
 *
 * Instructions: Write a program that converts Celcius to Fahrenheight.
 *
 * Recall F = (9/5)C + 32
 */

#include <iostream>
using namespace std;

int main()
{
    double celcius,
	   fahrenheight;

    cout << "Enter a temperature in Celcius: ";
    cin  >> celcius;

    fahrenheight = (9/5.0) * celcius + 32;

    cout << celcius << " celcius is " << fahrenheight << " fahrenheight." << endl;

    return 0;
}
