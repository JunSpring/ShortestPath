#include "ShortestPath.h"

// ��� ���� �޾� ������ �ʱ�ȭ �ϴ� ������
ShortestPath::ShortestPath(int vertices) : AL(vertices) 
{
    size = vertices;
    d.resize(size);
    p.resize(size);
}

// Edge�� �߰��ϴ� �Լ�
void ShortestPath::addEdge(int src, int dest, int weight) 
{
    AL.addEdge(src, dest, weight);
}

// �ʱ�ȭ �Լ�
void ShortestPath::InitializeSingleSource(int s) 
{
    // �����ڷ�� ����

    for (int v = 0; v < size; v++) 
    {
        d[v] = INT_MAX;
        p[v] = -1;
    }
    d[s] = 0;
}

// Relax �Լ�
void ShortestPath::Relax(int u, int v, int weight) 
{
    //�����ڷ�� ����

    if (d[v] > d[u] + weight) 
    {
        d[v] = d[u] + weight;
        p[v] = u;
    }
}

// Dijkstra�� ����Ͽ� �ִܰŸ��� ���ϴ� �Լ�
void ShortestPath::Dijkstra(int s) 
{
    // �����ڷ�� �ٸ� �κи� ����

    InitializeSingleSource(s);
    vector<bool> visited(size, false); // �湮�� Edge�� ����ϱ� ���� ����
    PriorityQueue<Edge, CompareEdge> pq;

    Edge start = { s,0 };
    pq.push(start); // ó���� ��� ��带 push���� �ʰ� ���������� push��

    while (!pq.isEmpty()) 
    {
        int u = pq.top().num; // �ּ� �Ÿ��� ������ ��� ����
        pq.pop();

        visited[u] = true;

        list<Edge> adj = AL.getAdjacentVertices(u);
        for (Edge v : adj) 
        {
            if (!visited[v.num])
            {
                Relax(u, v.num, v.weight);
                v.weight = d[v.num];
                pq.push(v); // ������ ���� �� �ڵ忡�� push��
            }
        }
    }
}

// ��� �Լ�
void ShortestPath::print()
{
    // Path�� ���� ���� ����� ����ó��
    try 
    {
        for (int i = 1; i < size; i++)
        {
            int node = i;
            stack<int> path; // ����� ���� ����

            while (node != -1)
            {
                path.push(node);
                node = p[node];
            }

            if (path.empty()) 
            {
                throw runtime_error("No path found to node " + to_string(i));
            }

            while (!path.empty())
            {
                cout << path.top() + 1;
                if (path.size() > 1)
                    cout << " -> ";
                path.pop();
            }

            cout << ": " << d[i] << endl;
        }
    }

    catch (exception e) 
    {
        cout << "Finding Path Error: " << e.what() << endl;
    }
}
