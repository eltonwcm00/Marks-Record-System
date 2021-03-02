#include<iostream>
using namespace std;

const int SIZE = 100;

class StudentMarks {

    private:

        struct Student {

            string name;
            int id, chem, math, phy;
        };

        Student student[SIZE];

        int number{};


    public:

        StudentMarks() = default;

        void addStudent() {

            int studentHash[SIZE];

            cout << "How many record of students you would like to insert ? : ";
            cin >> number;

            for(int x = 0; x < number; x++) {

                cout << "\nStudent "<< x + 1<<" ID [In the form of 4 digits, 1XXX - 9XXX] : ";
                cin >> student[x].id;

                while(student[x].id < 1000 || student[x].id > 9999) {

                    cout << "Input out of range."<<endl<<endl;
                    cout << "Enter student "<< x + 1<<" ID again! [In the form of 4 digits, start with 1XXX] : ";
                    cin >> student[x].id;
                }

                cout << "Student " << x+1 << " name : ";
                cin >> student[x].name;
                cout << "Chemistry marks of student "<< x+1 <<" : ";
                cin >> student[x].chem;
                cout << "Physic marks of student "<< x+1 <<" : ";
                cin >> student[x].phy;
                cout << "Mathematics marks of student "<< x+1 <<" : ";
                cin >> student[x].math;

                cout<<endl;
            }

            linearHashing();

        }

        void deleteStudent() {

            Student temp[number];
            int found = 0, ID;
            char choice;

            cout << "Please Enter Student ID to delete: ";
            cin >> ID;

            found = linearSearch(ID);

            if(found != -1) {

                cout << "Target found"<< endl;
                cout << "\nStudent ID: " << student[found].id;
                cout << "\nStudent name: " << student[found].name;
                cout << "\nSubjects mark: ";
                cout << "\n\t1.Chemistry: " << student[found].chem;
                cout << "\n\t1.Physics: " << student[found].phy;
                cout << "\n\t1.Mathematics: " << student[found].math;

                cout << "\n\nAre you sure want to delete? [Y/N] ";
                cin >> choice;

                if(choice == 'Y' || choice == 'y') {

                    for(int i = 0; i < number; i++) {

                        temp[i] = student[i];
                    }

                    for(int i = 0; i < number; i++) {

                        if(temp[i].id != ID) {
                            student[i] = temp[i];
                        }
                    }
                }
            
            } else {

                cout << "StudentID is not found" ;
            }
    }


        void searchStudent() {

            int value, found = 0;
            char choice;

            do {

                cout << "Please Enter Student ID to search: ";
                cin >> value;
                found = linearSearch(value);

                if(found != -1) {

                    cout << "Target found"<< endl;

                    cout << "\nStudent ID: " << student[found].id;
                    cout << "\nStudent name: " << student[found].name;
                    cout << "\nSubjects mark: ";
                    cout << "\n\t1.Chemistry: " << student[found].chem;
                    cout << "\n\t1.Physics: " << student[found].phy;
                    cout << "\n\t1.Mathematics: " << student[found].math;

                } else {

                    cout << "StudentID is not found" ;
                }

                cout << "Search again?[Y/N] ";
                cin >> choice;

            } while(choice != 'Y' || choice != 'y');
        }

        /************************** ALGORITHM **************************/

        // - Linear Searching
        int linearSearch(int value) {

            for (int i = 0; i <= number; i++) {

                if (student[i].id == value) {

                    return i;
                }

            }

            return -1;
        }

        // - Linear Probing Hash Table
        void linearHashing() {

            int studentHash[SIZE];

            for(int x = 0; x < number; x++) {

                studentHash[x] = student[x].id / 100;
            }
        }
};

int main() {

    StudentMarks sm;
    string name;
    int value, found;
    char grade;

    sm.addStudent();
    sm.deleteStudent();
    sm.searchStudent();

    return 0;
}

