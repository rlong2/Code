// This program calculates the area of a circle. A constructor 
// is used  to set a Circle object's default radius to 1.0

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Circle
{
    private:
        double radius;
    
    public:
        Circle();               // constructor
        void SetRadius(double);
        double CalcArea();
};

// Circle member function implementation
Circle::Circle()
{
    cout << "Circle object created. Radius set to 1.0" << endl;
    radius = 1.0;
}

void Circle::SetRadius(double r)
{
    if (r >= 0)
    {
        radius = r;
    } 
    // Else, leave radius set to default value of 1.0
}

double Circle::CalcArea()
{
    return 3.14159 * pow(radius, 2);
}

int main()
{
    Circle circle1,
           circle2;
           
    circle2.SetRadius(4.2);
    
    cout << setprecision(2) << fixed;
    cout << "The area of circle1 is " << circle1.CalcArea() << endl;
    cout << "The area of circle2 is " << circle2.CalcArea() << endl;
    
    return 0;
}
