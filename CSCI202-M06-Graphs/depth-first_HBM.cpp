/*
    Program Assignment #2: Depth-First Search Using Graphs
 
    Programmer: Hershey Marbeda
    Date: December 3, 2024
    File Name: depth-first_HBM.cpp
    Purpose: This program will demonstrate the depth-first search algorithm using graphs.
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <limits>

using namespace std;

void depthFirstTraversal(map<int, vector<int>>& graph, int startNode, unordered_set<int>& visited)
{
    visited.insert(startNode);
    cout << startNode << " ";
    
    for (int neighbor : graph[startNode])
    {
        if (visited.find(neighbor) == visited.end())
        {
            depthFirstTraversal(graph, neighbor, visited);
        }
    }
}

// Wrapper function to handle disconnected graphs
void depthFirstTraversalDisconnected(map<int, vector<int>>& graph)
{
    unordered_set<int> visited;
    cout << "Depth-First Traversal for the entire graph: ";
    
    // Iterate over all nodes in the graph (now in sorted order)
    for (const auto& node : graph)
    {
        if (visited.find(node.first) == visited.end())
        {
            // Perform DFS for each disconnected component
            depthFirstTraversal(graph, node.first, visited);
        }
    }
    
    cout << endl;
}

int main()
{
    // Table Heading
    cout << string(100, '*') << endl
         << "\t\t\t\t\t\t\t\tDepth-First Search Using Graphs (Ordered)" << endl
         << string(100, '*') << endl;
    
    // Declaration of Variables
    map<int, vector<int>> graph;
    int numEdges = 0;
    
    // User input for the graph
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;
    
    // Input Validation
    while (cin.fail() || numEdges < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter a valid number of edges: ";
        cin >> numEdges;
    }
    
    cout << "Enter the edges (format: start end):" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        
            // Add edge to the adjacency list (undirected graph)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // Perform Depth-First Traversal for the entire graph
    cout << endl;
    depthFirstTraversalDisconnected(graph);
    
        // To make it readable to the screen
    cout << endl << endl;
    return 0;
}
