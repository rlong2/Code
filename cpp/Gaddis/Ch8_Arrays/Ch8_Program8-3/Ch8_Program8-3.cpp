/* This program reads employee work hours from work.dat
 * located in the same folder as this cpp file
 * and stores them in an int array. An array is used to
 * input the hours and another to display them. 
 */

#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    const int NUM_EMPLOYEES = 6;
    int hours[NUM_EMPLOYEES];
    int count = 0;

    ifstream inputFile;             // input file stream object

    // Open the data file
    inputFile.open("work.dat");

    if (!inputFile)
	    cout << "Error opening data file" << endl;
    else 
    { // Read the numbers from the file into the array. 
      // When the loop is exited, count holds the # of items read in.
      while (count < NUM_EMPLOYEES && inputFile >> hours[count] )
	     count ++;

      // Close the file
      inputFile.close();

      // Display contents of array
      cout << "The hours worked by each employee are:" << endl;

      for (int employee = 0; employee < count; employee++)
      {
          cout << "Employee " << employee + 1 << ": ";
	  cout << hours[employee] << endl;
      }
    

        
    }
    return 0;
}
