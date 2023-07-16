//priorityQ.h: this file contains the definition of the Tree function

#ifndef PQ_HEADER
#define PQ_HEADER

#include "Graph.h"

using namespace std;

class PriorityQ
{
private:
	Node minHeap[20];
	int size;

public:
	PriorityQ();

	void insert(Node);
	void MinHeapify(int i);
	Node extractMin();
	void swap(Node&, Node&);

	//unused but useful functions
	int getSize() { return size; }
	void setNode(Node);
	int getPriority(string);
	void shiftUp(int i);
	
};

#endif