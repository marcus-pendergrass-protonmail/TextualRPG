#pragma once

#include <sstream>
#include <string>

/*
 A simple container class representing points in two-dimensional Euclidean space.
 */
class Point2D {
public:
    /*
     The x- and y-coordinates of the point.
     */
    float x;
    float y;

    /*
     Creates a new Point2D and initializes the coordinates to (0,0).
     */
    Point2D() { x = 0; y = 0; }

    /*
     Creates a new Point2D with the specified coordinates.
     */
    Point2D(float x, float y) {
        this->x = x;
        this->y = y;
    }

    /*
     Returns a string representation of this Point2D.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Point2D: (x,y) = (" << x << ", " << y << ")";
        return sout.str();
    }
};
