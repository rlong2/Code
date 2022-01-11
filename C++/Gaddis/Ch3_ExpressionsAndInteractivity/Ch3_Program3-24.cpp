// Experimenting with truncating char arrays

#include <iostream>
#include <string>

using namespace std;

int main()
{
    char word[10] = "Hello";

    cout << word << endl;

//    word = "HelloThereWorld"; // incompatible, cannot fit 16 chars!
    cout << word << endl;

    return 0;
}
