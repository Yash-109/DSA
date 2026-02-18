/*
 * Problem: Count Inversions in an Array
 * Technique: Divide and Conquer (Modified Merge Sort)
 * 
 * An inversion is a pair of indices (i, j) such that i < j and arr[i] > arr[j]
 * Returns the total number of inversions in the array
 * 
 * Time Complexity: O(n log n) - same as merge sort
 * Space Complexity: O(n) - temporary array for merging
 * 
 * Logic:
 * 1. Divide: Split array into two halves recursively
 * 2. Conquer: Count inversions in left half and right half recursively
 * 3. Combine: Count split inversions while merging sorted halves
 *    - When arr[i] > arr[j] (i from left, j from right)
 *    - All remaining elements in left half also form inversions with arr[j]
 *    - Add (mid - i + 1) to inversion count
 * 4. Base case (BC): single element has 0 inversions
 * 
 * Example: [6, 3, 5, 2, 7]
 *   Inversions: (6,3), (6,5), (6,2), (3,2), (5,2) = 5 inversions
 * 
 * Key Pattern: Divide -> Count Left + Right -> Count Split -> Combine
 */

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays and count split inversions
// Time Complexity: O(n) where n = end - st + 1
int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    // Merge and count inversions
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            // arr[i] > arr[j]: inversion found
            // All elements from i to mid are greater than arr[j]
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);  // Count split inversions
        }
    }

    // Copy remaining elements from left half
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right half
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for(int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }

    return invCount;
}

// Recursively divide array and count inversions
// Time Complexity: O(n log n)
int mergeSort(vector<int> &arr, int st, int end) {
    if(st < end) {
        int mid = st + (end - st) / 2;  // Avoid overflow

        // Count inversions in left half
        int leftInvCount = mergeSort(arr, st, mid);
        
        // Count inversions in right half
        int rightInvCount = mergeSort(arr, mid + 1, end);

        // Count split inversions while merging
        int invCount = merge(arr, st, mid, end);

        // Total inversions = left + right + split
        return leftInvCount + rightInvCount + invCount;
    }

    return 0;  // Base case: single element has 0 inversions
}

int main() {
    // Test Case 1: Example from description
    vector<int> arr1 = {6, 3, 5, 2, 7};
    cout << "Test Case 1:" << endl;
    cout << "Original array: ";
    for (int val : arr1) {
        cout << val << " ";
    }
    cout << endl;
    
    int ans1 = mergeSort(arr1, 0, arr1.size() - 1);
    cout << "Inversion count: " << ans1 << endl;
    cout << "Sorted array: ";
    for (int val : arr1) {
        cout << val << " ";
    }
    cout << endl;
    // Expected: 5 inversions - (6,3), (6,5), (6,2), (3,2), (5,2)

    // Test Case 2: Larger array
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {1, 3, 5, 10, 2, 6, 8, 9};
    cout << "Original array: ";
    for (int val : arr2) {
        cout << val << " ";
    }
    cout << endl;
    
    int ans2 = mergeSort(arr2, 0, arr2.size() - 1);
    cout << "Inversion count: " << ans2 << endl;
    cout << "Sorted array: ";
    for (int val : arr2) {
        cout << val << " ";
    }
    cout << endl;
    // Expected: 4 inversions - (3,2), (5,2), (10,2), (10,6), (10,8), (10,9)

    // Test Case 3: Already sorted (best case)
    cout << "\nTest Case 3 - Already sorted:" << endl;
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for (int val : arr3) {
        cout << val << " ";
    }
    cout << endl;
    
    int ans3 = mergeSort(arr3, 0, arr3.size() - 1);
    cout << "Inversion count: " << ans3 << endl;
    // Expected: 0 inversions

    // Test Case 4: Reverse sorted (worst case)
    cout << "\nTest Case 4 - Reverse sorted:" << endl;
    vector<int> arr4 = {5, 4, 3, 2, 1};
    cout << "Original array: ";
    for (int val : arr4) {
        cout << val << " ";
    }
    cout << endl;
    
    int ans4 = mergeSort(arr4, 0, arr4.size() - 1);
    cout << "Inversion count: " << ans4 << endl;
    // Expected: 10 inversions - n*(n-1)/2 for reverse sorted

    return 0;
}