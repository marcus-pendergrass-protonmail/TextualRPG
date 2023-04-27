#include <sstream>

#include "Paladin.h"

// default constructor
Paladin::Paladin() {
	this->playerName = "Unnamed player";
	this->characterName = "Unnamed character";
	this->characterAge = 0;
	this->characterDesc = "No description available.";
	// create the list of player actions that a Paladin is capable of
	this->playerActions = new List<PlayerActions>();
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::Fight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::SwordFight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::CastSpell));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::RideHorse));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::PutOnArmor));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::TakeOffArmor));
}

// second constructor
Paladin::Paladin(std::string playerName, std::string characterName, int characterAge) {
	this->playerName = playerName;
	this->characterName = characterName;
	this->characterAge = characterAge;
	this->characterDesc = "No description available.";
	// create the list of player actions that a Paladin is capable of
	this->playerActions = new List<PlayerActions>();
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::Fight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::SwordFight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::CastSpell));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::RideHorse));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::PutOnArmor));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::TakeOffArmor));
}

CharacterTypes Paladin::getCharacterType() {
	CharacterTypes* result = new CharacterTypes(CharacterTypes::CharacterType::Paladin);
	return *result;
}

List<PlayerActions>* Paladin::getPlayerActions() {
	return this->playerActions;
}

bool Paladin::canPerformAction(PlayerActions anAction) {
	bool result = false;
	for (int k = 0; k < this->playerActions->getSize(); k++) {
		PlayerActions* actionK = this->playerActions->peek(k);
		if (anAction == *actionK) {
			result = true;
			break;
		}
	}
	return result;
}


void Paladin::fight() {
	std::cout << "En Gaurde, you rascal!" << std::endl;
}


std::string Paladin::toString() {
	std::ostringstream sout;
	// output character name, player name, and character description
	sout << "Character name: " << this->getCharacterName() << std::endl;
	sout << "Player name: " << this->getPlayerName() << std::endl;
	sout << "Character description: " << this->getCharacterDescription() << std::endl;
	// output character type
	sout << "Character type: Paladin" << std::endl;
	sout << "Character actions: " << std::endl;
	sout << " PlayerActions::PlayerAction::Fight" << std::endl;
	sout << " PlayerActions::PlayerAction::SwordFight" << std::endl;
	sout << " PlayerActions::PlayerAction::RideHorse" << std::endl;
	sout << " PlayerActions::PlayerAction::CastSpell" << std::endl;
	sout << " PlayerActions::PlayerAction::PutOnArmor" << std::endl;
	sout << " PlayerActions::PlayerAction::TakeOffArmor" << std::endl;
	return sout.str();

}

