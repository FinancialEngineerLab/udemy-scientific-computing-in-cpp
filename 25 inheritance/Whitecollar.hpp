#include "Bluecollar.hpp"
#include <iostream>

#ifndef WHITECOLLAR_HPP
#define WHITECOLLAR_HPP

class Whitecollar : public Bluecollar
{
    public:
        Whitecollar();
        Whitecollar(int, int, int, int);
        ~Whitecollar();
        
        int getHourlywage() const;
        int getBonus() const;
        
        void setHourlywage(int);
        void setBonus(int);
        
        int getSalaryBonus() const;
        void printSalary() const;
        
    private:
        int hourlywage, bonus;
        static int companyBalance;
};

#endif 
