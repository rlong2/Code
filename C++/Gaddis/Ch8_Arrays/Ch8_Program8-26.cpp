/* This program stores employee hours worked and hourly pay rates
 * in two vectors. It deomstrates the use of the push_back member
 * function to add new elements to the vectors.
 */

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main()
{
    vector<int> hours;        // hours is an empty integer vector
    vector<double> payRate;    // payRate is an empty double vector
    
    double grossPay;
    int numEmployees;

    // Get number of employees
    cout << "How many employees do you have? ";
    cin  >> numEmployees;

    // Input the payroll data
    cout << "Enter the hours worked and hourly pay rates of the " 
	 << numEmployees << " employees.\n";
    
    for (int i = 0; i < numEmployees; i++)
    {
        int tempHours;         // Number of hours entered
	double tempRate;       // Pay rate entered

	cout << "Hours worked by employee #" << (i + 1) << ": ";
	cin  >> tempHours;
	hours.push_back(tempHours);    // Add an element to hours vector

	cout << "Hourly pay rate for employee #" << (i + 1) << ": ";
	cin  >> tempRate;
	payRate.push_back(tempRate);   // Add an element to payRate vector
    }

    // Display each employee's gross pay
    cout << "\nHere is the gross pay for each employee:\n";
    cout << fixed << showpoint << setprecision(2);

    for (int i = 0; i < numEmployees; i++)
    {
        grossPay = hours[i] * payRate[i];
	cout << "Employee #" << (i + 1);
	cout << ": $" << setw(7) << grossPay << endl;
    }

    return 0;
}
