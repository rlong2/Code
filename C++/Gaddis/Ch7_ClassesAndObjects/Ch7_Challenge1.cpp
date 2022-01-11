/* This program shows how an overloaded constructor is used.
* Challenge: Design a class called Date that has integer data members to store day, month, and year.
* The class should have a three-parameter default constructor that allows the date to be
* set at the time a new Date object is created. If the user creates a Date object without arguments,
* or if any of the dates are invalid, the defaultvalues of 1, 1, 2001 should be used.
* The class should have member functions to print the date as so: 3/15/16, March 15, 2016, 15 March 2016.
*
* Help on overloaded constructors from https://www.geeksforgeeks.org/constructor-overloading-c/
*/

#include <iostream>
#include<iomanip>
using namespace std;

class Date
{
    private:
        int day; 
        int month;
        int year;
        
    public:
       Date(int d, int m, int y);  // Constructor prototype with 3 parameters
       Date();                     // Constructor prototype with 0 parameters
       
       int GetDay();
       int GetMonth();
       int GetYear();
       
       void Display();
};

/* Date implementation */

// Getters
int Date::GetDay()
{ return day; }

int Date::GetMonth()
{ return month; }

int Date::GetYear()
{ return year; } 

Date::Date()                   // If no parameters are supplied, default 1/1/2001
{
    day = 1;
    month = 1;
    year = 2001;
    
    cout << "Default Date data collected." << endl;
}

Date::Date(int d, int m, int y)
{
    /* Error Checking */
    if ((m > 12 || m < 1) || (d < 1 || d > 31) || (y < 0)
         || (m == 2 && d > 28)
         || (m == 4 && d > 30)      // Checking month
         || (m == 6 && d > 30)      // and date accuracy
         || (m == 9 && d > 30)      // (Feb, April, June,
         || (m == 11 && d > 30))    // Sept, and Nov)
    {
        day = 1;
        month = 1;
        year = 2001;
        
    } else {
        day = d; 
        month = m;
        year = y;
    }
}

void Date::Display()
{
cout << endl;
    cout << "Your formatted date:" << endl;
    
    // Convert month int to a string, i.e. 3 becomes "March"
    string monStr;
    switch (month)
    {
        case 1:
            monStr = "January";
            break;
        case 2:
            monStr = "February";
            break;
        case 3:
            monStr = "March";
            break;
        case 4:
            monStr = "April";
            break;
        case 5:
            monStr = "May";
            break;
        case 6:
            monStr = "June";
            break;
        case 7:
            monStr = "July";
            break;
        case 8:
            monStr = "August";
            break;
        case 9:
            monStr = "September";
            break;
        case 10:
            monStr = "October";
            break;
        case 11:
            monStr = "November";
            break;
        case 12:
            monStr = "December";
            break;
        default: monStr = "Check month input";
            break;
    }
    
    // Display Dates
    int shortYear = year - year / 100 * 100;  // Trunucate a year to 2 digits
    cout << month << "/" << day << "/" << setw(2) << setfill('0') << shortYear << endl;   
    cout << monStr << " " << day << ", " << year << endl;
    cout << day << " " << monStr << " " << year << endl;
}

int main()
{
    // When creating object with parameters, use (day, month, year) formatting
    Date obj1;
    Date obj2(20, 11, 1981);
    Date obj3(28, 2, 2008);
    
    obj1.Display();
    obj2.Display();
    obj3.Display();

    return 0;
}
