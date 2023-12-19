#include <iostream>
#include "Whitecollar.hpp"

using namespace std;

int main()
{
    int hourlywage, bonus, workers,hours;
    
    cin >> hourlywage;
    cin >> bonus;
    cin >> workers;
    cin >> hours;
    
    Whitecollar mySalary(hourlywage, bonus, workers, hours);
    mySalary.printSalary();
    
    return 0;
}
