// Model Matching:KMP algorithm(including the advanced one)

#include <iostream>
#include <string>
using namespace std;

int *thenext(int n, string &);
int KMP(string &, string &, int *);

int main()
{
    string Main_String = "ababcabcacbab";
    string Match_String = "cabca";
    int *next = thenext(Match_String.size(), Match_String);

    cout<<"The next array is: ";
    for (int i = 0; i < Match_String.size(); ++i)
    {
        cout << next[i] << " ";
    }
    cout << endl;

    cout<<"The first presence of the matched string is number: ";
    cout<<KMP(Main_String,Match_String,next)<<endl;

    delete[] next;
}

int *thenext(int n, string &match_string)
{
    int *next = new int[n]{-1};
    next[1]=0;

    int i = 1;
    int j = 0;
    while (i < n-1 )
    {
        if (match_string[i] == match_string[j])
        {
            ++i; ++j;
            next[i] = j;
           
        }
        else if(match_string[i] != match_string[j]&&j==0)
        {
            ++i;
            next[i]=0;
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}

int KMP(string &main_string, string &match_string, int *next)
{
    int i = 0;
    int j = 0;

    while (j < match_string.size() && i < main_string.size())
    {
        if (main_string[i] == match_string[j])
        {
            ++i;
            ++j;
        }
        else if(j==0)
        {
            ++i;
        }
        else
        {
            j = next[j];
        }
    }

    if (j == match_string.size())
    {
        return i-match_string.size();
    }
    else
        return -1;
}