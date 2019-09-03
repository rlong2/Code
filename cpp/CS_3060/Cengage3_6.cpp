/*Write a program that accepts as input the mass, in grams, and density, 
in grams per cubic centimeters, and outputs the volume of the object 
using the formula: volume = mass / density.
Format your output to two decimal places.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    double mass,
           density,
           volume;
    
    // Get user input
    cout << "Enter the object's mass (in grams): ";
    cin  >> mass;
    cout << "\nEnter the object's density (in grams per cubic centimeter): ";
    cin  >> density;
    
    volume = mass / density;
    
    // Output volume to 2 decimal places
    cout << fixed << setprecision(2) << endl;
    cout << "The object's volume is " << volume << " cm^3" << endl;
    
    return 0;
}
