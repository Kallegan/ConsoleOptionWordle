#include "gameLoop.h"

int main() //tried to keep main as clean as possible. 
{   
    int keepPlaying{1};
    int gamesPlayed{};    

    do
    {      
        keepPlaying = gameLoop(keepPlaying, gamesPlayed);
        gamesPlayed++;        

    } while (keepPlaying == 1);

    return 0;
}
