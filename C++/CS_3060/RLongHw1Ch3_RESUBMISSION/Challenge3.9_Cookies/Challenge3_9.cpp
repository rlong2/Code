/* Author: Ryan Long
 * Class: CS 3060
 * Date: August 26, 2019
 *
 * Instructions: A bag holds 30 cookies. There are 10 servings per bag and a serving is 300 calories.
 * Write a program that asks the user to input how many cookies they ate and then report
 * how many calories were consumed.
 */

#include <iostream>
using namespace std;

int main()
{
    double cookiesEaten;
    double calories;

    cout << "How many cookies did you eat?: ";
    cin  >> cookiesEaten;

    // Calculate the calories consumed
    // Since a bag holds 30 cookies and there are 10 servings per bag,
    // 1 serving = 3 cookies. 
    // Since 1 serving is 300 calories, 1 cookie has (300 / 3) calories.
    // Therefore, 1 cookie has 100 calories.

    calories = cookiesEaten * 100.0;

    cout << "You consumed " << calories << " calories." << endl;

    return 0;
}
