#include "../include/termtext.hpp"
#include "../include/readhelper.hpp"
#include <iostream>
#include <cstdio>
using namespace std;
using namespace helper;
namespace advancedPrint{

    struct RGB {
    int r, g, b;
    };

    RGB toRGB(Color c) {
        switch (c) {
            case Color::Black:  return {0, 0, 0};
            case Color::Red:    return {255, 0, 0};
            case Color::Green:  return {0, 255, 0};
            case Color::Yellow: return {255, 255, 0};
            case Color::White:  return {255, 255, 255};
        }
        return {0, 0, 0};
    }
 



int moveMenuArrow(){
    while (true) {
        char byte1 = getch_linux();
        if (byte1 == '\n') {
            return 3;
        }
        if (byte1 == 'q' || byte1 == 'Q') {
            return 0;
        }

        if (byte1 == '\033') {
            getch_linux();                    
            char byte3 = getch_linux();      
            if (byte3 == 'A') return 1;
            if (byte3 == 'B') return 2;
        }
        
    }
}






    void moveTo(int row, int col) {
    printf("\x1b[%d;%dH", row, col);
    }   


  void clear()
{
    printf("\x1b[2J\x1b[3J\x1b[H");
    fflush(stdout);
}


    void setColor(Color c) {
    RGB v = toRGB(c);
    printf("\x1b[38;2;%d;%d;%dm", v.r, v.g, v.b);

   
    }

    void resetColor() {
    printf("\x1b[0m");
    }   

    void displayMenu(menu arrArr[10], int arrSize){
           for(int i=0; i<arrSize;i++){
        
                moveTo((arrArr[i].x) + 1, (arrArr[i].y) + 2);
                if(arrArr[i].selected ==1)
                {
                     setColor(Color::Yellow);
                    printf("%s %s", " -> ", arrArr[i].text);
                     resetColor();

               }
              else
              {
                    resetColor();
                     printf("%s", arrArr[i].text);
             }


            }
            fflush(stdout);   // to display the menu before waiting the key

    }


    


void addEmployee(Employee employees[], int& employeeCount)
{
    clear();

    cout << "\t\tADD EMPLOYEE "<<endl<<endl;

    cout << "Enter Employee ID: ";
    cin >> employees[employeeCount].id;

    cout << "Enter Employee Name: ";
    cin >> employees[employeeCount].name;

    cout << "Enter Employee Salary: ";
    cin >> employees[employeeCount].salary;

    employeeCount++;
}

void displayEmployees(Employee employees[], int count)
{
    clear();

   cout << "\t\tEMPLOYEE LIST"<<endl<<endl;

    if (count == 0)
    {
        cout << "No employees found." << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << "Employee No." << i + 1 << endl;
            cout << "ID: " << employees[i].id << endl;
            cout << "Name: " << employees[i].name << endl;
            cout << "Salary: " << employees[i].salary << endl;
            cout << "----------------------------" << endl;
        }
    }

    cout << "Press any enter to return to the menu..." << endl;
    cin.ignore();
    cin.get();
}

void runMenu(menu menuArray[], int size,
             Employee employees[], int& employeeCount)
{
    int current = 0;

    while (true)
    {
        clear();

        displayMenu(menuArray, size);

        int key = moveMenuArrow();

        if (key == 0)
            return;

        menuArray[current].selected = 0;

        if (key == 2)
        {
            current = (current + 1) % size;
        }
        else if (key == 1)
        {
            current = (current - 1 + size) % size;
        }
        else if (key == 3)
        {
            if (current == 0)
            {
                if (employeeCount < 2)
                {
                    addEmployee(employees, employeeCount);
                }
                else
                {
                    clear();
                    cout << "Employee storage is full!" << endl;
                    cout << "Press any enter to return to the menu..." << endl;
                    cin.ignore(); 
                    cin.get();
                }
            }
            else if (current == 1)
            {
                displayEmployees(employees, employeeCount);
            }
            else if (current == 2)
            {
                return;
            }
        }

        menuArray[current].selected = 1;
    }
}

    

}

