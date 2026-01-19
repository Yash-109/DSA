/*
 * Bubble Sort Implementation
 * Time Complexity: O(n^2) in worst case, O(n) in best case (optimized)
 * Space Complexity: O(1)


#include<iostream>
using namespace std;

// Bubble Sort with optimization (early termination if array is already sorted)
void bubbleSort(int arr[], int n)
{
    // Outer loop: iterate through all elements
    for(int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        // Inner loop: compare adjacent elements and swap if needed
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j] , arr[j+1]); 
                isSwap=true;
            }
        }

        if(isSwap == false)  // optimization but still tc: O(n^2)
        {
            break;
        }
    }
}

// Utility function to print array elements
// Helper function to print array elements
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
    bubbleSort(arr,n);
    printArray(arr,n);

    return 0;
}