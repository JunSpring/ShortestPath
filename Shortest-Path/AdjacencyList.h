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
    int V; // 노드 수
    vector<vector<Edge>> graph; // 인접 리스트

public:
    AdjacencyList(int vertices); // 생성자
    void addEdge(int src, int dest, int weight); // 간선 추가
    vector<Edge> getAdjacentVertices(int vertex); // 인접 노드들 반환
};

#endif
