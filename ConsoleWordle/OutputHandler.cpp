#include <iostream>
#include "outputHandler.h"
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"


void outputStrings(std::string s, int i, int color) //takes string, index and color for printing to console.
{
    std::string temp{ s };
    int index{ i };    
    int colorTemp = color;

    if (i == 0 )   //used to fill gap at start of index.
        printSide();    
    
    std::cout << BACKGROUND(colorTemp, "[ ");
    std::cout << BACKGROUND(colorTemp, temp[index]);
    std::cout << BACKGROUND(colorTemp, " ]");
    std::cout << " ";
    
    
    if (i == 4) 
        printSide(); //fills endgap.
}

//moved stray strings to own functions to make "playfield" easier to edit and keep track of.

void printHeadline()
{
    std::cout << " ______________________________  Games played: ";
}

void printSide() 
{
    std::cout << "|";
}

void printSides()
{
    std::cout << "|                              | ";
}

void printSidesEnd()
{
    std::cout << "|                              |  " << std::endl;
}

void printEndline()
{
    std::cout << "\n|______________________________|";
}

void victory()
{
    std::cout << "WINNER!";
}