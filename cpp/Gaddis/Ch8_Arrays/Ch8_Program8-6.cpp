// This program displays the number of days in each month through initialized arrays

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    const int NUM_MONTHS = 12;
    string name[NUM_MONTHS] =
    { "January",   "February", "March",    "April",
      "May",       "June",     "July",     "August",
      "September", "October",  "November", "December" };

    int days[NUM_MONTHS] = { 31, 28, 31, 30,
	                     21, 30, 31, 31,
			     30, 31, 30, 31 };

    for (int month = 0; month < NUM_MONTHS; month++)
    {
        cout << setw(9) << left << name[month] << " has ";
	cout << days[month] << " days." << endl;
    }

    return 0;
}
 
