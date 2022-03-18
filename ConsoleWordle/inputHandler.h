#pragma once
#include <string> 
#include <iostream>
#include "wordleBoard.h"
#include "wordCollection.h"

class InputHandler
{

public:
    std::string userGuess{};
    std::string totalGuesses{};
    std::string pickedRandom = getRandomWord();
    std::string totalRandom{}; 

    char continueGame{};
    bool isWinner{};
    
    void takeUserGuess();

    bool checkValid();          

    void toUpper();

    void mergeGuesses();

    void expandRandom();

    std::string getGuesses();

    std::string getRandoms();

    bool canPlay(int round);

    bool checkContinue();
};

