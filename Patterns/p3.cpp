#include<iostream>
using namespace std;

//      *
//     ***
//    *****
//   *******
//  *********

void ptn1(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
void ptn3(int a)
{
    
    for(int i=0;i<a;i++)
    {
        
        for(int j=0;j<a-i-1;j++)
        {
            cout<<" ";
        }

        char ch = 'A';
        int breakpoint= (2*i+1) / 2;    //main logic 
        for(int j=0;j<2*i+1;j++)
        {
            cout<<ch;
            if(j<breakpoint)
            {
                ch++;
            }
            else
            {
                ch--;
            }
            
        }
        cout<<endl;
    }
}

// *********
//  ******* 
//   *****
//    ***
//     *

void ptn2(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<i;j++)   // space
        {
            cout<<" ";
        }
        for(int j=0;j<2*a - (2*i +1);j++)     // *
        {
            cout<<"*";
        }
        for(int j=0;j<i;j++) // space
        {
            cout<<" ";
        }
        cout<<endl;
    }

}
int main(){
    int n;
    cin>>n; 
    // ptn1(n);
    // ptn2(n);
    ptn3(n);
    return 0;
}