#ifndef _CYCLE_QUEUE
#define _CYCLE_QUEUE

#include"array.hpp"
#include<algorithm>
#include<stdexcept>
#include<iostream>

using namespace std;

template<class T>
array_data<T>::~array_data()
{
    delete[] datas;
}

template<class T>
void array_data<T>::reset()
{
    T* temp_datas=new T[2*queue_size];
    copy(datas,datas+count,temp_datas);

    delete[] datas;
    datas=temp_datas;
    queue_size*=2;
}

template<class T>
T& array_data<T>::get(int theindex)const
{
    if(theindex<0||theindex>count)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return datas[theindex];
}

template<class T>
int array_data<T>::indexof(const T&theElement)const
{
    int index=0;
    for(;index<count;++index)
    {
        if(datas[index]==theElement)
        {
            return index;
        }
    }

    cout<<"Can not find the element."<<endl;
    return -1;
}

template<class T>
void array_data<T>::erase(int theindex)
{
    if(empty())
    return ;

    copy(datas+theindex,datas+count,datas+theindex-1);
    count--;
}

template<class T>
void array_data<T>::insert(int theindex,const T&theElement)
{
    if(theindex<0||theindex>=queue_size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    if((count+1)==queue_size)
    reset();

    copy(datas+theindex-1,datas+count,datas+theindex);
    datas[theindex]=theElement;
    count++;
}

template<class U>
ostream& operator<<(ostream& out,const array_data<U>&arr_data)
{
    for(int i=0;i<arr_data.count;++i)
    {
        out<<arr_data[i]<<" ";
    }
    out<<endl;
    return out;
}

template<class T>
void cycle_queue<T>::reset()
{
    T* newQueue=new T[this->queue_size*2];
    if(queue_front<2)
    {
        // 没有成环
        for(int i=0;i<this->queue_size-1;++i)
        newQueue[i]=this->datas[queue_front+i];
    }
    else
    {
        // 已经成环
        copy(this->datas+queue_front,this->datas+this->queue_size,newQueue);
        copy(this->datas,this->datas+queue_back,newQueue+this->queue_size-queue_front);
    }

    this->queue_front=0;
    this->queue_back=this->queue_size-1;
    this->queue_size*=2;
    delete[] this->datas;
    this->datas=newQueue;
}

template<class T>
void cycle_queue<T>::push(const T&theElement)
{
    if((queue_back+1)%this->queue_size==queue_front)
    reset();

    this->datas[queue_back]=theElement;
    queue_back=(queue_back+1)%this->queue_size;
}

template<class T>
void cycle_queue<T>::pop()
{
    if(queue_back==queue_front)
    {
        cout<<"The queue is empty."<<endl;
        return ;
    }

    queue_front=(queue_front+1)%this->queue_size;
}

template<class T>
T& cycle_queue<T>::front()const
{
    if(empty())
    {
        throw std::runtime_error("The queue is empty.");
    }

    return this->datas[queue_front];
}

#endif