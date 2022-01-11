/* Author: Ryan Long
 * Class: C++ 3060
 * Date: Monday, August 26, 2019
 *
 * Instructions: Write a program that prompts the user to enter the number of days 
 * they plan to spend on their next vacation. Then compute how long that is in hours,
 * in minutes, and in seconds.
 */

#include <iostream>
using namespace std;

int main()
{
    double days,
	   hours,
	   minutes,
	   seconds;

    cout << "Enter the number of days you plan to spend on vacation: ";
    cin  >> days;

    hours   = days    * 24.0;
    minutes = hours   * 60.0;
    seconds = minutes * 60.0;

    cout << "\nYou are planning to spend "    << days << " days on vacation." << endl;
    cout << days << " days is equivalent to " << hours << " hours or "
                                              << minutes << " minutes or "
					      << seconds << " seconds." << endl;

    return 0;
}
