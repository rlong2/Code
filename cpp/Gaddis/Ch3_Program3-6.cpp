// This program calculates the area of a circle using 'pow' from the mathc library
// Area of a cirlce = PI times raduis squared.

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

int main()
{
    double radius;
    double area;

    cout << "Enter the circle's radius: ";
    cin >> radius;

    area = PI * pow(radius, 2.0);

    cout << "The area is: "<< area << endl;

    return 0;
}

