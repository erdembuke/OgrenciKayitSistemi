#pragma once
#ifndef CPP_PROJECT_STUDENT_H
#define CPP_PROJECT_STUDENT_H
#endif //CPP_PROJECT_STUDENT_H

#include <iostream>

using namespace std;

class Student {
private:
    int id;
    string name;
    int examPt;

public:
    // constructor
    Student(int _id, string _name, int _examPt);
    // setter
    void setId(int _id);
    void setName(int _name);
    void setExamPt(int _examPt);
    // getter
    int getId();
    string getName();
    int getExamPt();
    // printAll method
    void printInformations();

};