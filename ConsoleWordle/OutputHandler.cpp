#include <iostream>
#include "OutputHandler.h"
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"


void printStuff(std::string s, int i, int color)
{
    std::string temp{ s };
    int index{ i };
    int colorTemp = color;    
    
    std::cout << BACKGROUND(colorTemp, "[ ");
    std::cout << BACKGROUND(colorTemp, temp[i]); //replacing temp with current  from while loop in main.
    std::cout << BACKGROUND(colorTemp, " ]");
    std::cout << " ";
}