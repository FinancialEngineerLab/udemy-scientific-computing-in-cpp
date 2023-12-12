#include <iostream>
#include <string>


using namespace std;

int main()
{
    string line = "";
    std::getline(cin, line);
    
    int decimalNumber = 0;
    int binaryNumber = 0;
    int multiplier = 1;
    
    for(int i =line.length(); i>0; i--)
    {
        string number = line.substr(i-1, 1);
        binaryNumber = stoi(number.c_str());
        decimalNumber += binaryNumber * multiplier;
        multiplier *= 2;
    };
    
    std::cout << decimalNumber << std::endl;
    

    return 0;
}
