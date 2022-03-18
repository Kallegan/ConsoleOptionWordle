#include "gameLoop.h"
#include <iostream>


int main()
{
    bool keepPlaying{true};
    do
    {       
        keepPlaying = gameLoop();

        std::cout << "after gameloop";

    } while (keepPlaying);     
   

    return 0; 
}

