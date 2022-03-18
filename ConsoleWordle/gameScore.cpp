#include "gameScore.h"

void GameScore::postGame(bool isWinner)
{
    if (!isWinner)
        losses++;
    else
    {
        std::cout << "WINNER! ";
        wins++;
    }
    gamesPlayed++;

    printf("\nGames played : %d.     Wins: %d.     Type Y to play again... ", gamesPlayed, wins);
}