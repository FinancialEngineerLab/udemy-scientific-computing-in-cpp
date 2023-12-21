#include <iostream>
#include <string>

const int CAPCAITY = 30;

using namespace std;

string studentName[CAPACITY];
string subject[CAPACITY];
int studentScore[CAPACITY];

void studentInfo(string, string, int);
void lookUpStudent();
void addStudent();
void editStudent();
void deleteStudent();

void studentInfo(string studentName, string subject, int studentScore)
{
    std::cout << "name: " << studentName << std::endl;
    std::cout << "subject: " << subject << std::endl;
    std::cout << "studentScore: " << studentScore << std::endl;
};

void lookUpStudent()
{
    bool foundRecord = false;
    int arrIndex = 0;
    string searchStudent;
    cin.ignore();
    
    std::cout << "enter name : " << std::endl;
    getline(cin, searchStudent);
    
    while(!foundRecord && arrIndex < CAPACITY)
    {
        if (studentName[arrIndex] == searchStudent)
        {
            foundRecord = true;
        }
        else
        {
            arrIndex++;
        }
    }
    
    if(foundRecord)
    {
        studentInfo(studentName[arrIndex], subject[arrIndex], studentScore[arrIndex]);
        std::cout << std::endl;
    }
    else
    {
        std::cout << " no found " << std::endl;    
    }
};

void addStudent()
{
    bool foundRecord = false;
    int arrIndex = 0;
    
    while(!foundRecord && arrIndex < CAPACITY)
    {
        if(studentName[arrIndex] == "")
        {
            foundRecord = true;
        }
        else
        {
            arrIndex++;
        }
    }
    
    if(foundRecord)
    {
        cin.ignore();
        std::cout << "name : " << std::endl;
        getline(cin, studentName[arrIndex]);
        std::cout << "subject : " << std::endl;
        getline(cin, subject[arrIndex]);
        
        std::cout << "score : " << std::endl;
        cin >> studentScore[arrIndex];
        std::cout << std::endl;
    }
    else
    {
        std::cout << "size of max , no exceed " << std::endl;
    }
};

void editStudent()
{
    bool foundRecord = false;
    int arrIndex = 0;
    int submenuChoice = 0;
    string searchStudent;
    
    cin.ignore();
    std::cout << "name : " << std::endl;
    getline(cin, searchStudent);
    
    while(!foundRecord && arrIndex < CAPACITY)
    {
        if(studentName[arrIndex] == searchStudent)
        {
            foundRecord = true;
        }
        else
        {
            arrIndex++;
        }
    };
    if(foundRecord)
    {
        studentInfo(studentName[arrIndex], subject[arrIndex], studentScore[arrIndex]);
        do
        {
            std::cout << "edit " << std::endl;
            std::cout << "1. name" << std::endl;
            std::cout << "2. subject" << std::endl;
            std::cout << "3. score" << std::endl;
            std::cout << "4. exit" << std::endl;
            cin >> submenuChoice;
            
            while(submenuChoice < 1 || submenuChoice > 4)
            {
                std::cout << "range of 1-4" << std::endl;
                std::cout << "re-enter " << std::endl;
                cin >> submenuChoice;
            }
            
            switch(submenuChoice)
            {
                case 1:
                    std::cout << "current name ";
                    std::cout << studentName[arrIndex] << std::endl;
                    cin.ignore();
                    std::cout << "enter new name ";
                    getline(cin, studentName[arrIndex]);
                    break;
                case 2:
                    std::cout << "current subject ";
                    std::cout << subject[arrIndex] << std::endl;
                    cin.ignore();
                    std::cout << "enter new subject ";
                    getline(cin, subject[arrIndex]);
                    break;
                case 3:
                    std::cout << "current score ";
                    std::cout << studentScore[arrIndex] << std::endl;
                    cin.ignore();
                    std::cout << "enter new score ";
                    getline(cin, studentScore[arrIndex]);
                    break;
                case 4:
                    std::cout << "exit " << std::endl;
                    break;
            }
        } while(submenuChoice != 4);
            
    }
    else
    {
        std::cout << " no list ! " << std::endl;
    }
}

void deleteStudent()
{
    bool foundRecord = false;
    int arrIndex = 0;
    int menuChoice = 0;
    string searchStudent;
    char confirmDeletion;
    
    cin.ignore();
    std::cout << "delete ! " << std::endl;
    getline(cin, searchStudent);
    
    while(!foundRecord && arrIndex < CAPACITY)
    {
        if(studentName[arrIndex] == searchStudent)
        {
            foundRecord = true;
        }
        else
        {
            arrIndex++;
        }
    }
    if(foundRecord)
    {
        studentInfo(studentName[arrIndex], subject[arrIndex], studentScore[arrIndex]);
        std::cout << "delete ?? " << std::endl;
        cin >> confirmDeletion;
        
        if(confirmDeletion == 'Y' || confirmDeletion == 'y')
        {
            studentName[arrIndex] ="";
            subject[arrIndex] = "";
            studentScore[arrIndex] = 0;
        }
    }
    else
    {
        std::cout << " no list ! " <<std::endl;
    }
    
}

int main()
{
    int menuChoice = 0;
    do
    {
        cin>>menuChoice;
        
        while(menuChoice <1 || menuChoice >5)
        {
            std::cout << "no range: re-enter "<< std::endl;
            cin >> menuChoice;
        }
        
        switch(menuChoice)
        {
            case 1:
                lookUpStudent();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            default:
                std::cout << "exit " <<std::endl;
                break;
                                
        }
    } while(menuChoice != 5);

    return 0;
}
