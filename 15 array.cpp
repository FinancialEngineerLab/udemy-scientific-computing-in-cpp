#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int row, col;
    int** array;
    
    std::cout << "rows " << std::endl;
    cin >> row;
    std::cout << "cols " << std::endl;
    cin >> col;
    
    array = new int*[row];
    
    for(int i =0;i<row;i++)
    {
        array[i] = new int[col];
    };
    for(int i =0;i<row;i++)
    {
        for(int j = 0; j<col; j++)
        {
            array[0][0] = 0;
            array[0][1] = 1;
            array[1][0] = 2;
            array[1][1] = 3;
        }
    }
    
    for(int i =0;i<row;i++)
    {
        delete[] array[i];
        delete[] array;
        array = NULL;
    }
    
    for(int i =0;i<row;i++)
    {
        for(int j =0; j<col; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for(int i = 0; i<row; i++)
    {
        delete[] array[i];
        delete[] array;
        array = NULL;
    }
    
    return 0;
}
