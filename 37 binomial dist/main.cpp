#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

using namespace std;

class Binomial
{
    private:
        int n, k;
        double p;
    
    public:
        Binomial(int N, int K, double P)
        {
            n = N;
            k= K;
            p = P;
        }
        
        double singleValue();
        void binomialTable();
        double expectedValue();
};

double Binomial::singleValue()
{
    double b, r;
    double q = 1.0 - p;

    assert(p > 0 && p < 1 && k >0 && k <=n);
    // trick: avoid underflow with log 
    b = n * log(q); // log(q^n), q^n initial vlaue
    
    // initial value 
    r = log(p/q);
    // recursive scheme //
    // i : recursive k 
    int m = n + 1; // for rewritten formula
    for(int i =1; i<=k; i++)
    {
        // P(x=k-1) : recursive
        b += r + log(static_cast<double>(m) / i - 1.0);
    }
    return exp(b);
};


void Binomial::binomialTable()
{
    std::cout << "table of binomial prob : " << std::endl;
    double b, r;
    double q = 1.0 - p;
    int m = n + 1;
    
    assert(p > 0 && p < 1);
    // trick: avoid underflow with log 
    b = n * log(q);
    r = log(p/q);
    
    std::cout << fixed << setprecision(6) << setw(5) << "0" << setw(15) << exp(b) << std::endl;
    for(int i =1; i<=n;i++)
    {
        b += r + log(static_cast<double>(m) / i - 1.0);
        std::cout << setw(5) << i << setw(15) << exp(b) << std::endl;
    }
};

double Binomial::expectedValue()
{
    return n * p;
}

int main()
{
    // P(X=k) & N =6 -> B (N = 6, K =1, P = 0.7)
    Binomial postedAnswer(6, 1, 0.7);
    std::cout << "prob p :" << postedAnswer.singleValue() << std::endl;
    std::cout << "expected value : " << postedAnswer.expectedValue() << std::endl;
    postedAnswer.binomialTable();
    
    std::cout << std::endl;
    Binomial tossCoins(6, 1, 0.5);
    std::cout << "prob p :" << tossCoins.singleValue() << std::endl;
    std::cout << "expected value : " << tossCoins.expectedValue() << std::endl;
    tossCoins.binomialTable();
}
