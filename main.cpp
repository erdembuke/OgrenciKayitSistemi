#include <iostream>
#include "Student.h"
#include <list>


using namespace std;

void showMenu() {
    cout << " * * * * * * * * *" << endl;
    cout << " *               *" << endl;
    cout << " *     MENU      *" << endl;
    cout << " *               *" << endl;
    cout << " * * * * * * * * *" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. Show All List" << endl;
    cout << "3. Delete Student By ID" << endl;
    cout << "4. Search Student" << endl;
    cout << "5. Close the App" << endl;
}

// adding student to the list method
void addNewStudent(list<Student> *pList) {
    int id, examPt;
    string name, surname, fullname;

    cout << "Student ID:";
    cin >> id;
    cout << "Student Name:";
    cin >> name;
    cout << "Student Surname:";
    cin >> surname;
    fullname = name + " " + surname;
    cout << "Student Point:";
    cin >> examPt;

    Student ogr(id, fullname, examPt); // creating new student with constructor and attributes above
    pList->push_back(ogr); // adding the list (with pushback)
}

void showList(list<Student> *pList) {
    list<Student>::iterator itr; // iterator
    cout << "\n* * * * * * * * Student List * * * * * * * *\n";
    for (itr = pList->begin(); itr != pList->end(); itr++) {
        cout << "\nID:" << itr->getId() << " Student informations...\n";
        itr->printInformations(); // calling the print method in Student.cpp
    }
    cout << "\n* * * * * * * * End of the List * * * * * * * *\n";
    cout << endl;

}

void deleteStudent(list<Student> *pList) {
    list<Student>::iterator itr; // iterator
    bool found = false;
    int id;

    cout << "Please input ID of the Student for DELETE:";
    cin >> id;

    for (itr = pList->begin(); itr != pList->end(); itr++) {
        if (itr->getId() == id) {
            pList->erase(itr); // erasing Student with iterator
            found = true;
            break;
        }
    }

    // after the loop, if itr couldn't find the student
    if (!found) {
        cout << "There is not a student with ID " << id << " !!!\n";
    }
}

void searchStudent(list<Student> *pList) {
    list<Student>::iterator itr; // iterator
    bool found = false;
    int id;

    cout << "Please input ID of the Student for SEARCH:";
    cin >> id;

    for (itr = pList->begin(); itr != pList->end(); itr++) {
        if (itr->getId() == id) {
            cout << "\nStudent with ID:" << id << " found successfully!\n";
            itr->printInformations();
            cout << endl;
            found = true;
            break;
        }
    }

    // after the loop, if itr couldn't find the student
    if(!found) {
        cout << "There is not a student with ID " << id << endl;
    }
}

int main() {
    list<Student> *stdList = new list<Student>; // Student list - data structure
    int choice = 0;

    do {
        showMenu();
        cout << "Please input a menu number:";
        cin >> choice;
        switch (choice) {
            case 1:
                addNewStudent(stdList);
                break;
            case 2:
                showList(stdList);
                break;
            case 3:
                deleteStudent(stdList);
                break;
            case 4:
                searchStudent(stdList);
                break;
            case 5:
                cout << "Cikis Yapiliyor..." << endl;
                delete stdList;
                break;
            default:
                cout << "Wrong input, please try again..." << endl;
                break;
        }

    } while (choice != 5);


    return 0;
}
