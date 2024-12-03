/*
     Program Assignment #2: Breadth-First Search Using Graphs
     
     Programmer: Hershey Marbeda
     Date: December 3, 2024
     File Name: depth-first_HBM.cpp
     Purpose: This program will demonstrate the breadth-first search algorithm using graphs.
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <limits>

using namespace std;

void breadthFirstTraversal(map<int, vector<int>>& graph, int startNode, unordered_set<int>& visited)
{
    queue<int> q;
    visited.insert(startNode);
    q.push(startNode);
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neighbor : graph[node])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

    // Wrapper function to handle disconnected graphs
void breadthFirstTraversalDisconnected(map<int, vector<int>>& graph)
{
    unordered_set<int> visited;
    cout << "Breadth-First Traversal for the entire graph: ";
    
        // Iterate over all nodes in the graph (now in sorted order)
    for (const auto& node : graph)
    {
        if (visited.find(node.first) == visited.end())
        {
                // Perform BFS for each disconnected component
            breadthFirstTraversal(graph, node.first, visited);
        }
    }
    
    cout << endl;
}

int main()
{
    // Table Heading
    cout << string(100, '*') << endl
         << "\t\t\t\t\t\t\t\tBreadth-First Search Using Graphs (Ordered)" << endl
         << string(100, '*') << endl;
    
    // Declaration of Variables
    map<int, vector<int>> graph;
    int numEdges = 0;
    
    
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
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // Perform Breadth-First Traversal for the entire graph
    cout << endl;
    breadthFirstTraversalDisconnected(graph);
    
    // To make it readable to the screen
    cout << endl << endl;
    return 0;
}

