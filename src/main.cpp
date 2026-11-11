#include <cstdio>
#include "../include/termtext.hpp"
#include "../include/readhelper.hpp"

using namespace std;
using namespace advancedPrint;  
using namespace helper;


int main() {
    menu m1 = {"New", 5, 20,1};
    menu m2 = {"Display", 7, 20,0};
    menu m3 = {"Exit", 9, 20, 0};

    menu menuArray[3]={m1,m2,m3};
   // Employee employees[2] = {};
    Employee * employees = new Employee[2];
    int employeeCount = 0;

    runMenu(menuArray, 3, employees, employeeCount);

    clear();
    moveTo(1, 1);
    delete[] employees;
    return 0;

}