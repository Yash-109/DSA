#include<bits/stdc++.h>
using namespace std;


// linearSearch Time complexity:o(n)   n=linear tme complexity
int linearSearch(int arr[],int size,int target)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int size=7;
    int target=8;
    cout<<linearSearch(arr,size,target);
    return 0;
}