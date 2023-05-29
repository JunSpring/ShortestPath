#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int vertices) 
{
    V = vertices;
    graph.resize(V);
}

void AdjacencyList::addEdge(int src, int dest, int weight) 
{
    Edge newEdge;
    newEdge.dest = dest;
    newEdge.weight = weight;
    graph[src].push_back(newEdge);
}

vector<Edge> AdjacencyList::getAdjacentVertices(int vertex) 
{
    return graph[vertex];
}
