// This program changes the contents of an intialized array

#include <iostream>
#include<string>
using namespace std;

int main()
{
    const int SIZE = 5;
    
    string pokemon[SIZE] = { "Mew", "Growlithe", "Alakazam", "Pikachu", "Muk" };
    
    // display initital array
    cout << "The initial array holds:" << endl;
    for (string var : pokemon)
    {
        cout << var << " ";
    }
    
    // Get new input
    cout << "\n\nEnter 5 new pokemon names to overwrite the initial array:" << endl;
    for (string &var : pokemon)
    {
        cin >> var;
    }
    
    // display array
    cout << "\nDisplaying contents of array:" << endl;
    for (string var : pokemon)
    {
        cout << var << " ";
    }
    return 0;
}
