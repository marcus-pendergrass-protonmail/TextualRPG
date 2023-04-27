#pragma once

#include <sstream>
#include <string>

class TestResults {

public:

    int pointsPossible;

    int pointsEarned;

    std::string comments;

    TestResults() {
        pointsPossible = 0;
        pointsEarned = 0;
        comments = "\n";
    }

    TestResults(int pointsPossible, int pointsEarned, std::string comments) {
        this->pointsPossible = pointsPossible;
        this->pointsEarned = pointsEarned;
        this->comments = comments;
    }

    std::string toString() {
        std::ostringstream sout;
        sout << "TestResults at " << this << std::endl;
        sout << "Points possible: " << pointsPossible << std::endl;
        sout << "Points earned: " << pointsEarned << std::endl;
        if (pointsEarned < pointsPossible) {
            sout << "Comments on failed tests:" << std::endl;
            sout << comments << std::endl;
        }
        return sout.str();
    }

};
