#include<iostream>
#include <string>
using namespace std;

const int SIZE = 10;

class StudentMarks {

    private:

        struct Student {
            string name;
            int id, chem, math, phy;
        };

        Student student[SIZE];
        int number;

    public:

        StudentMarks() { };

        void addStudent() {

            cout<<"How many record of students you would like to insert ? : ";
            cin>>number;

            for(int x = 0; x < number; x++) {

                cout<<"\nStudent "<< x + 1<<" ID [In the form of 4 digits, 1XXX - 9XXX] : ";
                cin>>student[x].id;

                while(student[x].id < 1000 || student[x].id > 9999) {

                    cout<<"Input out of range."<<endl<<endl;
                    cout<<"Enter student "<< x + 1<<" ID again! [In the form of 4 digits, start with 1XXX] : ";
                    cin>>student[x].id;
                }

                cout<<"Student " << x+1 << " name : ";
                getline(cin, student[x].name);
                cout<<"Chemistry marks of student "<<x+1<<" : ";
                cin>>student[x].chem;
                cout<<"Physic marks of student "<<x+1<<" : ";
                cin>>student[x].phy;
                cout<<"Mathematics marks of student "<<x+1<<" : ";
                cin>>student[x].math;

                cout<<endl;
            }

            linearHashing();
        }

        void displayStudent() {

            Student temp_sorted;
            int sort_choice, j;

            cout<<"Select a mode : \n--------------"<<endl;

            cout<<"Sort By \n---------"<<endl;
            cout<<"1. Student's ID "<<endl;
            cout<<"2. Student's name "<<endl;
            cout<<"3. Student's Chemistry mark"<<endl;
            cout<<"4. Student's Physic mark "<<endl;
            cout<<"5. Student's Mathematics mark"<<endl;

            cin>>sort_choice;

            while(sort_choice <= 0 || sort_choice > 5) {
                cout<<"Invalid entry, enter your choice again"<<endl;
                cin>>sort_choice;
            }

            for(int x=0; x<number; x++) {
                temp_sorted = student[x];
                j = x;
            }

            switch(sort_choice) {

                case 1 : while(j>0 && temp_sorted.id < student[j-1].id) { student[j] = student[j-1]; j--; student[j] = temp_sorted; }
                         break;

                case 2 : while(j>0 && temp_sorted.name < student[j-1].name) { student[j] = student[j-1]; j--; student[j] = temp_sorted; }
                         break;

                case 3 : while(j>0 && temp_sorted.chem< student[j-1].chem) { student[j] = student[j-1]; j--; student[j] = temp_sorted; }
                         break;

                case 4 : while(j>0 && temp_sorted.phy< student[j-1].phy) { student[j] = student[j-1]; j--; student[j] = temp_sorted; }
                         break;

                case 5 : while(j>0 && temp_sorted.math< student[j-1].math) { student[j] = student[j-1]; j--; student[j] = temp_sorted; }
                         break;
            }

            cout<<"\nNo.\tStudent ID\tName\tChemistry\tPhysics\t\tMathematics"<<endl;

            for(int x=0; x<number; x++) {
                cout<<x+1<<"\t"<<student[x].id<<"\t\t"<<student[x].name<<"\t\t"<<student[x].chem
                    <<"\t\t"<<student[x].phy<<"\t\t"<<student[x].math<<endl;
            }
        }


        void deleteStudent() {

            Student temp[number];
            int found = 0, ID;
            char choice;

            cout<<"Please Enter Student ID to delete: ";
            cin>>ID;

            found = linearSearch(ID);

            if(found != -1) {

                cout<<"Target found"<<endl;

                cout<<"\nStudent ID: "<<student[found].id;
                cout<<"\nStudent name: "<<student[found].name;
                cout<<"\nSubjects mark: ";
                cout<<"\n\t1.Chemistry: "<<student[found].chem;
                cout<<"\n\t1.Physics: "<<student[found].phy;
                cout<<"\n\t1.Mathematics: "<<student[found].math;

                cout<<"\n\nAre you sure want to delete? [Y/N] ";
                cin>>choice;

                if(choice == 'Y' || choice == 'y') {

                    for(int i=0; i<number; i++) {

                        temp[i] = student[i];
                    }

                    for(int i=0; i<number; i++) {

                        if(temp[i].id != ID) {
                            student[i] = temp[i];
                        }
                    }
                }

            } else {
                cout<<"StudentID is not found" ;
            }
        }


        void searchStudent() {

            int value, found = 0;
            char choice;

            do {

                cout<<"Please Enter Student ID to search: ";
                cin>>value;

                found = linearSearch(value);

                if(found != -1) {

                    cout<<"Target found"<< endl;

                    cout<<"\nStudent ID: "<<student[found].id;
                    cout<<"\nStudent name: "<<student[found].name;
                    cout<<"\nSubjects mark: ";
                    cout<<"\n\t1.Chemistry: "<<student[found].chem;
                    cout<<"\n\t1.Physics: "<<student[found].phy;
                    cout<<"\n\t1.Mathematics: "<<student[found].math;

                } else {

                    cout<<"Student ID is not found" ;
                }

                cout<<"Search again?[Y/N] ";
                cin>>choice;

            } while(choice == 'Y' || choice == 'y');
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

                studentHash[x] = student[x].id % SIZE;
            }
        }

        void editStudent() {

            int id,a;
            char z;

            do {
                cout << "Please Enter ID : " << endl;
                cin >> id;

                a = linearSearch(id);

                if(a != -1) {
                    cout<<"Student Id : " << student[a].id << endl;
                    cout<<"Student Name : ";
                    getline(cin,student[a].name);
                    cout<<"Chemistry : ";
                    cin>>student[a].chem;
                    cout<<"Mathematics : ";
                    cin>>student[a].math;
                    cout<<"Physics : ";
                    cin>>student[a].phy;
                    cout<<endl<<endl;
                    z = 'n';

                } else {

                    cout<<"Id Not Found! Continue[Y/N]"<<endl;
                    cin>>z;
                }

            } while (z == 'Y' || z == 'y');
        }
};

int main() {

    StudentMarks sm;
    int choice = 0;

    cout<<"Welcome to Student Marks Record"<<endl;

    while(choice != 6) {

        cout<<"\nMenu\n----\n"<<endl;
        cout<<"1. Add"<<endl;
        cout<<"2. Edit"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Search"<<endl;
        cout<<"6. Exit"<<endl<<endl;
        cout<<"Please Enter Your Choice :";
        cin>>choice;
        
        cout<<endl;

        if(choice == 1) {
            sm.addStudent();

        } else if(choice == 2) {
            sm.editStudent();

        } else if(choice == 3) {
            sm.deleteStudent();

        } else if(choice == 4) {
            sm.displayStudent();

        }else if(choice == 5){
            sm.searchStudent();
        }
    }
    return 0;
}
