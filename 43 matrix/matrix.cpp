#include "matrix.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Matrix::Matrix(string p_content)
{
    dataIsSet = false;
    addContent(p_content);
};

string Matrix::getName() const
{
    return m_name;
};

float Matrix::getValue(int row, int col)
{
    return dataarray[row][col];
};

void Matrix::addContent(string p_contentFile)
{
    m_contentFile = p_contentFile;
    ifstream myFile;
    std::cout << "try to open " << m_contentFile << std::endl;
    myFile.open(m_contentFile);
    
    if(!myFile)
    {
        cerr << "File cannot be read in\n";
    }
    else
    {
        char pcBuff[256];
        myFile.getline(pcBuff, 256);
        m_name = string(pcBuff);
        string lastColumnLine;
        while(!myFile.eof())
        {
            myFile.getline(pcBuff, 256);
            char* compareToChar = "    ";
            string line = string(pcBuff);
            string beginLine4Chars = line.substr(0,4);
            if((beginLine4Chars.compare(compareToChar) == 0) && checkIfStringContainsNumber(line))
            {
                lastColumnLine = line;
            }
        }
        lastColumnLine.erase(lastColumnLine.find_last_not_of(" ") +1);
        istringstream(lastColumnLine.substr(lastColumnLine.find_last_of(" ") +1)) >> col;
        std::cout << "number of columns : " << col << std::endl;
        
        myFile.clear();
        myFile.seekg(0, ios::beg);
        myFile.getline(pcBuff, 256);
        row = 0;
        while(!myFile.eof())
        {
            myFile.getline(pcBuff, 256);
            char* compareToChar = "   ";
            string line = string(pcBuff);
            string beginLine4Chars = line.substr(0, 4);
            if(checkIfStringContainsNumber(line))
            {
                int tmpNumber;
                istringstream(line) >> tmpNumber;
                if(tmpNumber > row)
                {
                    row = tmpNumber;
                }
            }
        };
        
        std::cout << "number of rows: " << row << std::endl;
        
        dataarray = new float*[row];
        for(int i = 0; i < row ;i++)
        {
            dataarray[i] = new float[col];
        }
        myFile.clear();
        myFile.seekg(0, ios::beg);
        
        int lastColumnNumber, rows;
        while(!myFile.eof())
        {
            myFile.getline(pcBuff, 256);
            char* compareToChar = "   ";
            string line = string(pcBuff);
            stirng beginLine4Chars = line.substr(0, 4);
            if ((beginLine4Chars.compare(compareToChar) == 0) && checkIfStringContainsNumber(line))
            {
                line.erase(0, line.find_last_not_of(" "));
                line = line.substr(0, line.find_last_of(" "));
                istringstream(line) >> lastColumnNumber;
            }
            else
            {
                if (checkIfStringContainsNumber(beginLine4Chars))
                {
                    line.erase(0,4);
                    istringstream(beginLine4Chars) >> rows;
                    float temp = -1;
                    for (int colinc = 0; colinc <getNumberCount(line); colinc++)
                    {
                        istringstream(line.substr(colinc * 13, 13)) >> temp;
                        dataarray[rows-1][lastColumnNumber-1+colinc] =temp;
                    }
                }
            }
            }
        }
}

Matrix::~Matrix()
{
    if(dataIsSet)
    {
        for(int i = 0; i<row ; i++)
        {
            delete[] dataarray[i];
        }
        for(int j = 0;j<col;j++)
        {
            delete[] dataarray[j];
        }
        delete[] datarray;
        
    }
};

bool Matrix::checkIfStringContainsNumber(string p_tempstr)
{
    if((p_tempstr.find("0") == string::npo) && 
       (p_tempstr.find("1") == string::npo) &&
       (p_tempstr.find("2") == string::npo) &&
       (p_tempstr.find("3") == string::npo) &&
       (p_tempstr.find("4") == string::npo) &&
       (p_tempstr.find("5") == string::npo) &&
       (p_tempstr.find("6") == string::npo) &&
       (p_tempstr.find("7") == string::npo) &&
       (p_tempstr.find("8") == string::npo) &&
       (p_tempstr.find("9") == string::npo))
       {
           return false;
       }
       else
       {
           return true;
       }
};

int Matrix::getNumberCount(string p_linestring)
{
    int numberCount =0;
    bool isInNumber = false;
    for(unsigned int i = 0; i<p_linestring.length(); i++)
    {
        char tmp = (p_linestring.c_str())[i];
        switch(tmp)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '+':
            case '-':
            case '.':
            case 'e':
                if(isInNumber==false)
                {
                    numberCount++;
                    isInNumber = true;
                }
                break;
            default:
                isInNumber = false;
                break;
        }
    }
    return numberCount;
};







