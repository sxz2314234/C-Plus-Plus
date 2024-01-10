// atomic.cc --test
#include <atomic>
#include <thread>
#include <iostream>
#include <assert.h>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x()
{
    x.store(true, std::memory_order_acquire); // 1
}

void write_y()
{
    y.store(true, std::memory_order_acquire); // 2
}
void read_x_then_y()
{
    while (!x.load(std::memory_order_release))
        ;
    if (y.load(std::memory_order_release)) // 3
        ++z;
}
void read_y_then_x()
{
    while (!y.load(std::memory_order_release))
        ;
    if (x.load(std::memory_order_release)) // 4
        ++z;
}
int main()
{
    x = false;
    y = false;
    z = 0;
    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);
    a.join();
    b.join();
    c.join();
    d.join();
    assert(z.load() != 1); // 5
    std::cout << z << std::endl;
}