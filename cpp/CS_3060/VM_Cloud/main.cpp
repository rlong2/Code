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

enum TimeZone{
    NO_TZ,
    PACIFIC,
    MOUNTAIN,
    CENTRAL,
    EASTERN,
    MAX_TZ
};

// Function prototype
void currentUsage(TimeZone tz, double costPerHour);

float mapPercentage[]{
    .5, .75, 1, .75, .5
};

int TotalMonies(int initialUsers, int direction, int currTime, TimeZone currentZone){
    //if(currTime <= 5 || currTime >= 11 || currentZone >= MAX_TZ || currentZone <= NO_TZ) return 0;
    
    if(currentZone >= MAX_TZ || currentZone <= NO_TZ) // base case
        return 0;
        
    int ret = mapPercentage[currTime - 6] * initialUsers;
    
    //direction = 0: both ways
    //direction = 1: left
    //direction = 2: right
    switch(direction){
        case 0:
            ret += TotalMonies(initialUsers, 1, currTime - 1, (TimeZone)(currentZone - 1));
            ret += TotalMonies(initialUsers, 2, currTime + 1, (TimeZone)(currentZone + 1));
            return ret;
        case 1:
            ret += TotalMonies(initialUsers, 1, currTime - 1, (TimeZone)(currentZone - 1));
            return ret;
        case 2:
            ret += TotalMonies(initialUsers, 2, currTime + 1, (TimeZone)(currentZone + 1));
            return ret;
        default:
            break;
    }
    
    return ret;
}

int main()
{
    TimeZone tz;
    double costPerHour;

    cout << "This program calculates VM stuff." << endl;

    cout << "Assume it is 8PM local time." << endl;
    cout << "Enter the time zone you're in:" << endl;
    cout << "1) Pacific" << endl;
    cout << "2) Mountain" << endl;
    cout << "3) Central" << endl;
    cout << "4) Eastern" << endl;
    cout << "Enter 1, 2, 3, or 4: ";
    
    int tmp;
    cin >> tmp;
    tz = (TimeZone)tmp;

    cout << "\nEnter the cost of VM per hour. Ex, .10): ";
    cin  >> costPerHour;

    int totalUsers = TotalMonies(500000, 0, 8, tz);
    std:cout << totalUsers << "\n";
    // currentUsage(tz, costPerHour);

    return 0;
}

// Function implementation
void currentUsage(TimeZone tz, double costPerHour)
{
    const int PEAK = 500000;                      // Peak number of users at 8PM
    const double REDUCTION = 0.75;               // At 7 and 9 PM, reduce load by 25%
    const int  VM_CAPACITY = 150;
    int totalVms;
    int users;
    double totalCost;

    if (tz == PACIFIC || tz == MOUNTAIN)
        cout << "\nYou are connected to the West datacenter." << endl;
    else
        cout << "\nYou are connected to the East datacenter." << endl;


    // Get one time zone cost
    users =  PEAK;            // 8PM

    if (tz - 1 <= NO_TZ)
    {
        cout << "I'm in pacific" << endl;
        users += PEAK * REDUCTION;        // Accounts for C time at 9PM
    }
    
    
    else if (tz + 1 >= MAX_TZ)
    {
        cout << "I'm in eastern" << endl;
    }
    
    // Add users in other time zones
    users += PEAK * REDUCTION;

    totalVms = users / VM_CAPACITY;
    totalCost = totalVms * costPerHour;

    cout << "\ntotal users in time zone: " << users << endl;
    cout << "Total VMs needed: " << totalVms << endl;
    cout << "Total cost is $" << totalCost << endl;


}
