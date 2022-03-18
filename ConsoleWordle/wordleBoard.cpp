#include "wordleBoard.h"

#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"
    

    enum WordleBoard::color : int
    {
        Gray = 100,
        Yellow = 43,
        Red = 41,
        Green = 42,
    };      

    int WordleBoard::assignColor(int color, int index, std::string totalGuess, std::string totalRandom)
    {        
        bool notFound = true;   

        if (totalGuess.length() != totalRandom.length() || totalGuess.length() == 0)       
        {           
            std::cerr << "Incorrect string length when assigning colors.";           
            exit(EXIT_FAILURE);
        }

        if (totalGuess[index] == totalRandom[index])
        {            
            color = Green;
            notFound = false;

            for (size_t i = 0; i < keyboard.size(); i++)
            {
                if (totalGuess[index] == keyboard[i])
                {
                    keyboarColor[i] = Green;
                   
                }
            }                
        }

        for (int j = 0; j < totalRandom.length() && notFound; j++) //checks current index in row.
        {
            if (totalGuess[index] == totalRandom[j])
            {
                color = Yellow;
                notFound = false;

                for (size_t i = 0; i < keyboard.size(); i++)
                {
                    if (totalGuess[index] == keyboard[i] && keyboarColor[i] != Green)
                    {
                        keyboarColor[i] = Yellow;
                    }
                }
            }
        }

        if (notFound) //current char not found is painted gray.    
        {
            color = Gray;
            for (size_t i = 0; i < keyboard.size(); i++)
            {
                if (totalGuess[index] == keyboard[i] && keyboarColor[i] != (Green || Yellow))
                {
                    keyboarColor[i] = Gray;
                }
            }
        }   
        return color;
    }


    void WordleBoard::printCurrentGuesses(std::string totalGuess, std::string totalRandom)
    {   
        int index{};
        int tempColor{};     

        system("cls");
        std::cout << boardHeader;        

        for (int i = 0; i < currentRound; i++)
        {
            std::cout << boardLeftSide;
            for (int j = 0; j < 5; j++) //prints the word in color one char at a time and frame it with same color.
            {
                std::cout << BACKGROUND(assignColor(tempColor, index, totalGuess, totalRandom), "[ " << totalGuess[index] << " ]") << " ";
                index++;
            }
            if (i + 1 != 6)//removes setup for next row since this will be the last row.
                std::cout << boardRightSide << boardSides;
            else
                std::cout << boardRightSide;
        }        
    }

    void WordleBoard::printKeyboard() //todo: use same function to print color, change way of passing to update class members.
    {
        
        int keyCount{9};
        std::string spacing{ "\n\n   " };

        for (size_t i = 0; i < keyboard.size(); i++)
        {
            std::cout << BACKGROUND(keyboarColor[i],"[ " << keyboard[i] << " ]") << " ";
            if (i == keyCount)
            {
                std::cout << spacing;
                keyCount += 9;
                if (keyCount == 18)
                    spacing += "      ";                    
            }
            
        }
        std::cout << std::endl;
    }

    void WordleBoard::fillEmpty()
    {      
        if (currentRound == 0)
            std::cout << boardHeader;

        for (int i = 0; i < (6 - currentRound); i++)
        {
            std::cout << boardLeftSide;

            for (int i = 0; i < 5; i++)
                std::cout << blankSpace;

            std::cout << boardRightSide;

            if (i + 1 == (6 - currentRound))//breaks before printing last row if its the last round.
                break;

            std::cout << boardSides;
        }
    
        std::cout << boardFooter;
        printKeyboard();
    }