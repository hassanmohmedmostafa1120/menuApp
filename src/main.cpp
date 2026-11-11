#include <cstdio>
#include "../include/termtext.hpp"
#include "../include/readhelper.hpp"

using namespace std;
using namespace advancedPrint;  
using namespace helper;


int main() {
    menu m1 = {"NEW GAME", 5, 20,1};
    menu m2 = {"RESUME", 7, 20,0};
    menu m3 = {"SETTINGS", 9, 20, 0};

    menu menuArray[3]={m1,m2,m3};
    const int size = 3;
    int current = 0;                
    while (true) {
        clear();
        displayMenu(menuArray, size);

        int key = moveMenuArrow();   
        if (key == 0) break;         

        menuArray[current].selected = 0;         
        if (key == 2)
            current = (current + 1) % size;       
        else if (key == 1)
            current = (current - 1 + size) % size; 
        menuArray[current].selected = 1;          
}
    clear();
    moveTo(1, 1);
    return 0;

}