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
    Sale cashier2;         // Define a tax-exempt Sale object
    Sale cashier3(0.23);
    
    cout << setprecision(2) << fixed;
    
    cout << "With a 6% tax rate, a $24.95 item is $" <<  cashier1.CalcSaleTotal(24.95) << endl;   
    cout << "With no tax, a $24.95 item is $" <<         cashier2.CalcSaleTotal(24.95) << endl;
    cout << "With a 23% tax rate, a $24.95 item is $" << cashier3.CalcSaleTotal(24.95) << endl;   

    return 0;
}
