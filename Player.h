#pragma once

#include <string>

#include "CharacterTypes.h"
#include "PlayerActions.h"
#include "List.h"

/*
 This class models a player in our role-playing game.
 */
class Player {

public:

    /*
     Constructs an unnamed and undescribed player who is 0 years old.
     */
    Player();

    /*
     Constructs a player with the given player name, character name, and character age.
     If the age argument is negative it is ignored, and the character's age is set to 0.
     */
    Player(std::string playerName, std::string characterName, int age);

    /*
    Returns the character type of this player. For the base class Player, the
    character type should be CharacterType::Generic
    */
    virtual CharacterTypes getCharacterType();

    ///*
    //Sets the character type of this player. 
    //*/
    //void virtual setCharacterType(CharacterTypes type);

    /*
    Returns a list of the actions this player is capable of. For the base class
    Player, this method returns a list containing two actions: PlayerAction::DoAnything
    and PlayerAction::DoNothing.
    */
    virtual List<PlayerActions>* getPlayerActions();

    /*
    Returns true if and only if this player can perform the specified action.
    For base class Player, this returns true if and only if the action is
    either PlayerAction::DoAnything or PlayerAction::DoNothing.
    */
    virtual bool canPerformAction(PlayerActions anAction);

    /*
     Returns the character's age in years.
     */
    int getCharacterAge();

    /*
     Sets the character's age in years. If the input argument is negative, a message is
     printed but no change is made to the character's age.
     */
    void setCharacterAge(int age);

    /*
     Returns the player's age in years.
     */
    std::string getPlayerName();

    /*
     Sets the player's name to the specified value.
     */
    void setPlayerName(std::string playerName);

    /*
     Returns the character's name.
     */
    std::string getCharacterName();

    /*
     Sets the character's name to the specified value.
     */
    void setCharacterName(std::string characterName);

    /*
     Returns the character's description.
     */
    std::string getCharacterDescription();

    /*
     Sets the character's description to the specified value.
     */
    void setCharacterDescription(std::string description);

    /*
     Returns a string representation of this player.
     */
    virtual std::string toString();

protected:

    /*
     Storage for player name, character name, character description, and character age.
     */

    std::string playerName;
    std::string characterName;
    std::string characterDesc;
    int characterAge;
    List<PlayerActions>* playerActions;

};
