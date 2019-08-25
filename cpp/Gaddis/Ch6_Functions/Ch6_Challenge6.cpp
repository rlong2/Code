/* Write a program that asks for the weight of a package and the distance it is to be shipped.
 * The info is passed to CalculateCharge function that computes and returns the  
 * shipping charge to be displayed. The main function should loop to handle 
 * multiple packages until a weight of 0 is entered.
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Global variable
int SHIPPING_MILAGE_INCREMENT = 500; // Rate increases every 500 miles

// Function prototype
double CalculateCharge(double weight, double distance);

int main()
{
    
    double userWeight = 1;
    double userDistance;

    cout << fixed << setprecision(2);
    cout << "Welcome to Puckerbutt Shipping Company. Here are our rates:" << endl;
    cout << "\nWeight of Package (in kilograms)    Rate per 500 Miles Shipped" << endl;
    cout << "2 kg or less                          $3.10" << endl;
    cout << "Over 2 kg but not more than 6 kg      $4.20" << endl;
    cout << "Over 6 kg but not more than 10 kg     $5.30" << endl;
    cout << "Over 10 kg                            $6.40" << endl;

    cout << "\nIf you enter a weight of 0, the program will end." << endl;

    while (userWeight > 0)
    {
        cout << "\nEnter the weight of the package: ";
        cin  >> userWeight;

        // If user wishes to exit program
        if (userWeight == 0)
        {   
            break;
        }

        cout << "Enter the distance to be shipped: ";
    	cin  >> userDistance;
    
        double rate = CalculateCharge(userWeight, userDistance);
	cout << "The shipping rate is $" << rate << endl;
    }

    
    
    cout << "\nThank you for using our shipping calculator. Goodbye!" << endl;

    return 0;

}

// Function Implementation
double CalculateCharge(double weight, double distance)
{
    double rate;
    int shippingIncrement = 1;

    if (weight <= 2)
        rate = 3.10;
    else if (weight > 2 && weight <= 6)
	rate = 4.20;
    else if (weight > 6 && weight <= 10)
        rate = 5.30;
    else
        rate = 6.40;

    // Get the milage increments of 500
    while (distance - SHIPPING_MILAGE_INCREMENT > 0)
        {
	    distance = distance - SHIPPING_MILAGE_INCREMENT;
	    shippingIncrement++;
        }

    rate = rate * shippingIncrement;

    return rate;

}
