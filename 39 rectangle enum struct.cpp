#include <iostream>
#include <string>

using namespace std;

enum Figure { rectangle, rightTriangle };

struct FigureProperties
{
    double sidelengthA, sidelengthB, area;
    string geometry;
};

double areaCalculator(Figure F, double a , double b)
{
    double area;
    
    switch(F)
    {
        case rectangle:
            area = a* b;
            break;
        case rightTriangle:
            area = (a*b)/ 2.0;
            break;
    }
    return area;
};

int main()
{
    FigureProperties re, rt;
    int choice = 0;
    do
    {
        std::cout << "1 for rectangle, 2 for right trigane, 3 for exit" << std::endl;
        
        cin>> choice;
        
        while( choice < 1 || choice > 3)
        {
            std::cout << "invalid " << std::endl;
            cin >> choice;
        }
        switch(choice)
        {
            case 1:
                std::cout << "lenght a, b " << std::endl;
                cin >> re.sidelengthA >> re.sidelengthB;
                re.geometry = "rectangle";
                re.area = areaCalculator(rectangle, re.sidelengthA, re.sidelengthB);
                std::cout << "calced " << re.geometry << " is : " << re.area << std::endl;
                break;
            case 2:
                std::cout << "lenght a, b " << std::endl;
                cin >> re.sidelengthA >> re.sidelengthB;
                re.geometry = "right rectangle";
                re.area = areaCalculator(rightTriangle, re.sidelengthA, re.sidelengthB);
                std::cout << "calced " << re.geometry << " is : " << re.area << std::endl;
                break;
            default:
                std::cout << "exit " << std::endl;
        }
    } while(choice != 3);

    return 0;
}
