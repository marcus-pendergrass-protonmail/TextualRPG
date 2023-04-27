#pragma once

#include <string>

/*
 A wrapped enum representing all types of actions a character in our RPG can
 perform. Most characters only perform a subset of these actions.
 */
class PlayerActions {

public:

    /*
     The raw enum.
     */
    enum class PlayerAction {
        BeMerry,
        Bluff,
        CastSpell,
        Charge,
        Chill,
        CloseUmbrella,
        Cry,
        DoAnything,
        DoNothing,
        Drink,
        Eat,
        FallInLove,
        Fight,
        GetAllSnarky,
        GetAngry,
        GetDrunk,
        GetHappy,
        GetSad,
        GoToSleep,
        Help,
        Hug,
        InviteEveryoneOver,
        Kill,
        Laugh,
        Listen,
        Negotiate,
        OpenUmbrella,
        Ostracize,
        PickALock,
        PutOnArmor,
        Revive,
        RideHorse,
        RunAway,
        RunTowards,
        SmileMysteriously,
        Surrender,
        SwordFight,
        TakeOffArmor,
        Talk,
        TellAJoke,
        Threaten,
        ThrowSpear,
        ThrowKnife,
        TipHat,
        TipWaitress,
        WakeUp,
        Walk,
        WalkAway,
        WalkTowards
    };

    /*
     Creates a new PlayerAction with the value doNothing.
     */
    PlayerActions();

    /*
     Creates a new PlayerAction with the given value.
     */
    PlayerActions(PlayerAction action);

    /*
     Creates a new PlayerAction whose value is determined by
     the input string. Note: the input string must exactly
     match the name of the PlayerAction value.
     */
    PlayerActions(std::string actionString);

    /*
     Returns the specific type of action of this action type.
     */
    PlayerActions::PlayerAction getAction();

    /*
     Returns a string representation of this character type.
     */
    std::string toString();

    /*
     Two player actions are equal if they have the same enum value.
     */
    bool operator==(const PlayerActions& other) const {
        return this->theAction == other.theAction;
    }

protected:

    /*
    The action represented by this PlayerActions.
    */
    PlayerActions::PlayerAction theAction;

    /*
     String representation of the above types.
     */
    std::string actionNames[48] = {
        "BeMerry",
        "Bluff",
        "CastSpell",
        "Charge",
        "Chill",
        "CloseUmbrella",
        "Cry",
        "DoAnything",
        "DoNothing",
        "Drink",
        "Eat",
        "FallInLove"
        "Fight",
        "GetAllSnarky",
        "GetAngry",
        "GetDrunk",
        "GetHappy",
        "GetSad",
        "GoToSleep",
        "Help",
        "Hug",
        "InviteEveryoneOver",
        "Kill",
        "Laugh",
        "Listen",
        "Negotiate",
        "OpenUmbrella",
        "Ostracize",
        "PickALock",
        "PutOnArmor",
        "Revive",
        "RideHorse",
        "RunAway",
        "RunTowards",
        "SmileMysteriously",
        "Surrender",
        "SwordFight",
        "TakeOffArmor",
        "Talk",
        "TellAJoke",
        "Threaten",
        "ThrowSpear",
        "ThrowKnife",
        "TipHat",
        "TipWaitress",
        "WakeUp",
        "Walk",
        "WalkAway",
        "WalkTowards"
    };

};