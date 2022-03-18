#pragma once
#include <iostream>
#include <string>

class GameScore
{
public:
    int gamesPlayed{};
    int wins{};
    int losses{};

    void postGame(bool isWinner);    
};