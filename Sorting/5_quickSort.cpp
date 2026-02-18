/*
 * Algorithm: Quick Sort
 * Type: Divide and Conquer Sorting Algorithm
 * Stability: Unstable (does not maintain relative order of equal elements)
 * 
 * Time Complexity:
 *   - Best Case:    O(n log n) - balanced partitions
 *   - Average Case: O(n log n)
 *   - Worst Case:   O(n²) - already sorted or reverse sorted
 * 
 * Space Complexity: O(log n) - recursion stack for balanced partitions
 *                   O(n) - worst case recursion depth
 * 
 * How it works:
 * 1. Pivot Selection: Choose a pivot element (usually last element)
 * 2. Partition: Rearrange array so elements < pivot are on left, >= pivot on right
 * 3. Divide: Recursively sort left and right partitions
 * 
 * Key Properties:
 * - In-place sorting (no extra array needed)
 * - Cache-friendly (good locality of reference)
 * - Preferred for arrays (not good for linked lists)
 * - Can be optimized with random pivot or median-of-three
 * 
 * Recurrence Relation: T(n) = T(k) + T(n-k-1) + O(n)
 * where k is the number of elements smaller than pivot
 */

#include <iostream>
#include <vector>
using namespace std;

// Partition array around pivot and return pivot's final position
// Time Complexity: O(n) where n = end - st + 1
int partition(vector<int> &arr, int st, int end) {
    int idx = st - 1;          // Index of smaller element
    int pivot = arr[end];      // Choose last element as pivot

    // Traverse array and move elements <= pivot to left side
    for(int j = st; j < end; j++) {
        if(arr[j] <= pivot) {  // For descending order: use >= only
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    // Place pivot in its correct position
    idx++;
    swap(arr[end], arr[idx]);
    return idx;  // Return pivot's final index
}

// Recursively partition and sort array
// Time Complexity: O(n log n) average, O(n²) worst case
void quickSort(vector<int> &arr, int st, int end) {
    if(st < end) {
        // Partition array and get pivot index
        int pivIdx = partition(arr, st, end);
        
        quickSort(arr, st, pivIdx - 1);    // Sort left half (elements < pivot)
        quickSort(arr, pivIdx + 1, end);   // Sort right half (elements > pivot)
    }
}

int main() {
    // Test Case 1: Random unsorted array
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    cout << "Original array: ";
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // Test Case 2: Already sorted array (worst case for basic quick sort)
    cout << "\nTest Case 2 - Already sorted:" << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original: ";
    for (int val : arr2) cout << val << " ";
    quickSort(arr2, 0, arr2.size() - 1);
    cout << "\nSorted: ";
    for (int val : arr2) cout << val << " ";
    cout << endl;

    // Test Case 3: Reverse sorted array (worst case)
    cout << "\nTest Case 3 - Reverse sorted:" << endl;
    vector<int> arr3 = {9, 7, 5, 3, 1};
    cout << "Original: ";
    for (int val : arr3) cout << val << " ";
    quickSort(arr3, 0, arr3.size() - 1);
    cout << "\nSorted: ";
    for (int val : arr3) cout << val << " ";
    cout << endl;

    // Test Case 4: Array with duplicates
    cout << "\nTest Case 4 - With duplicates:" << endl;
    vector<int> arr4 = {5, 2, 8, 2, 9, 1, 5};
    cout << "Original: ";
    for (int val : arr4) cout << val << " ";
    quickSort(arr4, 0, arr4.size() - 1);
    cout << "\nSorted: ";
    for (int val : arr4) cout << val << " ";
    cout << endl;

    return 0;
}