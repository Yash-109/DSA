#include<iostream>
using namespace std;

// 1
// 01
// 101
// 0101
// 10101

void ptn1(int n)
{
    for(int i=0;i<n;i++)
    {
        int start=1;
        if(i%2==0){
            start=1;
        }
        else{
            start=0;
        }

        for(int j=0;j<=i;j++)
        {
             cout<<start;
             start= 1 - start;
        }
        cout<<endl;
    }

}

// 1 
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
void ptn2(int n)
{ int a=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    ptn1(n);
    ptn2(n);
    return 0;
}