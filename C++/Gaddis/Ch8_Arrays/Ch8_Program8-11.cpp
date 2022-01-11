// This program uses an array to store the hours worked by
// a set of employees who all make the same hourly wage.

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
   const int NUM_WORKERS = 5;   // Set the number of employees
   int hours[NUM_WORKERS];      // Array to hold employee's hours
   double payRate;              // Hourly pay rate for employees
   double grossPay;             // An employee's gross pay
         
    // Input hours into the array
    cout << "Enter the hours worked by ";
    for (int i = 0; i < NUM_WORKERS; i++)
    {
        cout << "Employee #" << (i + 1) << ": ";
        cin >> hours[i];
    }
    
    // Get hourly pay rate
    cout << "\nAll the employees have the same pay rate." << endl;
    cout << "Enter the pay rate: $";
    cin >> payRate;
    
    // Display each employee's gross pay
    cout << "\nHere is the gross pay for each employee:" << endl;
    
    cout << fixed << showpoint << setprecision(2);
    
    for (int i = 0; i < NUM_WORKERS; i++)
    {
        grossPay = hours[i] * payRate;
        cout << "Employee #" << (i + 1) << ": $" << setw(7) << grossPay << endl;
    }
    
    return 0;
}
