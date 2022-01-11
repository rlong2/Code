/*    
    This program finds prime numbers using the Sieve of Eratosthenes menthod. 
    It is used in Project 1 of CS 4200.
    TODO: Make sure this can run when user input = 100,000,000
    
    Steps from Wikipdeia: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    
    Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
    Initially, let p equal 2, the smallest prime number.
    Enumerate the multiples of p by counting in increments of p from 2p to n, and mark them in the list (these will be 2p, 3p, 4p, ...; the p itself should not be marked).
    Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
    When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
    
    The non-prime numbers are marked with 0, and any number in the array not equal to 0 is prime.
*/

#include <iostream>
using namespace std;

// Function Prototype
int sieve(int userNum);

int main()
{
    int number;
    
    cout << "Enter an integer: ";
    cin  >> number;
    
    sieve(number);
    
    return 0;
}

// Function Implementation
int sieve(int userNum)
{
    int primes[userNum + 1];                 // Initialize array to hold 0 to n+1 integers
    int primeCounter = 0;
    int p = 2;
    
    primes[0] = 0;                          // 0 and 1 are not primes, 
    primes[1] = 0;                          // so set their value to 0
    
    for(int i = 2; i <= userNum; i++)       
    {
        if (i % p == 0 && i != 2)           // If the number is divisible by 2 and is not 2, zero it
            primes[i] = 0;
        else
            primes[i] = i; 
    }  
    
    for(int p = 2; p * p < userNum; p++)    // Iterate through the array again, finding 
    {                                       // numbers that are square roots of one another
        if (primes[p] != 0)                 // i.e., 3x3, 4x4, 5x5...
        {
            for (int i = p * p; i <= userNum; i += p)
                primes[i] = 0;
        }
    }

    // Print array
    cout << "array contains: ";             
    for (int var : primes)
    {
        if (var != 0)
        {
            primeCounter++;
            //cout << var << " ";
        }
    }
    
    cout << "\nThere are " << primeCounter << " primes." << endl;
}
