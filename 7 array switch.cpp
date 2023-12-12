#include <iostream>
#include <string>


using namespace std;

int main()
{
    double itemPrices[3] = {1.5, 2.5, 3.5};
    string items[3] = {"Butter", "Milk", "Eggs"};
    double totalInvoice[] = {0.0, 0.0, 0.0};
    
    int numOfItems = 0;
    int itemNum = 0;
    
    while(numOfItems != -1)
    {
        for(int j = 0; j<3;j++)
        {
            if(numOfItems != -1)
            {
                std::cout << j+1 << " for " << items[j] 
                 << "which costs " << itemPrices[j] << " euros (stop by entering -1)" << std::endl;
                 cin >> numOfItems;
                 
                 if(numOfItems != -1)
                 {
                     cin >> itemNum;
                     switch(itemNum)
                     {
                        case 1:
                            totalInvoice[0] += itemPrices[0] * numOfItems;
                            break;
                        case 2:
                            totalInvoice[1] += itemPrices[1] * numOfItems;
                            break;
                        case 3:
                            totalInvoice[2] += itemPrices[2] * numOfItems;
                            break;
                        default:
                            std::cout << " invalid input " << std::endl;
                            break;
                     }
                 }
            }
        };
    };
    int sum=0;
    for(int i =0; i<3; i++)
    {
        std::cout << "total for item # " << i+1 << " is : " << totalInvoice[i] << std::endl;
        sum += totalInvoice[i];
    };
    
    std::cout << sum << std::endl;

    return 0;
}
