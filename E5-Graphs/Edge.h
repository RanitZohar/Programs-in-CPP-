#pragma once
class Vertex;

class Edge
{
	Vertex* source;
	Vertex* destination;

public:
	Edge(Vertex* mySource, Vertex* myDestination);
	~Edge();
	bool operator==(Edge e);
	Vertex* getDestination();
	friend class Vertex;

};

