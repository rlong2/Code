// This program finds the index, offset, and tag of a cache

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cacheSize,
        cacheBlockSize,
        associativity,
        addressSize,
        numBlocks,
        numSets,
        tag,
        index,
        offset;
        
    cout << "Conversions:" << endl;
    cout << "KB * 2^10, MB * 2^20, GB * 2^30\n" << endl;
    
    cout << "Enter the cache size in bytes: ";
    cin  >> cacheSize;
    
    cout << "Enter block size: ";
    cin  >> cacheBlockSize;
    
    cout << "Enter address size: ";
    cin  >> addressSize;
    
    cout << "Enter associativity (1 for direct, 0 for full): ";
    cin  >> associativity;
    
    // If the cache is fully associative, there is no index
    if (associativity == 0)
        index = 0;    
    else
    {
        numBlocks = cacheSize / cacheBlockSize;
        numSets = numBlocks / associativity;
        index = log2(numSets);
    }
    
    // Calculate the tag and offset
    offset = log2(cacheBlockSize);
    tag = addressSize - index - offset;
     
    // Display results   
    cout << endl;
    cout << "index  = " << index << endl;
    cout << "offset = " << offset << endl;
    cout << "tag    = " << tag << endl;

    return 0;
}
