#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <vector>
#include <list>

using namespace std;

// Edge를 저장해야 하므로 Edge 구조체 선언
struct Edge 
{
    int num;    // Edge 번호
    int weight; // Edge weight
};

class AdjacencyList 
{
private:
    int size;                   // 노드 수
    vector<list<Edge>> graph;   // 인접 리스트

public:
    AdjacencyList(int vertices);                    // 노드 수를 받아 변수를 초기화 하는 생성자
    void addEdge(int src, int num, int weight);     // Edge를 추가하는 함수
    list<Edge> getAdjacentVertices(int vertex);     // 인접 노드를 반환하는 함수
};

#endif  // ADJACENCYLIST_H
