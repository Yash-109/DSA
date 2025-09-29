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

// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444
void ptn2(int n)
{
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            int top=i;
            int left = j;
            int right= (2*n-2)- j;
            int down = (2*n-2) - i;
            cout<<(n - min(min(top,down), min(right,left)));
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    // ptn1(n);
    ptn2(n);
    return 0;
}