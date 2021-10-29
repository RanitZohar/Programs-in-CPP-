#pragma once
#include <iostream>
#include <string>
#include<map>
#include "Vertex.h";
using namespace std;

class Graph
{
private:
	map<string, Vertex*> myGraph;
	bool findVertex(string v);
public:
	Graph();
	~Graph();
	bool addv(string v);
	bool adde(string v1, string v2);
	bool delv(string v);
	bool dele(string v1, string v2);
	void printAll();
	void printNeighbors(string vertex);
	void printFollowers(string v);
	void printAllReached(string v);
	string strReached(Edge* e, string str);
};

