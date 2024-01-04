#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>

using namespace std;

void initializeArray(int**, int, int);
int calculateEnergyDelta(int**, int, int, int);
void sampleArray(int**, int, double& ,double&);

void initializeArray(int** array, int sideLength, int random)
{
    for(int i =0; i<sideLength; i++)
    {
        for(int j = 0; j<sideLength;j++)
        {
            array[i][j] = 2 * (random) - 1;
        }
    }
};

int calculateEnergyDelta(int** array, int sideLength, int i, int j)
{
    return (-2 * (array[i][j]) * (array[(i+1 + sideLength) % sideLength][j]
                                + array[(i-1 + sideLength) % sideLength][j]
                                + array[(j+1 + sideLength) % sideLength][i]
                                + array[(j-1 + sideLength) % sideLength][i]));
};

void sampleArray(int** array, int sideLength, double& spin, double& energy)
{
    spin, energy = 0.0;
    
    for(int i = 0; i<sideLength;i++)
    {
        for (int j = 0; j<sideLength;j++)
        {
            spin += static_cast<double>(array[i][j]);
            energy -= static_cast<double>(array[i][j] * (array[i][(j+1) % sideLength]
                                                        +array[(i+1) % sideLength][j]));
        }
    }
    spin /= std::pow(sideLength, 2);
    energy /= std::pow(sideLength, 2);
    
}


int main()
{
    int** array;
    int sideLength = 30;
    int numberOfCycles = 10000;
    int frequecnySampling = 1000;
    
    double temperature = 5.0;
    temperature = 1.0/temperature;
    
    mt19937_64 gen;
    uniform_int_distribution<int> dist1(0, 2);
    uniform_int_distribution<int> dist2(0, 19);
    uniform_real_distribution<double> dist3(0, 1);
    
    int numberOfSamples = 0;
    int delta_E;
    double BoltzmannFactor;
    
    double spin = 0.0;
    double spinSum = 0.0;
    double energy = 0.0;
    double energySum = 0.0;
    
    array = new int*[sideLength];
    for(int i =0; i<sideLength; i++)
    {
        array[i] = new int[sideLength];
    }
    
    int randomNumber = dist1(gen);
    initializeArray(array, sideLength, randomNumber);
    
    for(int counter = 0; counter < numberOfCycles; counter++)
    {
        for(int average=0;average < sideLength; average++)
        {
            int i = dist2(gen);
            int j = dist2(gen);
            delta_E = calculateEnergyDelta(array, sideLength, i ,j);
            BoltzmannFactor = exp(delta_E * temperature);
            double x = dist3(gen);
            
            if(x<BoltzmannFactor)
            {
                array[i][j] *= -1;
            }
        }
        if(counter% frequecnySampling ==0)
        {
            sampleArray(array, sideLength, spin, energy);
            std::cout << " loops : "<< counter << fixed << setprecision(3) << "\t spin: " << spin << "\t energy: " << energy << std::endl;
            spinSum += spin;
            energySum += energy;
            numberOfSamples++;
        }
    }
    
    std::cout << "average magnetization is : "<< fixed << setprecision(3) << spinSum / numberOfSamples << std::endl;
    std::cout << "average energy per spin is : "<< fixed << setprecision(3) << energySum / numberOfSamples << std::endl;
    
    for(int i = 0; i<sideLength; i++)
    {
        delete[] array[i];
        for(int j =0;j<sideLength;j++)
        {
            delete[] array[j];
        }
        delete[] array;
    }
    return 0;
}
