#include <iostream>
#include <iomanip>

using namespace std;

const double pi = 3.141592;

int counter(int);
int counter(int number)
{
    if(number == 1 || number <=0)
    {
        return 1;
    }
    else
    {
        return (number *= counter(number - 1));
        
    }
}


int main()
{
    int number;
    cin >> number;
    std::cout << counter(number) << std::endl;
    return 0;
};
