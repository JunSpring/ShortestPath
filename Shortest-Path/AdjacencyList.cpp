#include "AdjacencyList.h"

// ��� ���� �޾� ������ �ʱ�ȭ �ϴ� ������
AdjacencyList::AdjacencyList(int vertices) 
{
    size = vertices;
    graph.resize(size);
}

// Edge�� �߰��ϴ� �Լ�
void AdjacencyList::addEdge(int src, int num, int weight) 
{
    Edge newEdge;
    newEdge.num = num;
    newEdge.weight = weight;
    graph[src].push_back(newEdge);
}

// ���� ��带 ��ȯ�ϴ� �Լ�
list<Edge> AdjacencyList::getAdjacentVertices(int vertex) 
{
    return graph[vertex];
}
