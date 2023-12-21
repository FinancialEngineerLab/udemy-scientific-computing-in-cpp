#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int i, j;
    std::cout <<"non tegative two numbers: ";
    cin >> i >> j;
    
    int x = i, y = j, z = 0;
    assert(z + x*y == i *j);
    
    while(x > 0)
    {
        if(x%2 ==1)
        {
            z += y;
        }
        y *= 2;
        x /= 2;
        assert(z + x*y == i *j );
    }
    assert(z + x* y == i * j);
    std::cout << "product is " << z << std::endl;
    
    return 0;
}
