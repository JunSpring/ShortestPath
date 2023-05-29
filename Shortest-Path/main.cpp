#include <fstream>
#include <sstream>
#include <string>
#include <fstream>
#include "ShortestPath.h"

bool readSPFromFile(string fileName, ShortestPath& SP);

int main()
{
    // graph 선언 및 텍스트파일에서 로드
    ShortestPath graph(0);
    if (!readSPFromFile("graph1.csv", graph))
        return 0;

    // graph에서 1번노드부터 Dijkstra 실행
    graph.Dijkstra(0);
    cout << "----- graph Dijkstra print -----" << endl;
    graph.printShortestPaths();
    return 0;
}

// 텍스트 파일을 읽고 Edge를 추가하는 함수
bool readSPFromFile(string fileName, ShortestPath& SP)
{
    ifstream file(fileName);
    if (!file)
    {
        cout << "Failed to open file: " << fileName << endl;
        return false;
    }

    string line;
    getline(file, line);
    int size = stoi(line);

    SP = ShortestPath(size);

    for (int i = 0; i < size; i++) {
        getline(file, line);
        stringstream ss(line);
        string cell;
        int j = 0;

        while (getline(ss, cell, ','))
        {
            if (stoi(cell) != 0)
                SP.addEdge(i, j, stoi(cell));
            j++;
        }
    }

    file.close();
    return true;
}
