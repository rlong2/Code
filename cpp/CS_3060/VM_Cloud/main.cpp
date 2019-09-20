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
#include <iomanip>
#include <math.h>     // for rounding up number of users from a decimal
using namespace std;

enum TimeZone
{
    NO_TZ,
    PACIFIC,
    MOUNTAIN,
    CENTRAL,
    EASTERN,
    MAX_TZ
};

enum Direction { BOTH, LEFT, RIGHT };

float mapPercentage[]{ .5, .75, 1, .75, .5 };        // used to reduce number of users in adjacent time zones

int TotalUsers(int initialUsers, Direction direction, int currTime, TimeZone currentZone){
    
    if(currentZone >= MAX_TZ || currentZone <= NO_TZ) // base case
        return 0;
        
    int ret = mapPercentage[currTime - 6] * initialUsers;
    
    switch(direction)
    {
        case Direction::BOTH:
            ret += TotalUsers(initialUsers, Direction::LEFT, currTime - 1, (TimeZone)(currentZone - 1));
            ret += TotalUsers(initialUsers, Direction::RIGHT, currTime + 1, (TimeZone)(currentZone + 1));
            return ret;
        case Direction::LEFT:
            ret += TotalUsers(initialUsers, Direction::LEFT, currTime - 1, (TimeZone)(currentZone - 1));
            return ret;
        case Direction::RIGHT:
            ret += TotalUsers(initialUsers, Direction::RIGHT, currTime + 1, (TimeZone)(currentZone + 1));
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
    const int  VM_CAPACITY = 150;

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

    int users = TotalUsers(500000, Direction::BOTH, 8, tz);
    
    int totalVms = ceil(users / (float)VM_CAPACITY);
    float totalCost = totalVms * costPerHour;

    cout << "\ntotal users in time zone: " << users << endl;
    cout << "Total VMs needed: " << totalVms << endl;
    cout << fixed << setprecision(2);
    cout << "Total cost is $" << totalCost << endl;

    return 0;
}
