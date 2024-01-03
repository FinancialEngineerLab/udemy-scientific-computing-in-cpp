#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

using namespace std;

const double pi = 3.141592, p = 0.231641;

class NormDistribution
{
    private:
        double x, mue, sigma;
    
    public:
        NormDistribution(double x, double M = 0, double S = 1): x(x), mue(M), sigma(S)
        {
            std::cout << "random variable: " << x << std::endl
                      << "mean: " << mue << std::endl
                      << "std : " << sigma << std::endl;
        }
        
        double zscore_prob();
        double stdNormDist(double z);
        
        static double poly_coeffs[6]; //bad code
};

double NormDistribution::poly_coeffs[6] = {0.0, 0.319381, -0.356563, 1.781477, -1.821255, 1.330274};
double NormDistribution::zscore_prob()
{
    return stdNormDist( (x-mue)/sigma);
};

double NormDistribution::stdNormDist(double z)
{
    assert(sigma> 0);
    
    //p function
    double k = 1.0 / (1.0 + p * fabs(z));
    
    // density function
    double d = std::exp(-z * z / 2.0) / std::sqrt(2.0 * pi);
    
    double f = poly_coeffs[5];
    // rewrite factored form of polynomial function:
    // P(x) ~ 1 - d(x) * k*(c_1 + k*(c_2 + k*(c_3 + k*(c_4 + c_5 * k)))) + c_0 
    for(int i =4;i>=0;i--)
    {
        f = f*k + poly_coeffs[i];
    }
    //d(x)* ..
    f *= d;
    
    return (z<0) ? f : (1.0-f);
};

int main()
{
    NormDistribution example(985.0, 1000.0, 12.0);
    std::cout << "prob : " << example.zscore_prob() << " 1- prob: " <<1.0 - example.zscore_prob() << std::endl;
}
