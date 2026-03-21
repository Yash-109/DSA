// LeetCode 11: Container With Most Water
// Time Complexity: O(n^2) - brute force approach
// Space Complexity: O(1) - only using constant extra space

/*
 * Approach 1 (Brute Force)
 * ------------------------
 * - For every pair of lines (i, j), compute width = j - i and height =
 *   min(height[i], height[j]); water = width * height.
 * - Track the maximum water over all pairs. Time: O(n^2).
 *
 * Approach 2 (Two Pointers - Optimal)
 * -----------------------------------
 * - Use two pointers lp (left) and rp (right) starting at the ends.
 * - At each step, compute width = rp - lp, ht = min(height[lp], height[rp]),
 *   and update maxWater.
 * - Move the pointer that has the smaller height inward, because the area is
 *   limited by the shorter line; moving the taller one cannot increase
 *   height, but moving the shorter one might find a taller line.
 * - Continue until lp >= rp. Time: O(n).
 *
 * Pseudocode (Two Pointers)
 * -------------------------
 *   function maxArea(height):
 *       lp = 0
 *       rp = height.size() - 1
 *       maxWater = 0
 *
 *       while lp < rp:
 *           width = rp - lp
 *           ht = min(height[lp], height[rp])
 *           currWater = width * ht
 *           maxWater = max(maxWater, currWater)
 *
 *           if height[lp] < height[rp]:
 *               lp = lp + 1
 *           else:
 *               rp = rp - 1
 *
 *       return maxWater
 */

#include<bits/stdc++.h>
using namespace std;

// brute force approach  
int container(int arr[], int size)
{
    int ans = 0;
    int width, height, currWater;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        { 
            width = j - i;
            height = min(arr[i], arr[j]);
            currWater = width * height;

            ans = max(ans, currWater);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(arr) / sizeof(arr[0]);  
    cout << container(arr, size);
    return 0;
}

// bruteforce:o(n^2) means 10^5*2=10^20 which is greater than 10^8 so Time  Limit Exciding (TLE)  we have to make it optimal

//optimal TC: O(n)  using two pointer approach,

class Solution{
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int lp=0,rp=height.size()-1;
        while(lp<rp)
        {
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int currWater= w*ht;
            maxWater=max(maxWater,currWater);

            height[lp]<height[rp] ? lp++ : rp--;  //ternary operator
        }

        return maxWater;
    }
};
 