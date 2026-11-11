#include <cstdio>
#include "../include/termtext.hpp"
#include "../include/readhelper.hpp"

using namespace std;
using namespace advancedPrint;  
using namespace helper;


int main() {
   clear();
    menu m1 = {"NEW GAME", 5, 20, Color::White,1};
    menu m2 = {"RESUME", 7, 20, Color::White,0};
    menu m3 = {"SETTINGS", 9, 20, Color::White,0};

    menu menuArray[3]={m1,m2,m3};
    
    displayMenu(menuArray,3);
 
        moveTo(20, 1);


  
    return 0;
}