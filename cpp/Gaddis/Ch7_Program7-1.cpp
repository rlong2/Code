// This program demonstrates a simple class that calculates the area of a circle

#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

class Circle
{
    private:
    double radius;
    
    public:
    void SetRadius(double r)
    {
        radius = r;
    }
    
    double CalcArea()
    {
        return 3.14159 * pow(radius, 2);
    }
};

int main()
{
    Circle circle1,
           circle2;
           
    circle1.SetRadius(1);
    circle2.SetRadius(4.5);
    
    cout << setprecision(2) << fixed;
    cout << "The area of circle1 is " << circle1.CalcArea() << endl;
    cout << "The area of circle2 is " << circle2.CalcArea() << endl;
    
    return 0;
}
