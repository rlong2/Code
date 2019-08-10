// This program calculates the area of a rectangle using a Rectangle class

#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double length;
        double width;
    public:
        void SetLength(double);
        void SetWidth(double);
        double GetLength();
        double GetWidth();
        double CalcArea();
};

// Function member implementations
void Rectangle::SetLength(double len)
{
    if (len >=0)
    {
        length = len;
    } else {
        cout << "Negative length. Length = 1.0" << endl;
        length = 1.0;
    }
}

void Rectangle::SetWidth(double wid)
{
    if (wid >=0)
    {
        width = wid;
    } else {
        cout << "Negative width. Width = 1.0" << endl;
    }
}

double Rectangle::GetLength()
{
    return length;
}

double Rectangle::GetWidth()
{
    return width;
}

double Rectangle::CalcArea()
{
    return length * width;    
}

int main()
{
    Rectangle box;
    
    double boxLength,
           boxWidth;
    
    cout << "This program calculates the area of a rectangle." << endl;
    cout << "Enter the rectangle length: ";
    cin >> boxLength;
    cout << "Enter the rectangle width: ";
    cin >> boxWidth;
    
    box.SetLength(boxLength);
    box.SetWidth(boxWidth);
    
    cout << "The area of the box is: " << box.CalcArea() << endl;
    
    return 0;
}
