#include "class_Tree.cpp"

int main()
{
    tree<char> tr('#');

    cout << "Please enter the expression to articulate the tree: " << endl;
    string str;
    cin >> str;

    tr.creat(str);
    tr.non_recrusive_postorder();
}