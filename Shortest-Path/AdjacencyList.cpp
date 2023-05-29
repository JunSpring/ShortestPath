#include "AdjacencyList.h"

// 노드 수를 받아 변수를 초기화 하는 생성자
AdjacencyList::AdjacencyList(int vertices) 
{
    size = vertices;
    graph.resize(size);
}

// Edge를 추가하는 함수
void AdjacencyList::addEdge(int src, int num, int weight) 
{
    Edge newEdge;
    newEdge.num = num;
    newEdge.weight = weight;
    graph[src].push_back(newEdge);
}

// 인접 노드를 반환하는 함수
list<Edge> AdjacencyList::getAdjacentVertices(int vertex) 
{
    return graph[vertex];
}
