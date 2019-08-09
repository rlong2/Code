// This program demonstrates the use of overloaded constructors

#include <iostream>
#include <iomanip>
using namespace std;

class Sale
{
    private:
        double taxRate;
    
    public:
        Sale()               // default constructor
        { taxRate = 0.0;
        }
        
        Sale(double rate)    // constructor with 1 parameter
        { taxRate = rate;    // handles tax-exempt sales
        }
        
        double CalcSaleTotal(double cost)
        { double total = cost + (cost * taxRate);
          return total;
        }
}; 
        

int main()
{
    Sale cashier1(0.06);     // Define a Sale object with 6% sales tax
    Sale cashier2();         // Define a tax-exempt Sale object
    
    cout << setprecision(2) << fixed;
    
    return 0;
}
