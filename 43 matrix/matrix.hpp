#include<string>
#include <iomanip>

#ifndef Matrix_HPP
#define Matrix_HPP

using namespace std;

class Matrix
{
    public:
        Matrix();
        Matrix(string);
        ~Matrix();
        
        void addContent(string);
        string getName() const;
        float getValue(int, int);
        
    private:
        float** dataarray;
        int row, col;
        string m_name, m_contentFile;
        bool dataIsSet;
        bool checkIfStringContainsNumber(string);
        int getNumberCount(string);
};

#endif
