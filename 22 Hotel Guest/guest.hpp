#include <iostream>
#include <string>

using namespace std;

#ifndef GUEST_HPP
#define GUEST_HPP

class Guest
{
    public:
        Guest();
        Guest(string ,int);
        ~Guest();
        
        void setName(string);
        void setDays(int);
        
        string getName() const;
        int getDays() const;
        
        double calculateCharges();
        
    private:
        string strName;
        int intDays;
};

#endif
