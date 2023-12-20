#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class carDealer
{
    protected:
        int numberOfCars;
    public:
        carDealer(int number = 0) : numberOfCars(number) {}
        virtual ~carDealer(){};
        virtual int value() const = 0;
};

class Ferrari: public carDealer
{
    public:
        static int price;
        Ferrari(int number) : carDealer(number) { std::cout << " Ferrari " << number << std::endl;}
        virtual int value() const { return numberOfCars * price;}
};

class Audi : public carDealer
{
    public:
        static int price;
        Audi(int number) : carDealer(number) {std::cout << " Audi " << number << std::endl; }
        virtual int value() const { return numberOfCars * price; }
};

int Ferrari :: price = 200000;
int Audi :: price = 60000;


int main()
{
    carDealer* C;
    Ferrari F(2);
    Audi A(4);
    int sum = 0;
    
    C = &F;
    std::cout << "type of polymorphic object is : " << typeid(*C).name() << std::endl;
    sum += (*C).value();
    C = &A;
    std::cout << "type of polymorphic object is : " << typeid(*C).name() << std::endl;
    sum += (*C).value();
    std::cout << "totla price of all ordered cars is : " << sum << " Euros\n";

    return 0;
}
