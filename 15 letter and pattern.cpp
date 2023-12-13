#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int ROWS = 13;
const int COLS = 13;
const char WHITESPACE = ' ';
const char STAR = '*';

void DisplayA();
void DisplayI();
void DisplayC();
void DisplayPlus();
void DisplayX();

void DisplayA()
{
    for(int r = 0; r<ROWS;r++)
    {
        for(int c = 0; c<COLS;c++)
        {
            if(r==0 || r== ROWS / 2)
            {
                std::cout << STAR;
            }
            else if(c==0 || c== COLS-1)
            {
                std::cout << STAR;
            }
            else
            {
                std::cout << WHITESPACE;
            }
        }
       
    std::cout << std::endl;
    }
}


void DisplayI()
{
    for(int r = 0; r<ROWS;r++)
    {
        for(int c = 0; c<COLS;c++)
        {
            if(c == COLS/2)
            {
                std::cout << STAR;
            }
            else
            {
                std::cout << WHITESPACE;
            }
        }
       
    std::cout << std::endl;
    }
}



void DisplayC() 
{
	for (int r = 0; r < ROWS; r++) 
	{
		for (int c = 0; c < COLS; c++) 
		{
			if (r == 0 || r == ROWS -1) //in the first iteration: r = 0; c = 0 up to 12
										//r = 12; c = 0 up to 12
			{
				cout << STAR;	
			}
			else if (c == 0)			//c = 0; r = 0 up to 12
			{
				cout << STAR;
			}
			else
				cout << WHITESPACE;
		}
	cout << endl;
	}
}

void DisplayPlus() 
{
	for (int r = 0; r < ROWS; r++) 
	{
		for (int c = 0; c < COLS; c++) 
		{
			if (r==ROWS/2) //in the first iteration: r = 0; c = 0 up to 12
										//r = 12; c = 0 up to 12
			{
				cout << STAR;	
			}
			else if (c == COLS/2)			//c = 0; r = 0 up to 12
			{
				cout << STAR;
			}
			else
				cout << WHITESPACE;
		}
	cout << endl;
	}
}

void DisplayX() 
{
	for (int r = 0; r < ROWS; r++) 
	{
		for (int c = 0; c < COLS; c++) 
		{
			if (r==c) //in the first iteration: r = 0; c = 0 up to 12
										//r = 12; c = 0 up to 12
			{
				cout << STAR;	
			}
			else if (c == COLS-1-r)			//c = 0; r = 0 up to 12
			{
				cout << STAR;
			}
			else
				cout << WHITESPACE;
		}
	cout << endl;
	}
}



int main()
{
    char pattern [ROWS][COLS];
    std::cout << std::endl;
    DisplayA();
    
    std::cout << std::endl;
    DisplayI();
    
    std::cout << std::endl;
    DisplayC();
    
    std::cout << std::endl;
    DisplayPlus();
    
    std::cout << std::endl;
    DisplayX();
    
    std::cout << std::endl;
    return 0;
}
