#include <iostream>
#include "wordsCollection.h"
#include "outputHandler.h"


int gameLoop(int keepPlaying, int gamesPlayed)
{

    std::string pickedRandom{};
    std::string userGuess{};

    pickedRandom = getRandomWord();
    int guesses{};
    int rounds{ 6 };
    int games{gamesPlayed};
    bool canGuess = true;
    bool correct = false;
    bool notFound = true;

    int backGray{ 100 };
    int backYellow{ 43 };
    int backRed{ 41 };
    int backGreen{ 42 };

    //system("CLS"); //clears the screen before next round starts.           
    printHeadline();
    std::cout << games << std::endl;
    do
    {
        printSides();
        std::cin >> userGuess;
        if (userGuess.length() != 5)
        {
            userGuess = { "xxxxx" };
        }

        for (size_t i = 0; i < userGuess.length(); i++)
        {
            notFound = true;
            userGuess[i] = std::toupper(userGuess[i]); //changing userguess to uppercase to be able to handle lower case input in comparison.
            if (userGuess[i] == pickedRandom[i])
            {
                outputStrings(userGuess, i, backGreen);
                notFound = false;
                continue;
            }

            for (size_t j = 0; j < userGuess.length(); j++)
            {
                if (userGuess[i] == pickedRandom[j])
                {
                    outputStrings(userGuess, i, backYellow);
                    notFound = false;
                    break;
                }
            }

            if (notFound)
            {
                outputStrings(userGuess, i, backGray);
            }
        }
        guesses++;

        std::cout << std::endl;

        if (guesses >= 6)
            canGuess = false;
        if (userGuess == pickedRandom)
        {
            correct = true;
            canGuess = false;
        }

    } while (canGuess);


    games++; //current game loop is at an end so games played is incremented. 

    if (correct)
    {
        victory();
    }
    else
    {
        printSidesEnd();   

        for (size_t i = 0; i < 5; i++)
        {
            
            outputStrings(pickedRandom, i, backRed);           
            
        }

        printEndline();
    }

    std::cout << "Submit 1 to play again: ";
    std::cin >> keepPlaying;

    return keepPlaying;

}