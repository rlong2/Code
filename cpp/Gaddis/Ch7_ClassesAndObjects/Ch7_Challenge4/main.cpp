/* This challenge is to write a Car class with year, make, and speed.
* The class should have the following member functions:
*
* Constructor - Accepts the car's year and make as arguments
* and assign these values to the object's year and make member variables.
* Constructor should assign the speed member variable to 0.
*
* Accessors - appropriate accessor functions should be created to allow values
* to be retrieved from an object's year, make, and speed member variables
*
* Accelerate - Adds 5 to the speed member variable each time it is called
*
* Brake - Same as accelerate, but subtracts 5
*
* Create a car object, accelerate 5 times.
* After each acceleration, display current speed.
* Call brake function 5 times.
* After each brake, display current speed.
*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    int year;
    string make;
    int speed;

public:
    Car(int y, string m);

    // Accessors
    int GetYear()
    { return year; }

    string GetMake()
    { return make; }

    int GetSpeed()
    { return speed; }

    // Mutators
    void Accelerate()
    { speed += 5; }

    void Brake()
    {
        if (speed >= 5)
            speed -= 5;
        else
            speed = 0;
    }
};

// Car constructor implementation
Car::Car(int y = 2010, string m = "Unknown")
{
    year = y;
    make = m;
    speed = 0;
}

int main()
{
    Car myCar(2002, "Honda Civic");

    cout << myCar.GetYear() << " " << myCar.GetMake() << " created.\n" << endl;

    cout << "Accelerating..." << endl;
    for (int i = 0; i < 5; i++)
    {
        myCar.Accelerate();
        cout << "Current speed: " << myCar.GetSpeed() << " mp/h" << endl;
    }

    cout << endl;

    cout << "Braking..." << endl;
    for (int i = 0; i < 5; i++)
    {
        myCar.Brake();
        cout << "Current speed: " << myCar.GetSpeed() << " mp/h" << endl;
    }
    cout << endl;

    return 0;
}
