#include"maxPriorityQueue.hpp"
#include<iostream>

using namespace std;

int main()
{
    maxHeap<int> heap;

    heap.push(2);
    heap.push(1);
    heap.push(4);
    heap.push(3);
    heap.push(6);
    heap.push(7);
    heap.show_heap();

    cout<<heap.top()<<endl;
    heap.pop();

    heap.show_heap();
}