#ifndef _MAXHEAP
#define _MAXHEAP
#include "maxPriorityQueue.hpp"

inline TreeNode &TreeNode::operator=(const TreeNode &obj)
{
    if (this == &obj)
    {
        return *this;
    }

    priority = obj.priority;
    element = obj.element;
    return *this;
}

inline bool TreeNode::operator<(const TreeNode &obj)
{
    if (priority < obj.priority)
        return true;
    else
        return false;
}

template <class T>
maxHeap<T>::maxHeap(initializer_list<T> init)
{
    heapsize = init.size() + 1;
    heapcount = init.size();

    heap = new T[heapsize];
    copy(init.begin(), init.end(), heap + 1);

    for (int root = heapsize / 2; root >= 1; ++root)
    {
        T rootelement = heap[root];

        int child = root * 2;
        while (child <= heapsize)
        {
            if (child < heapsize && heap[child] < heap[child])
                child++;

            if (heap[child] < rootelement)
                break;
            else
            {
                heap[child / 2] = heap[child];
                child *= 2;
            }
        }
        heap[child] = rootelement;
    }
}

template <class T>
maxHeap<T>::~maxHeap()
{
    delete[] heap;
}

template <class T>
void maxHeap<T>::pop()
{
    int index = 1;
    if (empty())
    {
        cout << "The heap is empty." << endl;
        return;
    }

    if (heap[2 * index] == 0 && heap[2 * index + 1] == 0)
    {
        // 只存在一个元素,就直接将第一个元素删除
        heap[index] = T();
        return;
    }

    // 存在两个以上元素,需要冒泡删除
    while (heap[2 * index] != 0)
    {
        int temp_index = heap[2 * index] < heap[2 * index + 1] ? 2 * index + 1 : 2 * index;
        heap[index] = heap[temp_index];

        index = temp_index;
    }
    heap[index] = heap[heapcount];
    heapcount--;
}

template <class T>
void maxHeap<T>::reset()
{
    T *newHeap = new T[heapsize * 2];
    copy(heap, heap + heapcount + 1, newHeap);

    delete[] heap;
    heap = newHeap;
    heapsize *= 2;
}

template <class T>
void maxHeap<T>::push(const T &obj)
{
    if (heapcount == heapsize - 1)
    {
        reset();
    }

    int currentnode = ++heapcount;
    while (currentnode != 1 && heap[currentnode / 2] < obj)
    {
        heap[currentnode] = heap[currentnode / 2];
        currentnode /= 2;
    }
    heap[currentnode] = obj;
}

template <class T>
void maxHeap<T>::show_heap() const
{
    for (int i = 1; i < heapcount; ++i)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

#endif