/* Write a program that lets a maker of chips and salsa keep track
* of their sales for 5 different types of salsa: mild, medium, sweet, hot, and zesty/
* 
* The program should use:
*     Two parallel five-element arrays: an array of strings to hold the 5 salsa names,
*     and an array of ints that holds the # of jars sold during the past month for each salsa type.
*
* Once the data has been entered, a sales report should be generated, displaying
* sales for each salsa type, total sales, and the names of the highest and 
* lowest selling salsas.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void SalesReport(string types[], int sold[], int size);

// Global variable
const int NUM_SALSAS = 5;

int main()
{
    string salsaTypes[NUM_SALSAS] = { "mild", "medium", "sweet", "hot", "zesty" };
    int      jarsSold[NUM_SALSAS];
    
    int tempJars;         // holds user inputted data on jars sold
    
    // Get salsa data
    cout << "Enter the number of jars sold during the past month:" << endl;
    for (int i = 0; i < NUM_SALSAS; i++)
    {
        cout << salsaTypes[i] << " salsas sold: ";
        cin  >> tempJars;
        jarsSold[i] = tempJars;
    }
    
    // Find and Generate sales report
    SalesReport(salsaTypes, jarsSold, NUM_SALSAS);

    return 0;
}

// Function implementations
void SalesReport(string types[], int sold[], int size)
{
    int totalSales = 0;       
    string highestSelling = types[0];      // Set default highest and lowest 
    string lowestSelling = types[0];       // selling salsa strings to 'mild'
    int intHigh = 0;
    int intLow  = sold[0];                 // Set default low int to # of mild salsas sold
   
    // This for loop iterates through the 2 arrays and pulls data from them
    for (int i = 0; i < size; i++)
    {
        totalSales += sold[i];         // Get total jars sold
        
        if (sold[i] > intHigh)         // Get highest selling salsa
        {
            intHigh = sold[i];
            highestSelling = types[i];
        }
        
        if (sold[i] < intLow)          // Get lowest selling salsa
        {
            intLow = sold[i];
            lowestSelling = types[i];
        }
        
    } // for
    
    // Display Sales Report
    cout << "\n******************************************" << endl;  
    cout <<   "* Puckerbutt Pepper Company Sales Report *" << endl;
    cout <<   "******************************************" << endl;
    cout << "Total jars sold: " << totalSales << endl;
    cout << "Highest Selling: " << highestSelling << endl;
    cout << "Lowest Selling:  "  << lowestSelling << endl;
}
