/* This program calculates gross pay for trainees.
 * Trainees are paid $22.55/hr. 
 * If a trainee exceeds 40 hours, the remaining hours get a 1.5x bonus
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Global constants
const double PAY_RATE = 22.55;    // hourly pay rate
const double BASE_HOURS = 40.0;   // max non-overtime hours
const double OT_MULTIPLIER = 1.5; // overtime multiplier

// Function Prototypes
double GetBasePay(double);
double GetOvertimePay(double);

int main()
{
    double hours,
	   basePay,
	   overtimePay = 0.0,
	   totalPay;

    cout << "How many hours did you work? ";
    cin >> hours;
    
    basePay = GetBasePay(hours);
    
    if (hours > 40)
    {
        overtimePay = GetOvertimePay(hours);
    } else {
	    overtimePay = 0.0;
    }
    
    // Calculate total pay
    totalPay = basePay + overtimePay;

    // Display
    cout << setprecision(2) << fixed << showpoint;
    cout << "Base Pay:     $" << setw(7) <<     basePay  << endl;
    cout << "Overtime Pay: $" << setw(7) << overtimePay  << endl;
    cout << "Total pay:    $" << setw(7) <<    totalPay  << endl;   

    return 0;
}


double GetBasePay(double hoursWorked)
{
    double basePay;

    if (hoursWorked > 40)
    {
        basePay = PAY_RATE * BASE_HOURS;
    } else {
	    basePay = PAY_RATE * hoursWorked;
    }

    return basePay;
}

double GetOvertimePay(double hoursWorked)
{
   double overtimePay;
   overtimePay  = (hoursWorked - BASE_HOURS) * PAY_RATE * OT_MULTIPLIER;

   return overtimePay; 
}
