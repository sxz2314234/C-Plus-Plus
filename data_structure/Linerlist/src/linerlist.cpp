/*
 * @Author: shi-xingzhi 3218635958@qq.com
 * @Date: 2023-07-10 15:36:22
 * @LastEditors: shi-xingzhi 3218635958@qq.com
 * @LastEditTime: 2023-08-07 17:51:27
 * @FilePath: \C-plus-plus\data_structure\linerlist_one.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include"linerlist.hpp"

template <class T>
void arrayList<T>::reSet(int newsize)
{
    if (newsize < arraysize)
    {
        cout << "Don't need to expand the size of array";
        return;
    }
    arraysize = newsize;
    T *temp = arr;
    arr = new T[newsize];
    copy(temp, temp + listsize, arr);
    delete[] temp;
}
template <class T>
void arrayList<T>::set(int theIndex, T theElment)
{
    if (theIndex >= 0 && theIndex <= listsize)
        arr[theIndex] = theElment;
    listsize++;
}
template <class T>
void arrayList<T>::clear()
{
    if (listsize == 0)
    {
        cout << "The array has been empty.";
        return;
    }
    listsize = 0;
}

template <class T>
arrayList<T>::arrayList(int initialcapacity)
{
    if (initialcapacity < 1)
        cout << "There is an err.";
    arr = new T[initialcapacity];
    listsize = 0;
    arraysize = initialcapacity;
}
template <class T>
arrayList<T>::arrayList(const arrayList<T> &thelist)
{
    arraysize = thelist.arraysize;
    listsize = thelist.listsize;
    T *elemence = new T[arraysize];
    copy(thelist.arr, thelist.arr + listsize, elemence);
}
template <class T>
int arrayList<T>::indexof(const T &theElement) const
{
    for (int i = 0; i < listsize; ++i)
        if (arr[i] == theElement)
            return i;
    return -1;
}
template <class T>
void arrayList<T>::erase(int theindex)
{
    if (listsize == 0)
        return;
    // while (theindex < listsize)
    //     arr[theindex - 1] = arr[theindex];
    // arr[theindex] = 0;
    // --arraysize;
    copy(arr + theindex + 1, arr + listsize, arr + theindex);
    delete (arr + listsize);
    listsize--;
}
template <class T>
void arrayList<T>::insert(int theindex, const T &theelement)
{
    if (listsize == arraysize - 1)
        return;
    ++listsize;
    --theindex;
    int i = theindex;
    while (theindex < listsize)
        arr[theindex + 1] = arr[theindex];
    arr[i] = theelement;
}
template <class T>
void arrayList<T>::output(ostream &out) const
{ // insert the ArrayList into the output stream
    copy(arr, arr + listsize, ostream_iterator<T>(out, " "));
}
template <class T>
ostream &operator<<(ostream &out, const arrayList<T> &x)
{ // overload <<
    x.output(out);
    return out;
}

// int main()
// {
//     linerlist<int>* pt=new arrayList<int>(100);
//     //利用函数的缺省值创建一个线性表
//     arrayList<char> z;
//     //利用线性表y复制创造一个线性表
//     arrayList<double> y(100);
//     arrayList<double> w(y);
// }