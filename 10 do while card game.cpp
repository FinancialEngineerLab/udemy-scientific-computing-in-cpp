#include <iostream>
#include <string>


using namespace std;


int playScratchcardGame(void)
{
    int randomNumber = 0;
    randomNumber = 1+ rand() %2;
    return randomNumber;
};


int main()
{
    string blankWin = "";
    int numberScratchcardTickets = 1;
    int randomNumber = 0;
    srand(time(0));
    bool invalidInput = false;
    
    do
    {
        std::cout << "how many scratchard tickets do you want to buy? " << std::endl;
        cin >> numberScratchcardTickets;
        if(numberScratchcardTickets <= 0)
        {
            invalidInput = true;
            std::cout << "Invalid nunberm please re-enter " << std::endl;
        }
        else
        {
            int totalWins = 0;
            int totalLosts = 0;
            for(int i = 0; i<numberScratchcardTickets;i++)
            {
                randomNumber = playScratchcardGame();
                int numberWins = 0;
                int numberLosts = 0;
                if(randomNumber ==1)
                {
                    blankWin = "win";
                    numberWins++;
                    totalWins += numberWins;
                }
                else
                {
                    blankWin = "blank";
                    numberLosts++;
                    totalLosts += numberLosts;
                }
                std::cout << blankWin << std::endl;
            };
            std::cout << totalWins << std::endl;
            std::cout << totalLosts << std::endl;
            invalidInput = false;
            
        }
        
    } while(invalidInput);

    return 0;
}
