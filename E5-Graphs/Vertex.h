#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Edge.h"
using namespace std;
enum Color { white, black, gray };
class Edge;

class Vertex
{
private:
	string key;
	list<Edge*> EdgeList;

public:
	Vertex(string key);
	~Vertex();
	bool destinationExists(Vertex* v);
	bool destinationExists(string v);
	void addEdge(Edge* e);
	void delEdge(string v2);
	string toString();
	string getKey();
	list<Edge*> getEdgeList();
	int numOfNeighbours();
	string findAllReached();
	

};

