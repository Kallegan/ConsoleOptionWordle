#include "inputHandler.h"

    
    void InputHandler::takeUserGuess() //not sure if this is the correct way but I
    {
        std::cin >> userGuess;
        checkValid();
        toUpper();
        mergeGuesses();
        expandRandom();
    }
    
    //used string length as a postcodition since anything else than 5 char string would brake the game.
    bool InputHandler::checkValid()
    {
        while (userGuess.length() != 5)
        {
            std::cerr << "Invalid input. Enter a five character word.";
            std::cin >> userGuess;
        }   

        return true;
    }  

    void InputHandler::toUpper() //converting guess to uppercase.
    {
        for (size_t i = 0; i < userGuess.length(); i++)
        {
            userGuess[i] = std::toupper(userGuess[i]); //converts guess to uppercase.
        }        
    }    
    //merging string with its current self. This will keep track of all total guesses.
    void InputHandler::mergeGuesses()
    {
        totalGuesses += userGuess;               
    }   
    //exapnding the size of the random with itself. Used to match the index with guess as the string grows.
    void InputHandler::expandRandom()
    {
        totalRandom += pickedRandom;
    }

    std::string InputHandler::getGuesses()
    {
        return totalGuesses;
    }

    std::string InputHandler::getRandoms()
    {
        return totalRandom;
    }


    bool InputHandler::canPlay(int round)
    {
        if (userGuess == pickedRandom)
        {
            return true;
            isWinner = true;
        }
        else if (round == 6)
        {
            std::cout << "\n              The secret word was : " << pickedRandom << std::endl;
            return true;
        }            
        else
            return false;        
    }

    bool InputHandler::checkContinue()
    {  
        std::cin >> continueGame;
        if (continueGame == 'y' || continueGame == 'Y')
            return true;
        else
            return false;
    }
  