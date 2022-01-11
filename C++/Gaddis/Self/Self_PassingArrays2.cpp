// This program passes a whole array to a function

#include<iostream>
using namespace std;

// Function Prototype
void ShowValues(string myArray[], int size);

int main()
{
    const int SIZE = 5;
    string pokedex[] = { "Pikachu", "Squirtle", "Muk", "Meowth", "Growlithe" };

    ShowValues(pokedex, SIZE);

    return 0;
}

// Function implementation
void ShowValues(string myArray[], int size)
{
    cout << "Array contains: ";
    for (int i = 0; i < size; i++)
	    cout << myArray[i] << " ";
    cout << endl;
}

