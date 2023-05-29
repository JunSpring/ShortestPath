#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm> // 비교함수를 넣기 위해 사용

using namespace std;

template<typename T, typename Compare = less<T>> 
class PriorityQueue 
{
private:
    vector<T> data;
    Compare comp; // 비교함수

    void heapifyUp(int index);      // Minheap의 특정 원소의 값을 변경 후 올림
    void heapifyDown(int index);    // Minheap의 특정 원소의 값을 변경 후 내림

public:
    bool isEmpty();     // 비어있는지 확인하는 함수
    void push(T item);  // 데이터를 추가하는 함수
    void pop();         // 데이터를 앞에서 삭제하는 함수
    T top();            // 가장 위 데이터를 반환하는 함수
};

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::heapifyUp(int i)
{
    // 강의자료와 동일

    int parent = (i - 1) / 2;

    // 비교함수를 통해 클래스 원형을 지킴
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
    //강의자료와 동일

    int size = data.size();
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    // 비교함수를 통해 클래스 원형을 지킴
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

// 비어있는지 확인하는 함수
template<typename T, typename Compare>
bool PriorityQueue<T, Compare>::isEmpty()
{
    return data.empty();
}

// 데이터를 추가하는 함수
template<typename T, typename Compare>
void PriorityQueue<T, Compare>::push(T item) 
{
    data.push_back(item);
    heapifyUp(data.size() - 1);
}

// 데이터를 앞에서 삭제하는 함수
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

// 가장 위 데이터를 반환하는 함수
template<typename T, typename Compare>
T PriorityQueue<T, Compare>::top()
{
    return data.front();
}

#endif  // PRIORITY_QUEUE_H
