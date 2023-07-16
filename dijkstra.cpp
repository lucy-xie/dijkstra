#include "dijkstra.h"

//dijkstras algorithm to find shortest path in a graph
void dijkstra(Graph graph, string start, string end)
{
    unordered_map<string, vector<Node>> g = graph.getGraph();
    unordered_map<string, int> dist;
    PriorityQ pq;
    unordered_map<string, string> parent;
    unordered_map<string, bool> processed;

    unordered_map<string, vector<Node>>::iterator itr;
    for (itr = g.begin(); itr != g.end(); itr++)
    {
        dist[itr->first] = INT_MAX;
        parent[itr->first] = "";
        processed[itr->first] = false;
    }

    dist[start] = 0;
    pq.insert(make_pair(start, 0));

    while (pq.getSize() != 0)
    {
        Node n = pq.extractMin();
        if (processed[n.first] == false)
        {
            processed[n.first] = true;
            for (auto i : g[n.first])
            {
                int totalWeight = n.second + i.second;
                if (dist[i.first] > totalWeight)
                {
                    parent[i.first] = n.first;
                    dist[i.first] = totalWeight;
                    pq.insert(make_pair(i.first, totalWeight));
                }

            }
        }
    }

    //print the shorest path as well as the total distance/weight
    vector<string> path;
    string currentNode = end;

    while (currentNode != start) {
        path.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << "\nShortest path from " << start << " to " << end << ": ";
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    cout << "\nDistance traveled: " << dist[end] << endl << endl;
}