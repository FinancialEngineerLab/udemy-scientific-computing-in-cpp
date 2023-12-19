#include "guest.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fillVectorOfObjects(std::vector<Guest>&);
void printVectorOfObjects(std::vector<Guest>&);

void fillVectorOfObjects(std::vector<Guest>& newDaysOfReservations)
{
    string name;
    int days;
    int numOfGuests;
    
    cin >> numOfGuests;
    
    for(int i = 0; i<numOfGuests;i++)
    {
        std::cout << "Guest Name : ";
        cin >> name;
        std::cout << "Reserved days: ";
        cin >> days;
        
        newDaysOfReservations.push_back(Guest(name, days));
    }
};

void printVectorOfObjects(std::vector<Guest>& newDaysOfReservations)
{
    for(int i = 0; i<newDaysOfReservations.size(); i++)
    {
        std::cout << "Guest name : " << newDaysOfReservations[i].getName() << std::endl;
        std::cout << "Reserved days : " << newDaysOfReservations[i].getDays() << std::endl;
        std::cout << "Charges : " << newDaysOfReservations[i].calculateCharges() << std::endl;
        
    }
}


int main()
{
    
    std::vector<Guest> daysOfReservations;
    fillVectorOfObjects(daysOfReservations);
    printVectorOfObjects(daysOfReservations);
    
    
    return 0;
}
