#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
using std::string;
class Student{
    private:
        string name;
        int grade;
    public:
        Student(const string &_name, int _grade):name(_name), grade(_grade){};
        void set_name(const string &_name);
        void set_grade(int _grade);
        void show_info() const;
        ~Student();
};

#endif