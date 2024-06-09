#include "graph.hpp"
#include <iostream>

Graph::Graph(const int n, int matrix[4][4]) : spots_count(n), map(vector<adjacent_matrix>(spots_count + 1))
{
    for (int i = 1; i <= spots_count; ++i)
    {
        map[i].spot = i;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1)
            {
                add(i + 1, j + 1);
            }
        }
    }
}

void Graph::add(int i, int j)
{
    if ((i < 1 || i > spots_count) || j < 1 || j > spots_count)
    {
        std::cout << "The index of map is out of boundry" << std::endl;
        return;
    }

    point *temp_point = new point(j, map[i].adjacent_point);
    map[i].adjacent_point = temp_point;
    map[i].degree++;
}

void Graph::show_graph()
{
    for (int i = 1; i <= spots_count; ++i)
    {
        point *temp = map[i].adjacent_point;
        std::cout << map[i].spot << " -> ";
        while (temp != nullptr)
        {
            /* code */
            std::cout << temp->number << " -> ";
            temp = temp->next;
        }
        std::cout << "null  | ";
        std::cout << "The degree is " << map[i].degree << std::endl;
    }
}