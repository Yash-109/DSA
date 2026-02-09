/*
 * Problem: Check if Array is Sorted
 * 
 * Use recursion to verify if array is sorted in ascending order
 * Checks from end to beginning
 * 
 * Time Complexity: O(n) - checks all elements
 * Space Complexity: O(n) - recursion call stack
 */

#include<iostream>
#include<vector>
using namespace std;

// Returns true if array is sorted in ascending order
bool isSorted(vector<int> arr, int n){
    // Base case: array with 0 or 1 element is always sorted
    if(n == 0 || n==1) return true;
    else{
        // Check if last element > second last AND rest of array is sorted
        return arr[n-1] > arr[n-2] && isSorted(arr, n-1);
    }
}
int main()
{
    vector<int> a = {1, 3, 6, 8, 7};
    
    if(isSorted(a, a.size())){
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;  // This will be printed
    }

    return 0;
}