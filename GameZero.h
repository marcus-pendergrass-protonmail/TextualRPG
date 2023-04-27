#pragma once

#include <string>

#include "Graph.h"
#include "List.h"
#include "Player.h"

/*
A very simple single-player textual RPG. The game is designed to provide rich
textual interactions with the player.

Scenario:

  - The player awakens in a dragon's lair.
  - The dragon belches three fire-ghosts, who attack the player.
  - If you defeat all three fire-ghosts, you collect the dragon's treasure.
  - If the fire-ghosts defeats the player, the game ends.

*/
class GameZero
{

public:

	/*
	The default constructor sets up the game, but does not start it.
	*/
	GameZero();

	/*
	Creates a new GameZero with the specified player.
	*/
	GameZero(Player* player);

	/*
	Method to start the game.
	*/
	void startGame();

	/*
	Mathod to end the game.
	*/
	void endGame();

	/*
	Returns a string representation of this game.
	*/
	std::string toString();

protected:

	/*
	The player in our RPG.
	*/
	Player* thePlayer;

	/*
	The graph for our RPG.
	*/
	Graph<List<std::string>, List<std::string>>* theGraph;

	/*
	Function to prompt the game player for character information, and then create
	the Player object representing the game player.
	*/
	void getUserInfo();

	/*
	Function to allow the user to (a) provide a response frequently during the game,
	and (b) allow the user to exit the game if his response is the word "exit".
	*/
	std::string getUserResponse();

	/*
	Builds the graph for our RPG, and stores its location in the theGraph attribute.
	*/
	void buildGameGraph();

	/*
	Prints the string data stored in the vertex of the game graph. The method
	should print a string, accept user input, then print the next string, 
	repeating until all strings have been printed.
	*/
	void printVertexData();

	/*
	Simulates the fight scene in this RPG.

	  - The dragon belches three fire-ghosts, who attack the player.
	  - If you defeat all three fire-ghosts, you collect the dragon's treasure.
	  - If the fire-ghosts defeats the player, the game ends.
	*/
	void simulateFight();


};

