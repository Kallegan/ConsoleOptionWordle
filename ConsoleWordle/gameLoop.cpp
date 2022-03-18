#include "gameLoop.h"

bool gameLoop()
{  
    GameScore static s_gameScore;    
    InputHandler iHandler;   
    WordleBoard drawBoard;   

    system("CLS");   
    drawBoard.fillEmpty(); //fills screen with empty playing fuild.
    do
    {   
        iHandler.takeUserGuess(); 
        drawBoard.currentRound++;
        drawBoard.printCurrentGuesses(iHandler.getGuesses(), iHandler.getRandoms());
        drawBoard.fillEmpty();

    } while (!iHandler.canPlay(drawBoard.currentRound));

    s_gameScore.postGame(iHandler.isWinner);     
    return iHandler.checkContinue();
}
