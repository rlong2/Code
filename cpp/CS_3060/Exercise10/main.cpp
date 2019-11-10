/*
 Ryan Long
 CS 3060
 November 10, 2019

 This program uses 3 base classes to create a vehicle.
 A user can create vehicles and print their attributes.

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
            cout << "\nCreating a vehicle..." << endl;
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
            cout << "\nManual or automatic (M/A)? ";
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
            cout << "\nVehicle type:" << endl;
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
                    //cin  >> chassis;
                    getline (cin >> ws, chassis);
                    break;
                default:
                    cout << "You've entered invalid input. Assinging default chassis..." << endl;
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
            cout << "\nChassis:           " << chassis << endl;
            cout << "Motor:             " << motor << "-cylinder"<< endl;
            cout << "Transmission type: " << numGears << " gear " << transmission << endl;
        }

        void PrintShortList()
        {
            cout << chassis << endl;
        }
};

//main function
int main()
   {
       vector<Vehicle> garage;

       int menuChoice;
       int details;

       cout << "Welcome to the car creator program! Build the cars of your dreams!" << endl;

       do
       {
          cout << "\n1. Create Car" << endl;
          cout << "2. Print Car List" << endl;
          cout << "3. Exit Program" << endl;
          cin  >> menuChoice;

          if (menuChoice == 1)                          // Create Vehicle,
          {                                             // store it in the garage
             Vehicle car1;
             garage.push_back(car1);
          }
          else if (menuChoice == 2)                     // Print vehicles in garage
          {
             cout << "\nYour garage contains:" << endl;

             for (int i = 0; i < garage.size(); i++)
             {
                 cout << i + 1 << ". ";
                 garage[i].PrintShortList();
             }

             cout << "Do you want to see more details?" << endl;
             cout << "Enter a car number, or 0 to view entire collection: ";
             cin  >> details;

             if (details == 0)
             {
                 for (int i = 0; i < garage.size(); i++)
                    garage[i].PrintVehicle();
             }
             else
                 garage[--details].PrintVehicle();
          }
          else                                           // Exit program
          {
              cout << "\nExiting..." << endl;
          }

       } while (menuChoice != 3);

       cout << "            ____       " << endl;
       cout << "         __/  |_\\_     " << endl;
       cout << "- - - - |  _     _``-. " << endl;
       cout << "        '-(_)---(_)--' " << endl;

       // ASCII art courtesy of Max Strandberg
       // https://www.asciiart.eu/vehicles/cars

        return 0;
   }
