#include<iostream>
using namespace std;

// *****
// *   *
// *   *
// *   *
// *****
void ptn1(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i== 0 || i==n-1 || j==0 || j==n-1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void ptn2(int n)
{
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {

        }
    }
}
int main()
{
    int n;
    cin>>n;
    ptn1(n);
    return 0;
}