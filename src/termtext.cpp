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
        case Color::Black:   return {0, 0, 0};
        case Color::Red:     return {255, 0, 0};
        case Color::Green:   return {0, 255, 0};
        case Color::Yellow:  return {255, 255, 0};
        case Color::White:  return {255, 255, 255};
    }
  
    }
 



int moveMenuArrow(){
        char byte1;
         do{
        byte1= getch_linux();
        if (byte1 == '\033') {
           char byte2=getch_linux();
         char   byte3=getch_linux();
            switch (byte3) {
                case 'A':
                
                    return 1; // Up Arrow
                    

                case 'B':
                    return 2; // Down Arrow

            }
        }
        
    } while (byte1 != 'q' && byte1 != 'Q');
    }






    void moveTo(int row, int col) {
    printf("\x1b[%d;%dH", row, col);
    }   


    void clear() {
    printf("\x1b[2J\x1b[H");
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
                     setColor(arrArr[i].c = Color::Red);
                    printf("%s %s\n", " -> ", arrArr[i].text);
                     resetColor();

               }
              else
              {
                    resetColor();  
                     printf(arrArr[i].text);
             }


            }

    }


    

}

