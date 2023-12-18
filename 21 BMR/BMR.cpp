#include "BMR.hpp"

BMR::BMR()
{
    int intAge_ = 0;
    int intHeight_ = 0;
    double dblWeight_ = 0.0;
};

BMR::BMR(int age, int height, double weight)
{
    intAge_ = age;
    intHeight_ = height;
    dblWeight_ = weight;
};

BMR::~BMR()
{
};

void BMR::setAge(int age)
{
    intAge_ = age;
};

void BMR::setHeight(int height)
{
    intHeight_ = height;
};

void BMR::setWeight(double weight)
{
    dblWeight_ = weight;
};

double BMR::calculateBMRMale()
{
    return (66.0 + (13.8 * dblWeight_) + (5.0 * intHeight_) - (6.8 * intAge_));
};

double BMR::calculateBMRFemale()
{
    return (655.0 + (9.5 * dblWeight_) + (1.9 * intHeight_) - (4.7 * intAge_));
};
