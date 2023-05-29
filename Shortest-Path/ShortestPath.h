#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <string>
#include <vector>
#include <iostream>
#include <stack> // ����� ���� ���
#include "AdjacencyList.h"
#include "PriorityQueue.h"

using namespace std;

// Edge�� ���ϱ� ���� ���Լ�
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
    int size;               // ��� ��
    AdjacencyList AL;       // ���� ����Ʈ
    vector<int> d;          // �ִ� �Ÿ� ����
    vector<int> p;          // ���� ��� ����

public:
    ShortestPath(int vertices);                     // ��� ���� �޾� ������ �ʱ�ȭ �ϴ� ������
    void addEdge(int src, int dest, int weight);    // Edge�� �߰��ϴ� �Լ�
    void InitializeSingleSource(int s);             // �ʱ�ȭ �Լ�
    void Relax(int u, int v, int weight);           // Relax �Լ�
    void Dijkstra(int s);                           // Dijkstra�� ����Ͽ� �ִܰŸ��� ���ϴ� �Լ�
    void print();                                   // ��� �Լ�
};

#endif  // SHORTESTPATH_H
