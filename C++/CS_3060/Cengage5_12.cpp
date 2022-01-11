/* 
The population of town A is less than the population of town B. 
However, the population of town A is growing faster than the population of town B.
Write a program that prompts the user to enter:
    The population of town A
    The population of town B
    The growth rate of town A
    The growth rate of town B
The program outputs:
 1)   After how many years the population of town A will be greater than or equal to the population of town B
 2)   The populations of both the towns at that time.

(A sample input is: Population of town A = 5,000, growth rate of town A = 4%, 
population of town B = 8,000, and growth rate of town B = 2%.)
 */

#include <iostream>
using namespace std;

int main() 
{
    int years,       // counts years
        popA,
        popB;
    
    double growthA,
           growthB;
           
    cout << "Enter the population of town A: ";
    cin  >> popA;
    cout << "Enter the population of town B: ";
    cin  >> popB;
    cout << "Enter the growth rate of town A: ";
    cin  >> growthA;
    cout << "Enter the growth rate of town B: ";
    cin  >> growthB;
    
    growthA = growthA / 100.0;
    growthB = growthB / 100.0;
    
    for (years = 0; popA < popB; years++)
    {
        popA = popA + (popA * growthA);
        popB = popB + (popB * growthB);
    }
    
    cout << "The population of A will be greater or equal "
             "to the population of B after " << years << " years" << endl;
    cout << "The population of A is now " << popA << endl;
    cout << "The population of B is now " << popB << endl;
    
    return 0;
}
