#include <iostream>
#include "WordsCollection.h"
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"


void printStuff(std::string s, int i)
{
    std::string temp{ s };
    int index{ i };
    int color{};

    enum class ForegroundColor : int {
        Red = 31,
        Green = 32,
        Yellow = 33,
        BrightRed = 91,
        BrightGreen = 92,
        BrightYellow = 93
    };

    enum class BackgroundColor : int {
        Red = 41,
        Green = 42,
        Yellow = 43,
        BrightRed = 101,
        BrightGreen = 102,
        BrightYellow = 103,
        Gray = 100,
    };

    std::cout << BACKGROUND(BackgroundColor::Gray, "[ ");
    std::cout << BACKGROUND(BackgroundColor::Gray, temp[i]);
    std::cout << BACKGROUND(BackgroundColor::Gray, " ]");
    std::cout << " ";
}