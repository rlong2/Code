// This program  uses a triangle class to calculate the triangle's area

#include <iostream>
using namespace std;

class Triangle
{
    private:
        double base,
               height;
    public:
        void SetBase(double);
        void SetHeight(double);
        double GetBase();
        double GetHeight();
        double CalcArea();
};

// Function member implementations
void Triangle::SetBase(double b)
{
    base = b;
}

void Triangle::SetHeight(double h)
{
    height = h;
}

double Triangle::GetBase()
{
    return base;
}

double Triangle::GetHeight()
{
    return height;    
}

double Triangle::CalcArea()
{
    return (1/2.0) * base * height;
}

int main()
{
    Triangle myTri;
    double triBase,
           triHeight;
           
    cout << "This program calculates the area of a triangle." << endl;
    cout << "Enter the base: ";
    cin >> triBase;
    cout << "Enter the height: ";
    cin >> triHeight;
    
    myTri.SetBase(triBase);
    myTri.SetHeight(triHeight);
    
    cout << "Area is " << myTri.CalcArea();
    
    return 0;
}
