#include <iostream>
#include "graph.hpp"

using namespace std;

const int matrix_size = 4;

int matrix[matrix_size][matrix_size] = {{1, 0, 1, 0}, {1, 1, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 1}};

int main()
{
    Graph tu(matrix_size, matrix);
    tu.show_graph();
}