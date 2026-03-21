/* 
 * Problem: 31. Next Permutation
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/next-permutation/
 * 
 * Find the next lexicographically greater permutation of numbers
 * If no greater permutation exists, rearrange to lowest possible order
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

/*
 * Approach (Pivot + Swap + Reverse)
 * ---------------------------------
 * - We want the smallest permutation that is greater than the current one.
 * - Steps:
 *   1) Scan from right to left to find the first index 'pivot' such that
 *        A[pivot] < A[pivot + 1].
 *      - If no such index exists, the array is in descending order; simply
 *        reverse the whole array to get the lowest (sorted ascending).
 *   2) From the right end again, find the first element A[i] that is
 *        strictly greater than A[pivot]. Swap A[i] and A[pivot].
 *   3) Finally, reverse the subarray from pivot+1 to end to make it the
 *        smallest possible (sorted ascending) suffix.
 *
 * Pseudocode
 * ---------
 *   function nextPermutation(A):
 *       n = A.size()
 *       pivot = -1
 *
 *       // step 1: find pivot
 *       for i from n-2 down to 0:
 *           if A[i] < A[i+1]:
 *               pivot = i
 *               break
 *
 *       if pivot == -1:
 *           reverse A[0 .. n-1]
 *           return
 *
 *       // step 2: find element just larger than A[pivot]
 *       for i from n-1 down to pivot+1:
 *           if A[i] > A[pivot]:
 *               swap A[i], A[pivot]
 *               break
 *
 *       // step 3: reverse suffix
 *       left  = pivot + 1
 *       right = n - 1
 *       while left < right:
 *           swap A[left], A[right]
 *           left  = left + 1
 *           right = right - 1
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A) {


        //  this problem can be solved by only: 
        //         next_permutaion(A.begin(),A.end());




        // find the pivot
        int pivot=-1;
        int n = A.size();

        for(int i=n-2;i>=0;i--)      // start n-2 bcz comparing with last-1
        {
            if(A[i]<A[i+1])
            {
                pivot = i;
                break;
            }
        }

        if(pivot == -1)
        {
            reverse(A.begin(), A.end());  // inplace changes: changed in same vector
            return;
        }

        // find next larger element
        for(int i=n-1;i>pivot;i--)
        {
            if(A[i]>A[pivot])
            {
                swap(A[i],A[pivot]);
                break;
            }
        }

        // reverse form piv+1 to n-1 using 2 pointer
        int i=pivot+1, j=n-1;

        while(i<=j)
        {
            swap(A[i],A[j]);
            i++;
            j--;
        }

        // or we can do: reverse(A.begin() + pivot +1, A.end());

    }
};