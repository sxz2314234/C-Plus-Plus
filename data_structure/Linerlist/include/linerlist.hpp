#include <iostream>
#include <iterator>
using namespace std;

// the template of the class,Linerlist
template <class T>
class linerlist
{
public:
    virtual ~linerlist(){};
    virtual bool empty() const = 0;                             // if return true,the list is empty
    virtual int size() const = 0;                               // return the amount of the list
    virtual T &get(int theindex) const = 0;                     // return the value that the index is theindex
    virtual int indexof(const T &theelement) const = 0;         // return the index of the theelement when it first occur
    virtual void erase(int theindex) = 0;                       // delete the element that the index is theindex
    virtual void insert(int theindex, const T &theelement) = 0; // insert
    virtual void output(ostream &out) const = 0;
};

template <class T>
class arrayList : public linerlist<T>
{
    // can be accessed by the class derived from arrayList
protected:
    T *arr;
    int arraysize;
    int listsize;

public:
    // constructor function,duplicate function and destructor function
    arrayList(int initialcapacity = 10);
    ~arrayList() { delete[] arr; }
    arrayList(const arrayList<T> &);

    // ADT method
    bool empty() const { return listsize == 0; }
    int size() const { return listsize; }
    T &get(int theIndex) const { return arr[theIndex]; }
    int indexof(const T &theElement) const;
    void erase(int theindex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &) const;
    T *start() { return arr; }
    T *end() { return arr + listsize; }

    // new-added method for matrix
    void reSet(int newsize);
    void set(int theIndex, T theElement);
    void clear();
};
