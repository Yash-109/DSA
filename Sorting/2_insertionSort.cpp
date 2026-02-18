
#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)  // O(n^2)
{
    for(int i=1;i<n;i++)  // started form 1 bcz we want first element of unsorted part
    {
        int curr = arr[i];
        int prev = i-1;

        while(prev>=0 && arr[prev] > curr)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;  // placing current element in its correct position
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[]={4,1,5,2,3};
    int n=sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}