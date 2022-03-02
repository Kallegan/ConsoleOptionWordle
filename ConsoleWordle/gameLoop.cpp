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

    system("CLS"); //clears the screen before next round starts.           
    std::cout << " ______________________________  Games played: " << games << std::endl;    
    do
    {

        std::cout << "|                              |  ";
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
    games++;
    if (correct)
    {
        std::cout << "WINNER!";
    }
    else
    {
        std::cout << "|                              |  " << std::endl;

        for (size_t i = 0; i < 5; i++)
        {
            outputStrings(pickedRandom, i, backRed);            
        }
        std::cout << "\n|______________________________|";
    }

    std::cout << "Press 1: to play again: ";
    std::cin >> keepPlaying;

    return keepPlaying;

}