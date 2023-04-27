#pragma once

#include <sstream>
#include <string>

/*
 A Node is a simple container that holds a pointer to a data item, and
 optionally can connect to other nodes using the nextNode and previousNode
 attributes.
 */
template <typename T>
class Node {

protected:

    /*
     Pointer to the data stored in this node.
     */
    T* data;

    /*
     Pointer to this node's successor.
     */
    Node<T>* nextNode;

    /*
     Pointer to this node's predecessor.
     */
    Node<T>* previousNode;

public:

    /*
     Creates an empty node.
     */
    Node() {
        this->data = nullptr;
        this->nextNode = nullptr;
        this->previousNode = nullptr;
    }

    /*
     Creates a node containing the specified data.
     */
    Node(T* data) {
        this->data = data;
        this->nextNode = nullptr;
        this->previousNode = nullptr;
    }

    /*
     Returns the data from the node.
     */
    T* getData() {
        return this->data;
    }

    /*
     Sets the data for this node.
     */
    void setData(T* data) {
        this->data = data;
    }

    /*
     Returns a pointer to this node's successor.
     */
    Node<T>* getNextNode() {
        return this->nextNode;
    }

    /*
     Sets this node's successor to the specified node.
     */
    void setNextNode(Node<T>* nextNode) {
        this->nextNode = nextNode;
    }

    /*
     Returns a pointer to this node's predecessor.
     */
    Node<T>* getPreviousNode() {
        return this->previousNode;
    }

    /*
     Sets this node's predecessor to the specified node.
     */
    void setPreviousNode(Node<T>* previousNode) {
        this->previousNode = previousNode;
    }

    /*
     Returns a string representation of this node.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Node at " << this << std::endl;
        if (this->data != nullptr) {
            sout << "Data at " << this->data << std::endl;
        }
        else {
            sout << "No data" << std::endl;
        }
        if (this->previousNode != nullptr) {
            sout << "Previous node at " << this->previousNode << std::endl;
        }
        else {
            sout << "No previous node" << std::endl;
        }
        if (this->nextNode != nullptr) {
            sout << "Next node at " << this->nextNode << std::endl;
        }
        else {
            sout << "No next node" << std::endl;
        }
        return sout.str();
    }

};
