#include "cmdui.h"
#include <iostream>
#include <string>
#define STARS "***********************************************"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//the name and grade entered by the user
void print_stars_line(){
    cout<<STARS<<endl;
}

void welcome(){
    cout<<"Studen Info Manager"<<endl;
    print_stars_line();
}

void prompt(){
    cout<<"1.Add a student."<<endl;
    cout<<"2.Change name."<<endl;
    cout<<"3.Change grade."<<endl;
    cout<<"4.Show student info."<<endl;
    cout<<"5.Quit."<<endl;
    print_stars_line();
}

Student* init_student(){
    string t_name;
    int t_grade;
    cout<<"Enter the name:"<<endl;
    cin>>t_name;
    cout<<"Enter the grade:"<<endl;
    cin>>t_grade;
    print_stars_line();
    return new Student(t_name, t_grade);
}

void change_name(Student *p_student){
    string t_name;
    cout<<"Enter the new name:"<<endl;
    cin>>t_name;
    p_student->set_name(t_name);
    print_stars_line();
}

void change_grade(Student *p_student){
    int t_grade;
    cout<<"Enter the new grade:"<<endl;
    cin>>t_grade;
    p_student->set_grade(t_grade);
    print_stars_line();
}

void show_info(const Student *p_student){
    p_student->show_info();
    print_stars_line();
}

void run(){
    bool run_on=true;
    Student *p_student;
    int order;
    welcome();
    while(run_on){
        prompt();
        cin>>order;
        switch (order)
        {
        case 1:
            p_student=init_student();
            break;
        case 2:
            change_name(p_student);
            break;
        case 3:
            change_grade(p_student);
            break;
        case 4:
            show_info(p_student);
            break;
        case 5:
            run_on=false;
            break;
        default:
            cout<<"Invalid order!"<<endl;
            break;
        }
    }
}