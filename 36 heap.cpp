#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

const int NUM_ELEMENTS = 7;

ostream& operator<<(ostream& stream, const vector<int>& numbers)
{
    std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    return stream;
}

int main(int argc, const char * argv[])
{
    std::vector<int> numbers;
    std::cout << "building the heap : " << std::endl;
    
    for(int i = 0; i< NUM_ELEMENTS;i++)
    {
        numbers.push_back((i*17 + 5) % 100);
        make_heap(numbers.begin(), numbers.end());
        std::cout << numbers << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "sorting in ascending order: " << std::endl;
    sort_heap(numbers.begin(), numbers.end());
    std::cout << numbers << std::endl << std::endl;
    
    int min, max = 0;
    min = *min_element(numbers.begin(), numbers.end());
    max = *max_element(numbers.begin(), numbers.end());
    
    std::cout << min << std::endl;
    std::cout << max << std::endl;
    
    make_heap(numbers.begin(), numbers.end());
    for(int  j = NUM_ELEMENTS; j >0; j--)
    {
        pop_heap(numbers.begin(), numbers.begin() + j);
        copy(numbers.begin(), numbers.begin() + j, ostream_iterator<int>(cout, " "));
        std::cout << "--> " << *(numbers.begin() + j -1);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    
    
    return 0;
}
