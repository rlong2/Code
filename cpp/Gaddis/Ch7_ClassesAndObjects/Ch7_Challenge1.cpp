// This program shows how an overloaded constructor is used.
// Help on overloaded constructors from https://www.geeksforgeeks.org/constructor-overloading-c/

#include <iostream>
using namespace std;

class Date
{
    private:
        int day; 
        int month;
        int year;
        
    public:
       Date();                     // Constructor prototype with 0 parameters
       Date(int d, int m, int y);  // Constructor prototype with 3 parameters
       
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
}

Date::Date(int d, int m, int y)
{
    day = d; 
    month = m;
    year = y;
}

void Date::Display()
{
cout << endl;
    cout << "Your formatted date:" << endl;
    cout << month << "/" << day << "/" << year << endl;   
    
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
    }
    
    cout << monStr << " " << day << ", " << year << endl;
    cout << day << " " << monStr << " " << year << endl;
}

int main()
{
    Date obj1;
    Date obj2(11, 20, 1981);
    
    obj1.Display();
    obj2.Display();

    return 0;
}
