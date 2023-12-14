#include <iostream>

using namespace std;

const int CAPACITY = 10;

int* enlargeArray(int [], int CAPACITY);
int* enlargeArray(int array[], int CAPACITY)
{
    int* enlargeArray = new int[CAPACITY*2];
    int value = 0;
    bool enteredNumberIn = false;
    do
    {
        for(int i =0; i<CAPACITY*2 ;i++)
        {
            if(i <CAPACITY)
            {
                enlargeArray[i] = array[i];
            }
            else
            {
                std::cout << "please fill .... entering 10 numbers greater than 10 ... " << std::endl;
                cin >> value;
                while(value<=10 || value == array[i])
                {
                    enteredNumberIn = true;
                    std::cout << "invalid input " << std::endl;
                    cin >> value;
                }
                enteredNumberIn = false;
                if(!enteredNumberIn)
                {
                    enlargeArray[i] =value;
                }
            }
        }
    } while(enteredNumberIn);
    return enlargeArray;
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int* arrayPointer = enlargeArray(array, CAPACITY);
    for(int i =0; i <CAPACITY * 2; i++)
    {
        std::cout << arrayPointer[i] << " ";
    };
    std::cout << std::endl;
    return 0;
}
