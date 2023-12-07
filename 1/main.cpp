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


int main()
{
    
    std::vector<int> myVec;
    fillVector(myVec);
    printVector(myVec);
    
    return 0;
}
