#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int scores[] = { 100, 99, 81, 87, 70,58, 30,40};
    int maxScore = 0;
    int minScore = 0;
    int total = 0;
    double avgScore = 0.0;
    
    int sizeOfArray = sizeof(scores) / sizeof(int);
    
    for(int i = 0; i<sizeOfArray; i++)
    {
        total += scores[i];
    };
    
    // 
    avgScore = total * 1.0 / sizeOfArray;
    
    maxScore = scores[0];
    minScore = scores[0];
    
    int tempScore = 0;
    
    // finding max and min with recursive
    for(int i = 0; i<sizeOfArray;i++)
    {
        tempScore = scores[i];
        if(tempScore > maxScore)
        {
            maxScore = tempScore;
        }
        if(tempScore < minScore)
        {
            minScore = tempScore;
        }
    }
    
    std::cout << total << std::endl;
    std::cout << avgScore << std::endl;
    std::cout << maxScore << std::endl;
    std::cout << minScore << std::endl;
  
    
    return 0;
}
