// This program has a class called 'Date' that stores month, day, and year.
// The class has a three-parameter default constructor.
// If the user creates a Date object w/o passing any arguments, 
// use default values Jan 1, 2001.
// The class should have member functions to print the date in these formats:
// 3/15/16, March 15, 2016, and 15 March 2016.

#include <iostream>
using namespace std;

class Date
{
    private:
        int day,
            month,
            year;
    public:
        Date(int d, int m, int y);   // constructor prototype with 3 parameters
        
        int GetDay()                 // Getters to access private variables
        { return day; }
        
        int GetMonth()
        { return month; }
        
        int GetYear()
        { return year; }
    
    void DisplayDate(int d, int m, int y);
};

// Date Implementation 
Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

// Date function Implementation
void Date::DisplayDate(int d, int m, int y)
{
    cout << endl;
    cout << "Your formatted date:" << endl;
    cout << m << "/" << d << "/" << y << endl;   
    
    string monStr;
    switch (m)
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
    }
    
    cout << monStr << " " << d << ", " << y << endl;
    cout << d << " " << monStr << " " << y << endl;
}

int main()
{
    int day,
        month,
        year;
    
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year: ";
    cin >> year;
    
    Date myDate(day, month, year);     // create Date object with user-provided data
    myDate.DisplayDate(day, month, year);
    return 0;
}
