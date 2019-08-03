/*  The East Coast sales division of a company generates 58 percent of total sales.
 *  Based on that percentage, write a program that will predict how much
 *  the East Cast division will generate if the company has $8.6 million in sales this year.
 *  Display the result on screen.
 */

// aka, calculate 58% of 8.6 million

#include <iostream>

using namespace std;

int main()
{
    double companySales = 8600000;
    double eastCoastGeneration = 0.58;
    
    double totalGeneration = companySales * eastCoastGeneration;

   cout << "Total generation: " << totalGeneration << endl; 

}
