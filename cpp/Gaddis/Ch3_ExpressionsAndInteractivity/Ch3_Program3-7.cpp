// This program uses a type cast to avoid integer division

#include <iostream>

using namespace std;

int main()
{
    int books;
    int months;
    double booksPerMonth;

    // Get user inputs
    cout << "How many books do you plan to read? ";
    cin >> books;

    cout << "How many months will it take you to read them? ";
    cin >> months;

    // Compute and display books read per month
    // booksPerMonth = books / months; // outputs an integer! Not what we want.

    booksPerMonth = static_cast<double>(books) / months; // casts int books to a double

    cout << "That is " << booksPerMonth << " books per month." << endl;

    return 0;
}
