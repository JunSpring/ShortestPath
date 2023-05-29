#include "ShortestPath.h"

// 노드 수를 받아 변수를 초기화 하는 생성자
ShortestPath::ShortestPath(int vertices) : AL(vertices) 
{
    size = vertices;
    d.resize(size);
    p.resize(size);
}

// Edge를 추가하는 함수
void ShortestPath::addEdge(int src, int dest, int weight) 
{
    AL.addEdge(src, dest, weight);
}

// 초기화 함수
void ShortestPath::InitializeSingleSource(int s) 
{
    // 강의자료와 동일

    for (int v = 0; v < size; v++) 
    {
        d[v] = INT_MAX;
        p[v] = -1;
    }
    d[s] = 0;
}

// Relax 함수
void ShortestPath::Relax(int u, int v, int weight) 
{
    //강의자료와 동일

    if (d[v] > d[u] + weight) 
    {
        d[v] = d[u] + weight;
        p[v] = u;
    }
}

// Dijkstra를 사용하여 최단거리를 구하는 함수
void ShortestPath::Dijkstra(int s) 
{
    // 강의자료와 다른 부분만 서술

    InitializeSingleSource(s);
    vector<bool> visited(size, false); // 방문한 Edge를 기록하기 위한 벡터
    PriorityQueue<Edge, CompareEdge> pq;

    Edge start = { s,0 };
    pq.push(start); // 처음에 모든 노드를 push하지 않고 순차적으로 push함

    while (!pq.isEmpty()) 
    {
        int u = pq.top().num; // 최소 거리를 가지는 노드 선택
        pq.pop();

        visited[u] = true;

        list<Edge> adj = AL.getAdjacentVertices(u);
        for (Edge v : adj) 
        {
            if (!visited[v.num])
            {
                Relax(u, v.num, v.weight);
                v.weight = d[v.num];
                pq.push(v); // 나머지 노드는 이 코드에서 push함
            }
        }
    }
}

// 출력 함수
void ShortestPath::print()
{
    // Path가 없을 것을 대비한 예외처리
    try 
    {
        for (int i = 1; i < size; i++)
        {
            int node = i;
            stack<int> path; // 출력을 위한 스택

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
