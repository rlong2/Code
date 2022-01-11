// This project uses a class with a boolean function that determines
// if a new value sent to it is the largest value received so far.

#include <iostream>
using namespace std;

class SimpleStat
{
private:
    int largest;        // The largest number received so far
    int sum;            // The sum of numbers received
    int count;          // # of numbers received

    bool IsNewLargest(int);

public:
    SimpleStat();
    bool AddNumber(int);
    double CalcAverage();

    int GetLargest()
    {
        return largest;
    }

    int GetCount()
    {
        return count;
    }
};

// SimpleStat implemetation

SimpleStat::SimpleStat()
{
    largest = sum = count = 0; // default constructor initializes data to 0
}

bool SimpleStat::AddNumber(int num)
{
    bool goodNum = true;
    if (num >= 0)
    {
        sum += num;
        count++;
        if (IsNewLargest(num))
            largest = num;
    }
        else
            goodNum = false;
}

bool SimpleStat::IsNewLargest(int num)
{
    if (num > largest)
        return true;
    else
        return false;
}

double SimpleStat::CalcAverage()
{
    if (count > 0)
        return static_cast<double>(sum) / count;
    else
        return 0;
}

/*****************************
*            main            *
******************************/

int main()
{
    int num;
    SimpleStat statHelper;

    cout << "Please enter the set of non-negative integer values you want to average." << endl;
    cout << "Seperate each entry by a space and enter -1 after the last value.\n" << endl;

    cin >> num;
    while (num >= 0)
    {
        statHelper.AddNumber(num);
        cin >> num;
    }

    cout << "\nYou entered " << statHelper.GetCount() << " values." << endl;
    cout << "The largest value was " << statHelper.GetLargest() << endl;
    cout << "The average value was " << statHelper.CalcAverage() << endl;

    return 0;
}
