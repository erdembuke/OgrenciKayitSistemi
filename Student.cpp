#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(int _id, string _name, int _examPt) {
    id = _id;
    name = _name;
    examPt = _examPt;
}

void Student::setId(int _id) {
    id = _id;
}

void Student::setName(int _name) {
    name = _name;
}

void Student::setExamPt(int _examPt) {
    examPt = _examPt;
}

int Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

int Student::getExamPt() {
    return examPt;
}

void Student::printInformations() {
    cout << "ID: " << id << "\nName: " << name << "\nExam Point: " << examPt << endl;
}

