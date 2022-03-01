#include <iostream>
#include "WordsCollection.h"
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"


void printStuff(std::string s, int i);

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



int main()
{    
    std::string pickedRandom{};
    std::string userGuess{};      

    std::string aphabet{ "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" };

    pickedRandom = getRandomWord();
    int guesses{};
    int rounds{6};

    bool canGuess = true;
    bool correct = false;
    bool notFound = true;    


    std::cout << pickedRandom << std::endl;
    do 
    {
        std::cout << "                                   " << aphabet;
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
                std::cout << BACKGROUND(BackgroundColor::Green, "[ ");
                std::cout << BACKGROUND(BackgroundColor::Green, userGuess[i]);
                std::cout << BACKGROUND(BackgroundColor::Green, " ]");
                std::cout << " ";
                notFound = false;               
                continue;
            }                

            for (size_t j = 0; j < userGuess.length(); j++)
            {
                if (userGuess[i] == pickedRandom[j])
                {
                    std::cout << BACKGROUND(BackgroundColor::Yellow, "[ ");
                    std::cout << BACKGROUND(BackgroundColor::Yellow, userGuess[i]);
                    std::cout << BACKGROUND(BackgroundColor::Yellow, " ]");
                    std::cout << " ";
                    notFound = false;
                    break;
                }                                
            }

            if (notFound)
            {

                printStuff(userGuess, i);
                                
                //std::cout << BACKGROUND(BackgroundColor::Gray, "[ ");
                //std::cout << BACKGROUND(BackgroundColor::Gray, userGuess[i]);
                //std::cout << BACKGROUND(BackgroundColor::Gray, " ]");
                //std::cout << " ";
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
            std::cout << BACKGROUND(BackgroundColor::Red, "[ ");           
            std::cout << BACKGROUND(BackgroundColor::Red, pickedRandom[i]);
            std::cout << BACKGROUND(BackgroundColor::Red, " ]");
            std::cout << " ";
        }
    }
    
    return 0;
}