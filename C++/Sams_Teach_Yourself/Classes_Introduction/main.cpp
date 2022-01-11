/* This program demonstrates how  to create a class
* using a constructor and public/private variables.
* An overloaded constructor makes it possible to create
* an instance of class Human with name and age.
* From Ch 9 of Sams Teach Yourself C++, pg 219 - 227
*/

#include <iostream>

using namespace std;

class Human
{
private:
    string name;
    int age;

public:
    Human() //  Default constructor
    {
        age = 0;
        name = "DefaultName";
        cout << "Default constructor created a default instance of class Human." << endl;
    }

    Human (string humanName, int HumanAge)
    {
        name = humanName;
        age = HumanAge;
        cout << "Overloaded constructor created " << name << " of age " << age << endl;
    }

    void SetName (string humanName)
    {
        name = humanName;
    }

    void SetAge (int humanAge)
    {
        age = humanAge;
    }

    void IntroduceSelf()
    {
        cout << "My name is " << name << " and I am " << age  << " years old." << endl;
    }
};

int main()
{
    Human firstWoman;
    firstWoman.SetName("Eve");
    firstWoman.SetAge(20);
    firstWoman.IntroduceSelf();

    cout << endl;

    Human firstMan("Paul", 44);
    firstMan.IntroduceSelf();

    return 0;
}
