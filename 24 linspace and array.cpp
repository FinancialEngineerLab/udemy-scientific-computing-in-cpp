
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int CAPACITY = 100;

int main()
{
    double col_1[CAPACITY];
    double col_2[CAPACITY];
    
    double linspace[10];
    
    for(int i = 0; i<10;i++)
    {
        linspace[i] = 0;
    };
    
    
	//linspace-array producing 10 elements ranging from 0.0 to 1.0
    double start, end = 0.0;
    start = 0.0;
    end = 1.0;
    
    for(int i =0;i<10;i++)
    {
        double I = static_cast<double>(i);
        double n = static_cast<double>(10)-1.0;
        linspace[i] = start + ((end-start) / n) * I;
    };
    
    
    //distribute linspace-function in column 1
    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<10;j++)
        {
            col_1[j*10 + i] = linspace[j];
        }
    }

    
	//distribute linspace-function in column 2 using a modulo-operator
    for(int i =0;i<CAPACITY;i++)
    {  
        col_2[i] = linspace[i % 10];
    };
    
    
    
    for(int i = 0 ;i<CAPACITY;i++)
    {
        std::cout <<setprecision(3) << fixed << col_1[i] << "\t" << col_2[i] << std::endl;
    }


    return 0;
}
