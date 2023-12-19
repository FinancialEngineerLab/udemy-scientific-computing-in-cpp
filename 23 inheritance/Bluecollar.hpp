#include <iostream>

using namespace std;

#ifndef BLUECOLLAR_HPP
#define BLUECOLLAR_HPP

class Bluecollar
{
    public:
        Bluecollar();
        Bluecollar(int, int);
        ~Bluecollar();
        
        int getHours() const;
        int getWorkers() const;
        
        void setHours(int);
        void setWorkers(int);
        
        int getSalary(int) const;
        
    private:
        int hours;
        int workers;
};

#endif
