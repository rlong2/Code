// This program demonstrates how a constructor executes

#include <iostream>
using namespace std;

class Demo
{
    public:
        Demo()        // Constructor
        {
            cout << "Now the constructor is running!" << endl;
        }
};

int main()
{
    cout << "This is displayed before the object is created." << endl;
    
    Demo demoObj;        // Define a Demo object
    
    cout << "This is displayed after the object is created." << endl;

    return 0;
}
