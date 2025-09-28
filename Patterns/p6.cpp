#include<iostream>
using namespace std;

// 1      1
// 12    21
// 123  321
// 12344321
void ptn1(int n)
{
    int space=2*(n-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<j+1;
        }
        for(int j=0;j<space;j++)
        {
            cout<<" ";
        }
        for(int j=i;j>=0;j--)
        {
            cout<<j+1;
        }
        cout<<endl;
        space-=2;
    }
}
int main(){
    int n;
    cin>>n;
    ptn1(n);
    return 0;
}