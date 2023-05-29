#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm> // ���Լ��� �ֱ� ���� ���

using namespace std;

template<typename T, typename Compare = less<T>> 
class PriorityQueue 
{
private:
    vector<T> data;
    Compare comp; // ���Լ�

    void heapifyUp(int index);      // Minheap�� Ư�� ������ ���� ���� �� �ø�
    void heapifyDown(int index);    // Minheap�� Ư�� ������ ���� ���� �� ����

public:
    bool isEmpty();     // ����ִ��� Ȯ���ϴ� �Լ�
    void push(T item);  // �����͸� �߰��ϴ� �Լ�
    void pop();         // �����͸� �տ��� �����ϴ� �Լ�
    T top();            // ���� �� �����͸� ��ȯ�ϴ� �Լ�
};

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::heapifyUp(int i)
{
    // �����ڷ�� ����

    int parent = (i - 1) / 2;

    // ���Լ��� ���� Ŭ���� ������ ��Ŵ
    while (i > 0 && comp(data[i], data[parent]))
    {
        swap(data[i], data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::heapifyDown(int i)
{
    //�����ڷ�� ����

    int size = data.size();
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    // ���Լ��� ���� Ŭ���� ������ ��Ŵ
    if (l < size && comp(data[l], data[smallest]))
    {
        smallest = l;
    }

    if (r < size && comp(data[r], data[smallest]))
    {
        smallest = r;
    }

    if (smallest != i)
    {
        std::swap(data[i], data[smallest]);
        heapifyDown(smallest);
    }
}

// ����ִ��� Ȯ���ϴ� �Լ�
template<typename T, typename Compare>
bool PriorityQueue<T, Compare>::isEmpty()
{
    return data.empty();
}

// �����͸� �߰��ϴ� �Լ�
template<typename T, typename Compare>
void PriorityQueue<T, Compare>::push(T item) 
{
    data.push_back(item);
    heapifyUp(data.size() - 1);
}

// �����͸� �տ��� �����ϴ� �Լ�
template<typename T, typename Compare>
void PriorityQueue<T, Compare>::pop() 
{
    if (isEmpty()) {
        return;
    }

    swap(data[0], data[data.size() - 1]);
    data.pop_back();
    heapifyDown(0);
}

// ���� �� �����͸� ��ȯ�ϴ� �Լ�
template<typename T, typename Compare>
T PriorityQueue<T, Compare>::top()
{
    return data.front();
}

#endif  // PRIORITY_QUEUE_H
