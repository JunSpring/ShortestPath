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
    int V; // ��� ��
    AdjacencyList graph; // ���� ����Ʈ
    vector<int> d; // �ִ� �Ÿ� �迭
    vector<int> p; // ���� ��� �迭

public:
    ShortestPath(int vertices); // ������
    void addEdge(int src, int dest, int weight); // ���� �߰�
    void InitializeSingleSource(int s); // �ʱ�ȭ �Լ�
    void Relax(int u, int v, int weight); // Relax �Լ�
    void Dijkstra(int s); // Dijkstra �˰���
    void printShortestPaths(); // �ִ� ��� ��� �Լ�
};

#endif
