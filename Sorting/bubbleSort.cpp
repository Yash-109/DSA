#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n)  // O(n*n)  // O(n^2)
{
    for(int i=0;i<n-1;i++)   //O(n)
    {
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++)  // this loops run n time when i change so // O(n)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j] , arr[j+1]); 
                isSwap=true;
            }
        }

        if(isSwap == false)  // optimization but still tc: O(n)
        {
            break;
        }
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++) 
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={4,1,5,2,3};
    int n=sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,n);
    printArray(arr,n);

    return 0;
}