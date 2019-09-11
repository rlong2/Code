/*
 * If the number of hotel rooms is at least 10, the discount is 10%
 *                                 at least 20, 20%.
 *                                 at least 30, 30%.
 *If rooms are booked for at least 3 days, there is an additional 5% discount.
 *
 * Write a program that prompts the user to enter the cost of renting one room,
 * the number of rooms booked, the number of days the rooms are booked, and the sales tax.
 *
 * The program outputs the cost of renting one room, the discount on each room as a percent,
 * the number of rooms booked, the number of days the rooms are booked, the total cost of the rooms,
 * the sales tax, and the total billing amount.
 *
 * Use appropriately named constants to store special values such as various discounts.
 */

#include <iostream>
using namespace std;

int main()
{

    const int FIVE_OFF   = 0.05,
	      TEN_OFF    = 0.10,
	      TWENTY_OFF = 0.20,
	      THIRTY_OFF = 0.30;

    double oneRoomCost,  // Cost of one room
	   salesTax, // Sales Tax
           multipleRoomCost, 
           discount = 1,
           totalCost;

    int roomsBooked;  // Number of rooms booked
    int daysRoomsBooked; // the number of days the rooms are booked for

    cout << "Enter the cost of renting one room: $";
    cin  >> oneRoomCost;

    cout << "Enter the number of rooms booked: ";
    cin  >> roomsBooked;

    cout << "Enter the number of days the rooms are booked for: ";
    cin  >> daysRoomsBooked;

    cout << "Enter the sales tax as a decimal: ";
    cin  >> salesTax;

    // Find applicable discounts
    if (roomsBooked < 10)
        cout << "less than 10 rooms booked, no discount" << endl;
    else if (roomsBooked >= 10 && roomsBooked < 20)
        discount = TEN_OFF;
    else if (roomsBooked >= 20 && roomsBooked < 30)
        discount = TWENTY_OFF; 
    else if (roomsBooked >= 30)
        discount = THIRTY_OFF;
    
    if (daysRoomsBooked >= 3)
        discount = discount + FIVE_OFF;    
    
    // Calculate total cost of rooms
    totalCost = oneRoomCost * roomsBooked * discount;
    double totalCostWithTax = totalCost + (totalCost * salesTax);

    // Output data
    cout << "\n\nThe cost of renting one room is $" << oneRoomCost << endl;
    cout << "The discount on each room is " << discount * 100 <<"%" << endl;
    cout << "The number of rooms booked is " << roomsBooked << endl;
    cout << "The total cost of the rooms is $" << totalCost << endl;
    cout << "The sales tax is " << salesTax;
    cout << "The total billing amount is $" << totalCostWithTax << endl;


    return 0;
}
