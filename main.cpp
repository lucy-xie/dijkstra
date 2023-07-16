//main.cpp

#include "main.h"

int main(int argc, char* argv[])
{

    try
    {

        if (argc < 2)
        {
            throw invalid_argument("Must pass input file name and complete path.");
        }

        //takes in command line arg and opens them into separate files to be read from
        string filename = argv[1];
        ifstream graphFile;

        graphFile.open(filename);

        if (!graphFile)
        {
            throw invalid_argument("ERROR: files failed to open\n");
        }

    
    //start timer
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    
    //variables
    string startV = "",
           endV = "",
           ns, nt, temp;
    int weight;
    Graph g;
    graphFile >> startV >> endV;
    getline(graphFile, temp);
    getline(graphFile, temp);

    //extract beginning and end of path
    cout << "Start and end vertex: " << startV << " " << endV << endl;
  
    //extract the rest of the file
    while (graphFile >> ns >> nt >> weight)
    {
        g.addToGraph(ns, nt, weight);
    }

    cout << "Adjacency list for the graph: " << endl;
    g.print();


    dijkstra(g, startV, endV);
    
    end = chrono::system_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count();


    }
    catch (...)
    {
        cout << "Caught an exception while running the code\n";
    }
    

}



