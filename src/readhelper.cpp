#include <iostream>   
#include <cstdio>     
#include <unistd.h>   
#include <termios.h>  
#include "../include/readhelper.hpp"





namespace helper{


char getch_linux() {
    char buf = 0; 

    struct termios old = {0}; 
    tcgetattr(0, &old);

    old.c_lflag &= ~ICANON;

    old.c_lflag &= ~ECHO;

    old.c_cc[VMIN] = 1;

    old.c_cc[VTIME] = 0;

    tcsetattr(0, TCSANOW, &old);

    read(0, &buf, 1);

    old.c_lflag |= ICANON;

    old.c_lflag |= ECHO;

    tcsetattr(0, TCSADRAIN, &old);

    return buf;
}



   
}