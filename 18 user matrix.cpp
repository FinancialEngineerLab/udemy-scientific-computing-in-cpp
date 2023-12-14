#include <iostream>
#include <vector>

using namespace std;

void defineVector(std::vector<std::vector<int> >&);
void printVector(const std::vector<std::vector<int> >&);
int calculateSum(std::vector<std::vector<int> >&);

void defineVector(std::vector<std::vector<int> >& myVector)
{
    int row, col;
    cin >> row;
    cin >> col;
    
    for (int i =0;i<row;i++)
    {
        std::vector<int> temp;
        for(int j =0; j<col; j++)
        {
            temp.push_back(j);
        }
        myVector.push_back(temp);
    };
    int input;
    std::cout << row * col << std::endl;
    
    for(int i =0; i<myVector.size();i++)
    {
        for(int j = 0; j<myVector[i].size();j++)
        {
            cin >> input;
            myVector[i][j] = input;
        }
    };
};

void printVector(const std::vector<std::vector<int> >& myVector)
{
    for(int i =0; i<myVector.size();i++)
    {
        for (int j = 0;j<myVector[i].size(); j++)
        {
            std::cout << myVector[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

int calculateSum(std::vector<std::vector<int> >& myVector)
{
    int total = 0;
    for(int i = 0;i<myVector.size();i++)
    {
        for(int j =0;j<myVector[i].size();j++)
        {
            total += myVector[i][j];
        }
    }
    return total;
};

int main()
{
    std::vector<std::vector<int> > matrix;
    defineVector(matrix);
    printVector(matrix);
    std::cout << calculateSum(matrix) << std::endl;
    return 0;
}
