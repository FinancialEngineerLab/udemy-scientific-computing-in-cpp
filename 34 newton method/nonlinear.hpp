#include <iostream>
#include <cfloat>
#include <cmath>

#ifndef NONLINEAR_HPP
#define NONLINEAR_HPP

typedef double(*funct) (double);

class Nonlinear
{
    public:
        funct Function;
        Nonlinear(funct F) { Function = F; }
        double fprime(double);
        virtual double iteration() = 0;
};

// differentiation //
double Nonlinear::fprime(double x)
{
    double n = FLT_EPSILON;
    
    if (fabs(x) > 1.0)
    {
        n *= fabs(x);
    }
    return (Function(x + n) - Function(x-n))/ (2.0 * n);
}

#endif
