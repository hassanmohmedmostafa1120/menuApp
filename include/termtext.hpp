#pragma once

namespace advancedPrint {

enum class Color {
    Black, Red, Green, Yellow, White
};

struct menu
{
    char *text;
    int x;
    int y;
    Color c;
    int selected ;
};
void moveTo(int row, int col);
void clear();

void setColor(Color c);
void resetColor();
void displayMenu(menu arr[10], int size);
int moveMenuArrow();

}