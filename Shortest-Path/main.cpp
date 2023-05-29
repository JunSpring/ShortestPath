#include <fstream>
#include <sstream>
#include <string>
#include "ShortestPath.h"

// csv������ �а� Edge�� �߰��ϴ� �Լ�
bool readSPFromFile(string fileName, ShortestPath& SP);

int main()
{
    // SP ���� �� csv���Ͽ��� �ε�
    ShortestPath SP(0);
    if (!readSPFromFile("graph1.csv", SP))
        return 0;

    // graph���� 1�������� Dijkstra ����
    SP.Dijkstra(0);
    cout << "----- graph Dijkstra print -----" << endl;
    SP.print();
    return 0;
}

// csv������ �а� Edge�� �߰��ϴ� �Լ�
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
