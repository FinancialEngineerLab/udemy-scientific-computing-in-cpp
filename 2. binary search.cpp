#include <iostream>
#include <vector>

using namespace std;

void fillVector(std::vector<int>&);
void printVector(const std::vector<int>&);
void sortVector(std::vector<int>&);
bool binarySearchAlgorithm(int, const std::vector<int>&);

void fillVector(std::vector<int>& newMyVector)
{
    int input;
    std::cout << "please type in the numbers and stop with (-1): ";
    cin >> input;
    
    while (input != -1)
    {
        newMyVector.push_back(input);
        cin >> input;
    }
};

void printVector(const std::vector<int>& newMyVector)
{
    std::cout << "the typed in numbers are: ";
    for(int i =0; i<newMyVector.size();i++)
    {
        std::cout << newMyVector[i] << " ";
    }
    std::cout << std::endl;
};

void sortVector(std::vector<int>& newMyVector)
{
    int minI, minE = 0;
    for (int i = 0; i<newMyVector.size() - 1; i++)
    {
        minE = newMyVector[i]; 
        minI = i;
        for(int j = i + 1; j<newMyVector.size(); j++)
        {
            if (newMyVector[j] < minE)
            {
                minE = newMyVector[j];
                minI = j;
            };
        };
        int temp = newMyVector[i];
        newMyVector[i] = minE;
        newMyVector[minI] = temp;
    }
    printVector(newMyVector);
};


bool binarySearchAlgorithm(int enteredNumber, const std::vector<int>& newMyVector)
{
    int low = 0;
    int mid = 0;
    int high = newMyVector.size() - 1;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        if (newMyVector[mid] == enteredNumber)
        {
            return true;
        }
        else if (newMyVector[mid] > enteredNumber)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        };
    };
    return false;
};

int main()
{
    std::vector<int> myVector;
    fillVector(myVector);
    printVector(myVector);
    sortVector(myVector);
    
    int enteredNumber = 0;
    std::cout << "Please type in an int to compare with the unbers in the lis: ";
    cin >> enteredNumber;
    
    if(binarySearchAlgorithm(enteredNumber, myVector) == true)
    {
        std::cout << "the number already exists ! " << std::endl;
    }
    else
    {
        std::cout << "the number was not typed in before !  "<< std::endl;
    }
    return 0;
};
