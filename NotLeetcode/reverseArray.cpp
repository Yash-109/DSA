#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6,7};
    int size = 7;
    
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    reverse(arr, size);
    
    cout << "Reversed array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}