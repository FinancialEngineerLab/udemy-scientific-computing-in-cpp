#include "newton.hpp"

double function_1(double x)
{
    return -(x)*(x)*(x) - 4.0 * (x) + 10.0;
}

double function_2(double x)
{
    return std::pow(x, 3) - 2.0 * (x) + 2.0;
}


int main()
{
    Newton polynomial_1(function_1, 1, 10, 1e-6);
    Newton polynomial_2(function_2, -1, 10, 1e-6);
    
    std::cout << " appx root ! " << polynomial_1.iteration() << std::endl;
    std::cout << " appx root ! " << polynomial_2.iteration() << std::endl;
    
}
