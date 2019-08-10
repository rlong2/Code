//This program demonstrates a simple class with member functions
// defined outside the class declaration

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Circle class declaration
class Circle
{
    private:
        double radius;          // member variable
    
    public:
        void SetRadius(double); // These are just prototypes
        double CalcArea();      // for the member fuctions
};

// Function Implementations
// The '::' tells the compiler which class the function belongs to
void Circle::SetRadius(double r)
{
    radius = r;
}

double Circle::CalcArea()
{
    return 3.14159 * pow(radius, 2);
}

int main()
{
    Circle circle1,         // Define two circle objects
           circle2;
    
    // Set circle's radii      
    circle1.SetRadius(1);
    circle2.SetRadius(4.5);
    
    // Get and display circle's areas
    cout << setprecision(2) << fixed;
    cout << "The area of circle1 is " << circle1.CalcArea() << endl;
    cout << "The area of circle2 is " << circle2.CalcArea() << endl;

    return 0;
}
