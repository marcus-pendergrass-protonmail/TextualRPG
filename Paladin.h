#pragma once

#include "Player.h"
#include "PlayerActions.h"
#include "List.h"
#include "CharacterTypes.h"

class Paladin : public Player {

public:

    /*
    Creates a new Paladin. All player information is set to default values.
    */
    Paladin();

    /*
    Creates a new Paladin with the specifies player name, character name, 
    and age.
    */
    Paladin(std::string playerName, std::string characterName, int age);

    /*
    Returns the character type of this Paladin.
    */
    CharacterTypes getCharacterType() override;

    /*
    Returns a list of actions this character is capable of.
    */
    List<PlayerActions>* getPlayerActions() override;

    /*
    Returns true if and only if this player can perform the specified action.
    */
    bool canPerformAction(PlayerActions anAction) override;

    /*
    Returns a string representation of this Paladin.
    */
    std::string toString() override;

    /*
    Implements the PlayerAction::Fight action.
    */
    void fight();

    /*
    Implements the PlayerAction::SwordFight action.
    */
    void swordFight();

    /*
    Implements the PlayerAction::CastSpell action.
    */
    void castSpell(std::string incantation);

    /*
    Implements the PlayerAction::RideHorse action.
    */
    void rideHorse();

    /*
    Implements the PlayerAction::PutOnArmor action.
    */
    void putOnArmor();

    /*
    Implements the PlayerAction::TakeOffArmor action.
    */
    void takeOffArmor();

};
