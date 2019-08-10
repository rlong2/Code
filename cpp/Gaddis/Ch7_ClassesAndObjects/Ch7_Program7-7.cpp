// This program demonstrates a destructor

#include <iostream>
using namespace std;

class Demo
{
    public:
        Demo();    // Constructor Prototype
       ~Demo();    // Destructor Prototype
};

Demo::Demo()       // Constructor function defenition
{ cout << "An object has just been defined, so the constuctor is running." << endl;
}

Demo::~Demo()      // Destructor function defenition
{ cout << "Now the destructor is running." << endl;
}

int main()
{
    Demo demoObj;  // Declare a demo object

    cout << "The object now exists, but is about to be destroyed." << endl;

    return 0;
}
