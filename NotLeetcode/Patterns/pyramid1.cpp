#include<iostream>
using namespace std;

int main()
{
    int n=4;
    for(int i=0;i<n;i++)
    {
        for(int j=n-i-1;j>0;j--) // want loop that iterate n-i-1 time and print space
        {
            cout<< " ";
        }
        for(int j=0;j<i+1;j++) // print simple num pattern
        {
            cout<<j+1;
        } 
        for(int j=i;j>0;j--) // print last number pattern which start from second line
        {
            cout<<j;
        }
        
        cout<<endl;
    }
    return 0;
}
