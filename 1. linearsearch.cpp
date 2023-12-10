#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fillVector(std::vector<int>& inputVec);
void fillVector(std::vector<int>& inputVec)
{
    int input;
    std:: cout << " ";
    cin >> input;
    
    while(input != -1)
    {
        inputVec.push_back(input);
        cin >> input;
    };
};

void printVector(const std::vector<int>& inputVec);
void printVector(const std::vector<int>& inputVec)
{
    std::cout << " existing numbers are ";
    for(int i = 0; i<inputVec.size(); i++)
    {
        std::cout << inputVec[i] << " ";
    }
    std::cout << std:: endl;
};

bool searchVector(int enteredNumber, std::vector<int>& inputVec);
bool searchVector(int enteredNumber,  std::vector<int>&inputVec)
{
    for (int i =0; i<inputVec.size();i++)
    {
        if(enteredNumber == inputVec[i])
        {
            return true;
        }
    };
    return false;
}

int main()
{
    
    std::vector<int> myVec;
    fillVector(myVec);
    printVector(myVec);
    
    int enteredNumber = 0;
    cin >> enteredNumber;
    
    if(searchVector(enteredNumber, myVec) == true)
    {
        std::cout << "number already exists ! " << std::endl;
    }
    else
    {
        std::cout << "number was not typed in before ! " << std::endl;
    };
    return 0;
}
