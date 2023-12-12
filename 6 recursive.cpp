#include <iostream>

using namespace std;

// recursive function programming //
double infiniteSeries(int);
double infiniteSeries(int number)
{
    float e = 1.0f;
    int factorial = 1;

    for(int i = 1; i<=number;i++)
    {
        // first iteration: 1 + 1/1 
		//second iteration: 1 + 1/1 + 1/2!
		//third iteration: 1 + 1/1 + 1/2! + 1/3! + ...
        factorial *= i;
        e += 1.0 / factorial;

    }
    return e;
};

int main()
{
    int number;
    cin >> number;

    std::cout << "approximate value for eulers = " << infiniteSeries(number) << std::endl;

    return 0;
}
