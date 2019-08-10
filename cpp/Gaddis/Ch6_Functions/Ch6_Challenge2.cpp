/* This program asks the user to enter a temperature in fahrenheight
* and the value is converted to celcius. The program also displays
* a Fahrenheight/Celcius temperature table.
* Recall C = (5/9.0)*(F - 32)
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype
double Convert(double fahrenheight);

int main()
{
    double userFah,
           celcius;
           
    cout << "Enter a temperature in fahrenheight: ";
    cin >> userFah;
    
    celcius = Convert(userFah);
    
    // Display user-prodided conversion
    cout << setprecision(1) << fixed;
    cout << userFah << " F is " << celcius << " C\n" << endl;
 
    // Display table of data showing conversions from 0F to 20F
    for (int i = 0; i <= 20; i++)
    {
        cout << i << " F is " << Convert(i) << " C" << endl;
    }
    return 0;
}

double Convert(double fahrenheight)
{
    double formula = ((5/9.0) * (fahrenheight - 32.0));
    return formula;
}
