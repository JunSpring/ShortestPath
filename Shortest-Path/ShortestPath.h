#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <vector>
#include <iostream>
#include <stack>
#include "AdjacencyList.h"
#include "PriorityQueue.h"

using namespace std;

class ShortestPath 
{
private:
    int V; // 노드 수
    AdjacencyList graph; // 인접 리스트
    vector<int> d; // 최단 거리 배열
    vector<int> p; // 선행 노드 배열

public:
    ShortestPath(int vertices); // 생성자
    void addEdge(int src, int dest, int weight); // 간선 추가
    void InitializeSingleSource(int s); // 초기화 함수
    void Relax(int u, int v, int weight); // Relax 함수
    void Dijkstra(int s); // Dijkstra 알고리즘
    void printShortestPaths(); // 최단 경로 출력 함수
};

#endif
