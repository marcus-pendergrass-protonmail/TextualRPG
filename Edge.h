#pragma once

#include <sstream>
#include <string>

#include "Pair.h"
#include "Vertex.h"

template <typename T, typename U>
class Edge {

protected:

    /*
     The pair of vertices associated with this directed edge. The first
     member of the pair is the "from" vertex, and the second member is the
     "to" vertex
     */
    Pair<Vertex<T>, Vertex<T>>* theEdge;

    /*
     The weight associated with this edge
     */
    double edgeWeight;

    /*
     The data stored in this edge
     */
    U* data;

public:

    /*
     Creates an edge with the specified initial and terminal vertices.
     */
    Edge(Vertex<T>* initialVertex, Vertex<T>* terminalVertex) {
        this->theEdge = new Pair<Vertex<T>, Vertex<T>>(initialVertex, terminalVertex);
        this->edgeWeight = 1;
        this->data = nullptr;
    }

    /*
     Returns the weight associated with this edge.
     */
    double getWeight() {
        return this->edgeWeight;
    }

    /*
     Sets the weight associated with this edge.
     */
    void setWeight(double weight) {
        this->edgeWeight = weight;
    }

    /*
     Returns a pointer to the data stored in this edge. If there is no data
     stored in this edge, the null pointer is returned.
     */
    U* getData() {
        return this->data;
    }

    /*
     Sets the data stored in this edge.
     */
    void setData(U* data) {
        this->data = data;
    }

    /*
     Returns the initial vertex for this edge.
     */
    Vertex<T>* getInitialVertex() {
        return this->theEdge->first;
    }

    /*
     Returns the terminal vertex for this edge.
     */
    Vertex<T>* getTerminalVertex() {
        return this->theEdge->second;
    }

    /*
     Returns true if and only if the initial and terminial vertices for this
     edge are identical.
     */
    bool isLoop() {
        return this->theEdge->first == this->theEdge->second;
    }

    /*
     Returns a string representation of this edge.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Edge at " << this << std::endl;
        sout << " Initial vertex at " << this->theEdge->first << std::endl;
        sout << " Terminal vertex as " << this->theEdge->second << std::endl;
        sout << " Edge weight is " << this->edgeWeight << std::endl;
        if (this->data != nullptr) {
            sout << " Data at " << this->data << std::endl;
        }
        else {
            sout << " No data" << std::endl;
        }
        return sout.str();
    }

};

/*
 Overload operator== to compare two Edges. This will return
 true if and only if the to and from pointers from each Edge
 point to the same vertices respectively, the data pointers
 from each edge point to the same memory location, and both
 edges have the same edge weight.
 */
template <typename T, typename U>
bool operator==(Edge<T, U>& lhs, Edge<T, U>& rhs) {
    //    std::cout << "operator== here" << std::endl;
    bool initialVerticesTheSame = lhs.getInitialVertex() == rhs.getInitialVertex();
    bool terminalVerticesTheSame = lhs.getTerminalVertex() == rhs.getTerminalVertex();
    bool dataTheSame = lhs.getData() == rhs.getData();
    bool weightsTheSame = lhs.getWeight() == rhs.getWeight();
    return initialVerticesTheSame && terminalVerticesTheSame && dataTheSame && weightsTheSame;
}

template <typename T, typename U>
bool operator!=(Edge<T, U>& lhs, Edge<T, U>& rhs) {
    return !(lhs == rhs);
}
