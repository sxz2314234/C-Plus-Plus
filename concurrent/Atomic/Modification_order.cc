/*

修改顺序 (Modification orders)
对一个原子变量的所有修改操作总是存在一定的先后顺序, 且所有线程都认可这个顺序,
 即使这些修改操作是在不同的线程中执行的. 
 这个所有线程一致同意的顺序就称为修改顺序 (modification order). 这意味着

两个修改操作不可能同时进行, 一定存在一个先后顺序. 
这很容易理解, 因为这是原子操作必须保证的, 否则就有数据竞争的问题.

即使每次运行的修改顺序可能都不同, 但所有线程看到的修改顺序总是一致的. 
如果线程 a 看到原子变量 x 由 1 变成 2, 那么线程 b 就不可能看到 x 由 2 变成 1.

无论使用哪种内存顺序, 原子变量的操作总能满足修改顺序一致性, 
即使是最松散的 memory_order_relaxed. 我们来看一个例子

*/

#include<iostream>
#include<atomic>
#include<thread>
#include<vector>

std::atomic<int> a{0};

void thread1() {
    for (int i = 0; i < 10; i += 2)
        a.store(i, std::memory_order_relaxed);
}

void thread2() {
    for (int i = 1; i < 10; i += 2)
        a.store(i, std::memory_order_relaxed);
}

void thread3(std::vector<int> *v) {
    for (int i = 0; i < 10; ++i)
        v->push_back(a.load(std::memory_order_relaxed));
}

void thread4(std::vector<int> *v) {
    for (int i = 0; i < 10; ++i)
        v->push_back(a.load(std::memory_order_relaxed));
}

int main() {
    std::vector<int> v3, v4;
    std::thread t1(thread1), t2(thread2), t3(thread3, &v3), t4(thread4, &v4);
    t1.join(), t2.join(), t3.join(), t4.join();

    for (int i : v3) std::cout << i << " ";
    std::cout << std::endl;
    for (int i : v4) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}