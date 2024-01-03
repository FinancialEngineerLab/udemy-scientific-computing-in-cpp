#include "regression.hpp"

using namespace std;

int main()
{
    regression linear;
    linear.input();
    
    if(linear.coefficients())
    {
        linear.output();
        linear.correlation();
    }

    exponential expo;
    expo.input();
    
    if(expo.coefficients())
    {
        expo.output();
        expo.correlation();
    }
    return 0;
}
