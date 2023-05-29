#include <fstream>
#include <sstream>
#include <string>
#include "ShortestPath.h"

// csv파일을 읽고 Edge를 추가하는 함수
bool readSPFromFile(string fileName, ShortestPath& SP);

int main()
{
    // SP 선언 및 csv파일에서 로드
    ShortestPath SP(0);
    if (!readSPFromFile("graph1.csv", SP))
        return 0;

    // graph에서 1번노드부터 Dijkstra 실행
    SP.Dijkstra(0);
    cout << "----- graph Dijkstra print -----" << endl;
    SP.print();
    return 0;
}

// csv파일을 읽고 Edge를 추가하는 함수
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
