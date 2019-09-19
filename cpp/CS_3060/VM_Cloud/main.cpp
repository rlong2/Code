/*
  Each VM can host 150 users at a time.
  Depending on location, users connect to a West or East datacenter.
  Users in Pacific and Mountain timezones connect to West datacenter.
  Users in Central and Eastern timezone connect to East datacenter.

  Peak usage: 500k users in each time zone at 8 pm local
  with a 25% reduction in users at the hour before and after 8 pm.
  Assume ZERO users for any other time of day.

  Write a program that allows the user to enter the time zone at 8 pm
  and calculate how many cloud instances are needed to handle the current
  workload in each datacenter AND what the total cost per hour is.
  Defaul cost is $0.10 per hour, but user can change that.

  The program should use at least one function, example: currentUsage(TZ, hourlyCost);

  Output the amount of users in each time zone and the current operational
  cost per hour in each of the two data centers.

  Example: user chooses Central time and leaves the cost at a default $0.10
  an hour per instance. This would mean there are 375k active users in Eastern time zone,
  500k in Central, 375k in Mountain, 250k in Pacific.
*/

#include <iostream>

using namespace std;

int main()
{
    int tz;
    double costPerHour;

    cout << "This program calculates VM stuff." << endl;

    cout << "\nEnter the time zone you're in at 8 PM:" << endl;
    cout << "1) Pacific" << endl;
    cout << "2) Mountain" << endl;
    cout << "3) Central" << endl;
    cout << "4) Eastern" << endl;
    cout << "Enter 1, 2, 3, or 4: " << endl;
    cin  >> tz;

    if (tz == 1 || tz == 2)
        cout << "You are connected to the West datacenter." << endl;
    else
        cout << "You are connected to the East datacenter." << endl;

    cout << "\nEnter the cost of VM per hour. Ex, .10): ";
    cin  >> costPerHour;




    return 0;
}
