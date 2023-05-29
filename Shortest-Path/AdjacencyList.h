#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <vector>
#include <list>

using namespace std;

// Edge�� �����ؾ� �ϹǷ� Edge ����ü ����
struct Edge 
{
    int num;    // Edge ��ȣ
    int weight; // Edge weight
};

class AdjacencyList 
{
private:
    int size;                   // ��� ��
    vector<list<Edge>> graph;   // ���� ����Ʈ

public:
    AdjacencyList(int vertices);                    // ��� ���� �޾� ������ �ʱ�ȭ �ϴ� ������
    void addEdge(int src, int num, int weight);     // Edge�� �߰��ϴ� �Լ�
    list<Edge> getAdjacentVertices(int vertex);     // ���� ��带 ��ȯ�ϴ� �Լ�
};

#endif  // ADJACENCYLIST_H
