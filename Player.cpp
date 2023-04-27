
#include "Player.h"

#include <iostream>
#include <sstream>

/*
Constructs an unnamed and undescribed player who is 0 years old.
*/
Player::Player() {
    this->playerName = "Unnamed Player";
    this->characterName = "Unnamed Character";
    this->characterAge = 0;
    this->characterDesc = "No description available.";
    this->playerActions = new List<PlayerActions>();
    this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::DoNothing));
    this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::DoAnything));
}

/*
Constructs a player with the given player name, character name, and character age.
If the age argument is negative it is ignored, and the character's age is set to 0.
*/
Player::Player(std::string playerName, std::string characterName, int age) {
    this->playerName = playerName;
    this->characterName = characterName;
    if (age >= 0) {
        this->characterAge = age;
    }
    else {
        std::cout << "Invalid character age: must be 0 or greater!";
        std::cout << "Setting age equal to 0. You can change this later by calling setCharacterAge(int).";
        this->characterAge = 0;
    }
    this->characterDesc = "No description available.";
    this->playerActions = new List<PlayerActions>();
    this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::DoNothing));
    this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::DoAnything));
}

CharacterTypes Player::getCharacterType() {
    CharacterTypes* result = new CharacterTypes(CharacterTypes::CharacterType::Generic);
    return *result;
}


List<PlayerActions>* Player::getPlayerActions() {
    return this->playerActions;
}

bool Player::canPerformAction(PlayerActions anAction) {
    if (anAction.getAction() == PlayerActions::PlayerAction::DoAnything) {
        return true;
    }
    else if (anAction.getAction() == PlayerActions::PlayerAction::DoNothing) {
        return true;
    }
    else {
        return false;
    }
}

/*
Returns the character's age in years.
*/
int Player::getCharacterAge() {
    return this->characterAge;
}

/*
Sets the character's age in years. If the input argument is negative, a message is
printed but no change is made to the character's age.
*/
void Player::setCharacterAge(int age) {
    if (age < 0) {
        std::cout << "Invalid character age: must be 0 or greater!";
    }
    else {
        this->characterAge = age;
    }
}

/*
Returns the player's age in years.
*/
std::string Player::getPlayerName() {
    return this->playerName;
}

/*
Sets the player's name to the specified value.
*/
void Player::setPlayerName(std::string playerName) {
    this->playerName = playerName;
}

/*
Returns the character's name.
*/
std::string Player::getCharacterName() {
    return this->characterName;
}

/*
Sets the character's name to the specified value.
*/
void Player::setCharacterName(std::string characterName) {
    this->characterName = characterName;
}

/*
Returns the character's description.
*/
std::string Player::getCharacterDescription() {
    return this->characterDesc;
}

/*
Sets the character's description to the specified value.
*/
void Player::setCharacterDescription(std::string description) {
    this->characterDesc = description;
}

/*
Returns a string representation of this player.
*/
std::string Player::toString() {
    std::ostringstream sout;
    // output character name, player name, and character description
    sout << "Character name: " << this->getCharacterName() << std::endl;
    sout << "Player name: " << this->getPlayerName() << std::endl;
    sout << "Character description: " << this->getCharacterDescription() << std::endl;
    // output character type
    sout << "Character type: Generic" << std::endl;
    sout << "Character actions: " << std::endl;
    sout << " PlayerActions::PlayerAction::DoNothing" << std::endl;
    sout << " PlayerActions::PlayerAction::DoAnything" << std::endl;
    return sout.str();
}

