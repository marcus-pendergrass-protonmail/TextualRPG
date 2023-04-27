#pragma once

#include <iostream>
#include <sstream>
#include <string>

/*
 A class to represent paired data. A Pair has a first element and
 a second element. These attributes are publicly accessible, and
 the types of the first and second element can be arbitrary.
 */
template <typename T, typename U>
class Pair {

public:

    /*
     Pointers to the data in this pair.
     */
    T* first;
    U* second;

    /*
     Creates an empty pair.
     */
    Pair() {
        this->first = nullptr;
        this->second = nullptr;
    }

    /*
     Creates a pair whose first and second elements are the specified data.
     */
    Pair(T* first, U* second) {
        this->first = first;
        this->second = second;
    }

    /*
     Returns true if and only if both elements of this pair are null.
     */
    bool isEmpty() {
        return (this->first == nullptr && this->second == nullptr);
    }

    /*
     Returns true if and only if both elements of this pair are non-null.
     */
    bool isComplete() {
        return (this->first != nullptr && this->second != nullptr);
    }

    /*
     Swaps the elements of the pair.
     */
    Pair<U, T>* swap() {
        return new Pair<U, T>(this->second, this->first);
    }

    /*
     Returns a string representation of this pair
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Pair at " << this << std::endl;
        if (this->first != nullptr) {
            sout << "First element at " << this->first << std::endl;
        }
        else {
            sout << "No first element" << std::endl;
        }
        if (this->second != nullptr) {
            sout << "Second element at " << this->second << std::endl;
        }
        else {
            sout << "No second element" << std::endl;
        }
        return sout.str();
    }

    /*
     Overload operator== to compare the pair to another one. This will
     return true if and only if this->first and rhs.first both point to the
     same data item AND this->second and rhs.second both point to the
     same data item.
     */
     //    bool operator==(Pair<T,U> const &rhs) {
     //        return (this->first == rhs.first && this->second == rhs.second);
     //    }

};

/*
 Overload operator== to compare two Pairs. This will return
 true if and only if lhs.first and rhs.first both point to the
 same data item AND lhs.second and rhs.second both point to the
 same data item.
 */
template <typename T, typename U>
bool operator==(Pair<T, U>& lhs, Pair<T, U>& rhs) {
    std::cout << "operator== here" << std::endl;
    return (lhs.first == rhs.first && lhs.first == rhs.first);
}
