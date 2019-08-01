// Hero's Inventory
// Demonstrates arrays
// Create an array of max 10 with a sword, shield, and arrows

// todo: pass array to function
// https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions
// https://www.programiz.com/cpp-programming/passing-arrays-function

#include <iostream>

using namespace std;

int numItems = 0;

void Display(string inventory[])
{
    cout << "Inventory: " << endl;
        for (int i; i < numItems; i++)
    {
        cout << inventory[i] << endl;
    }
}

void Menu()
{
    cout << "Menu:" << endl;
    cout << "Add weapon to inventory (a)" << endl;
    cout << "Display inventory (d)" << endl;
    cout << "Exit (e)" << endl;
}

int main()
{
    const int MAX_ITEMS = 10;
    string inventory[MAX_ITEMS];

    Menu();

    inventory[numItems++] = "sword";
    inventory[numItems++] = "shield";
    inventory[numItems++] = "arrows";

    Display(inventory);

	return 0;
}
