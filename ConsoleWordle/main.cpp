#include <iostream>
#include "WordsCollection.h"
#include "OutputHandler.h"
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

int main()
{    
    std::string pickedRandom{};
    std::string userGuess{};   
       
    pickedRandom = getRandomWord();
    int guesses{};
    int rounds{6};

    bool canGuess = true;
    bool correct = false;
    bool notFound = true;    

    int backGray{ 100 };
    int backYellow{ 43 };
    int backRed{ 41 };
    int backGreen{ 42 };


    std::cout << pickedRandom << std::endl;
    do 
    {
        std::cout << " :";
        std::cin >> userGuess;        
        if(userGuess.length() != 5)
        {            
            userGuess={"xxxxx"};
        }       
        
        for (size_t i = 0; i < userGuess.length(); i++)
        {
            notFound = true;
            userGuess[i] = std::toupper(userGuess[i]); //changing userguess to uppercase to be able to handle lower case input in comparison.
            if (userGuess[i] == pickedRandom[i])
            {   
                printStuff(userGuess, i, backGreen);
                notFound = false;               
                continue;
            }                

            for (size_t j = 0; j < userGuess.length(); j++)
            {
                if (userGuess[i] == pickedRandom[j])
                {
                    printStuff(userGuess, i, backYellow);
                    notFound = false;
                    break;
                }                                
            }

            if (notFound)
            {
                printStuff(userGuess, i, backGray); 
            }          
        }
        guesses++;      

        if (guesses >= 6)
            canGuess = false;
        if (userGuess == pickedRandom)
        {
            correct = true;
            canGuess = false;
        }
    } 
    while (canGuess);
    
    if (correct)
    {
        std::cout << "WINNER!";
    }
    else
    {
        std::cout << std::endl;

        for (size_t i = 0; i < 5; i++)
        {               
            printStuff(pickedRandom, i, backRed);
        }
    }
    
    return 0;
}