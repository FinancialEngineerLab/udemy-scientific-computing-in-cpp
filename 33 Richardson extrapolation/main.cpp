#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// threashold for convergecne criterion
const double tolerance = 1e-6;

typedef double(*funct)(double);

// trigonometric functions
double function_1(double x ) { return sin(x); }
double function_2(double x ) { return cos(x); }

class numericalDifferentiation
{
    private:
        double x;
        double n;
        funct Function;
        
    public:
        numericalDifferentiation(double X, funct f) { x = X; Function = f; n = 1.0/2.0;}
        double differenceQuotient(void);
        void extrapolation(void);
};

double numericalDifferentiation::differenceQuotient(void)
{
    return (Function(x+n) - Function(x- n)) / (2.0 * n);
};

void numericalDifferentiation::extrapolation(void)
{
    int i=0;
    int r = 0;
    double prefactor;
    double D[10];
    
    for(i = 0; i<=9;i++)
    {
        D[i] = 0.0;
    }
    do
    {
        if (r >= 1)
        {
            // r=4-> i=3, ... i = 2 ... i =1 ... i = 0
            for(int i = r-1; i>=0; i--)
            {
                // D[0] to D[1] ...
                D[i+1] = D[i];
            }
        }
        D[0] =  differenceQuotient();
        prefactor = 1.0;
        std::cout << setw(2) << setprecision(6) << D[0];
        
        for(i = 1; i<=r;i++)
        {
            // Richardson Exptralolation //
            prefactor *= 4.0;
            D[i] = (prefactor * D[i-1] - D[i]) / (prefactor - 1.0);
            std::cout << setw(10) << setprecision(6) << D[i];
        }
        // step value
        n /= 2.0; // n updated
        r++; // step updated 
        std::cout << std::endl;
    } while (r<=1 || fabs(D[r-1]- D[r-2]) > tolerance * fabs(D[r-1]));
    std::cout << std::endl;;
};





int main()
{
    numericalDifferentiation differentiate_f1(1.0,function_1);
    numericalDifferentiation differentiate_f2(1.0,function_2);
    
    differentiate_f1.extrapolation();
    differentiate_f2.extrapolation();
    
    return 0;
}
