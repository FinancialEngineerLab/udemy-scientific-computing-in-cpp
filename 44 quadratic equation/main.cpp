#include <iostream>
#include <complex>
#include <exception>

using namespace std;

typedef complex<double> complexNumber;

void quadraticEquation(double, double, double, complexNumber&, complexNumber&);
void quadraticEquation(double a, double b, double c, complexNumber& x1, complexNumber& x2)
{
    double discriminant;
    
    x1 = complexNumber(0, 0);
    x2 = complexNumber(0, 0);
    try
    {
        discriminant = b*b - 4.0 * a * c;
        if(fabs(a) < 1.0e-14)
        {
            throw runtime_error("fuck you");
        }
        
        if (discriminant >=0)
        {
            double d =sqrt(discriminant);
            x1 = complexNumber((-b+d)/(2.0 *a), 0.0);
            x2 = complexNumber((-b-d)/(2.0 *a), 0.0);
        }
        else
        {
            double d = sqrt(fabs(discriminant));
            x1 = complexNumber(-b/(2.0*a), d/(2.0*a));
            x2 = complexNumber(-b/(2.0*a), -d/(2.0*a));
        }
    }
    catch(const exception& error)
    {
        cerr << error.what();
        exit(1);
    }
};

int main()
{
    double a, b, c;
    complexNumber x1, x2;
    cin >> a>>b>>c;
    
    quadraticEquation(a,b,c,x1,x2);
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
    
    return 0;
    
}
