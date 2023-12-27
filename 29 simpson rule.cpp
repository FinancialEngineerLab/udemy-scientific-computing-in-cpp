#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <cmath>

const double pi = 3.141592;
const int n = 22;
const int DBL_EPSILON = 0.00001;

using namespace std;

typedef double(*function)(double);

double usualIntegral(double);
double exponentialIntegral(double);
double simpsonsRule(double, double, function);

double usualIntegral(double x)
{
    if (fabs(x) < DBL_EPSILON)
    {
        return 1.0;
    }
    else
    {
        return 1.0 / (1.0 + pow(x, 5.0));
    }
};

double exponentialIntegral(double x)
{
    if (fabs(x) < DBL_EPSILON)
    {
        return 1.0;
    }
    else
    {
        return 5.0 * x * std::exp(-2.0 * x);
    }
};

double simpsonsRule(double a, double b, function f)
{
    double coeff = 2.0;
    double h = (b-a)/n ;
    double simpson = f(a) + f(b);
    
    for(int i =1;i<n;i++)
    {
        simpson += (coeff = 6.0 - coeff) * f(a + i * h );
    };
    
    return simpson * h / 3.0;
}

int main()
{
    assert(n % 2 == 0);
    std::cout << fixed << setprecision(6) << simpsonsRule(0, 3, usualIntegral) << std::endl;
    std::cout << fixed << setprecision(6) << simpsonsRule(0.1, 1.3, exponentialIntegral ) << std::endl;
    return 0;
}
