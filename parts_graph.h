// TO-DO LIST:
// √Construct part-graph for different furniture: starting from the chair
// Separate overlapping cycles and create LIGs
// Find the key and local interlocking state for LIGs

// Data structure:
// undirected graph

#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
using namespace std;

#define FINISHED -1
#define NOCYCLE -2


// axis direction
#define NO_AXIS -1
#define X 0
#define Y 1
#define Z 2


// Class for an undirected graph
class Graph
{
private:
    int vertexCount;    // No. of vertices
    
    // show connection status
    bool ** connection;
    
    // show axis direction of the connection status
    //" we denote D(A, B) as the set of axial directions that part A can have at its joint with part B."
    bool *** connection_axis;  // Pointer to an array containing adjacency lists
    
    // vector stores cycles of a furniture parts-graph
    std::vector<std::vector<int>> cycles;
    
    // Parameters for first key
    int k1; // User input
    int direction;
    vector<vector<int>> k1_cycles; // cycles that contain key k1 in the parts-graph
    vector<int> k1_cycle; // first LIG
    vector<int> kN;
    vector<int> directionN;
    

public:
    Graph(int V);   // Constructor
    ~Graph();       // Destructor
    void addEdge(int v, int w, int direction);   // to add an edge to graph
    void removeEdge(int v, int w); // to remove an edge of graph
    void setLIGs(std::vector<int>);
    void printLIGs();
    
    // Helper function
    int helper_union(int index);
    
    // Assembly process
    void confirmK1();
    void constructG1();
    void assemblyVerify();
    void identifyGN();
    void constructGN();
};
