1#include <iostream>
#include <string>

using namespace std;

#ifndef BMR_HPP
#define BMR_HPP

// Harris - Benedict Formual for BMR //

class BMR
{
    public:
        BMR();
        BMR(int, int, double);
        ~BMR();
        
        // Mutator //
        void setAge(int);
        void setHeight(int);
        void setWeight(double);
        
        // accessor //
        int getAge() const
        {
            return intAge_;
        };
        
        int getHeight() const
        {
            return intHeight_;
        };
        
        double getWeight() const
        {
            return dblWeight_;
        };
        
        double calculateBMRMale();
        double calculateBMRFemale();
        
    private:
        int intAge_;
        int intHeight_;
        double dblWeight_;
};

#endif
