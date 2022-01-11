// Play again loop
// Modified from Beginning C++ Through Game Programming, 4th Edition
// http://www.delmarlearning.com/companions/content/1305109910/datafiles/index.asp?isbn=1305109910

#include <iostream>

using namespace std;

int main()
{
  char choice = 'y';
  
  while (choice == 'y')
  {
   cout << "Good game! Play again? (y/n): ";
   cin >> choice;
  } 
   
   cout << "Game over! Thanks for playing." << endl;
   return 0;
}
