#include <random>
#include <sstream>

#include "GameZero.h"
#include "Vertex.h"

GameZero::GameZero() {
	this->thePlayer = new Player();
	// get player information 
	this->getUserInfo();
	// build the game graph
	this->buildGameGraph();
	// output player info to screen
	std::cout << std::endl;
	std::cout << thePlayer->toString() << std::endl;
}

GameZero::GameZero(Player* player) {
	this->thePlayer = player;
	// build the game graph
	this->buildGameGraph();
	// output player info to screen
	std::cout << std::endl;
	std::cout << thePlayer->toString() << std::endl;
}

void GameZero::startGame() {
	std::cout << "Welcome to DUNGEONS OF DOOM! Press the Return key to continue, or type 'exit' then Return to quit." << std::endl;
	getUserResponse();
	this->printVertexData();
	this->simulateFight();
}

void GameZero::endGame() {
	std::cout << "Bye bye, hope to see you in DUNGEONS OF DOOM again soon!" << std::endl;
	std::exit(0);
}

std::string GameZero::toString() {
	std::ostringstream sout;
	sout << "GameZero at " << this << std::endl;
	sout << "Player info:" << std::endl;
	sout << this->thePlayer->toString() << std::endl;
	sout << "Story in the Dragon's Lair:" << std::endl;
	// get a pointer to the list of strings stored in vertex 0
	List<std::string>* storyList = this->theGraph->getVertexData(0);
	for (int k = 0; k < storyList->getSize(); k++) {
		// get item k from the list
		std::string* itemK = storyList->peek(k);
		sout << *itemK << std::endl;
	}
	return sout.str();
}

void GameZero::getUserInfo() {
	// get player name
	std::cout << "Enter your real name:" << std::endl;
	std::string playerName = getUserResponse();
	this->thePlayer->setPlayerName(playerName);

	// get character name
	std::cout << "Enter your character's name." << std::endl;
	std::string charName = getUserResponse();
	this->thePlayer->setCharacterName(charName);

	// get character age
	std::cout << "How old is your character?" << std::endl;
	std::string charAgeStr = getUserResponse();
	try {
		int charAge = std::stoi(charAgeStr);
		this->thePlayer->setCharacterAge(charAge);
	}
	catch (const std::exception e) {
		std::cout << e.what() << std::endl;
		// set characters age to 30
		std::cout << "Invalid age string. Setting character age to 30." << std::endl;
		this->thePlayer->setCharacterAge(30);
	}

	// get character description
	std::cout << "Enter a brief description of your character." << std::endl;
	std::string charDescription = getUserResponse();
	this->thePlayer->setCharacterDescription(charDescription);

}

std::string GameZero::getUserResponse() {
	std::string result = "";
	// allow the user to respond, catch the response using getline
	std::getline(std::cin, result);
	if (result == "exit") {
		this->endGame();
	}
	else {
		return result;
	}
}


void GameZero::buildGameGraph() {
	this->theGraph = new Graph<List<std::string>, List<std::string>>();
	// add a single vertex
	Vertex<List<std::string>>* dragonsLair = new Vertex<List<std::string>>();
	this->theGraph->addVertex(dragonsLair);
	// add some string data to describe the story that occurs in the dragons lair.
	List<std::string>* storyList = new List<std::string>();
	// add some strings to the list
	storyList->insertAtEnd(new std::string("You awaken in a large underground hall."));
	storyList->insertAtEnd(new std::string("Firelight flickers from torches mounted on the walls, illuminating vast treasures of gold, jewels, silks, and art."));
	storyList->insertAtEnd(new std::string("On top of the largest pile of gold lies a sleeping green dragon."));
	storyList->insertAtEnd(new std::string("Wisps of smoke curl lazily about her head as she snores."));
	storyList->insertAtEnd(new std::string("She opens one eye lazily, but she's staring right at you!"));
	storyList->insertAtEnd(new std::string("A low rumble quickly crescendos to a roar as she raises her head and spews out a stream of fire in your direction!!"));
	storyList->insertAtEnd(new std::string("You withstand the initial blast, but the flames congeal into three ghost-like forms!!!"));
	storyList->insertAtEnd(new std::string("Fire-ghosts! And they are attacking you!!!!"));
	storyList->insertAtEnd(new std::string("Fight for your life!!!!!"));

	// store the list in the vertex of this graph
	this->theGraph->storeInVertex(storyList, 0);
}


void GameZero::printVertexData() {
	List<std::string>* storyList = this->theGraph->getVertexData(0);
	std::string userResponse;
	for (int k = 0; k < storyList->getSize(); k++) {
		std::string* lineK = storyList->peek(k);
		std::cout << *lineK << std::endl;
		userResponse = getUserResponse();
	}
}

void GameZero::simulateFight() {
	// build our PRNGs
	std::random_device r;
	std::default_random_engine engn(r());
	std::uniform_real_distribution<double> prng(0.0, 1.0);

	// set up player's vitality, hit point values, and hit probability
	int playerVitality = 100;
	int playerDamagePerHit = 10;
	double playerHitProbability = 0.6;

	// set up the ghosts' vitality, hit points, and hit probabilities
	int ghostVitality[3] = { 30, 30, 30 };
	int ghostDamagePerHit = 5;
	double ghostHitProbability = 0.35;

	// fight will proceed in round. Need a round counter
	int roundNumber = 1;

	// main simulation loop
	while (playerVitality > 0) {
		std::cout << "Fire-Ghost Fight: Round " << roundNumber << std::endl;

		// for each ghostthat remains alive, check (a) if the player's blow 
		// lands on the ghost, and (b) if the ghost's blow lands on the
		// player
		for (int k = 0; k < 3; k++) {
			if (ghostVitality[k] > 0) {
				// check if player lands a blow on the ghost. If so, update
				// vitatality points for the ghost, and print a message to
				// the console
				double randVal = prng(engn);
				if (randVal <= playerHitProbability) { // player's blow landed!
					// decrement vitality points
					ghostVitality[k] -= ghostDamagePerHit;
					std::cout << "YES!! You land a hit on ghost " << k << ", its vitality is now " << ghostVitality[k] << std::endl;
					this->getUserResponse();
				}
				// if ghost k is still alive, check to see if they land a blow
				// on the player
				if (ghostVitality[k] > 0) {
					// check if ghost k lands a blow on player, if so, update
					// points and print a message
					randVal = prng(engn);
					if (randVal <= ghostHitProbability) { // ghost's blow landed
						// decrement player's vitality points and print message
						playerVitality -= playerDamagePerHit;
						std::cout << "OUCH!! Ghost " << k << " lands hit on you, your vitality is now " << playerVitality << std::endl;
						this->getUserResponse();
						if (playerVitality <= 0) {
							std::cout << "Hate to break it to you, "<< this->thePlayer->getPlayerName()  << " but..." << std::endl;
							this->getUserResponse();
							std::cout << "Your character, " << this->thePlayer->getCharacterName() << ", is dead. :-(" << std::endl;
							this->getUserResponse();
							std::cout << "But no worries, you can play again anytime you choose!" << std::endl;
							this->getUserResponse();
							this->endGame();
						}
					}
				}
			}
		}
		// check to see if any ghosts remain alive. If not, the player has won.
		if (ghostVitality[0] <= 0 && ghostVitality[1] <= 0 && ghostVitality[2] <= 0) {
			std::cout << "Your character wins! All 3 ghosts are dead!" << std::endl;
			this->getUserResponse();
			std::cout << "The treasure is yours!" << std::endl;
			this->getUserResponse();
			std::cout << "Don't spend it all in one place! :-)" << std::endl;
			this->getUserResponse();
			this->endGame();
		}

		// increment roundNumber
		roundNumber++;
	}

}
