// Calculate a user's pay
// 2 decimal places: https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double hours;
    double rate;
    double pay;
    
    cout << "How many hours did you work?" << endl;
    hours = 0;
    cin >> hours;
    
    cout << "How much do you make per hour? Just input a number" << endl;
    rate = 0;
    cin >> rate;
    
    pay = hours * rate;
    
    cout << "You made $" << setprecision(2) << fixed << pay << endl; 

    return 0;
}
