// This header file contains the Circle class declaration.
#ifndef CIRCLE_H
#define CIRCLE_H
#include<cmath>

class Circle
{
    private: 
        double radius;           // Circle radius
        int CenterX, CenterY;    // Circle coordinates
    
    public:
        Circle()                // Default constructor
        {
            radius = 1.0;
            CenterX = 0;
            CenterY = 0;
        }
        
        Circle(double r)       // 2nd Constructor, accepts radius var
        {
            radius = r;
            CenterX = 0;
            CenterY = 0;
        }
        
        Circle(double r, int x, int y)  // 3rd Constructor,
        {                               // Accepts radius, circle coordinates
            radius = r;
            CenterX = x;
            CenterY = y;
        }
        
        void SetRadius(double r)
        { radius = r; }
        
        int GetXcoord()
        { return CenterX; }
        
        int GetYcoord()
        { return CenterY; }
        
        double FindArea()
        { return 3.14159 * pow(radius, 2); }
};
#endif
