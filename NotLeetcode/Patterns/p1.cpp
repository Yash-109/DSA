#include<iostream>
using namespace std;

// *
// **
// ***
// ****
// *****
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<"\n";
    }
}

// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5
void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<i+1<<" ";
        }
        cout<<"\n";
    }
}

// A
// AB
// ABC
// ABCD
// ABCDE
void pattern4(int n)
{
    
    for(int i =0;i<n;i++)
    {
        char ch = 'A';
        for(int j=0;j<=i;j++)
        {
            cout<<ch;
            ch++;
        }
        cout<<endl;
        
    }
}

// A
// BB
// CCC
// DDDD
// EEEEE
void pattern5(int n)
{
    char ch = 'A';
    for(int i =0;i<n;i++)
    {
        
        for(int j=0;j<=i;j++)
        {
            cout<<ch;
            
        }
        ch++;
        cout<<endl;
        
    }
}

void pattern6(int n)
{
    
    for(int i =0;i<n;i++)
    {
        char ch = 'E' - i;
        for(int j=0;j<=i;j++)
        {
            cout<<ch;
            ch++;
        }
        
        cout<<endl;
        
    }
}
int main(){
    int t;
    cin>>t;      // for test case enter: how many pattern want to print
    for(int i=0;i<t;i++){
       int n;
       cin>>n;        // no of rows for each pattern particular
    //    pattern1(n);          
    //    pattern2(n);
    //    pattern3(n);
    //    pattern4(n);
    //    pattern5(n);
       pattern6(n);
    }
    
    return 0;
}