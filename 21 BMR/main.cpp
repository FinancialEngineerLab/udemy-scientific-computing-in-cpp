#include <iostream>
#include "BMR.hpp"

using namespace std;

int main()
{
    int age;
    int height;
    double weight;
    
    std::cout << "m: male, f: female" << std::endl;
    char input;
    cin >> input;
    
    if(input == 'f')
    {
        std::cout << "age ?" << std::endl;
        cin >> age;
        std::cout << "height ?" << std::endl;
        cin >> height;
        std::cout << "weight ?" << std::endl;
        cin >> weight;
        
        BMR Female(age, height, weight);
        std::cout << Female.getAge() << std::endl;
        std::cout << Female.getHeight() << std::endl;
        std::cout << Female.getWeight() << std::endl;
        std::cout << Female.calculateBMRFemale() << std::endl;
        
    }

    else
    {
        std::cout << "age ?" << std::endl;
        cin >> age;
        std::cout << "height ?" << std::endl;
        cin >> height;
        std::cout << "weight ?" << std::endl;
        cin >> weight;
        
        BMR Male;
        Male.setAge(age);
        Male.setHeight(height);
        Male.setWeight(weight);
        
        std::cout << "age " <<  Male.getAge() << std::endl;
        std::cout << "height(cm) " <<  Male.getHeight() << std::endl;
        std::cout << "weight(kg) " <<  Male.getWeight() << std::endl;
        std::cout <<  "BMR(kcal) " << Male.calculateBMRFemale() << std::endl;
        
    }

    return 0;
}
