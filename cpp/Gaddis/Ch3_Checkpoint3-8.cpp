/* Complete the following main function so that it asks for the user's
 * weight (in pounds) and displays the equivalent weight in kilograms.
 */

#include <iostream>

using namespace std;

int main()
{
    double pounds;
    double kilograms;

    cout << "Enter your weight in pounds: ";
    cin >> pounds;

    kilograms = pounds / 2.2;

    cout << "You weigh " << kilograms << " kilograms." << endl;

    return 0;
}
