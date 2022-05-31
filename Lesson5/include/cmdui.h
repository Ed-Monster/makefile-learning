#ifndef _CMDUI_H_
#define _CMDUI_H_

#include "student.h"
//Modified
void print_stars_line();
void welcome();
void prompt();
Student* init_student(Student &p_student);
void change_name(Student &r_student);
void change_grade(Student &r_student);
void show_info(const Student &r_student);
void run();

#endif