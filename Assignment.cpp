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
    int number;

    Student student[SIZE];
public:

    StudentMarks() {
        for(int i = 0; i < SIZE; i++){
            student[i].id = -1;
            student[i].name = "";
            student[i].phy = 0;
            student[i].chem = 0;
            student[i].math = 0;
        }
    };

    void addStudent() {

        //int studentHash[SIZE];
        int id,hash;
        cout<<"How many record of students you would like to insert ? : ";
        cin>>number;

        for(int x = 0; x < number; x++) {

            cout<<"\nStudent "<< x + 1<<" ID [In the form of 4 digits, 1XXX - 9XXX] : ";
            cin>>id;

            while(id < 1000 || id > 9999) {

                cout<<"Input out of range."<<endl<<endl;
                cout<<"Enter student "<< x + 1<<" ID again! [In the form of 4 digits, start with 1XXX] : ";
                cin>>id;
            }

            hash = id % SIZE;
            student[hash].id = id;
            cin.ignore();

            cout<<"Student " << x+1 << " name : ";
            getline(cin, student[hash].name);
            cout<<"Chemistry marks of student "<<x+1<<" : ";
            cin>>student[hash].chem;
            cout<<"Physic marks of student "<<x+1<<" : ";
            cin>>student[hash].phy;
            cout<<"Mathematics marks of student "<<x+1<<" : ";
            cin>>student[hash].math;

            cout << endl << endl << student[hash].id;

            cout<<endl;
        }
        /*
        cout<<"Hash Table\n----------\n"<<endl;
        cout<<"ID\tKey Index"<<endl;
        for(int y=0; y<number; y++) {
            studentHash[y] = student[y].id % SIZE;
             linear probing implementation
            cout<<student[y].id<<"\t"<<studentHash[y]<<endl;
        }*/
    }

    void display(){
        int count = 0,sort_choice = 0;
        for(int i = 0; i < SIZE; i++){
            if(student[i].id != -1){
                count++;
            }
        }
        Student temp[count];
        int j = 0;
        for(int i = 0; i < SIZE; i++){
            if(student[i].id != -1){
                temp[j].id = student[i].id;
                temp[j].name = student[i].name;
                temp[j].phy = student[i].phy;
                temp[j].chem = student[i].chem;
                temp[j].math = student[i].math;
                j++;
                //cout << temp[j].id << endl << temp[j].math << endl << temp[j].phy << endl << temp[j].chem;
            }
        }

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
        switch(sort_choice) {

            case 1 :
                for(int a = 0; a < count; a++){
                    for(int b = a+1; b < count; b++){
                        if(temp[b].id < temp[a].id){
                            Student swap;
                            swap = temp[a];
                            temp[a] = temp[b];
                            temp[b] = swap;
                        }
                    }
                }
                break;

            case 2 :
                for(int a = 0; a < count; a++){
                    for(int b = a+1; b < count; b++){
                        if(temp[b].name < temp[a].name){
                            Student swap;
                            swap = temp[a];
                            temp[a] = temp[b];
                            temp[b] = swap;
                        }
                    }
                }
                break;

            case 3 :
                for(int a = 0; a < count; a++){
                    for(int b = a+1; b < count; b++){
                        if(temp[b].chem < temp[a].chem){
                            Student swap;
                            swap = temp[a];
                            temp[a] = temp[b];
                            temp[b] = swap;
                        }
                    }
                }
                break;

            case 4 :
                for(int a = 0; a < count; a++){
                    for(int b = a+1; b < count; b++){
                        if(temp[b].phy < temp[a].phy){
                            Student swap;
                            swap = temp[a];
                            temp[a] = temp[b];
                            temp[b] = swap;
                        }
                    }
                }
                break;

            case 5 :
                for(int a = 0; a < count; a++){
                    for(int b = a+1; b < count; b++){
                        if(temp[b].math < temp[a].math){
                            Student swap;
                            swap = temp[a];
                            temp[a] = temp[b];
                            temp[b] = swap;
                        }
                    }
                }
                break;
        }
        cout<<"\nNo.\tStudent ID\tName\tChemistry\tPhysics\t\tMathematics"<<endl;

        for(int x=0; x<count; x++) {
            cout<<x+1<<"\t"<<temp[x].id<<"\t\t"<<temp[x].name<<"\t\t"<<temp[x].chem
                <<"\t\t"<<temp[x].phy<<"\t\t"<<temp[x].math<<endl;
        }
    }

    void deleteStudent() {

        //Student temp[number];
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
                student[found].id = -1;
                student[found].name = "";
                student[found].phy = 0;
                student[found].chem = 0;
                student[found].math = 0;

                /*for(int i=0; i<number; i++) {
                    temp[i] = student[i];
                }
                for(int i=0; i<number; i++) {
                    if(temp[i].id != ID) {
                        student[i] = temp[i];
                    }
                }*/

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

    void editStudent() {

        int id,a;
        char z;

        do {
            cout<<"Please Enter ID : " << endl;
            cin>>id;

            cin.ignore();

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

    /************************** ALGORITHM **************************/

    // - Linear Searching
    int linearSearch(int value) {

        for (int i = 0; i <= SIZE; i++) {

            if (student[i].id == value) {

                return i;
            }
        }

        return -1;
    }

};

int main() {

    StudentMarks sm;
    int choice = 0;

    cout<<"Welcome to Student Marks Record"<<endl;

    do{

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
            sm.display();

        }else if(choice == 5){
            sm.searchStudent();
        }
    }while(choice != 6);
    return 0;
}
