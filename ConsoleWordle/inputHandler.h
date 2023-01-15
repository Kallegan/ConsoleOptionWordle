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
    bool isWinner{}; // feedback: feels like this member doesn't really belong to input handling as this class is named for.
                    // Generally good practice for writing classes is that class should serve one task and deal with a clearly separable
                    // data of your project. This class is named input handler but seems like it handles many things including
                    // state of the game, merging some strings etc. Ideally if you name your class input handler, it should only 
                    // take care of handling the input.
    
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

