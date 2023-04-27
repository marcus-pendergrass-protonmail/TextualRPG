#pragma once

#include <cmath>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

#include "Edge.h"
#include "Graph.h"
#include "Point2D.h"
#include "TestResults.h"

class GraphTester {

public:

    /*
     Create an empty graph, test getNumVertices, getNumEdges, hasEdge,
     hasVertex, and isEmpty
     */
    static TestResults* test0() {

        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;

        // create an empty Graph
        Graph<int, std::string>* g = new Graph<int, std::string>();
        // test isEmpty
        pointsPossible++;
        if (g->isEmpty() == true) {
            pointsEarned++;
        }
        else {
            std::cout << "isEmpty returned false on an empty graph" << std::endl;
        }

        // test getNumVertices
        pointsPossible++;
        int numVerts = g->getNumVertices();
        if (numVerts == 0) {
            pointsEarned++;
        }
        else {
            sout << "getNumVertices returned " << numVerts << " on an empty graph" << std::endl;
        }

        // test getNumEdges
        pointsPossible++;
        int numEdges = g->getNumEdges();
        if (numEdges == 0) {
            pointsEarned++;
        }
        else {
            sout << "getNumEdges returned " << numEdges << " on an empty graph" << std::endl;
        }

        // test hasVertex
        pointsPossible++;
        // create a vertex not in g
        int i0 = 0;
        Vertex<int>* v0 = new Vertex<int>(&i0);
        if (g->hasVertex(v0) == false) {
            pointsEarned++;
        }
        else {
            sout << "hasVertex returned true on an empty graph" << std::endl;
        }

        // test hasEdge
        pointsPossible++;
        // create an edge not in g
        int i1 = 1;
        Vertex<int>* v1 = new Vertex<int>(&i1);
        if (g->hasEdge(v0, v1) == false) {
            pointsEarned++;
        }
        else {
            sout << "hasEdge returned true on an empty graph" << std::endl;
        }
        std::cout << "GraphTester::test0 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create an empty graph. Add several vertices to it, but no edges.
     After each vertex is added, test isEmpty and getNumVertices
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of vertices to add
        int numToAdd = 5;
        // create an empty graph
        Graph<Point2D, std::string>* g = new Graph<Point2D, std::string>();
        // create a vertex and add it to the graph
        for (int k = 0; k < numToAdd; k++) {
            Vertex<Point2D>* v = new Vertex<Point2D>(new Point2D(k, k));
            g->addVertex(v);
            // test isEmpty
            pointsPossible++;
            if (g->isEmpty() == false) {
                pointsEarned++;
            }
            else {
                sout << "isEmpty returned true on a non-empty graph" << std::endl;
            }
            // test getNumVertices
            pointsPossible++;
            int numVertices = g->getNumVertices();
            if (numVertices == k + 1) {
                pointsEarned++;
            }
            else {
                sout << "getNumVertices returned " << numVertices << ", should have been " << k + 1 << std::endl;
            }
        }
        std::cout << "GraphTester::test1 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create an empty graph, add vertices to it, then add edges between the
     existing vertices to create a cycle. Verify the connections in the cycle.
     Also verify getNumEdges, getInDegree, getOutDegree
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of vertices to add
        int numToAdd = 5;
        // create an empty graph
        Graph<Point2D, void>* g = new Graph<Point2D, void>();
        // add vertices
        for (int k = 0; k < numToAdd; k++) {
            Vertex<Point2D>* v = new Vertex<Point2D>(new Point2D(k, k));
            g->addVertex(v);
        }
        // add edges
        for (int k = 0; k < numToAdd; k++) {
            Vertex<Point2D>* fromVertex = g->getVertex(k);
            Vertex<Point2D>* toVertex = g->getVertex((k + 1) % numToAdd);
            g->addEdge(fromVertex, toVertex);
        }
        // test the connections using hasEdge
        for (int k = 0; k < numToAdd; k++) {
            Vertex<Point2D>* fromVertex = g->getVertex(k);
            Vertex<Point2D>* toVertex = g->getVertex((k + 1) % numToAdd);
            pointsPossible++;
            if (g->hasEdge(fromVertex, toVertex) == true) {
                pointsEarned++;
            }
            else {
                sout << "Connection from vertex " << k << " to vertex " << (k + 1) % numToAdd << " not present" << std::endl;
            }
        }
        // test getNumEdges
        pointsPossible++;
        int numEdges = g->getNumEdges();
        if (numEdges == numToAdd) {
            pointsEarned++;
        }
        else {
            sout << "getNumEdges returned " << numEdges << ", should have been " << numToAdd << std::endl;
        }
        // check in and out degrees of every vertex. All should be 1
        for (int k = 0; k < numToAdd; k++) {
            pointsPossible++;
            int inDegreeK = g->getVertex(k)->getInDegree();
            if (inDegreeK == 1) {
                pointsEarned++;
            }
            else {
                sout << "getInDegree returned " << inDegreeK << " on vertex " << k << ", should have been 1" << std::endl;
            }
            pointsPossible++;
            int outDegreeK = g->getVertex(k)->getOutDegree();
            if (outDegreeK == 1) {
                pointsEarned++;
            }
            else {
                sout << "getOutDegree returned " << outDegreeK << " on vertex " << k << ", should have been 1" << std::endl;
            }
        }
        std::cout << "GraphTester::test2 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create an empty graph, then add edges directly to the empty graph
     between the to create a cycle. Verify the connections in the cycle.
     Also verify getNumEdges, getInDegree, getOutDegree
     */
    static TestResults* test3() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of vertices to add
        int numToAdd = 5;
        // create an empty graph
        Graph<Point2D, void>* g = new Graph<Point2D, void>();
        // add edges
        Vertex<Point2D>* startNode = new Vertex<Point2D>(new Point2D(0, 0));
        Vertex<Point2D>* currFromNode = startNode;
        for (int k = 1; k < numToAdd; k++) {
            Vertex<Point2D>* currToNode = new Vertex<Point2D>(new Point2D(k, k));
            g->addEdge(currFromNode, currToNode);
            currFromNode = currToNode;
        }
        // complete the cycle
        g->addEdge(currFromNode, startNode);
        // test the connections using hasEdge
        for (int k = 0; k < numToAdd; k++) {
            Vertex<Point2D>* fromVertex = g->getVertex(k);
            Vertex<Point2D>* toVertex = g->getVertex((k + 1) % numToAdd);
            pointsPossible++;
            if (g->hasEdge(fromVertex, toVertex) == true) {
                pointsEarned++;
            }
            else {
                sout << "Connection from vertex " << k << " to vertex " << (k + 1) % numToAdd << " not present" << std::endl;
            }
        }
        // test getNumEdges
        pointsPossible++;
        int numEdges = g->getNumEdges();
        if (numEdges == numToAdd) {
            pointsEarned++;
        }
        else {
            sout << "getNumEdges returned " << numEdges << ", should have been " << numToAdd << std::endl;
        }
        // check in and out degrees of every vertex. All should be 1
        for (int k = 0; k < numToAdd; k++) {
            pointsPossible++;
            int inDegreeK = g->getVertex(k)->getInDegree();
            if (inDegreeK == 1) {
                pointsEarned++;
            }
            else {
                sout << "getInDegree returned " << inDegreeK << " on vertex " << k << ", should have been 1" << std::endl;
            }
            pointsPossible++;
            int outDegreeK = g->getVertex(k)->getOutDegree();
            if (outDegreeK == 1) {
                pointsEarned++;
            }
            else {
                sout << "getOutDegree returned " << outDegreeK << " on vertex " << k << ", should have been 1" << std::endl;
            }
        }
        std::cout << "GraphTester::test3 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a complete graph on n vertices. Test getInDegree, getOUtDgree,
     getIncomingVertices and getOutgoingVertices on every vertex.
     */
    static TestResults* test4() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of vertices
        int numVertices = 5;
        // create an empty graph
        Graph<Point2D, void>* g = new Graph<Point2D, void>();
        // add vertices
        for (int k = 0; k < numVertices; k++) {
            Vertex<Point2D>* v = new Vertex<Point2D>(new Point2D(k, k));
            g->addVertex(v);
        }
        // add edges (but no loops)
        for (int k = 0; k < numVertices; k++) {
            Vertex<Point2D>* fromVertex = g->getVertex(k);
            for (int j = 0; j < numVertices; j++) {
                if (k != j) {
                    Vertex<Point2D>* toVertex = g->getVertex(j);
                    g->addEdge(fromVertex, toVertex);
                }
            }
        }
        // test getInDegree
        for (int k = 0; k < numVertices; k++) {
            pointsPossible++;
            Vertex<Point2D>* v = g->getVertex(k);
            int inDegree = v->getInDegree();
            if (inDegree == numVertices - 1) {
                pointsEarned++;
            }
            else {
                sout << "getInDegree returned " << inDegree << ", should have been " << numVertices - 1 << std::endl;
            }
        }
        // test getOutDegree
        for (int k = 0; k < numVertices; k++) {
            pointsPossible++;
            Vertex<Point2D>* v = g->getVertex(k);
            int outDegree = v->getOutDegree();
            if (outDegree == numVertices - 1) {
                pointsEarned++;
            }
            else {
                sout << "getOutDegree returned " << outDegree << ", should have been " << numVertices - 1 << std::endl;
            }
        }
        // test getIncomingVertices
        for (int k = 0; k < numVertices; k++) {
            List<int>* incomingNdcsK = new List<int>();
            Vertex<Point2D>* v = g->getVertex(k);
            std::cout << "Vertex " << k << " incoming: ";
            List<Vertex<Point2D>>* incoming = g->getIncomingVertices(v);
            int sum = 0;
            for (int j = 0; j < incoming->getSize(); j++) {
                Vertex<Point2D>* inVertexJ = incoming->peek(j);
                int incomingNdxJ = inVertexJ->getData()->x;
                sum += incomingNdxJ;
                incomingNdcsK->insertAtEnd(&incomingNdxJ);
                std::cout << inVertexJ->getData()->x << " ";
            }
            // list of incoming vertices should sum to
            // numVertices*(numVertices-1)/2 - k and should not contain k
            int ref = numVertices * (numVertices - 1) / 2 - k;
            pointsPossible++;
            if (sum == ref && (incomingNdcsK->getIndex(&k) < 0)) {
                pointsEarned++;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        // test getOutgoingVertices
        for (int k = 0; k < numVertices; k++) {
            List<int>* outgoingNdcsK = new List<int>();
            Vertex<Point2D>* v = g->getVertex(k);
            std::cout << "Vertex " << k << " outgoing: ";
            List<Vertex<Point2D>>* outgoing = g->getOutgoingVertices(v);
            int sum = 0;
            for (int j = 0; j < outgoing->getSize(); j++) {
                Vertex<Point2D>* outVertexJ = outgoing->peek(j);
                int outgoingNdxJ = outVertexJ->getData()->x;
                sum += outgoingNdxJ;
                outgoingNdcsK->insertAtEnd(&outgoingNdxJ);
                std::cout << outVertexJ->getData()->x << " ";
            }
            // list of outgoing vertices should sum to
            // numVertices*(numVertices-1)/2 - k and should not contain k
            int ref = numVertices * (numVertices - 1) / 2 - k;
            pointsPossible++;
            if (sum == ref && (outgoingNdcsK->getIndex(&k) < 0)) {
                pointsEarned++;
            }
            std::cout << std::endl;
        }
        std::cout << "GraphTester::test4 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create n vertices and store them in an array. Then call addEdge
     with each distinct pair to create a complete graph on n vertices.
     Check for correct number of vertices and edges. Check for correct
     in and out degrees. Also check the connections for each vertex.
     */
    static TestResults* test5() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;

        // number of nodes of the graph
        int numNodes = 6;

        // build the complete graph
        Graph<int, int>* g = new Graph<int, int>();
        // create vertices first
        Vertex<int>** vertices = new Vertex<int>*[numNodes];
        for (int k = 0; k < numNodes; k++) {
            vertices[k] = new Vertex<int>(new int(k));
        }
        // add them to the graph and create the edges simulataneously
        for (int k = 0; k < numNodes; k++) {
            for (int j = 0; j < numNodes; j++) {
                if (k != j) {
                    g->addEdge(vertices[k], vertices[j]);
                }
            }
        }
        // check that number of vertices are correct
        pointsPossible++;
        int numVerts = g->getNumVertices();
        if (numVerts == numNodes) {
            pointsEarned++;
        }
        else {
            sout << "getNumVertices returned " << numVerts << ", should have been " << numNodes << std::endl;
        }
        // check that number of edge are correct
        pointsPossible++;
        int numEdges = g->getNumEdges();
        int ref = numNodes * (numNodes - 1);
        if (numEdges == ref) {
            pointsEarned++;
        }
        else {
            sout << "getNumVertices returned " << numEdges << ", should have been " << ref << std::endl;
        }
        // test getInDegree
        for (int k = 0; k < numVerts; k++) {
            pointsPossible++;
            Vertex<int>* v = g->getVertex(k);
            int inDegree = v->getInDegree();
            if (inDegree == numVerts - 1) {
                pointsEarned++;
            }
            else {
                sout << "getInDegree returned " << inDegree << ", should have been " << numVerts << std::endl;
            }
        }
        // test getOutDegree
        for (int k = 0; k < numVerts; k++) {
            pointsPossible++;
            Vertex<int>* v = g->getVertex(k);
            int outDegree = v->getOutDegree();
            if (outDegree == numVerts - 1) {
                pointsEarned++;
            }
            else {
                sout << "getOutDegree returned " << outDegree << ", should have been " << numVerts - 1 << std::endl;
            }
        }
        // test getIncomingVertices
        for (int k = 0; k < numVerts; k++) {
            List<int>* incomingNdcsK = new List<int>();
            Vertex<int>* v = g->getVertex(k);
            std::cout << "Vertex " << k << " incoming: ";
            List<Vertex<int>>* incoming = g->getIncomingVertices(v);
            int sum = 0;
            for (int j = 0; j < incoming->getSize(); j++) {
                Vertex<int>* inVertexJ = incoming->peek(j);
                int* incomingNdxJ = inVertexJ->getData();
                sum += *incomingNdxJ;
                incomingNdcsK->insertAtEnd(incomingNdxJ);
                std::cout << *(inVertexJ->getData()) << " ";
            }
            // list of incoming vertices should sum to
            // numVertices*(numVertices-1)/2 - k and should not contain k
            int ref = numVerts * (numVerts - 1) / 2 - k;
            pointsPossible++;
            if (sum == ref && (incomingNdcsK->getIndex(&k) < 0)) {
                pointsEarned++;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        // test getOutgoingVertices
        for (int k = 0; k < numVerts; k++) {
            List<int>* outgoingNdcsK = new List<int>();
            Vertex<int>* v = g->getVertex(k);
            std::cout << "Vertex " << k << " outgoing: ";
            List<Vertex<int>>* outgoing = g->getOutgoingVertices(v);
            int sum = 0;
            for (int j = 0; j < outgoing->getSize(); j++) {
                Vertex<int>* outVertexJ = outgoing->peek(j);
                int* outgoingNdxJ = outVertexJ->getData();
                sum += *outgoingNdxJ;
                outgoingNdcsK->insertAtEnd(outgoingNdxJ);
                std::cout << *(outVertexJ->getData()) << " ";
            }
            // list of outgoing vertices should sum to
            // numVertices*(numVertices-1)/2 - k and should not contain k
            int ref = numVerts * (numVerts - 1) / 2 - k;
            pointsPossible++;
            if (sum == ref && (outgoingNdcsK->getIndex(&k) < 0)) {
                pointsEarned++;
            }
            std::cout << std::endl;
        }
        std::cout << "GraphTester::test5 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a complete graph on n vertices (no loops). Run a symmetric random
     walk on the graph, and check to see that the number of visits to each
     vertex is within 3 sigma of its expected value.
     */
    static TestResults* test6() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;

        // number of nodes
        int numNodes = 10;
        // number of steps for the walk
        int numSteps = 1000000;

        // build the complete graph
        Graph<int, int>* g = new Graph<int, int>();
        // create vertices first
        Vertex<int>** vertices = new Vertex<int>*[numNodes];
        for (int k = 0; k < numNodes; k++) {
            vertices[k] = new Vertex<int>(new int(k));
        }
        // add them to the graph and create the edges simulataneously
        for (int k = 0; k < numNodes; k++) {
            for (int j = 0; j < numNodes; j++) {
                if (k != j) {
                    g->addEdge(vertices[k], vertices[j]);
                }
            }
        }
        // perform a random walk on the graph
        // First, have to build a random number generator.
        // for the seed of the random number generator.
        std::random_device r;
        // this creates a random number generator with the
        // seed set randomly
        std::default_random_engine rng(r());
        // produce random integers between 0 and numNodes - 2
        std::uniform_int_distribution<int> uniform_dist(0, numNodes - 2);
        // start vertex for the random walk
        int startVertexNdx = uniform_dist(rng);
        Vertex<int>* startVertex = g->getVertex(startVertexNdx);
        // walk and collect stats
        int* hist = new int[numNodes];
        for (int k = 0; k < numNodes; k++) {
            hist[k] = 0;
        }
        hist[startVertexNdx]++;
        int currVertexNdx = startVertexNdx;
        Vertex<int>* currVertex = startVertex;
        for (int k = 1; k < numSteps; k++) {
            List<Vertex<int>>* outgoingVerts = g->getOutgoingVertices(currVertex);
            int randomNdx = uniform_dist(rng);
            currVertex = outgoingVerts->peek(randomNdx);
            currVertexNdx = g->getVertexIndex(currVertex);
            hist[currVertexNdx]++;
        }
        // display the histogram
        std::cout << std::endl << "Histogram: number of times each vertex is visited:" << std::endl;
        for (int k = 0; k < numNodes; k++) {
            std::cout << k << ":" << *(vertices[k]->getData()) << ": " << hist[k] << std::endl;
        }
        std::cout << std::endl;
        // check that the observed proportions are within 3 sigma of their expected values
        double p = 1.0 / numNodes;
        double mean = p;
        double sigma = sqrt(p * (1 - p) / numSteps);
        std::cout << "Checking that observed proportions are within three sigma of their expected values" << std::endl;
        for (int k = 0; k < numNodes; k++) {
            pointsPossible++;
            double observedProportionK = 1.0 * hist[k] / numSteps;
            if (abs(observedProportionK - mean) < 3 * sigma) {
                pointsEarned++;
            }
            else {
                sout << "failure on vertex " << k << std::endl;
            }
        }
        std::cout << "GraphTester::test6 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a graph consisting of a single vertex with an edge to itself.
     Check degrees, indices, number of edges and vertices, isEmpty.
     */
    static TestResults* test7() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create a graph consisting of a single loop
        Graph<int, int>* g = new Graph<int, int>();
        Vertex<int>* v = new Vertex<int>(new int(0));
        g->addEdge(v, v);
        // test isEmpty
        pointsPossible++;
        if (g->isEmpty() == false) {
            pointsEarned++;
        }
        else {
            sout << "isEmpty returned true on a non-empty graph" << std::endl;
        }
        // test getNumVertices
        pointsPossible++;
        int numVerts = g->getNumVertices();
        if (numVerts == 1) {
            pointsEarned++;
        }
        else {
            sout << "getNumVertices returned " << numVerts << ", should have been 1" << std::endl;
        }
        // test getNumEdges
        pointsPossible++;
        int numEdges = g->getNumEdges();
        if (numEdges == 1) {
            pointsEarned++;
        }
        else {
            sout << "getNumEdges returned " << numEdges << ", should have been 1" << std::endl;
        }
        // test getVertex
        pointsPossible++;
        Vertex<int>* v0 = g->getVertex(0);
        if (v0 == v) {
            pointsEarned++;
        }
        else {
            sout << "getVertex returned an incorrect value" << std::endl;
        }
        // test getEdges
        pointsPossible++;
        List<Edge<int, int>>* theEdges = g->getEdges();
        if (theEdges->peek(0)->getInitialVertex() == v && theEdges->peek(0)->getTerminalVertex() == v) {
            pointsEarned++;
        }
        else {
            sout << "getEdges returned an incorrect value" << std::endl;
        }
        // test getIncomingVertices
        pointsPossible++;
        List<Vertex<int>>* incoming = g->getIncomingVertices(v);
        int numIncoming = incoming->getSize();
        if (numIncoming == 1) {
            pointsEarned++;
        }
        else {
            sout << "getIncomingVertices returned a list of size " << numIncoming << ", should have been 1" << std::endl;
        }
        pointsPossible++;
        Vertex<int>* v1 = incoming->peek(0);
        if (v1 == v) {
            pointsEarned++;
        }
        else {
            sout << "getIncomingVertices returned a list not containing v" << std::endl;
        }
        // test getOutgoingVertices
        pointsPossible++;
        List<Vertex<int>>* outgoing = g->getOutgoingVertices(v);
        int numOutgoing = outgoing->getSize();
        if (numOutgoing == 1) {
            pointsEarned++;
        }
        else {
            sout << "getOutgoingVertices returned a list of size " << numOutgoing << ", should have been 1" << std::endl;
        }
        pointsPossible++;
        Vertex<int>* v2 = outgoing->peek(0);
        if (v2 == v) {
            pointsEarned++;
        }
        else {
            sout << "getOutgoingVertices returned a list not containing v" << std::endl;
        }
        std::cout << "GraphTester::test7 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }


    /*
     Create a complete graph on n vertices (with loops). Run a symmetric random
     walk on the graph, and check to see that the number of visits to each
     vertex is within 3 sigma of its expected value.
     */
    static TestResults* test8() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;

        // number of nodes
        int numNodes = 10;
        // number of steps for the walk
        int numSteps = 1000000;

        // build the complete graph
        Graph<int, int>* g = new Graph<int, int>();
        // create vertices first
        Vertex<int>** vertices = new Vertex<int>*[numNodes];
        for (int k = 0; k < numNodes; k++) {
            vertices[k] = new Vertex<int>(new int(k));
        }
        // add them to the graph and create the edges simulataneously
        for (int k = 0; k < numNodes; k++) {
            for (int j = 0; j < numNodes; j++) {
                g->addEdge(vertices[k], vertices[j]);
            }
        }
        // perform a random walk on the graph
        // First, have to build a random number generator.
        // for the seed of the random number generator.
        std::random_device r;
        // this creates a random number generator with the
        // seed set randomly
        std::default_random_engine rng(r());
        // produce random integers between 0 and numNodes - 2
        std::uniform_int_distribution<int> uniform_dist(0, numNodes - 1);
        // start vertex for the random walk
        int startVertexNdx = uniform_dist(rng);
        Vertex<int>* startVertex = g->getVertex(startVertexNdx);
        // walk and collect stats
        int* hist = new int[numNodes];
        for (int k = 0; k < numNodes; k++) {
            hist[k] = 0;
        }
        hist[startVertexNdx]++;
        int currVertexNdx = startVertexNdx;
        Vertex<int>* currVertex = startVertex;
        for (int k = 1; k < numSteps; k++) {
            List<Vertex<int>>* outgoingVerts = g->getOutgoingVertices(currVertex);
            int randomNdx = uniform_dist(rng);
            currVertex = outgoingVerts->peek(randomNdx);
            currVertexNdx = g->getVertexIndex(currVertex);
            hist[currVertexNdx]++;
        }
        // display the histogram
        std::cout << std::endl << "Histogram: number of times each vertex is visited:" << std::endl;
        for (int k = 0; k < numNodes; k++) {
            std::cout << k << ":" << *(vertices[k]->getData()) << ": " << hist[k] << std::endl;
        }
        std::cout << std::endl;
        // check that the observed proportions are within 3 sigma of their expected values
        double p = 1.0 / numNodes;
        double mean = p;
        double sigma = sqrt(p * (1 - p) / numSteps);
        std::cout << "Checking that observed proportions are within three sigma of their expected values" << std::endl;
        for (int k = 0; k < numNodes; k++) {
            pointsPossible++;
            double observedProportionK = 1.0 * hist[k] / numSteps;
            if (abs(observedProportionK - mean) < 3 * sigma) {
                pointsEarned++;
            }
            else {
                sout << "failure on vertex " << k << std::endl;
            }
        }
        std::cout << "GraphTester::test8 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a story graph, and check various things.
     */
    static TestResults* test9() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create the graph
        Graph<std::string, int>* g = new Graph<std::string, int>();
        // create the vertices
        Vertex<std::string>* enterCave = new Vertex<std::string>(new std::string("Enter Cave"));
        Vertex<std::string>* encounterDragon = new Vertex<std::string>(new std::string("Encounter Dragon"));
        Vertex<std::string>* dragonNotHome = new Vertex<std::string>(new std::string("Dragon Not Home"));
        Vertex<std::string>* dragonWins = new Vertex<std::string>(new std::string("Dragon Wins"));
        Vertex<std::string>* dragonLoses = new Vertex<std::string>(new std::string("Dragon Loses"));
        Vertex<std::string>* stealDragonLoot = new Vertex<std::string>(new std::string("Steal Dragon Loot"));
        Vertex<std::string>* leaveCaveNoTreasure = new Vertex<std::string>(new std::string("Leave Cave No Treasure"));
        Vertex<std::string>* leaveCaveWithTreasure = new Vertex<std::string>(new std::string("Leave Cave With Treasure"));
        // add them to the graph. (Indices should correspond to the order in
        // which vertices are added.)
        g->addVertex(enterCave);
        g->addVertex(encounterDragon);
        g->addVertex(dragonNotHome);
        g->addVertex(dragonWins);
        g->addVertex(dragonLoses);
        g->addVertex(stealDragonLoot);
        g->addVertex(leaveCaveNoTreasure);
        g->addVertex(leaveCaveWithTreasure);
        // test isEmpty
        pointsPossible++;
        if (g->isEmpty() == false) {
            pointsEarned++;
        }
        else {
            sout << "isEmpty returned true on a non-empty graph" << std::endl;
        }
        // hook them up
        g->addEdge(enterCave, encounterDragon);
        g->setEdgeWeight(0, enterCave, encounterDragon);
        g->addEdge(enterCave, dragonNotHome);
        g->setEdgeWeight(1, enterCave, dragonNotHome);
        g->addEdge(encounterDragon, dragonWins);
        g->setEdgeWeight(2, encounterDragon, dragonWins);
        g->addEdge(encounterDragon, dragonLoses);
        g->setEdgeWeight(3, encounterDragon, dragonLoses);
        g->addEdge(dragonNotHome, stealDragonLoot);
        g->setEdgeWeight(4, dragonNotHome, stealDragonLoot);
        g->addEdge(dragonLoses, stealDragonLoot);
        g->setEdgeWeight(5, dragonLoses, stealDragonLoot);
        g->addEdge(dragonWins, leaveCaveNoTreasure);
        g->setEdgeWeight(6, dragonWins, leaveCaveNoTreasure);
        g->addEdge(stealDragonLoot, leaveCaveWithTreasure);
        g->setEdgeWeight(7, stealDragonLoot, leaveCaveWithTreasure);
        // test getNumVertices
        pointsPossible++;
        int numVerts = g->getNumVertices();
        if (numVerts == 8) {
            pointsEarned++;
        }
        else {
            sout << "getNumVertices returned " << numVerts << ", should have been 8" << std::endl;
        }
        // test getNumEdges
        pointsPossible++;
        int numEdges = g->getNumEdges();
        if (numEdges == 8) {
            pointsEarned++;
        }
        else {
            sout << "getNumEdges returned " << numEdges << ", should have been 8" << std::endl;
        }
        // check that indices are assigned to vertices correctly
        List<std::string>* vertexLabels = new List<std::string>();
        vertexLabels->insertAtEnd(new std::string("Enter Cave"));
        vertexLabels->insertAtEnd(new std::string("Encounter Dragon"));
        vertexLabels->insertAtEnd(new std::string("Dragon Not Home"));
        vertexLabels->insertAtEnd(new std::string("Dragon Wins"));
        vertexLabels->insertAtEnd(new std::string("Dragon Loses"));
        vertexLabels->insertAtEnd(new std::string("Steal Dragon Loot"));
        vertexLabels->insertAtEnd(new std::string("Leave Cave No Treasure"));
        vertexLabels->insertAtEnd(new std::string("Leave Cave With Treasure"));
        for (int k = 0; k < 8; k++) {
            pointsPossible++;
            std::string* vertKLabel = g->getVertex(k)->getData();
            if (*vertKLabel == *vertexLabels->peek(k)) {
                pointsEarned++;
            }
            else {
                sout << "vertex index " << k << " stored in incorrect order" << std::endl;
            }
        }
        // check that indices are assigned to edges correctly
        List<Edge<std::string, int>>* edges = g->getEdges();
        for (int k = 0; k < 8; k++) {
            pointsPossible++;
            Edge<std::string, int>* edgeK = edges->peek(k);
            if (edgeK->getWeight() == k) {
                pointsEarned++;
            }
            else {
                sout << "edge index " << k << " stored in incorrect order" << std::endl;
            }
        }
        // check all incoming connections for each vertex
        pointsPossible++;
        List<Vertex<std::string>>* incoming0 = g->getIncomingVertices(enterCave);
        if (incoming0->isEmpty()) {
            pointsEarned++;
        }
        else {
            sout << "enterCave should have no incoming vertices" << std::endl;
        }
        pointsPossible++;
        List<Vertex<std::string>>* incoming1 = g->getIncomingVertices(encounterDragon);
        if (incoming1->getSize() == 1 && incoming1->peek(0) == enterCave) {
            pointsEarned++;
        }
        else {
            sout << "encounterDragon should be preceeded by enterCave" << std::endl;
        }
        pointsPossible++;
        List<Vertex<std::string>>* incoming2 = g->getIncomingVertices(dragonNotHome);
        if (incoming2->getSize() == 1 && incoming2->peek(0) == enterCave) {
            pointsEarned++;
        }
        else {
            sout << "dragonNotHome shoiuld be preceeded by enterCave" << std::endl;
        }
        pointsPossible++;
        List<Vertex<std::string>>* incoming3 = g->getIncomingVertices(dragonWins);
        if (incoming3->getSize() == 1 && incoming3->peek(0) == encounterDragon) {
            pointsEarned++;
        }
        else {
            sout << "dragonWins should be preceeded by encounterDragon" << std::endl;
        }
        pointsPossible++;
        List<Vertex<std::string>>* incoming4 = g->getIncomingVertices(dragonLoses);
        if (incoming4->getSize() == 1 && incoming4->peek(0) == encounterDragon) {
            pointsEarned++;
        }
        else {
            sout << "dragonLoses should be preceeded by encounterDragon" << std::endl;
        }
        pointsPossible++;
        List<Vertex<std::string>>* incoming5 = g->getIncomingVertices(stealDragonLoot);
        bool sizeIs2 = incoming5->getSize();
        bool b1 = incoming5->peek(0) == dragonNotHome;
        bool b2 = incoming5->peek(1) == dragonLoses;
        if (sizeIs2 && b1 && b2) {
            pointsEarned++;
        }
        else {
            sout << "getIncomingVertices returned incorrect result on stealDragonLoot" << std::endl;
        }
        pointsPossible++;
        List<Vertex<std::string>>* incoming6 = g->getIncomingVertices(leaveCaveNoTreasure);
        if (incoming6->getSize() == 1 && incoming6->peek(0) == dragonWins) {
            pointsEarned++;
        }
        else {
            sout << "leaveCaveNoTreasure should be predeeded by dragonWins" << std::endl;
        }
        pointsPossible++;
        List<Vertex<std::string>>* incoming7 = g->getIncomingVertices(leaveCaveWithTreasure);
        if (incoming7->getSize() == 1 && incoming7->peek(0) == stealDragonLoot) {
            pointsEarned++;
        }
        else {
            sout << "leaveCaveWithTreasure should be preceeded by stealDragonLoot" << std::endl;
        }

        // check all outgoing connections for each vertex
        pointsPossible++;
        List<Vertex<std::string>>* outgoing0 = g->getOutgoingVertices(enterCave);
        if (outgoing0->getSize() == 2 && outgoing0->peek(0) == encounterDragon && outgoing0->peek(1) == dragonNotHome) {
            pointsEarned++;
        }
        else {
            sout << "enterCave should be followed by encounterDragon and dragonNotHome" << std::endl;
        }

        pointsPossible++;
        List<Vertex<std::string>>* outgoing1 = g->getOutgoingVertices(encounterDragon);
        if (outgoing1->getSize() == 2 && outgoing1->peek(0) == dragonWins && outgoing1->peek(1) == dragonLoses) {
            pointsEarned++;
        }
        else {
            sout << "encounterDragon should be followed by dragonWins and dragonLoses" << std::endl;
        }

        pointsPossible++;
        List<Vertex<std::string>>* outgoing2 = g->getOutgoingVertices(dragonNotHome);
        if (outgoing2->getSize() == 1 && outgoing2->peek(0) == stealDragonLoot) {
            pointsEarned++;
        }
        else {
            sout << "dragonNotHome should be followed by stealDragonLoot" << std::endl;
        }

        pointsPossible++;
        List<Vertex<std::string>>* outgoing3 = g->getOutgoingVertices(dragonWins);
        if (outgoing3->getSize() == 1 && outgoing3->peek(0) == leaveCaveNoTreasure) {
            pointsEarned++;
        }
        else {
            sout << "dragonWins should be followed by leaveCaveNoTreasure" << std::endl;
        }

        pointsPossible++;
        List<Vertex<std::string>>* outgoing4 = g->getOutgoingVertices(dragonLoses);
        if (outgoing4->getSize() == 1 && outgoing4->peek(0) == stealDragonLoot) {
            pointsEarned++;
        }
        else {
            sout << "dragonLoses should be followed by stealDragonLoot" << std::endl;
        }

        pointsPossible++;
        List<Vertex<std::string>>* outgoing5 = g->getOutgoingVertices(stealDragonLoot);
        if (outgoing5->getSize() == 1 && outgoing5->peek(0) == leaveCaveWithTreasure) {
            pointsEarned++;
        }
        else {
            sout << "stealDragonLoot should be followed by leaveCaveWithTreasure" << std::endl;
        }

        pointsPossible++;
        List<Vertex<std::string>>* outgoing6 = g->getOutgoingVertices(leaveCaveNoTreasure);
        if (outgoing6->isEmpty()) {
            pointsEarned++;
        }
        else {
            sout << "leaveCaveNoTreasure should have no outgoing vertices" << std::endl;
        }

        pointsPossible++;
        List<Vertex<std::string>>* outgoing7 = g->getOutgoingVertices(leaveCaveWithTreasure);
        if (outgoing7->isEmpty()) {
            pointsEarned++;
        }
        else {
            sout << "leaveCaveWithTreasure should have no outgoing vertices" << std::endl;
        }
        std::cout << "GraphTester::test9 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test storeInVertex(T*,int) and getVertexData(int)
     */
    static TestResults* test10() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create the graph
        Graph<std::string, int>* g = new Graph<std::string, int>();
        // create the vertices
        Vertex<std::string>* enterCave = new Vertex<std::string>();
        Vertex<std::string>* encounterDragon = new Vertex<std::string>();
        Vertex<std::string>* dragonNotHome = new Vertex<std::string>();
        Vertex<std::string>* dragonWins = new Vertex<std::string>();
        Vertex<std::string>* dragonLoses = new Vertex<std::string>();
        Vertex<std::string>* stealDragonLoot = new Vertex<std::string>();
        Vertex<std::string>* leaveCaveNoTreasure = new Vertex<std::string>();
        Vertex<std::string>* leaveCaveWithTreasure = new Vertex<std::string>();
        // add them to the graph. (Indices should correspond to the order in
        // which vertices are added.)
        g->addVertex(enterCave);
        g->addVertex(encounterDragon);
        g->addVertex(dragonNotHome);
        g->addVertex(dragonWins);
        g->addVertex(dragonLoses);
        g->addVertex(stealDragonLoot);
        g->addVertex(leaveCaveNoTreasure);
        g->addVertex(leaveCaveWithTreasure);
        // hook the vertices up
        g->addEdge(enterCave, encounterDragon);
        g->setEdgeWeight(0, enterCave, encounterDragon);
        g->addEdge(enterCave, dragonNotHome);
        g->setEdgeWeight(1, enterCave, dragonNotHome);
        g->addEdge(encounterDragon, dragonWins);
        g->setEdgeWeight(2, encounterDragon, dragonWins);
        g->addEdge(encounterDragon, dragonLoses);
        g->setEdgeWeight(3, encounterDragon, dragonLoses);
        g->addEdge(dragonNotHome, stealDragonLoot);
        g->setEdgeWeight(4, dragonNotHome, stealDragonLoot);
        g->addEdge(dragonLoses, stealDragonLoot);
        g->setEdgeWeight(5, dragonLoses, stealDragonLoot);
        g->addEdge(dragonWins, leaveCaveNoTreasure);
        g->setEdgeWeight(6, dragonWins, leaveCaveNoTreasure);
        g->addEdge(stealDragonLoot, leaveCaveWithTreasure);
        g->setEdgeWeight(7, stealDragonLoot, leaveCaveWithTreasure);
        // create data
        std::string** labels = new std::string * [8];
        labels[0] = new std::string("Enter Cave");
        labels[1] = new std::string("Encounter Dragon");
        labels[2] = new std::string("Dragon Not Home");
        labels[3] = new std::string("Dragon Wins");
        labels[4] = new std::string("Dragon Loses");
        labels[5] = new std::string("Steal Dragon Loot");
        labels[6] = new std::string("Leave Cave No Treasure");
        labels[7] = new std::string("Leave Cave With Treasure");
        // store data in the vertices
        for (int k = 0; k < 8; k++) {
            g->storeInVertex(labels[k], k);
        }
        // retrieve data and check
        for (int k = 0; k < 8; k++) {
            pointsPossible++;
            std::string* labelK = g->getVertexData(k);
            if (labelK == labels[k]) {
                pointsEarned++;
            }
            else {
                sout << "getVertexData(int) returned an incorrect value" << std::endl;
            }
        }
        std::cout << "GraphTester::test9 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test storeInEdge(U*, int) and getEdgeData(int)
     */
    static TestResults* test11() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create the graph
        Graph<std::string, int>* g = new Graph<std::string, int>();
        // create the vertices
        Vertex<std::string>* enterCave = new Vertex<std::string>();
        Vertex<std::string>* encounterDragon = new Vertex<std::string>();
        Vertex<std::string>* dragonNotHome = new Vertex<std::string>();
        Vertex<std::string>* dragonWins = new Vertex<std::string>();
        Vertex<std::string>* dragonLoses = new Vertex<std::string>();
        Vertex<std::string>* stealDragonLoot = new Vertex<std::string>();
        Vertex<std::string>* leaveCaveNoTreasure = new Vertex<std::string>();
        Vertex<std::string>* leaveCaveWithTreasure = new Vertex<std::string>();
        // add them to the graph. (Indices should correspond to the order in
        // which vertices are added.)
        g->addVertex(enterCave);
        g->addVertex(encounterDragon);
        g->addVertex(dragonNotHome);
        g->addVertex(dragonWins);
        g->addVertex(dragonLoses);
        g->addVertex(stealDragonLoot);
        g->addVertex(leaveCaveNoTreasure);
        g->addVertex(leaveCaveWithTreasure);
        // hook the vertices up
        g->addEdge(enterCave, encounterDragon);
        g->setEdgeWeight(0, enterCave, encounterDragon);
        g->addEdge(enterCave, dragonNotHome);
        g->setEdgeWeight(1, enterCave, dragonNotHome);
        g->addEdge(encounterDragon, dragonWins);
        g->setEdgeWeight(2, encounterDragon, dragonWins);
        g->addEdge(encounterDragon, dragonLoses);
        g->setEdgeWeight(3, encounterDragon, dragonLoses);
        g->addEdge(dragonNotHome, stealDragonLoot);
        g->setEdgeWeight(4, dragonNotHome, stealDragonLoot);
        g->addEdge(dragonLoses, stealDragonLoot);
        g->setEdgeWeight(5, dragonLoses, stealDragonLoot);
        g->addEdge(dragonWins, leaveCaveNoTreasure);
        g->setEdgeWeight(6, dragonWins, leaveCaveNoTreasure);
        g->addEdge(stealDragonLoot, leaveCaveWithTreasure);
        g->setEdgeWeight(7, stealDragonLoot, leaveCaveWithTreasure);
        // store int data in the edge
        for (int k = 0; k < 8; k++) {
            int* x = new int(k);
            g->storeInEdge(x, k);
        }
        // retrieve data and check
        for (int k = 0; k < 8; k++) {
            pointsPossible++;
            int* x = g->getEdgeData(k);
            if (*x == k) {
                pointsEarned++;
            }
            else {
                sout << "getEdgeData(int) returned an incorrect value" << std::endl;
            }

        }
        std::cout << "GraphTester::test11 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test storeInVertex(T*, Vertex<T>*) and getVertexData(Vertex<T>*)
     */
    static TestResults* test12() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create a complete graph on 10 vertices
        Graph<Point2D, std::string>* g = new Graph<Point2D, std::string>();
        Vertex<Point2D>** vertices = new Vertex<Point2D>*[10];
        for (int k = 0; k < 10; k++) {
            Vertex<Point2D>* vertexK = new Vertex<Point2D>();
            vertices[k] = vertexK;
            g->addVertex(vertexK);
        }
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 10; j++) {
                g->addEdge(vertices[k], vertices[j]);
            }
        }
        // store data in each vertex
        for (int k = 0; k < 10; k++) {
            g->storeInVertex(new Point2D(k, k), vertices[k]);
        }
        // retrieve data from each vertex and check
        for (int k = 0; k < 10; k++) {
            pointsPossible++;
            int pointKValue = g->getVertexData(vertices[k])->x;
            if (pointKValue == k) {
                pointsEarned++;
            }
            else {
                sout << "getVertexData returned an incorrect value" << std::endl;
            }
        }
        std::cout << "GraphTester::test12 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     test storeInEdge(U*, Vertex<T>*, Vertex<T>*) and getEdgeData(Vertex<T>*, Vertex<T>*)
     */
    static TestResults* test13() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create a complete graph on 5 vertices
        Graph<int, Point2D>* g = new Graph<int, Point2D>();
        Vertex<int>** vertices = new Vertex<int>*[5];
        for (int k = 0; k < 5; k++) {
            Vertex<int>* vertexK = new Vertex<int>();
            vertices[k] = vertexK;
            g->addVertex(vertexK);
        }
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                g->addEdge(vertices[k], vertices[j]);
            }
        }
        // store data in each edge
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                g->storeInEdge(new Point2D(k, j), vertices[k], vertices[j]);
            }
        }
        // retrieve data from each edge and check
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                pointsPossible++;
                Point2D* pointKJ = g->getEdgeData(vertices[k], vertices[j]);
                if (pointKJ->x == k && pointKJ->y == j) {
                    pointsEarned++;
                }
                else {
                    sout << "getEdgeData returned an incorrect value" << std::endl;
                }
            }
        }
        std::cout << "GraphTester::test13 results:" << std::endl;
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    static TestResults* testX() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;

        std::cout << "GraphTester::testX results:" << std::endl;
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

        r = test3();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test4();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test5();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test6();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test7();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test8();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test9();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test10();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test11();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test12();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        r = test13();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;

        return new TestResults(totalPossible, totalEarned, "");
    }

};

