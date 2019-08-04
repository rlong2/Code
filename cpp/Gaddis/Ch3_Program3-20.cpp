// This program shows how to read strings with spaces
// using the 'getline' function

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string city;

    cout << "Enter your full name: ";
    getline(cin, name);
    
    cout << "Enter the city you live in: ";
    getline(cin, city);

    cout << "Hi " << name << ", you live in " << city << "." << endl;

    return 0;
}
