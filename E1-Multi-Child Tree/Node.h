#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Node
	{
 public:
	 string content;   // Content of the current discussion
	 list<Node*> responses;   // A list of "vertex" organs, each of which represents a response to a discussion

	 Node(string newContent) //constructor
	 {
		 this->content = newContent;
	 }
	 Node() { this->content = ""; }  // Default constructor 
	 };