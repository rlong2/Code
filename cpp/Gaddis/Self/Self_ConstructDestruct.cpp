// This program shows how a simple destructor works

#include <iostream>
using namespace std;

class Demo
{
    public:
        Demo();
       ~Demo();	
};

Demo::Demo()
{ cout << "Demo object created." << endl;
}

Demo::~Demo()
{ cout << "Demo object destroyed." << endl;
}

int main()
{
    Demo Obj1;
    cout << "Doing something in main" << endl;

    return 0;
}
