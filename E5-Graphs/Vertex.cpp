#include "Vertex.h"
#include <list>


Vertex::Vertex(string myKey)
{
	key = myKey;
}

Vertex::~Vertex()
{
}

int Vertex::numOfNeighbours()//The function returns the number of edges coming out of the vertex
{
	return EdgeList.size();
}
bool Vertex::destinationExists(Vertex* v)//The function checks if there is a edge that connects it to the given vertex
{
	for (list<Edge*>::iterator itr = EdgeList.begin(), itr_end = EdgeList.end(); itr != itr_end; ++itr)
	{
		if ((*itr)->getDestination() == v)
			return true;
	}
	return false;
}
bool Vertex::destinationExists(string v)//The function checks if there is a edge that connects it to the given vertex name
{
	for (list<Edge*>::iterator itr = EdgeList.begin(), itr_end = EdgeList.end(); itr != itr_end; ++itr)
	{
		if ((*itr)->getDestination()->getKey() == v)
			return true;
	}
	return false;
}
void Vertex::addEdge(Edge* e)//Adds a new edge that comes out of the vertex
{
	for (list<Edge*>::iterator itr = EdgeList.begin(), itr_end = EdgeList.end(); itr != itr_end; ++itr)
		if (e == (*itr))
			throw ("ERROR");
	EdgeList.push_back(e);
}
void Vertex:: delEdge(string v)//Delete edge from the vertex if the edge exist.
{
	for (list<Edge*>::iterator itr = EdgeList.begin(), itr_end = EdgeList.end(); itr != itr_end; ++itr)
		if ((*itr)->getDestination()->getKey() == v)
		{
			EdgeList.erase(itr);
			break;
		}
}
string Vertex::toString()//Print all the edge of the vertex.
{
	string myStr = "";
	myStr += key;
	myStr += ":";
	for (list<Edge*>::iterator itr = EdgeList.begin(), itr_end = EdgeList.end(); itr != itr_end; ++itr)
	{
		myStr += " ";
		myStr += (*itr)->destination->key;
		
	}
	return myStr;
}
string Vertex::getKey()//Return the key of tha vertex
{
	return key;
}
list<Edge*> Vertex::getEdgeList()//Return the list of the vertex's edges
{
	return EdgeList;
}
string Vertex::findAllReached()//The function return all the reached of the vertex.
{
	string myStr = "";
	for (list<Edge*>::iterator itr = EdgeList.begin(), itr_end = EdgeList.end(); itr != itr_end; ++itr)
	{
		myStr += " ";
		myStr += (*itr)->destination->key;
	}
	return myStr;
}