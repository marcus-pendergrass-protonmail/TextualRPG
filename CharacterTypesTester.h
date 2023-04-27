#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "CharacterTypes.h"
#include "TestResults.h"

class CharacterTypesTester {

public:


    /*
     Test default constructor, getType().
     */
    static TestResults* test0() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // character type should be unknown
        pointsPossible++;
        CharacterTypes* cts = new CharacterTypes();
        CharacterTypes::CharacterType ct = cts->getType();
        if (ct == CharacterTypes::CharacterType::Unknown) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value";
        }
        std::cout << "CharacterTypesTester::test0 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test full constructor, getType
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        //
        CharacterTypes* c;
        CharacterTypes::CharacterType ct;
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Barbarian);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Barbarian) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Bard);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Bard) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Cleric);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Cleric) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Druid);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Druid) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Fighter);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Fighter) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Generic);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Generic) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Monk);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Monk) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Other);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Other) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Paladin);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Paladin) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Ranger);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Ranger) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Rogue);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Rogue) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Sorcerer);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Sorcerer) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Unknown);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Unknown) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Warlock);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Warlock) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Wizard);
        ct = c->getType();
        if (ct == CharacterTypes::CharacterType::Wizard) {
            pointsEarned++;
        }
        else {
            sout << "getType returned an incorrect value" << std::endl;
        }

        std::cout << "CharacterTypesTester::test1 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test toString
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        //
        CharacterTypes* c;
        std::string str;
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Barbarian);
        str = c->toString();
        if (str == "Barbarian") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Bard);
        str = c->toString();
        if (str == "Bard") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Cleric);
        str = c->toString();
        if (str == "Cleric") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Druid);
        str = c->toString();
        if (str == "Druid") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Fighter);
        str = c->toString();
        if (str == "Fighter") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Generic);
        str = c->toString();
        if (str == "Generic") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Monk);
        str = c->toString();
        if (str == "Monk") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Other);
        str = c->toString();
        if (str == "Other") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Paladin);
        str = c->toString();
        if (str == "Paladin") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Ranger);
        str = c->toString();
        if (str == "Ranger") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Rogue);
        str = c->toString();
        if (str == "Rogue") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Sorcerer);
        str = c->toString();
        if (str == "Sorcerer") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Unknown);
        str = c->toString();
        if (str == "Unknown") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Warlock);
        str = c->toString();
        if (str == "Warlock") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }
        //
        pointsPossible++;
        c = new CharacterTypes(CharacterTypes::CharacterType::Wizard);
        str = c->toString();
        if (str == "Wizard") {
            pointsEarned++;
        }
        else {
            sout << "toString returned an incorrect value" << std::endl;
        }

        std::cout << "CharacterTypesTester::test2 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    static TestResults* testX() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;

        std::cout << "CharacterTypesTester::testX results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    static TestResults* runAllTests() {
        int totalPossible = 0;
        int totalEarned = 0;

        TestResults* r;

        r = test0();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test1();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test2();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        return new TestResults(totalPossible, totalEarned, "");
    }

};
