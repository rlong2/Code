// This program shows how an overloaded constructor is used.
// Altered from https://www.geeksforgeeks.org/constructor-overloading-c/

#include <iostream>
using namespace std;

class Construct
{
    private:
        float area;
       
    public:
       float GetArea();
       Construct();
       Construct(int a, int b);
       void Display();
};

// Construct implementation
float Construct::GetArea()
{
    return area;
}

Construct::Construct()
{
    area = 0;
}

Construct::Construct(int a, int b)
{
    area = a * b;    
}

void Construct::Display()
{
   cout << "Area is " << area << endl;  
}

int main()
{
    
    Construct obj1;
    Construct obj2(5, 10);
    
    obj1.Display();
    obj2.Display();

    return 0;
}
