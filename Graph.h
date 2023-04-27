#pragma once

#include <cmath>
//#include <ctgmath>
#include <sstream>
#include <string>
#include <typeinfo>

#include "Vertex.h"
#include "Edge.h"

// Note 1: when adding vertices or edges, use List::insertAtEnd. This
//         makes the indices assigned to the vertex or edge are in the
//         same order as the order in which the vertices or edges were
//         added.

/*
 A class to represent finite directed graphs.
 */
template <typename T, typename U>
class Graph {

protected:

    /*
     List of vertices of this graph.
     */
    List<Vertex<T>>* vertices;

    /*
     List of edges of this graph.
     */
    List<Edge<T, U>>* edges;

public:

    /*
     Creates an empty graph.
     */
    Graph() {
        this->vertices = new List<Vertex<T>>();
        this->edges = new List<Edge<T, U>>();
    }

    /*
     Returns true if and only if this graph is empty.
     */
    bool isEmpty() {
        return this->vertices->isEmpty();
    }

    /*
     Returns the number of vertices in this graph.
     */
    int getNumVertices() {
        return this->vertices->getSize();
    }

    /*
     Returns a pointer to a list containing pointers to all the vertices in
     this graph.
     */
    List<Vertex<T>>* getVertices() {
        return this->vertices;
    }

    /*
     Returns the number of edges in this graph.
     */
    int getNumEdges() {
        return this->edges->getSize();
    }

    /*
     Returns a pointer to a list containing pointers to all the edges in this
     graph.
     */
    List<Edge<T, U>>* getEdges() {
        return this->edges;
    }

    /*
     Returns the in-degree of the specified vertex, or a negative
     number if the specified vertex does not belong to this graph.
     */
    int getInDegree(Vertex<T>* vertex) {
        int inDegree;
        int ndx = this->vertices->getIndex(vertex);
        if (ndx < 0) {
            inDegree = -1;
        }
        else {
            inDegree = vertex->getInDegree();
        }
        return inDegree;
    }

    /*
     Returns the out-degree of the specified vertex, or a negative
     number if the specified vertex does not belong to this graph.
     */
    int getOutDegree(Vertex<T>* vertex) {
        int outDegree;
        int ndx = this->vertices->getIndex(vertex);
        if (ndx < 0) {
            outDegree = -1;
        }
        else {
            outDegree = vertex->getOutDegree();
        }
        return outDegree;
    }

    /*
     Returns the vertex with the given index. If no vertex has the given
     index, this method returns the null pointer.
     */
    Vertex<T>* getVertex(int index) {
        return this->vertices->peek(index);
    }

    /*
     Adds the specified vertex to this graph. Vertices can't be added twice,
     so if the specified vertex is already part of this graph, this method
     does nothing.
     TODO: give this an int return type to flag whether the add was successful.
     */
    void addVertex(Vertex<T>* vertex) {
        int ndx = this->vertices->getIndex(vertex);
        // if the specified vertex is already in the graph, do nothing,
        // otherwise insert the new vertex at the end of the vertex list
        if (ndx < 0) {
            this->vertices->insertAtEnd(vertex);
        }
    }

    /*
     Returns true if and only the specified vertex is
     part of this graph.
     */
    bool hasVertex(Vertex<T>* vertex) {
        return this->vertices->getIndex(vertex) >= 0;
    }

    /*
     Returns the edge in this graph with the given indices, or the null pointer
     if no edge with the given index exists in this graph.
     TODO: add to spec, implement
     */
    Edge<T, U>* getEdge(int index);

    /*
     Adds an unidirectional edge to the Graph, from the first argument to
     the second, provided that edge does not already exist. If an edge
     already exists in this graph between the from and to vertices, this
     method does nothing. If either of the two input vertices are not already
     part of this Graph, they are added. If the from and to vertices are
     actually the same vertex, a loop is added to that vertex.
     TODO: give this an int return type to flag if the add was successful
     */
    void addEdge(Vertex<T>* from, Vertex<T>* to) {
        // see if this edge is alread in the graph

        int edgeNdx = -1;
        for (int k = 0; k < this->edges->getSize(); k++) {
            Edge<T, U>* edgeK = this->edges->peek(k);
            if (edgeK->getInitialVertex() == from && edgeK->getTerminalVertex() == to) {
                edgeNdx = k;
                break;
            }
        }

        // if this edge is already in the graph, do nothing. Otherwise:
        if (edgeNdx < 0) {
            Edge<T, U>* newEdge = new Edge<T, U>(from, to);
            // need to handle a special case: if the from and to vertices
            // are actually the same, then we're adding a edge from that
            // vertex to itself. Otherwise, we're adding an edge between
            // different vertices
            if (from == to) {
                // get the indices for the from node (which is the same as
                // the to node). If getIndex returns a negative number, it
                // means that the corresponding vertex is not a member of
                // this graph.
                int fromNdx = this->vertices->getIndex(from);
                // if the vertex is not in the graph, add it
                if (fromNdx < 0) {
                    this->vertices->insertAtEnd(from);
                }
                // add the new edge to this graph
                this->edges->insertAtEnd(newEdge);
                // manage previousNodes and nextNodes. Since the edge goes
                // from a vertex to itself, the vertex is both an incoming
                // and outgoing vertex of itself.
                from->addOutVertex(from);
            }
            else {
                // get the indices for the from and to nodes. If getIndex returns
                // a negative number, it means that the corresponding vertex is
                // not a member of this graph.
                int fromNdx = this->vertices->getIndex(from);
                int toNdx = this->vertices->getIndex(to);
                // if the from vertex is not in the graph, add it
                if (fromNdx < 0) {
                    this->vertices->insertAtEnd(from);
                }
                // if the to vertex is not in the graph, add it
                if (toNdx < 0) {
                    this->vertices->insertAtEnd(to);
                }
                // add the new edge to this graph
                this->edges->insertAtEnd(newEdge);
                // manage previousNodes and nextNodes
                from->addOutVertex(to);
            }
        }
    }

    /*
     Returns true if and only if the specified edge is
     part of this graph.
     */
    bool hasEdge(Vertex<T>* from, Vertex<T>* to) {
        bool result = false;
        for (int k = 0; k < this->getNumEdges(); k++) {
            Edge<T, U>* edgeK = this->edges->peek(k);
            if (edgeK->getInitialVertex() == from && edgeK->getTerminalVertex() == to) {
                result = true;
            }
        }
        return result;
    }

    /*
     Returns a list of the outgoing vertices from the specified vertex.
     If the specified vertex is not part of this graph, an empty list
     is returned.
     */
    List<Vertex<T>>* getOutgoingVertices(Vertex<T>* vertex) {
        List<Vertex<T>>* result = new List<Vertex<T>>();
        if (this->hasVertex(vertex)) {
            int outDegree = vertex->getOutDegree();
            for (int k = 0; k < outDegree; k++) {
                result->insertAtEnd(vertex->getOutVertex(k));
            }
        }
        return result;
    }

    /*
     Returns a list of the incoming vertices to the specified vertex.
     If the specified vertex is not part of this graph, an empty list
     is returned.xx     */
    List<Vertex<T>>* getIncomingVertices(Vertex<T>* vertex) {
        List<Vertex<T>>* result = new List<Vertex<T>>();
        if (this->hasVertex(vertex)) {
            int inDegree = vertex->getInDegree();
            for (int k = 0; k < inDegree; k++) {
                result->insertAtEnd(vertex->getInVertex(k));
            }
        }
        return result;
    }

    /*
     Returns the weight of the specified edge. If the specified edge is not
     part of this graph, this method returns NaN (not a number) as a double.
     */
    double getEdgeWeight(Vertex<T>* from, Vertex<T>* to) {
        double result = std::nan("");
        for (int k = 0; k < this->getNumEdges(); k++) {
            Edge<T, U>* edgeK = this->edges->peek(k);
            if (edgeK->getInitialVertex() == from && edgeK->getTerminalVertex() == to) {
                result = edgeK->getWeight();
            }
        }
        return result;
    }

    /*
    Returns the weight of the edge with the given index. If no edge in this
    graph has the given index, this method returns NaN (not a number) as a
    double.
    */
    double getEdgeWeight(int index) {
        double result = std::nan("");
        Edge<T, U>* theEdge = this->edges->peek(index);
        if (theEdge != nullptr) {
            result = theEdge->getWeight();
        }
        return result;
    }

    /*
     Sets the weight of the specified edge. If the specified edge is not
     part of this graph, this method does nothing. If the set operation was
     successful this method returns 0. If it was unsuccessful this method
     returns a negative number.
    */
    int setEdgeWeight(double weight, Vertex<T>* from, Vertex<T>* to) {
        int result = -1;
        for (int k = 0; k < this->getNumEdges(); k++) {
            Edge<T, U>* edgeK = this->edges->peek(k);
            if (edgeK->getInitialVertex() == from && edgeK->getTerminalVertex() == to) {
                edgeK->setWeight(weight);
                result = 0;
            }
        }
        return result;
    }

    /*
     Sets the weight of the edge with the given index. If no edge in this
     graph has the given index, this method does nothing. If the set operation
     was successful this method returns 0. If it was unsuccessful this method
     return a negative number.
    */
    int setEdgeWeight(double weight, int index) {
        int result = -1;
        Edge<T, U>* theEdge = this->edges->peek(index);
        if (theEdge != nullptr) {
            theEdge->setWeight(weight);
            result = 0;
        }
        return result;
    }

    /*
     Stores the specified data in the specified vertex of this graph. If the
     specified vertex is not in this graph, then this method does nothing. If
     the store operation is successful, this method returns 0. If it is
     unsuccessful, this method returns a negative number.
     */
    int storeInVertex(T* data, Vertex<T>* vertex) {
        int result = -1;
        if (this->hasVertex(vertex)) {
            vertex->setData(data);
            result = 0;
        }
        return result;
    }

    /*
     Stores the specified data in the vertex of this graph with the specified
     index. If no vertex of this graph has the specified index, this method
     does nothing.If the store operation is successful, this method returns 0.
     If it is unsuccessful, this method returns a negative number.
     */
    int storeInVertex(T* data, int index) {
        int result = -1;
        Vertex<T>* v = this->vertices->peek(index);
        if (v != nullptr) {
            v->setData(data);
            result = 0;
        }
        return result;
    }

    /*
     Retrieves a pointer to the data that is stored in the specified vertex.
     If the specified vertex is not part of this graph, or if there is no data
     stored in the vertex, this method returns the null pointer.
     */
    T* getVertexData(Vertex<T>* vertex) {
        T* result = nullptr;
        if (this->hasVertex(vertex)) {
            result = vertex->getData();
        }
        return result;
    }

    /*
     Retrieves a pointer to the data that is stored in the vertex with the
     specified index. If no vertex of this graph has the specified index, or
     if there is no data stored in the vertex, this method returns the null
     pointer.
     */
    T* getVertexData(int index) {
        T* result = nullptr;
        Vertex<T>* v = this->vertices->peek(index);
        if (v != nullptr) {
            result = v->getData();
        }
        return result;
    }

    /*
     Stores the specified data in the specified edge of this graph. If the
     specified edge is not in this graph, then this method does nothing. If
     the store operation is successful, this method returns 0. If it is
     unsuccessful, this method returns a negative number.
     */
    int storeInEdge(U* data, Vertex<T>* from, Vertex<T>* to) {
        int result = -1;
        for (int k = 0; k < this->getNumEdges(); k++) {
            Edge<T, U>* edgeK = this->edges->peek(k);
            if (edgeK->getInitialVertex() == from && edgeK->getTerminalVertex() == to) {
                edgeK->setData(data);
                result = 0;
            }
        }
        return result;
    }

    /*
     Stores the specified data in the the edge of this graph with the specified
     index. If no edge of this graph has the specified index, this method does
     nothing. If the store operation is successful, this method returns 0. If it
     is unsuccessful, this method returns a negative number.
     */
    int storeInEdge(U* data, int index) {
        int result = -1;
        Edge<T, U>* theEdge = this->edges->peek(index);
        if (theEdge != nullptr) {
            theEdge->setData(data);
            result = 0;
        }
        return result;
    }

    /*
     Retrieves a pointer to the data that is stored in the specified edge.
     If the specified edge is not part of this graph, or if there is no data
     stored in the edge, this method returns the null pointer.
     */
    U* getEdgeData(Vertex<T>* from, Vertex<T>* to) {
        U* result = nullptr;
        for (int k = 0; k < this->getNumEdges(); k++) {
            Edge<T, U>* edgeK = this->edges->peek(k);
            if (edgeK->getInitialVertex() == from && edgeK->getTerminalVertex() == to) {
                result = edgeK->getData();
            }
        }
        return result;
    }

    /*
     Retrieves a pointer to the data that is stored in the edge with the
     specified index. If no edge of this graph has the specified index, or
     if there is no data stored in the edge, this method returns the null
     pointer.
     */
    U* getEdgeData(int index) {
        U* result = nullptr;
        Edge<T, U>* theEdge = this->edges->peek(index);
        if (theEdge != nullptr) {
            result = theEdge->getData();
        }
        return result;
    }

    /*
     Returns the index of the specified vertex in this graph. If the specified
     vertex is not part of this graph, this method returns a negative number.
     */
    int getVertexIndex(Vertex<T>* vertex) {
        return this->vertices->getIndex(vertex);
    }

    /*
     Returns the index of the specified edge in this graph. If the specified
     edge is not part of this graph, this method returns a negative number.
     */
    int getEdgeIndex(Edge<T, U>* edge) {
        return this->edges->getIndex(edge);
    }

    /*
     Returns a string representation of this Graph.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Graph at " << this << std::endl;
        sout << " Number of vertices: " << this->getNumVertices() << std::endl;
        sout << " Number of edges: " << this->getNumEdges() << std::endl;
        sout << " Storing data of type " << typeid(T).name() << " in vertices" << std::endl;
        sout << " Storing data of type " << typeid(U).name() << " in edges" << std::endl;
        return sout.str();
    }

};
