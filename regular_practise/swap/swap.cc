// 定制一个专属类的swap函数
// 交换两个点的坐标值

#include<iostream>
#include<utility>

// pimpl: pinter to implementation
class PointerImpl
{
    private:
    int x;
    int y;

    public:
    PointerImpl(int _x=0,int _y=0):x(_x),y(_y){};

    int get_x()const{return x;}
    int get_y()const{return y;}
};

class Pointer
{
    PointerImpl* pimpl;
    public:
    Pointer(PointerImpl*temp=nullptr):pimpl(temp){};
    Pointer(int _x=0,int _y=0):pimpl(new PointerImpl(_x,_y)){};

    void swap(Pointer&);
    void print()const;
};

void Pointer::swap(Pointer&other)
{
    using std::swap;
    swap(pimpl,other.pimpl);
}

void Pointer::print()const
{
    using std::cout;
    cout<<"( "<<pimpl->get_x()<<", "<<pimpl->get_y()<<" )"<<std::endl;
}

// 对std::swap函数进行全特化
namespace std
{
    template<>
    void swap<Pointer>(Pointer&a,Pointer&b)
    {
        a.swap(b);
    }
}

// no-member的swap函数
void swap(Pointer&a,Pointer&b)
{
    a.swap(b);
}

int main()
{
    Pointer test1(1,2);
    Pointer test2(3,4);

    using std::swap;
    swap(test1,test2);

    std::cout<<"The test1 is ";
    test1.print();
    std::cout<<"The test2 is ";
    test2.print();
}