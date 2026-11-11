#pragma once

namespace advancedPrint {

enum class Color {
    Black, Red, Green, Yellow, White
};

struct Employee
{
    int id;
    char name[50];
    double salary;
};


struct menu
{
    const char *text;
    int x;
    int y;

    int selected ;
};
void moveTo(int row, int col);
void clear();

void setColor(Color c);
void resetColor();
void displayMenu(menu arr[10], int size);
int moveMenuArrow();
void runMenu(menu menuArray[], int size, Employee employees[], int& employeeCount);
void  addEmployee(Employee& employee);
void displayEmployees(Employee employees[], int count);
}