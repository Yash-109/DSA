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