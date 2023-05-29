#include "ShortestPath.h"

ShortestPath::ShortestPath(int vertices) : graph(vertices) 
{
    V = vertices;
    d.resize(V);
    p.resize(V);
}

void ShortestPath::addEdge(int src, int dest, int weight) 
{
    graph.addEdge(src, dest, weight);
}

void ShortestPath::InitializeSingleSource(int s) 
{
    for (int v = 0; v < V; v++) 
    {
        d[v] = INT_MAX;
        p[v] = -1;
    }
    d[s] = 0;
}

void ShortestPath::Relax(int u, int v, int weight) 
{
    if (d[v] > d[u] + weight) 
    {
        d[v] = d[u] + weight;
        p[v] = u;
    }
}

void ShortestPath::Dijkstra(int s) 
{
    InitializeSingleSource(s);
    vector<bool> visited(V, false); // 방문 여부 배열 초기화
    PriorityQueue<int> pq;

    pq.push(s);

    while (!pq.isEmpty()) 
    {
        int u = pq.top(); // 최소 거리를 가지는 노드 선택
        pq.pop();

        visited[u] = true;

        vector<Edge> adj = graph.getAdjacentVertices(u);
        for (const Edge& edge : adj) 
        {
            int v = edge.dest;
            int weight = edge.weight;

            if (!visited[v]) 
            {
                Relax(u, v, weight);
                pq.push(v);
            }
        }
    }
}

void ShortestPath::printShortestPaths() 
{
    for (int i = 1; i < V; i++) 
    {
        int node = i;
        stack<int> path;

        while (node != -1) {
            path.push(node);
            node = p[node];
        }

        while (!path.empty()) {
            cout << path.top() + 1;
            if (path.size() > 1)
                cout << " -> ";
            path.pop();
        }

        cout << ": " << d[i] << endl;
    }
}
