#include"array.hpp"
#include<iostream>

using namespace std;

int main()
{
    cycle_queue<int> test_queue;
    for(int i=0;i<7;++i)
    test_queue.push(i);

    for(int i=0;i<7;++i)
    {
        int j=test_queue.front();
        test_queue.pop();
        cout<<j<<" ";
    }
    cout<<endl;
}