/* This program lets the user choose between 5 functions:
* 1. Convert F to C
* 2. Calculate the volume of a sphere
* 3. Print all values <= n that are multiples of 3 or 5
* 4. Check if a string is a palindrome
* 5. Exit the program
*/
#include <iostream>
#include <iomanip>
#include<string>
#include<cmath>
using namespace std;

// Function prototypes
void ConvertTemp();
void VolumeOfSphere();
void PrintValues();
void CheckPalindrome();

int main()
{
    int userChoice;
    cout << setprecision(2) << fixed;

    do
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Enter the following to perform an action." << endl;
        cout << "1. Convert Fahrenheight to Celsius" << endl;
        cout << "2. Calculate the volume of a sphere" << endl;
        cout << "3. Print all values <= n that are multiples of 3 or 5" << endl;
        cout << "4. Check if a string is a palindrome" << endl;
        cout << "5. Exit Program" << endl;
        cout << "--------------------------------------------------------" << endl;

        cout << "Please enter an input: ";
        cin >> userChoice;

        cout << endl;

        switch (userChoice)
        {
        case 1:
            ConvertTemp();
            break;
        case 2:
            VolumeOfSphere();
            break;
        case 3: PrintValues();
            break;
        case 4: CheckPalindrome();
            break;
        case 5:
            break;
        default:
            cout << "Invalid input" << endl;

        }

    } while (userChoice != 5);

    // User selects 5
    cout << "Thank you for using the program. Have a nice day!" << endl;

    return 0;
}

// Function Implementations
void ConvertTemp()
{
    double fah,
           cel;

    cout << "Please enter a value for fahrenheight: ";
    cin >> fah;

    cel = (5/9.0) * (fah - 32);

    cout << "\n" << fah << " fahrenheight is " << cel << " celcius\n" << endl;
}

void VolumeOfSphere()
{
    double radius,
           volume;

    cout << "Please enter the radius of your sphere: ";
    cin >> radius;

    volume = (4/3.0) * 3.14159 * pow(radius, 3);

    cout << "Your sphere's volume is " << volume << endl << endl;
}

void PrintValues()
{
    int number;
    cout << "Please enter a maximum value (integer) to check for multiples: ";
    cin >> number;

    cout << "Printing multiples of 3 or 5:" << endl;

    for (int i = 0; i <= number; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            cout << i << endl;
        }
    }

    cout << endl;
}
void CheckPalindrome()
{
    bool isPalindrome;
    string userString;
    int stringLength;

    cout << "Please enter a string to see if it is a palindrome: ";
    cin.ignore();
    getline(cin, userString);

    stringLength = userString.length();

    for (int i = 0; i < stringLength; i++)
    {
        if (userString[i] != userString[stringLength -i -1])
        {
            isPalindrome = false;
            break;
        } else {
            isPalindrome = true;
        }
    }

    if (isPalindrome)
    {
        cout << userString << " is a palindrome." << endl;
    } else {
        cout << userString << " is not a palindrome." << endl;
    }

    cout << endl;
}


