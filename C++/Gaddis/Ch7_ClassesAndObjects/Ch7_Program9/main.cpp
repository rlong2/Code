// This program passes an object to a function.
// One object is passed by reference, the other is passed by value.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class InventoryItem
{
private:
    int partNum;
    string description;
    int onHand;
    double price;

public:
    void StoreInfo(int p, string d, int oH, double cost); // prototype

    int GetPartNum()
    {
        return partNum;
    }

    string GetDescription()
    {
        return description;
    }

    int GetOnHand()
    {
        return onHand;
    }

    double GetPrice()
    {
        return price;
    }
};

// Implementation code for InventoryItem class function StoreInfo
void InventoryItem::StoreInfo(int p, string d, int oH, double cost)
{
    partNum = p;
    description = d;
    onHand = oH;
    price = cost;
}

// Function prototypes for main
void StoreValues(InventoryItem&);          // receives object by reference
void ShowValues(InventoryItem);             // receives object by value

/*************************
*              main      *
**************************/
int main()
{
    InventoryItem part;

    StoreValues(part);
    ShowValues(part);

    return 0;
}

// function implementations

// StoreValues stores user input data in the members of
// an InventoryItem object passed to it by reference.
void StoreValues(InventoryItem &item)
{
    int partNum;  // local variables to hold user input
    string description;
    int qty;
    double price;

    cout << "Enter data for the new part number" << endl;
    cout << "Part number: ";
    cin >> partNum;
    cout << "Description: ";
    cin.get();
    getline(cin, description);
    cout << "Quantity on hand: ";
    cin >> qty;
    cout << "Unit price: ";
    cin >> price;

    // Store the data in the InventoryItem object
    item.StoreInfo(partNum, description, qty, price);
}

// ShowValues displays the member data stored in the InventoryItem
// object pass to it by value.
void ShowValues(InventoryItem item)
{
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "Part Number   : " << item.GetPartNum() << endl;
    cout << "Description   : " << item.GetDescription() << endl;
    cout << "Units on hand : "  << item.GetOnHand() << endl;
    cout << "Price         : $" << item.GetPrice() << endl;
}
