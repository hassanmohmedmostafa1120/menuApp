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
    runMenu(menuArray, 3);
    clear();
    moveTo(1, 1);
    return 0;

}