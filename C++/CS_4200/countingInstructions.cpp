#include <iostream>
using namespace std;

// Global variables
int addi = 0;
int add  = 0;
int sw   = 0;
int lw   = 0;
int slt  = 0;
int beq  = 0;
int jal  = 0;
int j    = 0;
int jr   = 0;

// Function prototype
int fun(int s);

int main()
{
    // main:
    int x = 0;
    int i = 2;
    
    addi++;
    sw++;
    sw++;
    addi++;
    addi++;
    addi++;
    
    // loop:
    beq++;
    while ( i != 0)
    {
        jal++;
        x = x + fun(i--);
        add++;
        addi++;
    }
    
    addi++;
    lw++;
    lw++;
    addi++;
    jr++;
    
    cout << "addi = " << addi << endl;
    cout << "add  = " << add  << endl;
    cout << "sw   = " << sw   << endl;
    cout << "lw   = " << lw   << endl;
    cout << "slt  = " << slt  << endl;
    cout << "beq  = " << beq  << endl;
    cout << "jal  = " << jal  << endl;
    cout << "j    = " << j    << endl;
    cout << "jr   = " << jr   << endl;
    return 0;
}

// Function implementation
int fun(int s)
{
    addi++;
    sw++;
    sw++;
    
    int r;
    
    slt++;
    if (s > 0)
    {
        beq++;
        addi++;
        jal++;
        j++;
        
        s--;
        r = fun(s);
    }
    else
    {
        addi++;
        r = 0;
    }
    r = r + s;
    
    return r;
}
