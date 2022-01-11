/* 
 *  Prompt the user to enter the size of the hard drive specified
 *  by the manufacturer, on the hard drive box.
 *  Output the actual storage capacity of the hard drive.
 *  Ex, 40 GB is really 37.25 GB
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{
    long givenSize;           // How much space the box says you get
    long double actualSize;   // Holds how much space you really get
    
    // Get user input
    cout << "Enter the size of HD specified by the manufacturer (in GB): ";
    cin  >> givenSize;
    
    // Convert GB to kB, divide by 1024^3
    actualSize = (givenSize * 1000000000) / pow(1024, 3);
    
    // Output result to 2 decimal places
    cout << fixed << setprecision(2) << endl;
    cout << "The actual HD size is " << (double)actualSize << " GB." << endl;
    return 0;
}
