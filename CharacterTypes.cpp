#include "CharacterTypes.h"

/*
 Creates a character type with the value Unknown.
 */
CharacterTypes::CharacterTypes() {
    this->theType = CharacterTypes::CharacterType::Unknown;
}

/*
 Creates a character type with the specified type
 */
CharacterTypes::CharacterTypes(CharacterTypes::CharacterType type) {
    this->theType = type;
}

/*
 Returns the specific type of this character type.
 */
CharacterTypes::CharacterType CharacterTypes::getType() {
    return this->theType;
}

/*
 Two character types are equal if they have the same enum value.
 */
std::string CharacterTypes::toString() {
    return this->typeNames[static_cast<int>(theType)];
}
