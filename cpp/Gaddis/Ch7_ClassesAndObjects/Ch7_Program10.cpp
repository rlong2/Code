// This program uses a constant reference parameter.
// It also shows how to return an object from a function.
// Very similar to program 9

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

    int GetPartNum() const          // The Get functions have all been
    {                               // made const functions. This ensures
        return partNum;             // They cannot alter any class member data.
    }

    string GetDescription() const
    {
        return description;
    }

    int GetOnHand() const
    {
        return onHand;
    }

    double GetPrice() const
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
InventoryItem CreateItem();              // returns an InventoryItem object
void ShowValues(const InventoryItem&);   // Receives a reference to an InventoryItem object

/*************************
*              main      *
**************************/
int main()
{
    InventoryItem part = CreateItem();
    ShowValues(part);

    return 0;
}

// function implementations

// CreateItem stores user input data in the members of
// a locally defined InventoryItem object, then returns it.
InventoryItem CreateItem()
{
    InventoryItem tempItem;  // local InventoryItemobject
    int partNum;             // local variables to hold user input
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

    // Store the data in the InventoryItem object and return it
    tempItem.StoreInfo(partNum, description, qty, price);
    return tempItem;
}

// ShowValues displays the member data stored in the InventoryItem
// object passed to it. Because it was passed as a constant reference,
// ShowValues accesses the original object, not a copy, but it can only
// call member functions declared to be const. This prevents it from
// calling any mutator functions.
void ShowValues(const InventoryItem &item)
{
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "Part Number   : " << item.GetPartNum() << endl;
    cout << "Description   : " << item.GetDescription() << endl;
    cout << "Units on hand : "  << item.GetOnHand() << endl;
    cout << "Price         : $" << item.GetPrice() << endl;
}
