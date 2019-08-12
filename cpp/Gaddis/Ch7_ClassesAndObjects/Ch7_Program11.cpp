// This program nests one class inside another. It has a class
// with a member variable that is an instance of another class.

#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double length;
        double width;
        
    public:
        void SetLength(double len)
        { length = len; }
        
        void SetWidth(double wid)
        { width = wid; }
        
        double GetLength()
        { return length; }
        
        double GetWidth()
        { return width; }
        
        double CalcArea()
        { return length * width; }
};

class Carpet
{
    private:
        double pricePerSqYd;       
        Rectangle size;       // size is an instance of     
                              // the Rectangle class
        
    public:
        void setPricePerYd(double p)
        { pricePerSqYd = p; }
        
        void setDimensions(double len, double wid)
        { 
            size.SetLength(len / 3);             // Convert feet to yards
            size.SetWidth(wid / 3);
        }
        
        double getTotalPrice()
        { return (size.CalcArea() * pricePerSqYd); }
};

/*************************
*          main          *
**************************/
int main()
{
    Carpet purchase;            // This variable is a Carpet object
    double pricePerYd;
    double length;
    double width;
    
    cout << "Room length in feet: ";
    cin >> length;
    cout << "Room width in feet: ";
    cin >> width;
    cout << "Carpet price per sq. yard: ";
    cin >> pricePerYd;
    
    purchase.setDimensions(length, width);
    purchase.setPricePerYd(pricePerYd);
    
    cout << "\nThe total price of my new " << length << " x " << width
         << " carpet is $" << purchase.getTotalPrice() << endl;

    return 0;
}
