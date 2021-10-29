#pragma once
#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

bool Graph::addv(string v)//Add a vertex to the Directed graph
{
	for (map<string, Vertex*>::iterator itr = myGraph.begin(), itr_end = myGraph.end(); itr != itr_end; ++itr) {
		if ((*itr).first == v)
			return false;
	}
	myGraph[v] = new Vertex(v);
	return true;
}
bool Graph::delv(string v)//Delete a vertex from the Directed graph
{
	if (!findVertex(v))
		return false;
	myGraph.erase(v);
	for (map<string, Vertex*>::iterator itr = myGraph.begin(), itr_end = myGraph.end(); itr != itr_end; ++itr)
	{
		Vertex* vertex = (*itr).second;
		if (vertex->destinationExists(v))
		{
			vertex->delEdge(v);
		}
	}
	return true;

}
bool Graph::findVertex(string v)//Check if a vertex exists in the graph
{
	return !(myGraph.find(v) == myGraph.end());
}
bool Graph::adde(string v1, string v2)//Add a edge to the Directed graph
{
	if (!findVertex(v1) || !findVertex(v2))
		return false;
	Vertex* v = myGraph[v1];
	Vertex* u = myGraph[v2];

	if (v->destinationExists(u))
		return false;
	v->addEdge(new Edge(v, u/*, 0*/));
	return true;
}
bool Graph::dele(string v1, string v2)//Delete a edge from the Directed graph
{
	if (!myGraph[v1]->destinationExists(v2))
		return false;
	myGraph[v1]->delEdge(v2);
	return true;
}
void Graph::printAll()//print all the graph
{
	for (map<string, Vertex*>::iterator itr = myGraph.begin(), itr_end = myGraph.end(); itr != itr_end; ++itr) {

		cout << (*itr).second->toString();
		cout << endl;
	}

}


void Graph::printNeighbors(string  vertex) // Given vertex V, print all vertexes that have an edge from V to them.
{
	if (!(myGraph.find(vertex) == myGraph.end()))
	{
		Vertex* v = myGraph[vertex];
		list<Edge*> myEdgeList = v->getEdgeList();
		for (list<Edge*>::iterator itr = myEdgeList.begin(), itr_end = myEdgeList.end(); itr != itr_end; ++itr)
		{
			Vertex* vertex = (*itr)->getDestination();
			cout << vertex->getKey() << " ";
		}
	}
}
void Graph::printFollowers(string v) // Given vertex V, print all the vertices that have an edge from them to V.
{
	if (!(myGraph.find(v) == myGraph.end()))
	{
		for (map<string, Vertex*>::iterator itr = myGraph.begin(), itr_end = myGraph.end(); itr != itr_end; ++itr)
		{
			Vertex* vertex = (*itr).second;
			if (vertex->destinationExists(v))
			{
				cout << vertex->getKey() << " ";
			}
		}
	}
	else
		cout << "ERROR";
}

void Graph::printAllReached(string v)//Given vertex V, prints all vertexes that can be reached from V
{
	if (!(myGraph.find(v) == myGraph.end()))
	{
		if (myGraph[v]->numOfNeighbours() > 0)
		{
			string newStr = "";
			list<Edge*> myEdgeList = myGraph[v]->getEdgeList();
			string str = v + " ";
			for (list<Edge*>::iterator itr = myEdgeList.begin(), itr_end = myEdgeList.end(); itr != itr_end; ++itr)
			{
				str += (*(itr))->getDestination()->getKey() + " ";

			}

			for (list<Edge*>::iterator itr = myEdgeList.begin(), itr_end = myEdgeList.end(); itr != itr_end; ++itr)
			{
				str = strReached(*(itr), str);
			}
			cout << str;
		}
		else
			cout << v;
	}
	else
		cout << "ERROR";
}
string Graph::strReached(Edge* e,string str)//A function to help, finding all the vertices that can be reached from a given edge.
{
	string s;
	Vertex* vertex = e->getDestination();
	s = e->getDestination()->getKey() + " ";
		if (vertex->numOfNeighbours() > 0)
		{
			list<Edge*>  EgeSon = vertex->getEdgeList();
			for (list<Edge*>::iterator itr2 = EgeSon.begin(), itr2_end = EgeSon.end(); itr2 != itr2_end; ++itr2)
			{
				s = (*itr2)->getDestination()->getKey() + " ";
				if (str.find(s) == std::string::npos)
				{
					str += s;
					str = strReached((*itr2), str);
				}
			}
		}
	return str;

}