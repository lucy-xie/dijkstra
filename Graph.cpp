#include "Graph.h"

void Graph::addToGraph(string startNode, string destNode, int weight) 
{
    // Check if the startNode already exists in the graph
    if (verticies.find(startNode) == verticies.end()) {
        // Create an empty vector for the startNode if it doesn't exist
        verticies[startNode] = vector<pair<string, int>>();
    }

    // Add the edge from startNode to destNode with the given weight
    verticies[startNode].push_back(make_pair(destNode, weight));

    // Check if the destNode doesn't exist in the graph
    if (verticies.find(destNode) == verticies.end()) {
        // Create an empty vector for the destNode if it doesn't exist
        verticies[destNode] = vector<pair<string, int>>();
    }
}



void Graph::print()
{
    unordered_map<string, vector<pair<string, int>>>::iterator itr;
    vector<pair<string, int>> currVec;
    for (itr = verticies.begin(); itr != verticies.end(); itr++)
    {
        currVec = itr->second;
        cout << itr->first << ":  ";
        for (auto i : currVec)
        {
            cout << i.first << " " << i.second << ", ";
        }
        cout << endl;
    }
}