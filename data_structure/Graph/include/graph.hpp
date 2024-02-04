#pragma once
#include<vector>

using namespace std;

class Graph
{
    public:
    struct point
    {
        /* data */
        int number;
        point* next;

        point(int n=0,point*nt=nullptr):number(n),next(nt){};
    };
    struct adjacent_matrix
    {
        /* data */
        int spot;
        int degree;
        point* adjacent_point; // must be equal to the index of map

        adjacent_matrix(int s=0,int d=0,point* a=nullptr):spot(s),degree(d),adjacent_point(nullptr){};
    };
    
    private:
    const int spots_count;
    vector<adjacent_matrix> map;

    public:
    Graph(const int n,int matrix[4][4]);
    Graph()=delete;

    void add(int,int);
    void show_graph();
};