/* Write a program that usees a loop to display the characters for each ASCII code
* 32 through 127. Display 16 characters on each line with one space between characters.
*
* https://www.includehelp.com/tips/cpp/print-character-through-ascii-value-using-cout.aspx
*/

#include <iostream>
using namespace std;

int main()
{
    int formatter = 0;          // variable to track how many chars are printed
    
    cout << "Printing ASCII characters 32 through 127..." << endl;
    for (int i = 32; i <= 127; i++)
    {
        cout << (char)i << " ";
        formatter++;
        
        if (formatter == 16 ||  // Make a new line every 16 characters
            formatter == 32 ||
            formatter == 48 ||
            formatter == 64 ||
            formatter == 80)
            cout << endl;
    }
    return 0;
}
