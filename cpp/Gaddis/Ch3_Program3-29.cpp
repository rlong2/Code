// This program calculates the length of the hypotenuse given the length of the other 2 sides.
// Uses <cmath> for 'sqrt' and squaring.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;

    // get lengths of the 2 sides
    cout << "Enter the length of side a: ";
    cin >> a;
    cout << "Enter the length of side b: ";
    cin >> b;

    // compute and display length of hypotenuse
    // Recall a^2 + b^2 = c^2
    c = sqrt(pow(a, 2.0) + pow(b, 2.0)); 

    cout << "The length of the hypotenuse is " << c << "." << endl;

    return 0;
}
