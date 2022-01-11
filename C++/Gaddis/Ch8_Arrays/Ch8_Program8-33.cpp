// This program uses an array of structs
// A default constructor ensures a struct
// is created even if no values are passed

#include <iostream>
#include <iomanip>
using namespace std;

struct PayInfo
{
    int hours;
    double payRate;
    
    PayInfo(int h = 0, double p = 0.0)  // Constructor
    {
        hours = h;
        payRate = p;
    }
};

int main()
{
    const int NUM_EMPS = 3;
    PayInfo workers[NUM_EMPS];    // Define an array of PayInfo structs
    double grossPay;
    
    // Get payroll data
    cout <<"Enter the hours worked and hourly pay rates of "
         << NUM_EMPS << " employees.\n";
         
    for (int i = 0; i < NUM_EMPS; i++)
    {
        cout << "\nHours worked by employee #" << (i + 1) << ": ";
        cin  >> workers[i].hours;
        cout << "Hourly pay rate for this employee: $";
        cin  >> workers[i].payRate;
    } 
    
    // Display each employee's gross pay
    cout << "\nHere is the gross pay for each employee:\n";
    cout << fixed << showpoint << setprecision(2);
    
    for (int i = 0; i < NUM_EMPS; i++)
    {
        grossPay = workers[i].hours * workers[i].payRate;
        cout << "Employee #" << (i + 1);
        cout << ": $" << setw(7) << grossPay << endl;
    }
    
    return 0;
}
