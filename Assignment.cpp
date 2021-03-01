#include<iostream>
using namespace std;

const int SIZE = 100;

class StudentMarks
{
 private:

    struct Student
    {
        string name;
        int id, chem, math, phy;
    };

    Student student[SIZE];
    int head,tail;

 public:
    StudentMarks()
    {
       
    }

    void deleteStudent()
    {
        int found=0, ID;
        char choice;
        
            cout << "Please Enter Student ID to delete: ";
            cin >> ID;
            found = linearSearch(ID);

            if(found != -1){
            cout << "Target found"<< endl;
            cout << "\nStudent ID: " << student[found].id;
            cout << "\nStudent name: " << student[found].name;
            cout << "\nSubjects mark: ";
            cout << "\n\t1.Chemistry: " << student[found].chem;
            cout << "\n\t1.Physics: " << student[found].phy;
            cout << "\n\t1.Mathematics: " << student[found].math;

            cout << "Are you sure want to delete? [Y/N] ";
            cin >> choice;

            if(choice == 'Y' || choice == 'y'){
                student[found].id=-1; student[found].name = " "; student[found].chem=-1; student[found].phy=-1; student[found].math=-1;
            }
            
            }else{
                cout << "StudentID is not found" ;
            }
    }

    void search()
    {
        int value, found=0;
        char choice;
        do{
            cout << "Please Enter Student ID to search: ";
            cin >> value;
            found = linearSearch(value);

            if(found != -1){
            cout << "Target found"<< endl;

            cout << "\nStudent ID: " << student[found].id;
            cout << "\nStudent name: " << student[found].name;
            cout << "\nSubjects mark: ";
            cout << "\n\t1.Chemistry: " << student[found].chem;
            cout << "\n\t1.Physics: " << student[found].phy;
            cout << "\n\t1.Mathematics: " << student[found].math;

            }else{
                cout << "StudentID is not found" ;
            }

            cout << "Search again?[Y/N] ";
            cin >> choice;
        }while(choice != 'Y' || choice != 'y');
        
    }

    int linearSearch(int value)
    {
        for (int i=0; i<=SIZE; i++)
        {
            if (student[i].id == value)
                return i;
        }
        return -1;	
    }
};
