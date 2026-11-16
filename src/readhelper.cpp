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



 int isInteger(char *arr)
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (!isdigit(arr[i]))
            return 0;
    }

    return 1;
}



void stringCopy(char destination[], const char source[])
{
    int i = 0;

    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}


int validateAlpha(char * str){
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool isUpper = (c >= 'A' && c <= 'Z');
        bool isLower = (c >= 'a' && c <= 'z');

        if (!(isUpper || isLower))
            return 0;
    }
    return 1;
}
   
}