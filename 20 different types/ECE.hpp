#include <iostream>
#include <string>

using namespace std;

#ifndef ECE_H
#define ECE_H

class ECE
{
    public:
    ECE();
    ECE(string, int, double); //overload constructor
    ~ECE();
    
    void setType(string);
    void setLuminousEfficacy(int);
    void setPrice(double);
    
    string getType() const
    {
        return strType;
    };
    
    int getLuminousEfficacy() const
    {
        return intLuminousEfficacy;
    };
    
    double getPrice() const
    {
        return dblPrice;
    };
    
    double calculateECE();
    
    private:
    string strType;
    int intLuminousEfficacy;
    double dblPrice;
    
};

#endif
