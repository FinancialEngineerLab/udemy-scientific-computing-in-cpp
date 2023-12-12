#include <iostream>
#include <string>
#include <ctime>

using namespace std;


int playScratchcardGame(void)
{
    int randomNumber = 0;
    randomNumber = 1+ rand() %2;
    return randomNumber;
};


int main()
{
    int randNumber1, randNumber2;
    int userAnswer, compAnswer;
    bool wrongAnswer;
    
    srand(time(0));
    
    randNumber1 = 1 + rand() % 20;
    randNumber2 = 1 + rand() % 20;
    
    compAnswer = randNumber1 * randNumber2;
    
    std::cout << randNumber1 << " & " << randNumber2 << ": ";
    
    do
    {
        cin >> userAnswer;
        if(userAnswer != compAnswer)
        {
            std::cout << "wrong " << std::endl;
            wrongAnswer = true;
        }
        else if (userAnswer == compAnswer)
        {
            std::cout << "correct " << std::endl;
            std::cout << randNumber1 << " x " << randNumber2 << "is : " <<compAnswer << std::endl;
            wrongAnswer = false;
        }
    } while(wrongAnswer == true);
    
    return 0;
}
