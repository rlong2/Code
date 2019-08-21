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
    
    SalesReport(salsaTypes, jarsSold, NUM_SALSAS);

    return 0;
}

// Function implementations
void SalesReport(string types[], int sold[], int size)
{
    int totalSales = 0;       
    string highestSelling = types[0];
    string lowestSelling;
    int tempHigh = 0;
    int tempLow  = sold[0];
    
    for (int i = 0; i < size; i++)        // Get total jars sold
    {
        totalSales += sold[i];
    }
    
    cout << "Total jars sold: " << totalSales << endl;
    
    for (int i = 0; i < size; i++)       // Get highest selling salsa
    {
        if (sold[i] > tempHigh)
        {
            tempHigh = sold[i];
            highestSelling = types[i];
        }
        
    }
    
    cout << "Highest Selling: " << highestSelling << endl;
    
    
    for (int i = 0; i < size; i++)       // Get lowest selling salsa
    {
        if (sold[i] < tempLow)
        {
            tempLow = sold[i];
            lowestSelling = types[i];
        }
    }
    
    cout << "Lowest Selling:" << lowestSelling << endl;
    /*
    cout << "\n******************************************" << endl;  // Display Sales Report
    cout <<   "* Puckerbutt Pepper Company Sales Report *" << endl;
    cout <<   "******************************************" << endl;
    cout << "Highest selling salsa: " << highestSelling << " with " 
                                      << tempHigh << " jars." << endl;
                                      
    cout << "Lowest selling salsa: "  << lowestSelling << " with "
                                      << tempHigh << " jars." << endl;
 */
}
