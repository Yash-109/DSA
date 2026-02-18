/*
 * Algorithm: Merge Sort
 * Type: Divide and Conquer Sorting Algorithm
 * Stability: Stable (maintains relative order of equal elements)
 * 
 * Time Complexity:
 *   - Best Case:    O(n log n)
 *   - Average Case: O(n log n)
 *   - Worst Case:   O(n log n)
 * 
 * Space Complexity: O(n) - requires additional array for merging
 * 
 * How it works:
 * 1. Divide: Split array into two halves recursively until single elements
 * 2. Conquer: Recursively sort both halves
 * 3. Combine: Merge the two sorted halves into one sorted array
 * 
 * Key Properties:
 * - Predictable performance (always O(n log n))
 * - Stable sort (preserves order of equal elements)
 * - Not in-place (requires extra space)
 * - Preferred for linked lists and external sorting
 * 
 * Recurrence Relation: T(n) = 2T(n/2) + O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays: arr[st...mid] and arr[mid+1...end]
// Time Complexity: O(n) where n = end - st + 1
void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    // Compare elements from both halves and add smaller one to temp
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {        // for desceneding order do >= only
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left half (if any)
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right half (if any)
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}

// Recursively divide array and merge sorted halves
// Time Complexity: O(n log n)
void mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;  // Avoid overflow with (st + end) / 2

        mergeSort(arr, st, mid);       // left half
        mergeSort(arr, mid + 1, end);  // right half

        merge(arr, st, mid, end);      // merge sorted halves
    }
}

int main() {
    // Test Case 1: Random unsorted array
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // Test Case 2: Already sorted array
    cout << "\nTest Case 2 - Already sorted:" << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original: ";
    for (int val : arr2) cout << val << " ";
    mergeSort(arr2, 0, arr2.size() - 1);
    cout << "\nSorted: ";
    for (int val : arr2) cout << val << " ";
    cout << endl;

    // Test Case 3: Reverse sorted array (worst case for some algorithms)
    cout << "\nTest Case 3 - Reverse sorted:" << endl;
    vector<int> arr3 = {9, 7, 5, 3, 1};
    cout << "Original: ";
    for (int val : arr3) cout << val << " ";
    mergeSort(arr3, 0, arr3.size() - 1);
    cout << "\nSorted: ";
    for (int val : arr3) cout << val << " ";
    cout << endl;

    return 0;
}
