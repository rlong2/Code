/*
 * Kathryn bought 750 shares oof stock at $35/share. 
 * A year later she sold them for just $31.15/share.
 * Write a program that displays:
 *     The total amount paid for the stock
 *     The total amount received from selling the stock
 *     The total amount of money she lost
 */

#include <iostream>

using namespace std;

int main()
{
    int shares = 750;
    double initialPrice = 35.00;
    double finalPrice = 31.15;

    double paid = shares * initialPrice;
    double made = shares * finalPrice;
    double lost = paid - made;

    cout << "Kathryn paid $" << paid << " for the stock." << endl;
    cout << "She received $" << made << " for selling the stock." << endl;
    cout << "She lost $" << lost << " in total." << endl;

    return 0;
}
