// Hero's Inventory
// Demonstrates arrays
// Create an array of max 10 with a sword, shield, and arrows

#include <iostream>

using namespace std;

int main()
{
    const int MAX_ITEMS = 10;
    string inventory[MAX_ITEMS];
    
    int numItems = 0;
    inventory[numItems++] = "sword";
    inventory[numItems++] = "shield";
    inventory[numItems++] = "arrows";
    
    for (int i; i < numItems; i++)
    {
        cout << inventory[i] << endl;
    }
	
	return 0;
}
