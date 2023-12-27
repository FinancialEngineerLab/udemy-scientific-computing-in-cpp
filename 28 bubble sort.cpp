#include <iostream>
#include <algorithm>

using namespace std;

const int NUM_ELEMENTS = 6;

void bubbleSort(int, int[], bool(*)(int, int));
bool ascendingSort(int, int);
bool descendingSort(int, int);

void bubbleSort(int numOfElements, int array[], bool (*compareNumbers)(int, int))
{
    bool wasElementSorted;
    do
    {
        wasElementSorted = true;
        for(int i =0;i<numOfElements -1 ;i++)
        {
            if ( (*compareNumbers)(array[i], array[i+1]) )
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                wasElementSorted = false;
            }
        }
    } while(!wasElementSorted);
}

bool ascendingSort(int x, int y)
{
    if (x > y)
    {
        return true;
    }
    return false;
}

bool descendingSort(int x, int y)
{
    if (x < y)
    {
        return true;
    }
    return false;
}

int main()
{
    int array[NUM_ELEMENTS];
    
    for(int i = 0; i<NUM_ELEMENTS; i++)
    {
        array[i] = (17 * i + 5 ) % 10;
    }
    std::cout << "current array filled with arbitrary numbers : " << std::endl;
    
    for(int i = 0; i<NUM_ELEMENTS; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    bubbleSort(NUM_ELEMENTS, array, ascendingSort);
    std::cout <<"sorted in an ascending way : " << std::endl;
    
    for(int i = 0; i<NUM_ELEMENTS; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    bubbleSort(NUM_ELEMENTS, array, descendingSort);
    std::cout <<"sorted in an descending way : " << std::endl;
    for(int i = 0; i<NUM_ELEMENTS; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    

    return 0;
}
