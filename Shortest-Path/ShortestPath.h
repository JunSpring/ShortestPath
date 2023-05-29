#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <string>
#include <vector>
#include <iostream>
#include <stack> // 출력을 위해 사용
#include "AdjacencyList.h"
#include "PriorityQueue.h"

using namespace std;

// Edge를 비교하기 위한 비교함수
struct CompareEdge
{
    bool operator()(Edge ledge, Edge redge)
    {
        return ledge.weight < redge.weight;
    }
};

class ShortestPath 
{
private:
    int size;               // 노드 수
    AdjacencyList AL;       // 인접 리스트
    vector<int> d;          // 최단 거리 벡터
    vector<int> p;          // 선행 노드 벡터

public:
    ShortestPath(int vertices);                     // 노드 수를 받아 변수를 초기화 하는 생성자
    void addEdge(int src, int dest, int weight);    // Edge를 추가하는 함수
    void InitializeSingleSource(int s);             // 초기화 함수
    void Relax(int u, int v, int weight);           // Relax 함수
    void Dijkstra(int s);                           // Dijkstra를 사용하여 최단거리를 구하는 함수
    void print();                                   // 출력 함수
};

#endif  // SHORTESTPATH_H
