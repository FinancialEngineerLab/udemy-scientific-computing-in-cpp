#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void getLightPerformance();
void printECE(std::vector<ECE>, double);
double calculateTotalPrice(std::vector<ECE>);

void getLightPerformance()
{
    ifstream myFile;
    myFile.open("C:\\downloads\\light_values.txt", ios::in);
    if(myFile.fail())
    {
        std::cout << " ... " << std::endl;
        exit(1);
    }
    else
    {
        string line;
        std::vector<ECE> listOfLights;
        while(getline(myFile, line))
        {
            int commaPos[2];
            int posIndex = 0;
            for(int i =0;i<line.length();i++)
            {
                if(line[i] == ',')
                {
                    commaPos[posIndex] = i;
                    posIndex++;
                }
            }
            string types = line.substr(0, commaPos[0]);
            inf efficacy = stoi(line.substr(commaPos[0] + 1, commaPos[1] - commaPos[0] -1));
            double pricees = atof(line.substr(commaPos[1] + 1).c_str());
            
            listOfLights.push_back(ECE(types, efficacy, prices));
        }
        myFile.close();
        double total = calculateTotalPrice(listOfLights);
        printECE(listOfLights, total);
    }
};

double calculateTotalPrice(std::vector<ECE> listOfLights)
{
    double total = 0.0;
    for(int i= 0;i<listOfLights.size();i++)
    {
        total += listOfLights[i].getPrice)_;
    }
    return total;
};

void printECE(std::vector<ECE> listOfLights, double total)
{
    for(int i = 0; i<listOfLights.size(); i++)
    {
        std::cout << "light type # " << (i+1) << " : " << listOfLights[i].getType();
        std::cout << ", Liminous Efficacy : " << listOfLights[i].getLuminousEfficacy() << " 1m\W";
        std::cout << ", Pirce: " << listOfLights[i].getPrice() << " Euro ";
        std::cout << ", ECE: " << fixed << setprecision(2) << listOfLights[i].calculateECE() << std::endl;
    }
    std::cout << "total .. " << fixed << setprecision(2) << total << " EUro. " << std::endl;
}



int main()
{
    getLightPerformance();
    return 0;
}
