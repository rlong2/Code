//This program implements a Rectangle class

#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double length,
               width;
    public:
        void SetLength(double);
        void SetWidth(double);
        double GetLength();
        double GetWidth();
        double CalcArea();
};

// Member function implementations
void Rectangle::SetLength(double len)
{
    if (len >= 0.0)
    {
        length = len;
    } else {
        length = 1.0;
        cout << "Ivalid length. Using a default of 1.0" << endl;
    }
}

void Rectangle::SetWidth(double wid)
{
    if (wid >= 0.0)
    {
        width = wid;
    } else {
        width = 1.0;
        cout << "Ivalid width. Using a default of 1.0" << endl;
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
    
    // Get box length and width
    cout << "This program will calculate the area of a rectangle." << endl;
    cout << "Enter the box's length: ";
    cin >> boxLength;
    cout << "Enter the box's width: ";
    cin >> boxWidth;
    
    // Call member functions to set box dimensions
    box.SetLength(boxLength);
    box.SetWidth(boxWidth);
    
    // Call member functions to calculate and display area
    cout << "\nHere is the rectangle data:" << endl;
    cout << "Length: " << box.GetLength() << endl;
    cout << "Width: " << box.GetWidth() << endl;
    cout << "Area: " << box.CalcArea() << endl;
    
    return 0;
}
