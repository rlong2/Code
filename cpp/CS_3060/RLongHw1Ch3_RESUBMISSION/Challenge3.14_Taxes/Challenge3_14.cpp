/* Author: Ryan Long
 * Class: CS 3060
 * Date: August 28, 2019 
 *
 * Instructions: Write a program that asks for the month, year, and total amount 
 * collected at a cash register (sales plus sales tax).
 * Assume state sales tax is 4% and county sales tax is 2%.
 *
 * Ex: Total amount known, and sales tax = 6%, Sales S = T/1.06 where T is total income (sales + sales tax)
 */

#include <iostream>
using namespace std;

// Global variables
const double stateTax  = 0.04;
const double countyTax = 0.02;
const double totalTax  = 1.06;

int main()
{
    string month;
    int year;
    double totalCollected;
    double sales;
    double countySalesTax;
    double stateSalesTax;
    double totalSalesTax;

    // Get user input
    cout << "Welcome to your tax report generator!" << endl;
    cout << "Enter the month: ";
    cin  >> month;
    cout << "Enter the year: ";
    cin  >> year;
    cout << "How much did you collect at the register? $";
    cin  >> totalCollected;

    // Calculate taxes
    sales = totalCollected / totalTax;
    countySalesTax = totalCollected * countyTax;
    stateSalesTax  = totalCollected * stateTax;
    totalSalesTax  = stateSalesTax + countySalesTax;

    // Display report
    cout << "\n" <<  month << " " << year << endl;
    cout << "---------------------" << endl;
    cout << "Total collected:  $" << totalCollected << endl;
    cout << "Sales:            $" << sales << endl;
    cout << "County Sales Tax: $" << countySalesTax << endl;
    cout << "State Sales Tax:  $" << stateSalesTax << endl;
    cout << "Total Sales Tax:  $" << totalSalesTax << endl;

}

