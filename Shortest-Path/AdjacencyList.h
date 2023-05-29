#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <vector>

using namespace std;

struct Edge 
{
    int dest;
    int weight;
};

class AdjacencyList 
{
private:
    int V; // ��� ��
    vector<vector<Edge>> graph; // ���� ����Ʈ

public:
    AdjacencyList(int vertices); // ������
    void addEdge(int src, int dest, int weight); // ���� �߰�
    vector<Edge> getAdjacentVertices(int vertex); // ���� ���� ��ȯ
};

#endif
