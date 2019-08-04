/* Word Game! 
 * Basically Mad Libs
 * Note that 'getline' is used so user can input phrases with spaces.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // User input
    string name, city, activity, animal, product, petName;
    int num1, num2;

    cout << "Enter some info and I'll tell you a story!\n" << endl;
    cout << "Your name: ";
    getline(cin, name);
    cout << "A city: ";
    getline(cin, city);
    cout << "An activity: ";
    getline(cin, activity);
    cout << "An animal: ";
    getline(cin, animal);
    cout << "A product: ";
    getline(cin, product);
    cout << "Your pet's name. If you don't have one, make it up: ";
    getline(cin, petName);
    cout << "A number: ";
    cin >> num1;
    cout << "Another number: ";
    cin >> num2;

    // Output story
    cout << "/nThere once was a person named " << name << "." << endl;
    cout << name << " decided to venture to " << city << " to " << activity << "." << endl;
    cout << "Of course, " << name << " would have to find a way to bring " << petName << ", " << endl;
    cout << "one of " << num1 << " pet " << animal << "s that " << name << " owned." << endl;
    cout << "To continue this story, please mail $" << num2 << " to " << product << ", Inc.\n" << endl;

    return 0;

}
