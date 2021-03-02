#include<iostream>
using namespace std;

const int SIZE = 10;

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
        Student temp[SIZE];
        int found=0, ID;
        char choice;

        /*          Testing          */                   
        for(int i=0; i<2; i++){
        cout << "Student " << i+1 << " ID: ";
        cin >> student[i].id;
        cout << "Student " << i+1 << " name: ";
        cin >> student[i].name;
         cout << "chemistry: ";
        cin >> student[i].chem;
         cout << "Phy: ";
        cin >> student[i].phy;
         cout << "math: " ;
        cin >> student[i].math;
        }
        /*          End Test        */
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

            cout << "\n\nAre you sure want to delete? [Y/N] ";
            cin >> choice;

            if(choice == 'Y' || choice == 'y'){
                for(int i=0; i<SIZE; i++){
                        temp[i] = student[i];
                }

                for(int i=0; i<SIZE; i++){
                    if(temp[i].id != ID)
                        student[i]=temp[i];
                }
                //student[found].id=-1; student[found].name = " "; student[found].chem=-1; student[found].phy=-1; student[found].math=-1;
            }
            
            }else{
                cout << "StudentID is not found" ;
            }
    }


    void search()
    {
        int value, found=0;
        char choice;

        /*          Testing          */                   
        for(int i=0; i<2; i++){
        cout << "Student " << i+1 << " ID: ";
        cin >> student[i].id;
        cout << "Student " << i+1 << " name: ";
        cin >> student[i].name;
         cout << "chemistry: ";
        cin >> student[i].chem;
         cout << "Phy: ";
        cin >> student[i].phy;
         cout << "math: " ;
        cin >> student[i].math;
        }
        /*          End Test        */
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

int main()
{
    //Student s[SIZE];
    StudentMarks sm;
    string name;
    int value, found;
    char grade;

    sm.deleteStudent();

    

    return 0;
}

