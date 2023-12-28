#include <iostream>
#include <cmath>

using namespace std;

typedef double(*function)(double);

double function_1(double);
double function_2(double);

function arrayFunctionPointer[] = { function_1, function_2 };

void tabularValue(function, double, double, double);

double function_1(double x)
{
    return sqrt(x);
}

double function_2(double x)
{
    return exp(x);
}

void tabularValue(function f, double a, double b, double n)
{
    for(double x =a; x<b + n / 2; x += n)
    {
        std::cout << x << "\t" << f(x) << std::endl;
    }
}

int main()
{
    for(int i = 0; i <2; i++)
    {
        tabularValue(arrayFunctionPointer[i], i , i + 1, 0.2);
        std::cout << std::endl;
    }
}
