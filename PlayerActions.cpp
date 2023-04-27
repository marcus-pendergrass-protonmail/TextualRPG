#include "PlayerActions.h"

PlayerActions::PlayerActions() {
	this->theAction = PlayerAction::DoNothing;
}

PlayerActions::PlayerActions(PlayerAction action) {
	this->theAction = action;
}

PlayerActions::PlayerActions(std::string actionString) {
	int matchingK = -1;
	for (int k = 0; k < 48; k++) {
		if (this->actionNames[k] == actionString) {
			matchingK = k;
			break;
		}
	}
	if (matchingK >= 0) {
		this->theAction = static_cast<PlayerAction>(matchingK);
	}
	else {
		this->theAction = PlayerAction::DoNothing;
	}
}


PlayerActions::PlayerAction PlayerActions::PlayerActions::getAction() {
	return this->theAction;
}

std::string PlayerActions::toString() {
	return this->actionNames[static_cast<int>(this->theAction)];
}


