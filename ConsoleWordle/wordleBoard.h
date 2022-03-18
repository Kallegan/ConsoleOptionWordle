#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "inputHandler.h"

class WordleBoard
{

public:  
    int currentRound{};
    std::array<int, 26> keyboarColor{};
    const std::array<char, 26> keyboard
    { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
        'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

    const std::string boardHeader
    { 
        "   db   d8b   db  .d88b.  d8888b. d8888b. db      d88888b \n"
        "   88   I8I   88 .8P  Y8. 88  `8D 88  `8D 88      88'     \n"
        "   88   I8I   88 88    88 88oobY' 88   88 88      88ooooo \n"
        "   Y8   I8I   88 88    88 88`8b   88   88 88      88~~~~~ \n"
        "   `8b d8'8b d8' `8b  d8' 88 `88. 88  .8D 88booo. 88.     \n"
        "    `8b8' `8d8'   `Y88P'  88   YD Y8888D' Y88888P Y88888P \n"
        "              _______________________________  \n"
        "             |                               | \n"
    };  

    const std::string boardRightSide{ "| " };
    const std::string boardLeftSide{ "             | " };
    const std::string boardSides{ " \n             |                               | \n" };
    const std::string boardFooter{ "\n             |_______________________________|\n\n" };

    std::string blankSpace{ "[   ] " };
           

    enum color : int;    

    int assignColor(int color, int index, std::string guess, std::string rand);

    void printCurrentGuesses(std::string guess, std::string rand);

    void printKeyboard();

    void fillEmpty();
};


