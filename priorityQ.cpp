#include "priorityQ.h"

//default constructor
PriorityQ::PriorityQ()
{
	size = 0;
}

//inserts a new vertex to minHeap
void PriorityQ::insert(Node n)
{
	size++;
	int i = size - 1;
	minHeap[i] = n;

	while (i != 0 && minHeap[(i - 1) / 2].second > minHeap[i].second)
	{
		swap(minHeap[i], minHeap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

//gets and removes root node from minHeap
Node PriorityQ::extractMin()
{
	if (size <= 0)
		throw invalid_argument("ERROR: minHeap is empty, cannot extrace the min.");
	if (size == 1)
	{
		size--;
		return minHeap[0];
	}

	Node root = minHeap[0];
	minHeap[0] = minHeap[size - 1];
	size--;
	MinHeapify(0);

	return root;
}

//puts the heap into min heap order
void PriorityQ::MinHeapify(int i)
{

	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	int smallest = i;

	if (l <= size && minHeap[l].second < minHeap[i].second)
		smallest = l;
	if (r <= size && minHeap[r].second < minHeap[smallest].second)
		smallest = r;
	if (smallest != i)
	{
		swap(minHeap[i], minHeap[smallest]);
		MinHeapify(smallest);
	}
	
}

//swaps information of two nodes
void PriorityQ::swap(Node& x, Node& y)
{
	Node temp = x;
	x = y;
	y = temp;
}


//change the priority of a specific node
void PriorityQ::setNode(Node n)
{
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (minHeap[i].first == n.first) {
			minHeap[i].second = n.second;
			index = i;
			break;
		}
	}

	shiftUp(index);
}

//returns the priority of a specific node
int PriorityQ::getPriority(string s)
{
	for (int i = 0; i < 20; i++)
	{
		if (minHeap[i].first == s)
		{
			return minHeap[i].second;
		}
	}

	throw out_of_range("couldn't find key");
}

//helper function to reestablish min heap order
void PriorityQ::shiftUp(int i)
{
	int parent = (i - 1) / 2;
	while (i > 0 && minHeap[parent].second > minHeap[i].second) {

		// Swap parent and current node
		swap(minHeap[parent], minHeap[i]);

		// Update i to parent of i
		i = parent;
		parent = (i - 1) / 2;
	}
}