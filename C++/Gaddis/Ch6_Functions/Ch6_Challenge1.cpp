/* This program asks the user to enter an item's wholesale cost 
* and its markup percentage. It then displays the item's retail price.
* Example: If wholesale cost is $5.00 with 100% markup, retail price is $10.00.
* Example: If wholesale cost is $5.00 with 50% markup, retail price is $7.50.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype
double CalculateRetail(double wholesaleCost, double markup);

int main()
{
    double wholesaleInput,
           markupInput,
           retailPrice;
           
    cout << "Enter the item's wholesale cost: ";
    cin >> wholesaleInput;
    
    cout << "Etner the item's markup percentage. (Ie, .5 for 50%): ";
    cin >> markupInput;
    
    retailPrice = CalculateRetail(wholesaleInput, markupInput);
    
    // Display output formatted to 2 decimal places
    cout << setprecision(2) << fixed << endl;
    cout << "Retail price is: $" << retailPrice << endl;
    
    return 0;
}

double CalculateRetail(double wholesaleCost, double markup)
{
    double retail;
    retail = wholesaleCost + (wholesaleCost * markup);
    return retail;
}
