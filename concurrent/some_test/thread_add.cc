#include<iostream>
#include<thread>
using namespace std;

class thread_guard
{
    void (*func)(int);
    thread* the_thread;
    public:
    explicit thread_guard(void (*)(int));
    thread_guard():func(nullptr),the_thread(nullptr){};
};

thread_guard::thread_guard(void(*f)(int)):func(f)
{
    (*the_thread)=
}

class test
{
    int t;
    public:
    test(int t_):t(t_){};
    test():t(0){};

    void set_value(int s){t=s;}
    void operator()()
    {
        cout<<"This is "<<t<<"th thread."<<endl;
    }
};

int main()
{
    test* cases=new test[10];
    thread* threads=new thread[10];

    for(int i=0;i<10;++i)
    {
        cases[i].set_value(i);
    }
    for(int i=0;i<10;++i)
    {
        threads[i].
    }
}