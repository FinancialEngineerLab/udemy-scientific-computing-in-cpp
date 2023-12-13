#include <iostream>

using namespace std;

int evenNumbers(int);
int oddNumbers(int);





int main()
{
    int productOfOddNumbers = 1;
    int productOfEvenNumbers = 1;
    int counter = 0;
    
    for(int counter = 1; counter <= 5; counter++)
    {
        if (counter%2 != 0)
        {
            productOfOddNumbers *= counter; // 2,4
        }
        else
        {
            productOfEvenNumbers *= counter; // 1,3,5
        }
    };
    
    std::cout << productOfEvenNumbers << std::endl;
    std::cout << productOfOddNumbers << std::endl;
    
    
    return 0;
}
