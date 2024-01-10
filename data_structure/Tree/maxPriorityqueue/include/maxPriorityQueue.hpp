#pragma once
#include<iostream>
#include<algorithm>
#include<initializer_list>

using namespace std;

template<class T>
class maxPriorityQueue
{
    public:
    virtual ~maxPriorityQueue(){};
    virtual bool empty()const=0;      // 当且仅当队列为空,返回true
    virtual int size()const=0;        // 返回队列的元素个数
    virtual const T& top()const=0;    // 返回优先级最大的元素的引用
    virtual void pop()=0;             // 删除队首元素
    virtual void push(const T&)=0;    // 插入元素
};

class TreeNode
{
    private:
    int priority;
    char element;

    public:
    TreeNode():priority(0),element('*'){};
    TreeNode(int p,char e):priority(p),element(e){};

    inline TreeNode& operator=(const TreeNode&);
    bool operator==(int pri){return priority==pri;}
    bool operator!=(int pri){return priority!=pri;}
    inline bool operator<(const TreeNode&);    // 比较优先级
};

template<class T>
class maxHeap:public maxPriorityQueue<T>
{
    int heapsize;
    int heapcount;
    T* heap;

    void reset();
    public:
    maxHeap():heapsize(10),heapcount(0),heap(new T[heapsize]){};
    maxHeap(initializer_list<T>);
    ~maxHeap();

    bool empty()const{return heapcount==0;}
    int size()const{return heapcount;}
    const T& top()const{return heap[1];}
    void pop();
    void push(const T&);

    void show_heap()const;
};

#include"../src/maxPriorityQueue.cc"