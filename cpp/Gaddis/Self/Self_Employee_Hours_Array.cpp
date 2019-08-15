// This program uses an array to store worker's hours and calculate their total pay

#include <iostream>
using namespace std;

int main()
{
    double totalPay;
    double hourlyRate;
    const int NUM_WORKERS = 5;
    int hours[NUM_WORKERS];
    
    // Input hours worked by each employee
    cout << "Enter employee hours here:" << endl;
    for (int i = 0; i < NUM_WORKERS; i++)
    {
        cout << "Employee #" << (i + 1) << ": ";
        cin >> hours[i];
    }
    
    // Get hourly rate:
    cout << "\nEvery employee make the same amount." << endl;
    cout << "Input their hourly pay rate: ";
    cin >> hourlyRate;
    
    // Display how much the employees made in total
    cout << "\nHere is each employee's total pay:"<< endl;
    for (int i = 0; i < NUM_WORKERS; i++)
    {
        totalPay = hours[i] * hourlyRate;
        cout << "Employee #" << (i + 1) << ": $" << totalPay << endl;
    }
    
    return 0;
}
