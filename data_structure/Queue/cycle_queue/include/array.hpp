#pragma once

#include<iostream>

using namespace std;

template<class T>
class Array
{
    public:
    virtual ~Array(){};
    virtual bool empty() const = 0;                             // if return true,the list is empty
    virtual int size() const = 0;                               // return the amount of the list
    virtual T &get(int theindex) const = 0;                     // return the value that the index is theindex
    virtual int indexof(const T &theelement) const = 0;         // return the index of the theelement when it first occur
    virtual void erase(int theindex) = 0;                       // delete the element that the index is theindex
    virtual void insert(int theindex, const T &theelement) = 0; // insert
};

template<class T>
class array_data:public Array<T>
{
    protected:
    int queue_size;
    int count;
    T* datas;

    void reset();  // 重新new数组的大小,2倍递增

    public:
    array_data():queue_size(5),count(0),datas(new T[queue_size]){};
    explicit array_data(int s):queue_size(s),count(0),datas(new T[queue_size]){};
    ~array_data();

    bool empty()const{return count==0;}
    int size()const{return queue_size;}
    T& get(int theindex)const;
    int indexof(const T&)const;
    void erase(int);
    void insert(int,const T&);

    template<class U>
    friend ostream& operator<<(ostream&,array_data<U>&);
};

template<class U>
ostream& operator<<(ostream&,const array_data<U>&);

template<class T>
class cycle_queue:public array_data<T>
{
    public:
    cycle_queue():array_data<T>(),queue_front(0),queue_back(0){};
    explicit cycle_queue(int s):array_data<T>(s),queue_front(0),queue_back(0){};

    bool empty()const{return queue_front==queue_back;}
    bool full()const{return (queue_front+1)%this->queue_size==queue_back;}
    int size()const{return array_data<T>::size();}
    // T& get(int theindex)const{return array_data<T>::get(theindex);}

    T& front()const;
    void push(const T&);
    void pop();


    private:
    int queue_front;
    int queue_back;

    void reset();
};

#include"../src/array.cc"
