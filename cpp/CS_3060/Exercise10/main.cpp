/*
 Ryan Long

 Create a program with 3 base classes to create a vehicle
 A user should be able to select from a list of vehicles
 to show its attributes.

 https://www.geeksforgeeks.org/multiple-inheritance-in-c/
 http://www.trytoprogram.com/cplusplus-programming/multiple-inheritance/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Base Class 1
class Motor
{
    public:
        int motor;
        Motor()
        {
            cout << "Creating a vehcicle..." << endl;
            cout << "Enter number of cylinders (1-4): ";
            cin  >> motor;
        }
};

//Base Class 2
class Transmission
{
    public:
        char choice;
        string transmission;
        int numGears;

        Transmission()
        {
            cout << "Manual or automatic (M/A)? ";
            cin  >> transmission;

            if (choice == 'a' || choice == 'A')
            {
                transmission = "automatic";
            }
            else
            {
                transmission = "manual";
            }
            cout << "Number of gears: ";
            cin  >> numGears;
        }
};

//Base Class 3
class Chassis
{
    public:
    // Sedan, truck, minivan, etc
    int choice;
    string chassis;
        Chassis()
        {
            cout << "Vehicle types:" << endl;
            cout << "1. Sedan" << endl;
            cout << "2. Limo" << endl;
            cout << "3. Smart Car" << endl;
            cout << "4. Monster Truck" << endl;
            cout << "5. Custom" << endl;
            cout << "Select your vehicle's body type: ";
            cin  >> choice;

            switch (choice)
            {
                case 1:
                    chassis = "Sedan";
                    break;
                case 2:
                    chassis = "Limo";
                    break;
                case 3:
                    chassis = "Smart Car";
                    break;
                case 4:
                    chassis = "Monster Truck";
                    break;
                case 5:
                    cout << "Enter your vehicle's body type: ";
                    cin  >> chassis;
                    break;
                default:
                    cout << "You've entered invalid input. Assinging chassis..." << endl;
                    chassis = "Weinermobile";
            }
        }
};

// Sub class inheriting from Base Class(Parent)
class Vehicle : public Motor, public Transmission, public Chassis
{
    public:
        void PrintVehicle()
        {
            cout << "Motor:             " << motor << "-cylinder"<< endl;
            cout << "Transmission type: " << numGears << " gear " << transmission << endl;
            cout << "Chassis:           " << chassis << endl;
        }
};

//main function
int main()
   {
       vector<Vehicle> garage;

       int menuChoice;

       cout << "Welcome to the car creator program! Build the cars of your dreams!" << endl;

       do
       {
          cout << "\n1. Create Car" << endl;
          cout << "2. Print Car List" << endl;
          cout << "3. Exit Program" << endl;
          cin  >> menuChoice;

          if (menuChoice == 1)
          {
             Vehicle car1;
             garage.push_back(car1);

          }
          else if (menuChoice == 2)
          {
             cout << "Garage:" << endl;

             for (int counter = 0; counter < garage.size(); counter++)
                garage[counter].PrintVehicle();
          }
          else
          {
              cout << "Exiting..." << endl;
          }

       } while (menuChoice != 3);

        return 0;
   }
