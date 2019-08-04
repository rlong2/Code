/* Green fields Landscaping Case Study - Part 1
 *
 * This program will determine the number of cubic yards of mulch the customer needs and the total price.
 * Program Steps
 *   1. Set the price for a cubic yard of mulch (currently 22.00)
 *   2. Ask user to input number of square feet to be covered
 *   3. Calculate number of cubic feet of mulch needed
 *   4. Calculate number of cubic yards of mulch needed
 *   5. Calculate the total price for the mulch
 *   6. Display results
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double squareFeet;      // square feet of land to be covered
    int depth;              // how many inches deep the mulch is spread

    double cubicYards;      // number of cubic yards of mulch needed
    double cubicFeet;       // number of cubic feet of mulch needed
    double totalPrice;      // total price for mulch

    double PRICE_PER_CUBIC_YARD = 22.00;

    // Get Inputs
    cout << "Grettings from Green Fields Landscaping Company!" << endl;
    cout << "Please enter the number of square feet to be covered: ";
    cin >> squareFeet;

    cout << "Please enter how deep (in inches) you need the mulch to be: ";
    cin >> depth;

    // Calculate
    cubicFeet = squareFeet * (depth / 12.0);
    cubicYards = cubicFeet / 27.0;
    totalPrice = cubicYards * PRICE_PER_CUBIC_YARD;

    // Display outputs
    cout << "\nNumber of cubic yards needed: " << cubicYards << endl;
    cout << "Price per cubic yard: $" << PRICE_PER_CUBIC_YARD << endl;
    cout << "Total Price: $" << totalPrice << endl;


    return 0;
}
