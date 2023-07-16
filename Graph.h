//Graph.h: this file contains my implementation of a weighted directed graph

#ifndef Graph_HEADER
#define Graph_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <unordered_map>
#include <utility>

using namespace std;
using std::istringstream;

typedef pair<string, int> Node;

class Graph
{
private: 
	unordered_map<string, vector<Node>> verticies;
public:
	unordered_map<string, vector<Node>> getGraph() { return verticies; }
	void addToGraph(string, string, int);
	void print();
};



#endif