// This program computes the area of a circle
// Recall area = Pi * r^2

#include <iostream>
#include <iomanip>

using namespace std;

// Prototype Functions
double GetRadius();
double GetArea(double radius);

// global constants    
double const PI = 3.14159;
    
int main()
{
    double radius;
    double area;
    
    cout << fixed << showpoint << setprecision(2); // set output formatting

    radius = GetRadius();
    
    area = GetArea(radius);
    
    cout << "Area is " << area << endl;

    return 0;
}

double GetRadius()
{
    double rad;
    cout << "Enter radius: ";
    cin >> rad;
    return rad;
}

double GetArea(double radius)
{
    return PI * radius * radius;
}
