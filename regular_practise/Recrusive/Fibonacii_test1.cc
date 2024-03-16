#include<iostream>

using namespace std;
const int Size=10;

int ans[Size]={0};
int Fibon_Calculation(int);

int main()
{
    ans[1]=1;

    for(int i=0;i<Size;++i)
    {
        if(i==0||i==1)
        {
            cout<<"The "<<i+1<<"th of Fibonacii is:"<<ans[i]<<endl;
            continue;
        }

        if(ans[i]==0)
        {
            ans[i]=ans[i-1]+ans[i-2];
        }
        cout<<"The "<<i+1<<"th of Fibonacii is:"<<ans[i]<<endl;
    }
}