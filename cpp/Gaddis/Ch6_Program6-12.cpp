// This program demonstrates two value-returning function
// to find the area of a circle.
// Recall Area = Pi * r^2

#include <iostream>

using namespace std;

// Function Prototypes
double GetRadius();
double Square(double number);

int main()
{
    const double PI = 3.14159;
    double radius;
    double area;
    
    // Get radius 
    cout << "This program calculates the area of a cirlce." << endl;
    radius = GetRadius();
    
    // Calculate area
    area = PI * Square(radius);
    
    // Display
    cout << "The area is " << area << endl;
    
    return 0;
}

double GetRadius()
{
    double rad;
    cout << "Enter the radius: ";
    cin >> rad;
    return rad;
}

double Square(double number)
{
    return number * number;
}
