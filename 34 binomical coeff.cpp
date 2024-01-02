#include <iostream>
#include <cassert>

using namespace std;

long binomialCoefficeint(int n, int k)
{
    long binomial = 1L;
    assert(n >=k && k>=0);
    if (k > 2/n)
    {
        k = n- k;
    };
    for(int i = 1; i <=k; i++)
    {
        binomial = binomial * (n - k + i) /i;
    };
    return binomial;
}

int main(int argc, const char * argv[]) {
    
    int n, k;
    
    cin >> n >> k;
    
    std::cout << binomialCoefficeint(n, k) << std::endl;
    return 0;
}
