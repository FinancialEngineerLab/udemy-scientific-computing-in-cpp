#include "Whitecollar.hpp"

int Whitecollar::companyBalance = 100000;

Whitecollar::Whitecollar()
{
    hourlywage = 0;
    bonus = 0;
};

Whitecollar::Whitecollar(int newHourlywage, int newBonus, int newHours, int newWorkers)
    : Bluecollar(newHours, newWorkers)
{
    hourlywage = newHourlywage;
    bonus = newBonus;
};

Whitecollar::~Whitecollar()
{

};

int Whitecollar::getHourlywage() const
{
    return hourlywage;
};

int Whitecollar::getBonus() const
{
    return bonus;
};

void Whitecollar::setHourlywage(int newHourlywage)
{
    hourlywage = newHourlywage;
};

void Whitecollar::setBonus(int newBonus)
{
    bonus = newBonus;
};

int Whitecollar::getSalaryBonus() const
{
    return (getSalary(hourlywage) + bonus);
};

void Whitecollar::printSalary() const
{
    std::cout << getSalary(hourlywage) << std::endl;
    std::cout << getSalaryBonus() << std::endl;
    companyBalance -= (getSalaryBonus() + getSalary(hourlywage));
    std::cout << companyBalance << std::endl;
}
