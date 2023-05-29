#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class PriorityQueue 
{
private:
    vector<T> data;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    bool isEmpty();
    void push(const T& item);
    void pop();
    const T& top();
};

template<typename T>
bool PriorityQueue<T>::isEmpty()
{
    return data.empty();
}

template<typename T>
void PriorityQueue<T>::push(const T& item) 
{
    data.push_back(item);
    heapifyUp(data.size() - 1);
}

template<typename T>
void PriorityQueue<T>::pop() 
{
    if (isEmpty()) {
        return;
    }

    swap(data[0], data[data.size() - 1]);
    data.pop_back();
    heapifyDown(0);
}

template<typename T>
const T& PriorityQueue<T>::top()
{
    return data.front();
}

template<typename T>
void PriorityQueue<T>::heapifyUp(int i) 
{
    int parent = (i - 1) / 2;

    while (i > 0 && data[i] < data[parent]) 
    {
        swap(data[i], data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

template<typename T>
void PriorityQueue<T>::heapifyDown(int i) 
{
    int size = data.size();
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < size && data[l] < data[smallest]) 
    {
        smallest = l;
    }

    if (r < size && data[r] < data[smallest])
    {
        smallest = r;
    }

    if (smallest != i) 
    {
        swap(data[i], data[smallest]);
        heapifyDown(smallest);
    }
}


#endif  // PRIORITY_QUEUE_H
