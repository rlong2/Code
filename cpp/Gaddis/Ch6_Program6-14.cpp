// This program uses functions to calculate health club membership fees

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function Prototypes
void DisplayMenu();
int GetChoice();
void ShowFees(string category, double rate, int months);

int main()
{
    // constants for monthly membership rates
    const double ADULT_RATE = 120.0,
                 CHILD_RATE = 60.0,
                 SENIOR_RATE = 100.0;
    
    int choice,    // Hold user's menu choice 
        months;    // Number of months being paid
        
    // Set cout formatting
    cout << fixed << showpoint << setprecision(2);
    
    do 
    {    
        DisplayMenu();
        choice = GetChoice();
        if (choice != 4) // if user does not want to exit
        {
            cout << "How many months do you want to pay for? ";
            cin >> months;
            
            switch (choice)
            {
                case 1: ShowFees("Adult", ADULT_RATE, months);
                        break;
                case 2: ShowFees("Child", CHILD_RATE, months);
                        break;
                case 3: ShowFees("Senior", SENIOR_RATE, months);
                        break;
            } 
        }
    } while (choice != 4);
    
    return 0;
}

void DisplayMenu()
{
    cout << "\n Health Club Membership Menu" << endl << endl;
    cout << "1. Standard Adult Membership" << endl;
    cout << "2. Child Membership" << endl;
    cout << "3. Senior Citizen Membership" << endl;
    cout << "4. Exit Program"  << endl;
}

int GetChoice()
{
    int userChoice;
    cout << "\nEnter your choice: ";
    cin >> userChoice;
    
    // Check for valid input
    while (userChoice > 4 || userChoice < 1)
    {
        cout << "Please enter a valid choice: ";
        cin >> userChoice;
    }
    return userChoice;
}

void ShowFees(string memberType, double rate, int months)
{
    cout << endl
         << "Membership Type: " << memberType << "    "
         << "Number of Months: " << months << "    "
         << "Total Charges: $" << (rate * months) << endl;
}
