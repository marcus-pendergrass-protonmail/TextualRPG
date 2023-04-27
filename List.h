#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "Chain.h"

/*
 A templated class representing lists. A List<T> manages pointers to objects of type T.
 */
template <typename T>
class List : public Chain<T> {

protected:

    /*
     Creates a list consisting of the specified node.
     */
    List(Node<T>* existingNode) {
        if (existingNode == nullptr) {
            this->startNode = nullptr;
            this->endNode = nullptr;
            this->numNodes = 0;
        }
        else {
            this->numNodes = 1;
            // The existing node may already be linked to other nodes.
            // If so they should be part of this list.
            // First, find the end node, and update numNodes
            Node<T>* currentNode = existingNode;
            while (currentNode->getNextNode() != nullptr) {
                currentNode = currentNode->getNextNode();
                this->numNodes++;
            }
            // set the end node of this list
            this->endNode = currentNode;
            // Next, find the start node, and update numNodes
            currentNode = existingNode;
            while (currentNode->getPreviousNode() != nullptr) {
                currentNode = currentNode->getPreviousNode();
                this->numNodes++;
            }
            // set the start node of this list
            this->startNode = currentNode;
        }
    }

public:

    /*
     Creates an empty list.
     */
    List() : Chain<T>() {}

    /*
     Returns the index of the first occurance of the specified
     data in this chain, or, if the specified data is not in
     this chain, returns a negative number.

     Note: the specified data is considered to be in this chain
     iff its pointer has the same value as one of the pointers
     managed by this list.
     */
    int getIndex(T* data) {
        int result = -1;
        int sz = this->getSize();
        for (int k = 0; k < sz; k++) {
            T* peekResult = this->peek(k);
            if (peekResult == data) {
                result = k;
                break;
            }
        }
        return result;
    }

    /*
     Removes the node at the specified position, and returns the
     data from that node. If there is no node in the specified
     position, this method leaves the list unaltered and returns
     the null pointer.
     */
    T* removeFromPosition(int position) {
        T* result;
        if (this->isEmpty()) {
            // return nullptr if this list is empty
            result = nullptr;
        }
        else if (this->numNodes == 1) {
            // if this list contains exactly 1 node, only
            // can return data from position 0.
            if (position != 0) {
                result = nullptr;
            }
            else {
                // get data
                result = this->removeFromEnd();
            }
        }
        else {
            // get the node in the specified position
            Node<T>* currentNode = this->startNode;
            for (int k = 0; k < position; k++) {
                currentNode = currentNode->getNextNode();
            }
            // currentNode is now the node in the specified position
            List<T>* lastHalf = this->splitAfter(position);
            // remove the node and get the data
            result = this->removeFromEnd();
            // put the two halves back together
            this->append(lastHalf);
        }
        return result;
    }

    /*
     Inserts the specified data into the list as a new node in
     the specified position.
     TODO: what if position isn't a valid location in the list?
     */
    void insertAtPosition(int position, T* data) {
        if (this->isEmpty()) {
            this->startNode = new Node<T>(data);
            this->endNode = this->startNode;
            this->numNodes = 1;
        }
        else if (position == 0) {
            Node<T>* newStart = new Node<T>(data);
            this->startNode->setPreviousNode(newStart);
            newStart->setNextNode(this->startNode);
            this->startNode = newStart;
            this->numNodes++;
        }
        else {
            List<T>* lastHalf = this->splitAfter(position - 1);
            // insertAtEnd will increment numNodes, so we don't have
            // to do it here
            this->insertAtEnd(data);
            this->append(lastHalf);
            //            this->numNodes++;
        }
    }

    /*
     Splits this list after the specified position, removing all
     nodes after that position from this list, and returning these
     nodes as another list.
     */
    List<T>* splitAfter(int position) {
        List<T>* result;
        if (this->numNodes < 2) {
            // can't split, so return an empty list
            result = new List<T>();
        }
        else {
            // get node at specified position
            Node<T>* currentNode = this->startNode;
            for (int k = 0; k < position; k++) {
                currentNode = currentNode->getNextNode();
            }
            // currentNode is now the node at the specified position
            // if currentNode == endNode, the split does nothing
            if (currentNode == this->endNode) {
                // the split does nothing, so return an empty list
                result = new List<T>();
            }
            else {
                // otherwise currentNode->getNextNode() will be the new
                // root of the returned list
                Node<T>* newRoot = currentNode->getNextNode();
                // break the link between newNode and its predecessor
                newRoot->setPreviousNode(nullptr);
                // break the link between the current node and its successor
                currentNode->setNextNode(nullptr);
                // the end node of this list should now be the current node
                this->endNode = currentNode;
                // update the number of nodes in this list
                this->numNodes = position + 1;
                // create the list consisting of the nodes after the
                // specified position
                result = new List<T>(newRoot);
            }
        }
        return result;
    }

    /*
     Appends the specified list to this one.
     */
    void append(List<T>* suffix) {
        // if suffix is empty we do nothing
        if (!suffix->isEmpty()) {
            if (this->isEmpty()) {
                this->startNode = suffix->startNode;
                this->endNode = suffix->endNode;
                this->numNodes = suffix->numNodes;
            }
            else {
                this->endNode->setNextNode(suffix->startNode);
                suffix->startNode->setPreviousNode(this->endNode);
                this->endNode = suffix->endNode;
                this->numNodes += suffix->getSize();
            }
        }
    }

    /*
     Prepends the specified list to this one.
     */
    void prepend(List<T>* prefix) {
        // if prefix is empty do nothing
        if (!prefix->isEmpty()) {
            if (this->isEmpty()) {
                this->startNode = prefix->startNode;
                this->endNode = prefix->endNode;
                this->numNodes = prefix->getSize();
            }
            else {
                this->startNode->setPreviousNode(prefix->endNode);
                prefix->endNode->setNextNode(this->startNode);
                this->startNode = prefix->startNode;
                this->numNodes += prefix->getSize();
            }
        }
    }

    /*
     Returns a string representation of this list.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "List at " << this << std::endl;
        if (this->startNode != nullptr) {
            sout << "List contains " << this->numNodes << " nodes" << std::endl;
            sout << "Start node at " << this->startNode << std::endl;
            sout << "End node at " << this->endNode << std::endl;
        }
        else {
            sout << "This list is empty" << std::endl;
        }
        return sout.str();
    }

};
