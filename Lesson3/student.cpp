#include "student.h"
#include <iostream>
using std::cout;
using std::endl;

void Student::set_name(const string &_name){
    name=_name;
    cout<<"Name successfully changed to \""<<name<<"\"."<<endl;
};

void Student::set_grade(int _grade){
    grade=_grade;
    cout<<"Grade successfully changed to \""<<grade<<"\"."<<endl;
};

void Student::show_info() const {
    cout<<"Name:"<<name<<endl;
    cout<<"Grade:"<<grade<<endl;
}

Student::~Student(){
    cout<<"Object destroyed successfully."<<endl;
}
