#include "nonlinear.hpp"

using namespace std;

#ifndef NEWTON_HPP
#define NEWTON_HPP

class Newton : public Nonlinear
{
    private:
        double xStart;
        int maxIter;
        double eps;
        
    public:
        Newton(funct F, double X, int I, double E) :
            Nonlinear(F), xStart(X), maxIter(I), eps(E) { }
        
        virtual double iteration();
};

double Newton::iteration()
{
    std::cout << std::endl;
    double denominator, y, x = xStart;
    int iter = 0;
    
    while(iter < maxIter)
    {
        denominator = fprime(x); // from parent class
        
        if(fabs(denominator) < DBL_EPSILON)
        {
            std::cout << " denom is 0 \n";
        }
        y = x - Function(x) / denominator;

      
        if(fabs(y) > FLT_MAX)
        {
            std::cout << "overflow" << std::endl;
        }
        if(fabs(x-y) < eps * fabs(x))
        {
            break;
        }

        std::cout << " y = " << y << "\t" << "x = " << x << std::endl;
        iter++;
        x = y;
    }

    // max iter //
    if (iter >= maxIter)
    {
        x = 0.0;
        std::cout << "maximun nubmer of iter steps are reached " << std::endl;
    }
    return y;
};




#endif
