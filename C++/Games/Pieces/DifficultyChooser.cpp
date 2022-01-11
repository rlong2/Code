// Menu Chooser with switch statements
// Modified from Beginning C++ Through Game Programming, 4th Edition
// http://www.delmarlearning.com/companions/content/1305109910/datafiles/index.asp?isbn=1305109910

#include <iostream>

using namespace std;

int main()
{
   cout << "Difficulty Levels" << endl;
   cout << "1 - Easy" << endl;
   cout << "2 - Medium" << endl;
   cout << "3 - Hard" << endl;
   
   cout <<"Your choice: ";
   int choice = 0;
   cin >> choice;
   
   switch(choice)
   {
       case 1:
           cout << "You picked Easy";
           break;
        case 2:
           cout << "You picked Meduim";
           break;
        case 3:
           cout << "You picked Hard";
           break;
        default:
            cout << "Illegal choice" << endl;
   }
   return 0;
}
