#include <iostream>
#include "outputHandler.h"
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"


void outputStrings(std::string s, int i, int color) //takes string, index and color for printing to console.
{
    std::string temp{ s };
    int index{ i };
    int colorTemp = color;

    if (i == 0)
    {
        std::cout << "|";
    }
    
    std::cout << BACKGROUND(colorTemp, "[ ");
    std::cout << BACKGROUND(colorTemp, temp[i]);
    std::cout << BACKGROUND(colorTemp, " ]");
    std::cout << " ";
    
    if (i == 4)
    {
        std::cout << "|";
    }
}