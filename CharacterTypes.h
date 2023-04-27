#pragma once

#include <string>

/*
 A wrapped enumeration representing the different categories of players in
 our RPG. An instance of this class represents a single character type.
 */
class CharacterTypes {

public:

    /*
     The raw enum.
     */
    enum class CharacterType {
        Barbarian,
        Bard,
        Cleric,
        Druid,
        Fighter,
        Monk,
        Paladin,
        Ranger,
        Rogue,
        Sorcerer,
        Warlock,
        Wizard,
        Generic,
        Other,
        Unknown
    };

    /*
     Creates a character type with the value Unknown.
     */
    CharacterTypes();

    /*
     Creates a character type with the specified type
     */
    CharacterTypes(CharacterType type);

    /*
     Returns the specific type of this character type.
     */
    CharacterTypes::CharacterType getType();

    /*
     Returns a string representation of this character type.
     */
    std::string toString();

    /*
     Two character types are equal if they have the same enum value.
     */
    bool operator==(const CharacterTypes& other) const {
        return this->theType == other.theType;
    }

protected:

    /*
     The type of this character type
     */
    CharacterType theType;

    /*
     String representation of the above types.
     */
    std::string typeNames[15] = {
        "Barbarian",
        "Bard",
        "Cleric",
        "Druid",
        "Fighter",
        "Monk",
        "Paladin",
        "Ranger",
        "Rogue",
        "Sorcerer",
        "Warlock",
        "Wizard",
        "Generic",
        "Other",
        "Unknown"
    };

};
