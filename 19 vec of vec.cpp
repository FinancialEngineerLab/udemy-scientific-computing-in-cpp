
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int const COLS = 3;

int main()
{
    std::vector<std::vector<double> > data;
    std::vector<double> rowVector(COLS);
    int row = 0;
    
    ifstream myFile;
    myFile.open("c:\\Temp\\data.txt", ios::in);
    
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            data.push_back(rowVector);
            for(int col = 0; col <COLS;col++)
            {
                myFile >> data[row][col];
            }
            row++;
        }
    }
    else
    {
        exit(1);
    }
    myFile.close();
    
    for(int i =0; i<data.size();i++)
    {
        for(int j =0; j<data[i].size();j++)
        {
            std::cout << fixed << setprecision(1) << data[i][j] << " ";
        };
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::vector<double> rowSum;
    for(int i =0;i<data.size(); i++)
    {
        double rowSum = 0.0;
        for(int j =0;j<data[i].size();j++)
        {
            rowSum += data[i][j];
        }
        std::cout << "sum of row # " << i+1 << " : " << rowSum << std::endl;
    }
    std::cout << std::endl;
    
    std::vector<double> colSum;
    
    for(int i = 0;i<data.size(); i++)
    {
        double colSum = 0.0;
        for(int j = 0; j<data[i].size();j++)
        {
            colSum += data[j][i];
        }
        std::cout << "sum of col # " << i +1 << " : " << colSum << std::endl;
    }
    
    
    return 0;
}
