#include "Edge.h"

Edge::Edge(Vertex* mySource, Vertex* myDestination)
{
	source = mySource;
	destination = myDestination;
}


Edge::~Edge()
{
}
bool Edge ::operator==(Edge e)//The function checks if 2 edges are equal.
{
	if ((destination == e.destination) && (source == e.source))
		return true;
	return false;

}
Vertex* Edge::getDestination()//The function return the destination of the edge.
{
	return destination;
}
