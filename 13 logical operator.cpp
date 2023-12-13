#include <iostream>
#include <string>

using namespace std;

int main()
{
    string studentsFirstName = "";
    string studentsLastName = "";
    int score = 0;
    int scores[3];
    
    cin >> studentsFirstName;
    cin >> studentsLastName;
    
    studentsFirstName += " " + studentsLastName;
    
    bool wrongScore;
    int total = 0;
    
    do
    {
        for(int i =0; i<5;i++)
        {
            std::cout << "socre ! " << std::endl;
            cin >> scores[i];
            total += scores[i];
            wrongScore = false;
            
            if(total > 100)
            {
                std::cout << "no 100 " << std::endl;
                wrongScore = true;
                total = 0;
            }
        }
    } while(wrongScore);
    
    if (total == 100)
    {
        std::cout << "{perfect}" << std::endl;
    }
    else if (total <= 80 ^ total >= 95)
    {
        std::cout << "good " << std::endl;
    }
    else if(total >= 50 && total <= 60)
    {
        std::cout << "bad " << std::endl;
    }
    else
    {
        std::cout << "failed " << std::endl;
    }
    
    std::cout << "full name : " << studentsFirstName << std::endl;
    std::cout << "total score : " << total << std::endl;
    
    for (int i =0;i<3;i++)
    {
        std::cout << "score # " << (i+1) << " : " << scores[i] << " " << std::endl;
    }
    
    return 0;
}
