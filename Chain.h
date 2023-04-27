
#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "Node.h"


/*
 A template representing doubly-linked chains. A chain supports insertion and
 removal at either end, and peek at any valid position.
 */
template <typename T>
class Chain {

    // for testing only
    friend class ChainTester;

protected:

    /*
     Pointer to the start node of the chain.
     */
    Node<T>* startNode;

    /*
     Pointer to the end node of the chain.
     */
    Node<T>* endNode;

    /*
     To keep track of the number of nodes in the chain.
     */
    int numNodes;

public:

    /*
     Creates an empty chain.
     */
    Chain() {
        this->startNode = nullptr;
        this->endNode = nullptr;
        this->numNodes = 0;
    }

    /*
     Returns true if and only if this chain has no nodes.
     */
    bool isEmpty() {
        return this->numNodes == 0;
    }

    /*
     Returns the number of nodes in this chain.
     */
    int getSize() {
        return this->numNodes;
    }

    /*
     Returns a pointer to the dat stored in the node at the
     specified position of this chain. Does not remove the node from this chain.
     */
    T* peek(int position) {
        T* result;
        if (this->isEmpty()) {
            result = nullptr;
        }
        else {
            Node<T>* currentNode = this->startNode;
            for (int k = 0; k < position; k++) {
                currentNode = currentNode->getNextNode();
            }
            result = currentNode->getData();
        }
        return result;
    }

    /*
     Sets the data of the node in the specified position. If the position
     does not exist in this chain, this method does nothing.
     */
    void setData(T* data, int position) {
        if (!this->isEmpty()) {
            Node<T>* currentNode = this->startNode;
            for (int k = 0; k < position; k++) {
                currentNode = currentNode->getNextNode();
            }
            currentNode->setData(data);
        }
    }

    /*
     Inserts the specified data at the beginning of this chain.
     */
    void insertAtStart(T* data) {
        Node<T>* newStart = new Node<T>(data);
        if (this->isEmpty()) {
            this->startNode = newStart;
            this->endNode = newStart;
            this->numNodes = 1;
        }
        else {
            newStart->setNextNode(this->startNode);
            this->startNode->setPreviousNode(newStart);
            this->startNode = newStart;
            this->numNodes++;
        }
    }

    /*
     Removes the node at the start of this chain, and returns its data.
     */
    T* removeFromStart() {
        T* result;
        if (this->isEmpty()) {
            result = nullptr;
        }
        else if (this->numNodes == 1) {
            result = this->startNode->getData();
            delete startNode;
            this->startNode = nullptr;
            this->endNode = nullptr;
            this->numNodes = 0;
        }
        else {
            result = this->startNode->getData();
            Node<T>* newStart = this->startNode->getNextNode();
            newStart->setPreviousNode(nullptr);
            delete this->startNode;
            this->startNode = newStart;
            this->numNodes--;
        }
        return result;
    }

    /*
     Removes the node at the end of this chain, and returns its data.
     */
    T* removeFromEnd() {
        T* result;
        if (this->isEmpty()) {
            result = nullptr;
        }
        else if (this->numNodes == 1) {
            result = this->endNode->getData();
            delete startNode;
            this->startNode = nullptr;
            this->endNode = nullptr;
            this->numNodes = 0;
        }
        else {
            result = this->endNode->getData();
            Node<T>* newEnd = this->endNode->getPreviousNode();
            newEnd->setNextNode(nullptr);
            delete this->endNode;
            this->endNode = newEnd;
            this->numNodes--;
        }
        return result;
    }

    void insertAtEnd(T* data) {
        Node<T>* newEnd = new Node<T>(data);
        if (this->isEmpty()) {
            this->endNode = newEnd;
            this->startNode = newEnd;
            this->numNodes = 1;
        }
        else {
            newEnd->setPreviousNode(this->endNode);
            this->endNode->setNextNode(newEnd);
            this->endNode = newEnd;
            this->numNodes++;
        }
    }

    /*
     Returns a string representation of this chain.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Chain at " << this << std::endl;
        if (this->startNode != nullptr) {
            //            sout << "Chain contains " << this->numNodes << " nodes" << std::endl;
            sout << "Start node at " << this->startNode << std::endl;
            sout << "End node at " << this->endNode << std::endl;
        }
        else {
            //            sout << "This chain is empty" << std::endl;
            sout << "No start node" << std::endl;
            sout << "No end node" << std::endl;
        }
        return sout.str();
    }

};
