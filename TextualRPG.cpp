// TextualRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CharacterTypesTester.h"
#include "GameZero.h"
#include "GraphTester.h"
#include "Player.h"
#include "Paladin.h"
#include "TestResults.h"

int main()
{
    std::cout << "Hello TextualRPG!\n";

    Paladin* pal = new Paladin("Marcus", "Sir Whackamole", 38);
    pal->setCharacterDescription("A rather forgetful knight, but his heart is in the right place.");

    GameZero* theGame = new GameZero(pal);
    theGame->startGame();

}

